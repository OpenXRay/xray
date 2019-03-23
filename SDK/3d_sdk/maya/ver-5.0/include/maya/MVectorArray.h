#ifndef _MVectorArray
#define _MVectorArray
//
//-
// ==========================================================================
// Copyright  (C)  Alias|Wavefront,  a division of Silicon Graphics  Limited.
// All rights  reserved.  These coded  instructions,  statements and computer
// programs contain unpublished information  proprietary to  Alias|Wavefront,
// a  division  of  Silicon  Graphics  Limited,  which  is  protected by  the
// Canadian  and  US federal copyright law and  may not be disclosed to third
// parties or  copied  or  duplicated,  in  whole  or in part,  without prior
// written consent of Alias|Wavefront, a division of Silicon Graphics Limited
// ==========================================================================
//+
//
// CLASS:    MVectorArray
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MVectorArray)
//
//  This class implements an array of integers.  Common convenience functions
//  are available, and the implementation is compatible with the internal
//  Maya implementation so that it can be passed efficiently between plugins
//  and internal maya data structures.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES



#include <maya/MTypes.h>
#include <maya/MStatus.h>

// *****************************************************************************

// DECLARATIONS

#include <maya/MVector.h>
#include <maya/MStatus.h>

// *****************************************************************************

// CLASS DECLARATION (MVectorArray)

/// Array of MVectors data type
/**
  Implement an array of MVectors data type.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MVectorArray  
{

public:
	///
					MVectorArray();
	///
					MVectorArray( const MVectorArray& other );
	///
					MVectorArray( const MVector vectors[], unsigned count );
	///
					MVectorArray( const double vectors[][3], unsigned count );
	///
					MVectorArray( const float vectors[][3], unsigned count );
	///
					MVectorArray( unsigned initialSize, 
								  const MVector &initialValue 
								  = MVector::zero );
	///
					~MVectorArray();
	///
 	const MVector&	operator[]( unsigned index ) const;
	///
 	MVector &		operator[]( unsigned index );
 	///
 	MVectorArray &  operator=( const MVectorArray & other );
	///
	MStatus			set( const MVector& element, unsigned index );
	///
	MStatus			set( double element[3], unsigned index );
	///
	MStatus			set( float element[3], unsigned index );
	///
	MStatus			setLength( unsigned length );
	///
	unsigned		length() const;
	///
	MStatus			remove( unsigned index );
	///
	MStatus			insert( const MVector & element, unsigned index );
	///
	MStatus			append( const MVector & element );
 	///
 	MStatus         copy( const MVectorArray& source );
	///
	MStatus			clear();
	///
	MStatus			get( double [][3] ) const;
	///
	MStatus			get( float [][3] ) const;
	///
	void			setSizeIncrement ( unsigned newIncrement );
	///
	unsigned		sizeIncrement () const;
	///
	friend OPENMAYA_EXPORT IOS_REF(ostream) &operator<<(IOS_REF(ostream) &os, 
											   const MVectorArray &array);

protected:
// No protected members

private:
	MVectorArray( void* );
	void * arr;
	bool   own;
	static const char* className();
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MVectorArray */
