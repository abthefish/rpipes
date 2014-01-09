/* weezy.h - raspberry pi weezy specific includes */

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

#ifndef _WEEZY_H_
#define _WEEZY_H_

#include "arch.h"

#ifdef WEEZY
#include <stdio.h>

/* weezy gpio mem map of io space start */
#include <sys/mman.h>
#include <fcntl.h>
#include <stdlib.h>
#define BLOCK_SIZE (4*1024)
#define MAP_GPIO_BASE  0x20200000

void setup_io();
#endif /* WEEZY */
#endif /* _WEEZY_H_ */
