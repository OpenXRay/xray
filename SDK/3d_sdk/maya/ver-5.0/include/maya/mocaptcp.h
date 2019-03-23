/*
 * *****************************************************************************
 *
 * Copyright (C) 1997-2001 Alias|Wavefront Inc.
 *
 * These coded instructions, statements and computer programs contain
 * unpublished information proprietary to Alias|Wavefront Inc. and are
 * protected by Canadian and US federal copyright laws. They may not be
 * disclosed to third parties or copied or duplicated, in whole or in part,
 * without prior written consent of Alias|Wavefront Inc.
 *
 * Unpublished-rights reserved under the Copyright Laws of the United States.
 *
 * *****************************************************************************
 */

/*
 * captcp.h -	Definitions for handling serial lines for motion
 *		capture servers for Maya
 */

#if !defined(__CAPTCP_H__)
#define __CAPTCP_H__ 1

/*
 * Figure out if we should use prototypes or not
 */

#if defined(PROTOTYPES) || defined(FUNCPROTO) || defined(__STDC__) || defined(__EXTENSIONS__) || defined(__cplusplus)
#define _PROTO(x)	x
#else
#define _PROTO(x)	()
#endif

/*
 * Capture library TCP/IP routines function declarations/prototypes
 */

/*
 * Open a connection to a socket on a host and tcp port.
 */
int CapTcpOpen _PROTO((char *name));

#endif /* __CAPTCP_H__ */
