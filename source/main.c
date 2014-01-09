/*  rpipes - email notifrication on low temperature detection */
/*  main.c - raspberry pi gpio specific includes              */

/* 
Copyright (C) 2014 Ray Schuler (rschuler the-one-at champlain.edu)

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

Also add information on how to contact you by electronic and paper mail.
*/

/*  
 *  todo: 
 *  be lazy!  let CSI-280 students improve.
 *  
 * Notes:
 -  only using gpio on raspi connector (0-25 wth some gaps)
    since all pins < 31, no need to adjust base address.
    for pins > 31, add the follwing code for each required
    base:
 // determine which base address to use
 if(out_pin > 31) 
 GPIO_BASE += 4;
 if(in_pin > 31) 
 GPIO_LEVEL += 4;
 out_pin %= 32; // 32 out_pins per register
 in_pin %= 32; //  32 in_pins per register
 
 - code to test pin 17 for high bit
 if(reg_value & 0x00020000){
 GPIO_SET(out_pin,HIGH);
 } else {
 GPIO_SET(out_pin,LOW);
 }
 
*/

#include "arch.h"

#ifdef WEEZY
#include "weezy.h" /* linux build */
#endif

/* baremetal includes */
#include <stdint.h>
#include "utils.h"
#include "gpio.h"

#ifdef WEEZY
volatile unsigned *gpio;
#endif

void main ()
{

  /* sandbox testing */
  // printf("sandbox testing...\n");

  /* gpio vars */  
  volatile unsigned int* GPIO_BASE = (unsigned int *)0x20200000;
  volatile unsigned int* GPIO_HIGH;
  volatile unsigned int* GPIO_LOW;
  volatile unsigned int* GPIO_LEVEL;
  unsigned int out_pin = 25;
  unsigned int in_pin = 17;

  /* general variables */

  LEVEL value = 0;  
  LEVEL old_value = 0;  

#ifdef WEEZY
  setup_io();
  GPIO_BASE = gpio;
  printf("GPIO_BASE (weezy): %08X\n", GPIO_BASE);
#endif
  
  GPIO_LEVEL = GPIO_BASE + 13;        /* 13*4bytes */
  GPIO_FSEL(out_pin, OUTPUT);
  GPIO_FSEL(in_pin, INPUT);
  
  GPIO_HIGH = GPIO_BASE+7;
  GPIO_LOW = GPIO_BASE+10;

  out_pin %= 32; // 32 outpins per register
  in_pin %= 32; //  32 inpins per register

  /* start controlling pins */  

  /* perform a read when out_pin is high */
  while (1) {
    // GPIO_SET(out_pin,LOW);
    // sleep(1);
    // GPIO_SET(out_pin,HIGH);
    value = GPIO_GET(in_pin);
    printf("  switch status: %0x\n", value);
    if ( (old_value==1) && value==0) {
      printf("    sending alert email...\n");
      
      /* assumes execution from rpipes directory */
      system(
       "cat email-message.txt > email-message-send.txt"
            );
      system(
       "/sbin/ifconfig | grep addr:10 >> email-message-send.txt"
            );
      system(
       "cat email-message-send.txt | mail -s \"Rpipes Alert\" rschuler the-one-at champlain.edu"
            );
      
      printf("    mail sent...\n");
      
    } // end if ( (old_value==1)

    old_value = value;
    //    sleep(60);
    sleep(5); // don't need to poll this often but will make testing easier
  } // end while (1)

#ifdef WEEZY
  printf("goodbye.\n");
#endif  
}
