/* aczutro -*- c-basic-offset:4 -*-
 *
 * useful-cpp - a collection of commonly-used functions for C++ programs
 *
 * Copyright 2005 - 2020 Alexander Czutro
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

#include "libaczutro.h"

#include <cstdarg>
#include <cstring>
#include <iostream>


using namespace aczutro;


void error_and_exit(uint8_t status, bool recommend_help, const char* arg0, const char* message, ...)
{
    if(message && *message)
    {
        std::cerr << arg0 << ": ";

        va_list ap;
        va_start(ap, message);

        const char* p = message;
        while(*p)
        {
            if(*p == '%')
            {
                p++;
                switch(*p)
                {
                case 'i':
                    std::cerr << va_arg(ap, long);
                    break;
                case 'd':
                    std::cerr << va_arg(ap, double);
                    break;
                case 's':
                    std::cerr << va_arg(ap, const char*);
                    break;
                default:
                    std::cerr << "%";
                    break;
                }
            }
            else
                {
                std::cerr << *p;
            }
            p++;
        }

        va_end(ap);

        std::cerr << std::endl << std::flush;
    }

    if(recommend_help)
    {
        std::cerr << "Try '" << arg0 << " --help' for more information."
                  << std::endl << std::flush;
    }

    exit(status);
}


void memory_dump(const char* label, const void* mem, uint64_t n, dump_mode mode)
{
    printf("%s:", label);

    switch(mode)
    {
    case DUMP_BYTE:
    {
        const auto p = reinterpret_cast<const uint8_t*>(mem);
        for(uint i = 0; i < n; i++)
        {
            if((i % 16 == 0) && i)
            {
                printf("\n%*c", int(strlen(label) + 1), ' ');
            }
            if(i % 4 == 0)
            {
                printf("  ");
            }
            printf(" %02x", p[i]);
        }
        break;
    }

    case DUMP_HALF:
    {
        const auto p = reinterpret_cast<const uint16_t*>(mem);
        for(uint i = 0; i < n; i++)
        {
            if((i % 8 == 0) && i)
            {
                printf("\n%*c", int(strlen(label) + 1), ' ');
            }
            if(i % 2 == 0)
            {
                printf("  ");
            }
            printf(" %04x", p[i]);
        }
        break;
    }

    case DUMP_WORD:
    {
        const auto p = reinterpret_cast<const uint32_t*>(mem);
        for(uint i = 0; i < n; i++)
        {
            if(i % 4 == 0)
            {
                if(i)
                {
                    printf("\n%*c", int(strlen(label) + 2), ' ');
                }
                else
                {
                    printf(" ");
                }
            }
            printf("  %08x", p[i]);
        }
        break;
    }

    }

    printf("\n");
}

/* aczutro */
