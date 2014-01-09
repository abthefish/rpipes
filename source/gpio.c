/* gpio.c - raspberry pi gpio specific code */
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

#include "gpio.h"

#ifdef WEEZY
#include <stdio.h>
extern gpio;
#endif

void GPIO_FSEL(unsigned int pin, FSEL sel)
{
  volatile unsigned int* GPIO_BASE = (unsigned int *)0x20200000;
  unsigned int curState = 0;

#ifdef WEEZY
  GPIO_BASE = (unsigned int *)gpio;
#endif  

  // get right address for pin
    if(pin >= 10)
      GPIO_BASE++;
    if(pin >= 20)
      GPIO_BASE++;
    if(pin >= 30)
      GPIO_BASE++;
    if(pin >= 40)
      GPIO_BASE++;
    if(pin >= 50)
      GPIO_BASE++;
  
    pin %= 10; // we can set 10 pins per register

#ifdef WEEZY
    //    printf("extern gpio: %08x\n", gpio);
    //    printf("GPIO_BASE: %08x\n", GPIO_BASE);
#endif

    curState = *(GPIO_BASE);       // get GPIO reg state
    curState &= ~(7 << (pin * 3)); // clear bits in question
    curState |= sel << (pin * 3);  // set bits in question
    
    *(GPIO_BASE) = curState;       // right state back to GPIO reg
}

void GPIO_SET(unsigned int pin, LEVEL lvl)
{
  volatile unsigned int* GPIO_BASE = (unsigned int *)0x20200000;

#ifdef WEEZY
  GPIO_BASE = (unsigned int *)gpio;
#endif  

  // determine which base address to use
  if(pin > 31)
    GPIO_BASE += 4;
  
  // determine whether we are setting or clearing
  if(lvl == HIGH)
    GPIO_BASE += 7;
  else
    GPIO_BASE += 10;

  pin %= 32; // we can set 32 pins per register
  
  *(GPIO_BASE) = 1 << pin;
}

LEVEL GPIO_GET(unsigned int pin)
{
  volatile unsigned int* GPIO_BASE = (unsigned int *)0x20200000;
  volatile unsigned int* GPIO_LEVEL;
  unsigned int val = 0;

#ifdef WEEZY
  GPIO_BASE = (unsigned int *)gpio;
#endif  

  GPIO_LEVEL = GPIO_BASE + 13;
  
  // determine which base address to use
  if(pin > 31)
    GPIO_LEVEL += 4;
  
  val = *(GPIO_LEVEL); // get all values

  pin %= 32; // we can get 32 pins per register
    
  val = (val >> pin) & 0x01; // isolate pin in quesetion

  if(val == 1)
    return HIGH;
  return LOW;
}

