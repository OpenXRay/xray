#ifndef LINUX
#pragma once
#endif
#ifndef _MDoubleArray
#define _MDoubleArray
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
// CLASS:    MDoubleArray
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MDoubleArray)
//
//  This class implements an array of doubles.  Common convenience functions
//  are available, and the implementation is compatible with the internal
//  Maya implementation so that it can be passed efficiently between plugins
//  and internal maya data structures.
//
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

// CLASS DECLARATION (MDoubleArray)

/// Array of doubles data type
/**
  Implement an array of doubles data type.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MDoubleArray  
{
public:
 	///
					MDoubleArray();
 	///
					MDoubleArray( const MDoubleArray& other );
 	///
					MDoubleArray( const double src[], unsigned count );
 	///
					MDoubleArray( const float src[], unsigned count );
	///
					MDoubleArray( unsigned initialSize, 
								  double initialValue = 0 );
	///
					~MDoubleArray();
	///
 	double			operator[]( unsigned index ) const;
 	///
 	double &	 	operator[]( unsigned index );
 	///
 	MDoubleArray &  operator=( const MDoubleArray & other );
	///
	MStatus			set( double element, unsigned index );
	///
	MStatus			set( float element, unsigned index );
 	///
	MStatus			setLength( unsigned length );
	///
 	unsigned        length() const;
 	///
 	MStatus         remove( unsigned index );
 	///
 	MStatus         insert( double element, unsigned index );
 	///
 	MStatus         append( double element );
 	///
 	MStatus         copy( const MDoubleArray& source );
 	///
 	MStatus		 	clear();
	///
	MStatus			get( double[] ) const;
	///
	MStatus			get( float[] ) const;
	///
	void			setSizeIncrement ( unsigned newIncrement );
	///
	unsigned		sizeIncrement () const;
	///
	friend OPENMAYA_EXPORT ostream &operator<<(ostream &os, 
											   const MDoubleArray &array);

protected:
// No protected members

private:
	MDoubleArray( void* );

 	void * arr;
	bool   own;
	static const char* className();
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MDoubleArray */
