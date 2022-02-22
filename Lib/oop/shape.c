/*****************************************************************************
* Code accompanying the Application Note:
* "Object-Oriented Programming in C"
* https://www.state-machine.com/doc/AN_OOP_in_C.pdf
*
* Copyright (C) 2005-2018 Quantum Leaps. All Rights Reserved.
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

#include "shape.h" /* Shape class interface */
#include "driverlib/debug.h"


/* constructor implementation */
void Shape_ctor(Shape * const me, int16_t x, int16_t y) {
    static const struct ShapeVtbl ShapeVTable =
    {
         .draw = &Shape_draw
    };
    me->vptr = &ShapeVTable;
    me->x = x;
    me->y = y;

}

/* move-by operation implementation */
void Shape_moveBy(Shape * const me, int16_t dx, int16_t dy) {
    me->x += dx;
    me->y += dy;
}

uint32_t Shape_area(Shape const * const me)
{
    return me->x * me->y;
}

void Shape_draw(Shape const * const me)
{
    ASSERT(0);      /* purely-virtual function should never be called */
}

/* "getter" operations implementation */
int16_t Shape_getX(Shape const * const me) {
    return me->x;
}

int16_t Shape_getY(Shape const * const me) {
    return me->y;
}
