/*
 * $Id$
 *
 * Copyright (C) 2006 voice-system.ro
 *
 * This file is part of opensips, a free SIP server.
 *
 * opensips is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version
 *
 * opensips is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

/*!
 * \file
 * \brief Script variables
 */

#ifndef _SCRIPT_VAR_H_
#define _SCRIPT_VAR_H_

#include "usr_avp.h"

#define VAR_VAL_STR     (1<<0)
#define VAR_VAL_NULL    (1<<1)

typedef struct script_val {
	int flags;
	int_str value;
} script_val_t, *script_val_p;

typedef struct script_var {
	str name;
	script_val_t v;
	struct script_var *next;
} script_var_t, *script_var_p;

script_var_t* add_var(str *name);
script_var_t* set_var_value(script_var_t *var, int_str *value, int flags);
script_var_t* get_var_by_name(str *name);

void reset_vars();
void destroy_vars();
void destroy_vars_list(script_var_t *svl);

#endif

