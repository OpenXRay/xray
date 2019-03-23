#ifndef LINUX
#pragma once
#endif
#ifndef _MPointArray
#define _MPointArray
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
// CLASS:    MPointArray
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MPointArray)
//
//	This class implements an array of MPoints.  Common convenience functions
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
#include <maya/MPoint.h>

// *****************************************************************************

// DECLARATIONS


// *****************************************************************************

// CLASS DECLARATION (MPointArray)

/// Array of MPoint data type
/**
  Implement an array of MPoint data type.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MPointArray  
{
public:
	///
					MPointArray();
	///
					MPointArray( const MPointArray& other );
	///
					MPointArray( const MPoint points[], unsigned count );
	///
					MPointArray( const double points[][4], unsigned count );
	///
					MPointArray( const float points[][4], unsigned count );
	///
					MPointArray( unsigned initialSize, 
								 const MPoint &initialValue 
								 = MPoint::origin );
	///
					~MPointArray();
	///
	const MPoint&	operator[]( unsigned index ) const;
	///
	MPoint&	        operator[]( unsigned index );
 	///
 	MPointArray &   operator=( const MPointArray & other );
	///
	MStatus			set( const MPoint& element, unsigned index);
	///
	MStatus 		set( unsigned index, double x, double y, double z=0, 
						 double w=1);
	///
	MStatus			set( double element[4], unsigned index);
	///
	MStatus			set( float element[4], unsigned index);
	///
	MStatus			setLength( unsigned length );
	///
	unsigned		length() const;
	///
	MStatus			remove( unsigned index );
	///
	MStatus			insert( const MPoint & element, unsigned index );
	///
	MStatus			append( const MPoint & element );
	///
	MStatus 		append( double x, double y, double z=0, double w=1 );
 	///
 	MStatus         copy( const MPointArray& source );
	///
	MStatus			clear();
	///
	MStatus			get( double [][4] ) const;
	///
	MStatus			get( float [][4] ) const;
	///
	void			setSizeIncrement ( unsigned newIncrement );
	///
	unsigned		sizeIncrement () const;
	///
	friend OPENMAYA_EXPORT ostream &operator<<(ostream &os, 
											   const MPointArray &array);

protected:
// No protected members

private:


	MPointArray( void* );
	void * arr;
	bool   own;
	static const char* className();
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MPointArray */
