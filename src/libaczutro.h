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

#ifndef libaczutro_h
#define libaczutro_h libaczutro_h

#include <cstdarg>
#include <cstdint>
#include <type_traits>

namespace aczutro{

    /*!
     * Returns a c string containing version information.
     */
    inline const char* version()
    {
        return "1.1";
    }



    /*** numerical tests *****************************************************/

#define is_even(a)          ((a) % 2 == 0)
#define is_odd(a)           ((a) % 2 == 1)
#define is_between(a, b, c) (((b) <= (a)) && ((a) <= (c)))


    /*!
     * If the first arguments equals one of the candidates, returns the index
     * of the first match (starts from 1).
     *
     * If there are no matches, returns 0.
     *
     * \param a    number to compare
     * \param n    number of candidates
     * \param ...  the candidates
     */
    template<typename T> uint16_t is_one_of(T a, uint8_t n, ...)
    {
        va_list args;
        va_start(args, n);

        using U = typename std::conditional<
            (std::is_same<T, float>::value || std::is_same<T, double>::value),
            double,
            int
            >::type;

        for(uint8_t i = 0; i < n; i++)
        {
            if(a == (T)va_arg(args, U))
            {
                va_end(args);
                return i + 1;
            }
        }

        va_end(args);
        return 0;
    }



    /*** printing information ************************************************/

    /*!
     * Prints an error message to STDERR and quits the main application.
     *
     * If 'recommend_help' is true, the message
     * "Try 'arg0 --help' for more information." is also printed.
     *
     * \param status  The exit status.
     * \param arg0    The name of the application.
     * \param message A formatted message, like in printf.
     * \param ...     Variadic arguments referenced in the formatted message,
     *                like in printf.
     */
    void error_and_exit(uint8_t status, bool recommend_help, const char* arg0,
                        const char* message, ...);


    /*!
     * Operation mode of function memory_dump.
     */
    enum dump_mode
    {
        DUMP_BYTE,
        DUMP_HALF,
        DUMP_WORD
    };


    /*!
     * Prints 'n' bytes/halfwords/words of raw memory contents,
     * starting at address 'mem'.
     *
     * \param label A label to print at the beginning (e.g. variable name).
     * \param mem   Address to start at.
     * \param n     Number of elements to print.
     * \param mode  Type of elements to print.
     */
    void memory_dump(const char* label, const void* mem, uint64_t n, dump_mode mode=DUMP_BYTE);



    /*** byte manipulation ***************************************************/

    /*!
     * Concatenates two bytes.
     */
    inline uint16_t make_halfword(uint8_t a, uint8_t b)
    {
        return (a << 8) | b;
    }


    /*!
     * Writes into a1, a2 the two bytes contained in halfword.
     */
    inline void unpack_halfword(uint16_t halfword, uint8_t* a1, uint8_t* a2)
    {
        *a1 = (halfword >> 8) & 0x00ff;
        *a2 = halfword & 0x00ff;
   }


    /*!
     * Concatenates two halfwords into a word.
     */
    inline uint32_t make_word(uint16_t a, uint16_t b)
    {
        return (a << 16) | b;
    }


    /*!
     * Concatenates four bytes into a word.
     */
    inline uint32_t make_word(uint8_t a, uint8_t b, uint8_t c, uint8_t d)
    {
        return (a << 24) | (b << 16) | (c << 8) | d;
    }


    /*!
     * Concatenates a halfword and two bytes into a word.
     */
    inline uint32_t make_word(uint16_t a, uint8_t b, uint8_t c)
    {
        return (a << 16) | (b << 8) | c;
    }


    /*!
     * Writes into a1, a2 the two halfwords contained in a word.
     */
    inline void unpack_word(uint32_t word, uint16_t* a1, uint16_t* a2)
    {
        *a1 = (word >> 16) & 0x0000ffff;
        *a2 = word & 0x0000ffff;
   }

    /*!
     * Writes into a1, a2, a3 and a4 the four bytes contained in a word.
     */
    inline void unpack_word(uint32_t word, uint8_t* a1, uint8_t* a2, uint8_t* a3, uint8_t* a4)
    {
        *a1 = (word >> 24) & 0x000000ff;
        *a2 = (word >> 16) & 0x000000ff;
        *a3 = (word >> 8) & 0x000000ff;
        *a4 = word & 0x000000ff;
   }

} // namespace aczutro

#endif

/* aczutro */
