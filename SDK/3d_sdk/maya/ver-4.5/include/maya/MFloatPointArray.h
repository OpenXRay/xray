#ifndef LINUX
#pragma once
#endif
#ifndef _MFloatPointArray
#define _MFloatPointArray
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
// CLASS:    MFloatPointArray
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFloatPointArray)
//
//	This class implements an array of MFloatPoints.  Common convenience
//  functions are available, and the implementation is compatible with the
//  internal Maya implementation so that it can be passed efficiently between
//  plugins and internal maya data structures.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MTypes.h>
#include <maya/MStatus.h>
#include <maya/MFloatPoint.h>

// *****************************************************************************

// DECLARATIONS


// *****************************************************************************

// CLASS DECLARATION (MFloatPointArray)

/// Array of MFloatPoint data type
/**
  Implement an array of MFloatPoint data type.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MFloatPointArray  
{
public:
	///
	MFloatPointArray();
	///
	MFloatPointArray( const MFloatPointArray& other );
	///
	MFloatPointArray( const MFloatPoint points[], unsigned count );
	///
	MFloatPointArray( const float points[][4], unsigned count );
	///
	MFloatPointArray( const double points[][4], unsigned count );
	///
	MFloatPointArray( unsigned initialSize, 
					  const MFloatPoint &initialValue 
					  = MFloatPoint::origin );
	///
	~MFloatPointArray();

	///
	const MFloatPoint&	operator[]( unsigned index ) const;
	///
	MFloatPoint&	    operator[]( unsigned index );
 	///
 	MFloatPointArray &  operator=( const MFloatPointArray & other );
	///
	MStatus			set( const MFloatPoint& element, unsigned index);
	///
	MStatus 		set( unsigned index, float x, float y, float z=0, 
						 float w=1);
	///
	MStatus			set( float element[4], unsigned index);
	///
	MStatus			set( double element[4], unsigned index);
	///
	MStatus			setLength( unsigned length );
	///
	unsigned		length() const;
	///
	MStatus			remove( unsigned index );
	///
	MStatus			insert( const MFloatPoint & element, unsigned index );
	///
	MStatus			append( const MFloatPoint & element );
	///
	MStatus 		append( float x, float y, float z=0, float w=1 );
 	///
 	MStatus         copy( const MFloatPointArray& source );
	///
	MStatus			clear();
	///
	MStatus			get( float [][4] ) const;
	///
	MStatus			get( double [][4] ) const;
	///
	void			setSizeIncrement ( unsigned newIncrement );
	///
	unsigned		sizeIncrement () const;
	///
	friend OPENMAYA_EXPORT ostream &operator<<(ostream &os, 
											   const MFloatPointArray &array);

protected:
// No protected members

private:


	MFloatPointArray( void* );
	void * arr;
	bool   own;
	static const char* className();
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MFloatPointArray */
