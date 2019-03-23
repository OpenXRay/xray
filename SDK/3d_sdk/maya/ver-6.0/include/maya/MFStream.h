#ifndef _MFStream
#define _MFStream
//
//-
// ==========================================================================
// Copyright (C) Alias Systems Corp., and/or its licensors ("Alias").  
// All rights reserved.  These coded instructions, statements, computer  
// programs, and/or related material (collectively, the "Material")
// contain unpublished information proprietary to Alias, which is
// protected by Canadian and US federal copyright law and by international
// treaties. This Material may not be disclosed to third parties, or be copied
// or duplicated, in whole or in part, without the prior written consent of
// Alias.  ALIAS HEREBY DISCLAIMS ALL WARRANTIES RELATING TO THE MATERIAL,
// INCLUDING, WITHOUT LIMITATION, ANY AND ALL EXPRESS OR IMPLIED WARRANTIES OF
// NON-INFRINGEMENT, MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
// IN NO EVENT SHALL ALIAS BE LIABLE FOR ANY DAMAGES WHATSOEVER, WHETHER DIRECT,
// INDIRECT, SPECIAL, OR PUNITIVE, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE
// OR OTHER TORTIOUS ACTION, OR IN EQUITY, ARISING OUT OF OR RELATED TO THE
// ACCESS TO, USE OF, OR RELIANCE UPON THE MATERIAL.
// ==========================================================================
//+
//
// CLASS:    MFStream
//
// *****************************************************************************

///
/**
	The MFStream.h header file was created to centralize the including of the
	fstream header.  You can define REQUIRE_IOSTREAM to
	allow "iostream" to be included rather than "iostream.h".  
	This option is provided as a convenience for external developers.
*/

#if defined(REQUIRE_IOSTREAM) || defined (AW_NEW_IOSTREAMS) || (_MSC_VER >= 1300)
	#include <fstream>
	using std::endl;
	using std::streambuf;
	using std::filebuf;
	using std::ifstream;
	using std::ofstream;
	using std::fstream;

#else
	#include <fstream.h>

#endif

#endif // _MFStream
