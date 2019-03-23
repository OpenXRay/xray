#ifndef _MIOStream
#define _MIOStream
//
// *****************************************************************************
//
// Copyright (C) 1997-2003 Alias|Wavefront Inc.
//
// These coded instructions, statements and computer programs contain
// unpublished information proprietary to Alias|Wavefront Inc. and are 
// protected by Canadian and US federal copyright laws. They may not be 
// disclosed to third parties or copied or duplicated, in whole or in part, 
// without prior written consent of Alias|Wavefront Inc.
//
// Unpublished-rights reserved under the Copyright Laws of the United States.
//
// *****************************************************************************
//
// CLASS:    MIOStream
//
// *****************************************************************************

///
/**
	The MIOStream.h header file was created to centralize the including of the
	iostream header.  If developing on Linux, you can define REQUIRE_IOSTREAM to
	allow "iostream" to be included rather than "iostream.h".  
	This option is provided as a convenience for external developers.  We
	do not use this define and as a result it cannot be applied to
	our supplied examples.
*/

#if defined(REQUIRE_IOSTREAM)
	// Linux only
	#include <iostream>
	#define IOS_REF(iosref) std::iosref
#else
	#include <iostream.h>
	#define IOS_REF(iosref) iosref
#endif

#endif // _MIOStream
