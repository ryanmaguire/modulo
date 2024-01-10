/******************************************************************************
 *                                  LICENSE                                   *
 ******************************************************************************
 *  This file is free software: you can redistribute it and/or modify         *
 *  it under the terms of the GNU General Public License as published by      *
 *  the Free Software Foundation, either version 3 of the License, or         *
 *  (at your option) any later version.                                       *
 *                                                                            *
 *  This file is distributed in the hope that it will be useful,              *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of            *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
 *  GNU General Public License for more details.                              *
 *                                                                            *
 *  You should have received a copy of the GNU General Public License         *
 *  along with this file.  If not, see <https://www.gnu.org/licenses/>.       *
 ******************************************************************************
 *  Author:     Ryan Maguire                                                  *
 *  Date:       January 10, 2024                                              *
 ******************************************************************************/

/*  Include guard to prevent including this file twice.                       */
#ifndef MODULO_H
#define MODULO_H

extern unsigned int mod4(unsigned int n);
extern unsigned int mod4_bit(unsigned int n);
extern unsigned int mod4_shift(unsigned int n);
extern unsigned int mod4_slow(unsigned int n);
extern unsigned int mod25_slow(unsigned int n);
extern unsigned int mod25(unsigned int n);

#endif
/*  End of include guard.                                                     */
