###############################################################################
#	makefile
#
#	A makefile script raspi under weezy linux
###############################################################################
#  rpipes - email notification on low temperature detection */
# 
# Copyright (C) 2014 Ray Schuler (rschuler the-one-at champlain.edu)
# 
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 2
# of the License, or (at your option) any later version.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software 
# Foundation, Inc., 51 Franklin Street, Fifth Floor, 
# Boston, MA 02110-1301, USA.

# Also add information on how to contact you by electronic and paper mail.

CC=gcc
CFLAGS=-O3  # baremetal and/or asm() may require -O0
DEPS = arch.h utils.h gpio.h weezy.h
OBJ = main.o  utils.o gpio.o weezy.o
SOURCE = source/

%.o: $(SOURCE)%.c $(SOURCE)$(DEPS)
	$(CC) -I $(SOURCE) -c -o $@ $< $(CFLAGS)

# Rule to make the object files.
%.o: $(SOURCE)%.c
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)

clean:
	rm -vf main *.o

