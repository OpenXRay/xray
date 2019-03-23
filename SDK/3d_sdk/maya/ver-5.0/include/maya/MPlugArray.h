
#ifndef _MPlugArray
#define _MPlugArray
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
// CLASS:    MPlugArray
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MPlugArray)
//
// This class implements an array of MPlugs.  Common convenience functions
// are available, and the implementation is compatible with the internal
// Maya implementation so that it can be passed efficiently between plugins
// and internal maya data structures.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES



#include <maya/MTypes.h>
#include <maya/MStatus.h>

// *****************************************************************************

// DECLARATIONS

class MPlug;

// *****************************************************************************

// CLASS DECLARATION (MPlugArray)

/// Array of MPlugs data type
/**
  Implement an array of MPlugs data type.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MPlugArray  
{

public: 
	///
					MPlugArray();
	///
					MPlugArray( const MPlugArray& other );
	///
					MPlugArray( const MPlug src[], unsigned count );
	///
					~MPlugArray();
	///
	MPlug			operator[]( unsigned index ) const;
	///
	MPlug			operator[]( unsigned index );
	///
	MPlugArray&		operator=( const MPlugArray & other );
	///
	MStatus			set( const MPlug& element, unsigned index );
	///
	MStatus			setLength( unsigned length );
	///
	unsigned		length() const;
	///
	MStatus			remove( unsigned index );
	///
	MStatus			insert( const MPlug & element, unsigned index );
	///
	MStatus			append( const MPlug & element );
	///
	MStatus			clear();
	///
	MStatus			get( MPlug dest[] ) const;
	///
	void			setSizeIncrement ( unsigned newIncrement );
	///
	unsigned		sizeIncrement () const;

protected:
// No protected members

private:
	MPlugArray ( void * );
	friend class MPlug;
	void * arr;
	bool   own;
	static const char* className();
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MPlugArray */
