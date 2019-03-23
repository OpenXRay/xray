#ifndef LINUX
#pragma once
#endif
#ifndef _MColorArray
#define _MColorArray
//
// *****************************************************************************
//
// Copyright (C) 1999-2001 Alias|Wavefront Inc.
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
// CLASS:    MColorArray
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MColorArray)
//
//	This class implements an array of MColor's.  Common convenience functions
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
#include <maya/MColor.h>

// *****************************************************************************

// DECLARATIONS


// *****************************************************************************

// CLASS DECLARATION (MColorArray)

/// Array of MColor data type
/**
  Implement an array of MColor data type.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MColorArray  
{
public:
	///
					MColorArray();
	///
					MColorArray( const MColorArray& other );
	///
					MColorArray( const MColor colors[], unsigned count );
	///
					MColorArray( const float colors[][4], unsigned count );
	///
					MColorArray( const double colors[][4], unsigned count );
	///
					MColorArray( unsigned initialSize, 
								 const MColor &initialValue );
	///
					~MColorArray();
	///
	const MColor&	operator[]( unsigned index ) const;
	///
	MColor&	        operator[]( unsigned index );
 	///
 	MColorArray &   operator=( const MColorArray & other );
	///
	MStatus			set( const MColor& element, unsigned index );
	///
	MStatus 		set( unsigned index, float r, float g, float b, float a=1 );
	///
	MStatus			set( float element[4], unsigned index);
	///
	MStatus			setLength( unsigned length );
	///
	unsigned		length() const;
	///
	MStatus			remove( unsigned index );
	///
	MStatus			insert( const MColor & element, unsigned index );
	///
	MStatus			append( const MColor & element );
	///
	MStatus 		append( float r, float g, float b, float a=1 );
	///
	MStatus			clear();
	///
	MStatus			get( float [][4] ) const;
	///
	void			setSizeIncrement ( unsigned newIncrement );
	///
	unsigned		sizeIncrement () const;
	///
	friend OPENMAYA_EXPORT ostream &operator<<(ostream &os, 
											   const MColorArray &array);

protected:
// No protected members

private:


	MColorArray( void* );
	void * arr;
	bool   own;
	static const char* className();
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MColorArray */
