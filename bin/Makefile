# aczutro
#
# useful-cpp - a collection of commonly-used functions for C++ programs
#
# Copyright 2005 - 2017 Alexander Czutro
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#
################################################################### aczutro ###

.SUFFIXES:	.cc .o
first:		all

### some variables ############################################################

# paths and targets

BASE = ..
INCLUDE = $(BASE)/include
LIB = $(BASE)/lib
SRC = $(BASE)/src

MAIN = aczutro
LIB_SRC = lib$(MAIN)

# compiler

CCC = g++
DEFINITIONS = 
CFLAGS = -c -Wall -O3 -std=c++14 $(DEFINITIONS) -I$(INCLUDE)
LFLAGS = -L$(LIB) -l$(MAIN)

### rules #####################################################################

all:			$(LIB)/$(LIB_SRC).a

# $(MAIN):		$(LIB)/$(MAIN).o $(LIB)/$(LIB_SRC).a
# 			$(CCC) -o $@ $< $(LFLAGS)
# 			strip $@

$(LIB)/%.o:		$(SRC)/%.cc $(INCLUDE)/$(LIB_SRC).h
			mkdir -p $(LIB)
			$(CCC) -o $@ $< $(CFLAGS)

$(LIB)/$(LIB_SRC).a:	$(LIB)/$(LIB_SRC).o
			ar rv $@ $<
			ranlib $@

# cleaning

.PHONY:	clean

clean:
	@rm -rf $(MAIN) $(LIB)

### aczutro ########################################################### end ###
