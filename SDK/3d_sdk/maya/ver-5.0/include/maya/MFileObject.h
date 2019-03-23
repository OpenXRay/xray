
#ifndef _MFileObject
#define _MFileObject
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
// CLASS:    MFileObject
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFileObject)
//
//	The MFileObject class implements an object that contains both a
//	filename and a search path.  The search path is specified by a single
//	string in which multiple elements are separated by ':' characters.  As
//	well this string can contain Unix environment variables, specified as
//	$VARNAME,
//
//	Filenames can be produced by the class by combining the path element
//	with the filename element of the MFileObject.  As well, methods are
//	available to test for the existance of the files produced.
//
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES



#include <maya/MStatus.h>
#include <maya/MTypes.h>

// *****************************************************************************

// DECLARATIONS

class MString;

// *****************************************************************************

// CLASS DECLARATION (MFileObject)

/// Manipulate Unix filenames and search paths
/**
  Manipulate Unix filenames and search paths
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MFileObject  
{
public:
	///
				MFileObject();
	///
				MFileObject( const MFileObject & other );
	///
				virtual ~MFileObject();
	///
	MFileObject& operator=( const MFileObject & other );
	///
	MStatus   	setName( const MString & fileName );
	///
	MStatus   	setRawPath( const MString & pathString );
	///
	MStatus   	setFullName( const MString & fileName );
	///
	MString  	name() const;
	///
	MString  	rawPath() const;
	///
	MString  	path() const;
	///
	MString  	fullName() const;
	///
	unsigned	pathCount();
	///
	MString  	ithPath( unsigned index );
	///
	MString  	ithFullName( unsigned index );
	///
	bool        exists();
	///
	bool        exists( unsigned index );
	///
	bool        isSet() const;

protected:
// No protected members

private:
	void * data;
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MFileObject */
