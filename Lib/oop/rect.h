/*****************************************************************************
* Code accompanying the Application Note:
* "Object-Oriented Programming in C"
* https://www.state-machine.com/doc/AN_OOP_in_C.pdf
*
* Copyright (C) 2005-2017 Quantum Leaps. All Rights Reserved.
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
* along with this program. If not, see <https://www.gnu.org/licenses/>.
*
* Contact Information:
* https://www.state-machine.com
****************************************************************************/
#ifndef RECT_H
#define RECT_H

#include "shape.h" /* the base class interface */

/* Rectangle's attributes... */
typedef struct {
    Shape super; /* <== inherits Shape */

    /* attributes added by this subclass... */
    uint16_t width;
    uint16_t height;
} Rectangle;

/* constructor prototype */
void Rectangle_ctor(Rectangle * const me, int16_t x, int16_t y,
                    uint16_t width, uint16_t height);
void Rectangle_draw(Rectangle const * const me);
uint32_t Rectangle_area(Rectangle const * const me);
#endif /* RECT_H */
