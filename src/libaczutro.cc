/* aczutro -*- c-basic-offset:4 -*-
 *
 * useful-cpp - a collection of commonly-used functions for C++ programs
 *
 * Copyright 2005 - 2017 Alexander Czutro
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 ******************************************************************* aczutro */

#include <cstdarg>
#include <cstring>

#include <iostream>

#include <libaczutro.h>


/*** printing information ****************************************************/

void aczutro::error_and_exit(uint8_t status,
                             bool recommend_help,
                             const char *arg0,
                             const char *message, ...
                             ){
    if(message && *message){
        std::cerr << arg0 << ": ";
        va_list ap;
        const char *p = message;
        va_start(ap, message);
        while(*p){
            if(*p == '%'){
                p++;
                switch(*p){
                case 'i': std::cerr << va_arg(ap, long);	break;
                case 'd': std::cerr << va_arg(ap, double);	break;
                case 's': std::cerr << va_arg(ap, const char*);	break;
                default:  std::cerr << "%";			break;
                }//switch
            }else{
                std::cerr << *p;
            }//else
            p++;
        }//while
        va_end(ap);
        std::cerr << std::endl << std::flush;
    }//if
    if(recommend_help){
        std::cerr << "Try '" << arg0 << " --help' for more information."
                  << std::endl << std::flush;
    }//if
    exit(status);
}//error_and_exit

/*****************************************************************/

void aczutro::memory_dump(const char *label, const void *mem,
                          uint64_t n, dump_mode mode){
    printf("%s:", label);
    switch(mode){
    case DUMP_BYTE:{
        const uint8_t *p = reinterpret_cast<const uint8_t*>(mem);
        for(uint i = 0; i < n; i++){
            if((i % 16 == 0) && i){
                printf("\n%*c", (int)(strlen(label) + 1), ' ');
            }//if
            if(i % 4 == 0){
                printf("  ");
            }//if
            printf(" %02x", p[i]);
        }//for
        break;
    }//DUMP_BYTE
    case DUMP_HALF:{
        const uint16_t *p = reinterpret_cast<const uint16_t*>(mem);
        for(uint i = 0; i < n; i++){
            if((i % 8 == 0) && i){
                printf("\n%*c", (int)(strlen(label) + 1), ' ');
            }//if
            if(i % 2 == 0){
                printf("  ");
            }//if
            printf(" %04x", p[i]);
        }//for
        break;
    }//DUMP_HALF
    case DUMP_WORD:{
        const uint32_t *p = reinterpret_cast<const uint32_t*>(mem);
        for(uint i = 0; i < n; i++){
            if(i % 4 == 0){
                if(i){
                    printf("\n%*c", (int)(strlen(label) + 2), ' ');
                }else{
                    printf(" ");
                }//else
            }//if
            printf("  %08x", p[i]);
        }//for
        break;
    }//DUMP_WORD
    }//switch
    printf("\n");
}//memory_dump

/* aczutro ************************************************************* end */
