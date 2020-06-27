/*
This file is part of fnblit
Copyright 2020 浅倉麗子

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, version 3 of the License.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef _FNBLIT_H_
#define _FNBLIT_H_

#include <stdint.h>

#ifdef  __cplusplus
extern "C" {
#endif

int fnblit_set_font(void *font);
int fnblit_set_fg(uint32_t colour);
int fnblit_set_bg(uint32_t colour);
int fnblit_set_fb(void *fb, uint32_t pitch, uint32_t width, uint32_t height);

__attribute__ ((__format__ (__printf__, 3, 4)))
int fnblit_printf(uint32_t x, uint32_t y, const char *fmt, ...);

#ifdef  __cplusplus
}
#endif

#endif
