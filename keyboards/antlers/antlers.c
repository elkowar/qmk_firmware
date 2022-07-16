/* Copyright 2022 ElKowar
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "antlers.h"
#include <math.h>

#ifdef CONSOLE_ENABLE
#    include "print.h"
#endif

/*void pointing_device_init_kb(void) {*/
    /*pointing_device_set_cpi(512);*/
/*}*/

report_mouse_t pointing_device_task_kb(report_mouse_t report) {
    float rotation_deg = 30;
    float rotation = rotation_deg * 0.017453;
    report.x = report.x * cos(rotation) - report.y * sin(rotation);
    report.y = report.x * sin(rotation) + report.y * cos(rotation);
    return pointing_device_task_user(report);
}
