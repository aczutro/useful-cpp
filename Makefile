# aczutro
#
# useful-cpp - a collection of commonly-used functions for C++ programs
#
# Copyright 2005 - 2020 Alexander Czutro
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

all: build

SRC=src
BUILD=build

$(BUILD)/CMakeCache.txt: $(SRC)/CMakeLists.txt
	rm -f $@
	cmake -S$(SRC) -B$(BUILD) \
		-DCMAKE_INSTALL_PREFIX=$(HOME)/.local

build: $(BUILD)/CMakeCache.txt
	make -C $(BUILD)

install: build
	make -C $(BUILD) install

clean:
	rm -rf $(BUILD)

help:
	@echo "usage:"
	@echo
	@echo "make [all]    Same as make build"
	@echo "make build    Creates build system, then builds project."
	@echo "make install  Creates build system, then builds and installs project."
	@echo "make clean    Removes build system."

.PHONY: all build install clean help

### aczutro ########################################################### end ###
