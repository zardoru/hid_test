/****************************************************************************
 * Copyright (C) 2016 Maschell
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
 ****************************************************************************/

#ifndef _HID_H_
#define _HID_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "common/types.h"
#include "common/common.h"
#include "dynamic_libs/os_functions.h"
#include "dynamic_libs/syshid_functions.h"
#include "dynamic_libs/vpad_functions.h"

typedef struct _my_cb_user{
	unsigned char buf[16];
	unsigned char bufmax[16];
	unsigned char bufmin[16];
	unsigned int transfersize;
    unsigned int handle;
	HIDDevice * device;
}my_cb_user;

typedef struct _bptr_my_cb_user{
	unsigned char *buf;
	unsigned int transfersize;
    unsigned int handle;
	HIDDevice * device;
} _bptr_my_cb_user;

void hid_init();

void hid_deinit();


void my_read_cb(u32 handle,s32 error,u8 *p_buffer,u32 bytes_transfered,void *p_user);
s32 my_attach_cb(HIDClient *p_client, HIDDevice *p_device, u32 attach);


#ifdef __cplusplus
}
#endif

#endif /* _HID_H_ */
