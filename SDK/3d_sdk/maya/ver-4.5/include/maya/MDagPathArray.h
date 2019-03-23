#ifndef LINUX
#pragma once
#endif
#ifndef _MDagPathArray
#define _MDagPathArray
//
// *****************************************************************************
//
// Copyright (C) 1997-2001 Alias|Wavefront Inc.
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
// CLASS:    MDagPathArray
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MDagPathArray)
//
//	The DAG Path Array Class provides methods for manipulating arrays of DAG
//	Paths.
//
//	Methods are provided for obtaining the DAG Path elements by index, clearing
//	the array, determining the length of the array, and removing, inserting and
//	appending array elements.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MTypes.h>
#include <maya/MStatus.h>

// *****************************************************************************

// DECLARATIONS

class MDagPath;

// *****************************************************************************

// CLASS DECLARATION (MDagPathArray)

///  Indexable Array of DAG Paths
/**

Provides methods for manipulating arrays of DAG Paths.

Arrays of DAG Paths are useful for storing and manipluating multiple Paths
to a particular DAG Node.  The DAG Path method MDagPath::getAllPathsTo()
and DAG Node Function Set method MFnDagNode::getAllPaths() implicitly
return an array of DAG Paths.

These arrays may also be used to manage Paths for a number of different
Nodes.

DAG Path arrays are used in conjunction with DAG Paths (MDagPath) and
individual elements of the arrays can be parameters to some methods of the
DAG Node Function Set (MFnDagNode).

*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MDagPathArray  
{

public:
	///
					MDagPathArray();
	///
					~MDagPathArray();
	///
	const MDagPath&	operator[]( unsigned index ) const;
	///
	MDagPath &		operator[]( unsigned index );
	///
	MStatus			setLength( unsigned length );
	///
	unsigned		length() const;
	///
	MStatus			remove( unsigned index );
	///
	MStatus			insert( const MDagPath & element, unsigned index );
	///
	MStatus			append( const MDagPath & element );
	///
	MStatus			clear();
	///
	friend OPENMAYA_EXPORT ostream &operator<<(ostream &os, 
											   const MDagPathArray &array);

protected:
// No protected members

private:
	///
	void * arr;

	static const char* className();
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MDagPathArray */
