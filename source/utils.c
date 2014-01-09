/*  utils.c - raspberry pi utility functions */

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

#include "utils.h"

void uwait(unsigned int val)
{
  volatile unsigned int t = val;
  while(t--)
    wait(9);
}

void mwait(unsigned int val)
{
  volatile unsigned int t = val;
  while(t--)
    wait(12500);
}

void wait_seconds(unsigned int t)
{
#ifdef WEEZY
  sleep(t);
#endif
#ifndef WEEZY
  mwait(t*1000);
#endif
}
