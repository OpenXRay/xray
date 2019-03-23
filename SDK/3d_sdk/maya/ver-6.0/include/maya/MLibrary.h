
#ifndef _MLibrary
#define _MLibrary
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
// CLASS:    MLibrary
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MLibrary)
//
//	When creating a "library mode" Maya application, this class must be
//	used in the program's main routine to initialize Maya, and later
//	to cleanUp allocated Maya state.  A typical usage would be:
//     main(int argc, char **argv)
//     {
//         MStatus status;
//         status = MLibrary::initialize (argv[0], true);
//         if ( !status ) {
//             status.perror("MLibrary::initialize");
//             return (1);
//         }
// 
//         // Maya API code goes here
// 
//         MLibrary::cleanup();
//         return (0);
//     }
//
//  If the call to cleanup is omitted, you will get errors when the program
//  exits, as static destructors in the Maya libraries are run.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES



#include <maya/MStatus.h>
#include <maya/MTypes.h>

// *****************************************************************************

// DECLARATIONS

// *****************************************************************************

// CLASS DECLARATION (MLibrary)

/// Set up Maya to run in library mode.
/**
 Initialize and cleanup routines for Maya running in library mode.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MLibrary  
{
public:
	///
						MLibrary ();
	///
	virtual				~MLibrary ();
	///
	static MStatus		initialize (char* applicationName,
									bool viewLicense = false);
	///
	static MStatus		initialize (bool wantScriptOutput,
									char* applicationName,
									bool viewLicense = false);
	///
	static void			cleanup( int exitStatus = 0 );

protected:
// No protected members

private:
// No private members

};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MLibrary */
