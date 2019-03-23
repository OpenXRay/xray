
#ifndef _MApiVersion
#define _MApiVersion
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
