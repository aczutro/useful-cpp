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

#ifndef libaczutro_h
#define libaczutro_h libaczutro_h

#include <cstdarg>
#include <cstdint>

namespace aczutro{

#define ACZUTRO_VERSION "aczutro version 1.0"

    /* Returns a c string containing version information. */
    inline const char *version(){
        return ACZUTRO_VERSION;
    }//version


    /*** numerical tests *****************************************************/

#define is_even(a)          ((a) % 2 == 0)
#define is_odd(a)           ((a) % 2 == 1)
#define is_between(a, b, c) (((b) <= (a)) && ((a) <= (c)))

    /* If the first argument ('a') equals one of the arguments starting from
     * the third position, returns the index of the first match (1 for the
     * first argument after 'n', 2 for the second, etc.).  If there are no
     * matches, returns 0.
     * The second argument ('n') specifies the number of arguments that follow
     * 'n'. */
    template<typename T> uint16_t is_one_of(T a, uint8_t n, ...){
        va_list args;
        va_start(args, n);
        typedef typename std::conditional<
            (std::is_same<T, float>::value || std::is_same<T, double>::value),
            double,
            int
            >::type U;
        for(uint8_t i = 0; i < n; i++){
            if(a == (T)va_arg(args, U)){
                va_end(args);
                return i + 1;
            }//if
        }//for
        va_end(args);
        return 0;
    }//is_one_of


    /*** printing information ************************************************/

    /* Prints an error message to STDERR and quits the main application.
     * In addition, if 'recommend_help' is true, the message
     * "Try 'arg0 --help' for more information." is also printed. */
    void error_and_exit(uint8_t status,      // exit status
                        bool recommend_help, // flag
                        const char *arg0,    // the name of the application
                        const char *message, // the error message
                        ...                  // variable arguments to message
                                             // (think printf)
                        );

    enum dump_mode {DUMP_BYTE, DUMP_HALF, DUMP_WORD};

    /* Prints 'n' bytes/halfwords/words of raw memory contents,
     * starting at address 'mem'. */
    void memory_dump(const char *label, const void *mem, uint64_t n,
                     dump_mode mode=DUMP_BYTE);


    /*** byte manipulation ***************************************************/

    /* Concatenates two bytes. */
    inline uint16_t make_halfword(uint8_t a, uint8_t b){
        return (a << 8) | b;
    }//make_halfword


    /* Writes into a1, a2 the two bytes contained in halfword. */
    inline void unpack_halfword(uint16_t halfword, uint8_t *a1, uint8_t *a2){
        *a1 = (halfword >> 8) & 0x00ff;
        *a2 = halfword & 0x00ff;
        return;
    }//unpack_halfword


    /* Concatenates two halfwords or four bytes. */
    inline uint32_t make_word(uint16_t a, uint16_t b){
        return (a << 16) | b;
    }//make_word

    inline uint32_t make_word(uint8_t a, uint8_t b, uint8_t c, uint8_t d){
        return (a << 24) | (b << 16) | (c << 8) | d;
    }//make_word


    /* Writes into a1, a2 the two halfwords contained in a word,
     * or into a1, a2, a3, a4 the four bytes contained in a word. */
    inline void unpack_word(uint32_t word, uint16_t *a1, uint16_t *a2){
        *a1 = (word >> 16) & 0x0000ffff;
        *a2 = word & 0x0000ffff;
        return;
    }//unpack_word

    inline void unpack_word(uint32_t word,
                            uint8_t *a1, uint8_t *a2, uint8_t *a3, uint8_t *a4){
        *a1 = (word >> 24) & 0x000000ff;
        *a2 = (word >> 16) & 0x000000ff;
        *a3 = (word >> 8) & 0x000000ff;
        *a4 = word & 0x000000ff;
        return;
    }//unpack_word

}//aczutro

#endif

/* aczutro ************************************************************* end */
