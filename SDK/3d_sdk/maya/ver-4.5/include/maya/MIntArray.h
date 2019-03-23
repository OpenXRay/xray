#ifndef LINUX
#pragma once
#endif
#ifndef _MIntArray
#define _MIntArray
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
// CLASS:    MIntArray
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MIntArray)
//
//	This class implements an array of integers.  Common convenience functions
//	are available, and the implementation is compatible with the internal
//	Maya implementation so that it can be passed efficiently between plugins
//	and internal maya data structures.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MTypes.h>
#include <maya/MStatus.h>

// *****************************************************************************

// DECLARATIONS

// *****************************************************************************

// CLASS DECLARATION (MIntArray)

/// Array of integers data type
/**
  Implement an array of integers data type.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MIntArray  
{

public:
 	///
					MIntArray();
 	///
					MIntArray( const MIntArray& other );
 	///
					MIntArray( const int src[], unsigned count );
	///
					MIntArray( unsigned initialSize, 
							   int initialValue = 0 );
	///
					~MIntArray();
	///
 	int				operator[]( unsigned index ) const;
 	///
 	int&	 		operator[]( unsigned index );
 	///
 	MIntArray &     operator=( const MIntArray & other );
	///
	MStatus			set( int element, unsigned index );
 	///
	MStatus			setLength( unsigned length );
	///
 	unsigned        length() const;
 	///
 	MStatus			remove( unsigned index );
 	///
 	MStatus			insert( int element, unsigned index );
 	///
 	MStatus			append( int element );
 	///
 	MStatus         copy( const MIntArray& source );
 	///
 	MStatus		 	clear();
	///
	MStatus			get( int[] ) const;
	///
	void			setSizeIncrement ( unsigned newIncrement );
	///
	unsigned		sizeIncrement () const;
	///
	friend OPENMAYA_EXPORT ostream &operator<<(ostream &os, 
											   const MIntArray &array);

protected:
// No protected members

private:
	MIntArray( void* );

 	void* fArray;
	bool   own;
	static const char* className();
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MIntArray */
