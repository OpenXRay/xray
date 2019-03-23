
#ifndef _MApiVersion
#define _MApiVersion
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

#ifndef MNoVersionString

// Create 2 cpp macros which will allow use to get the value of
// the #define MAYA_API_VERSION into a string and assigned to
// the global variable.
#define _versionString1( _version ) _versionString2(_version)
#define _versionString2( _version ) PLUGIN_EXPORT char MApiVersion[] =  #_version

#ifdef __cplusplus
extern "C" {
#endif

_versionString1(MAYA_API_VERSION);

#ifdef __cplusplus
}
#endif

// Delete the temporary macros
#undef _versionString1
#undef _versionString2

#endif // MNoVersionString

#endif /* _MApiVersion */
