/*
 * $Id$
 *
 * Copyright (C) 2001-2003 FhG Fokus
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


#ifndef PARSE_URI_H
#define PARSE_URI_H

/*
 * SIP URI parser
 */


#include "../str.h"
#include "../parser/msg_parser.h"

/* buf= pointer to begining of uri (sip:x@foo.bar:5060;a=b?h=i)
 * len= len of uri
 * returns: fills uri & returns <0 on error or 0 if ok
 */
int parse_uri(char *buf, int len, struct sip_uri* uri);
/* headers  : the list of headers to parse (taken from uri structure)
 * h_name[] : array of header names
 * h_val[]  : array of header values
 * h_size   : size of header array */
int parse_uri_headers(str headers, str h_name[], str h_val[], int h_size);
int parse_sip_msg_uri(struct sip_msg* msg);
int parse_orig_ruri(struct sip_msg* msg);
int compare_uris(str *raw_uri_a,struct sip_uri* parsed_uri_a,
					str *raw_uri_b,struct sip_uri *parsed_uri_b);

#endif /* PARSE_URI_H */
