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

cmake_minimum_required (VERSION 3.17)
project(useful-cpp)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

file(GLOB header-files *.h)
file(GLOB source-files *.cc *.h)

add_library(aczutro STATIC ${source-files})

install(TARGETS aczutro DESTINATION lib/libaczutro)
install(FILES ${header-files} DESTINATION include/libaczutro)

### aczutro ########################################################### end ###
