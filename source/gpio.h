/* gpio.h - raspberry pi gpio specific includes */
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

#ifndef _GPIO_H_
#define _GPIO_H_

#include "arch.h"

typedef enum{
  LOW = 0,
  HIGH = 1
} LEVEL;

typedef enum{
  INPUT = 0,
  OUTPUT = 1,
  ALT0 = 2,
  ALT1 = 3,
  ALT2 = 4,
  ALT3 = 5,
  ALT4 = 6,
  ALT5 = 7
} FSEL;

/**
 * Sets the corresponding GPIO pin to the LEVEL passed in
 */
void GPIO_SET(unsigned int pin, LEVEL lvl);

/**
 * Gets the current LEVEL of the GPIO pin
 */
LEVEL GPIO_GET(unsigned int pin);

/**
 * Sets the function select for the corresponding GPIO pin
 */
void GPIO_FSEL(unsigned int pin, FSEL sel);

#endif /* _GPIO_H_ */
