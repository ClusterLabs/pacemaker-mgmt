/*
 * API of management library.
 *
 * Author: Huang Zhen <zhenhltc@cn.ibm.com>
 * Copyright (C) 2005 International Business Machines
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

#ifndef __MGMT_H
#define __MGMT_H 1

#include <mgmt/mgmt_common.h>

#define ENABLE_HB 	1
#define ENABLE_LRM 	2
#define ENABLE_CRM 	4
#define CACHE_CIB 	8

extern int init_mgmt_lib(const char* client_name, int enable_components);
extern int final_mgmt_lib(void);
typedef int (*event_handler)(const char* event);
extern char* process_msg(const char* msg);
extern int reg_event(const char* type, event_handler func);

#endif /* __MGMT_H */
