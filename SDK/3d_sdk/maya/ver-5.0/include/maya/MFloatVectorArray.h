#ifndef _MFloatVectorArray
#define _MFloatVectorArray
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
// CLASS:    MFloatVectorArray
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFloatVectorArray)
//
//  This class implements an array of MFloatVectors.  Common convenience
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

// *****************************************************************************

// DECLARATIONS

#include <maya/MFloatVector.h>

// *****************************************************************************

// CLASS DECLARATION (MFloatVectorArray)

/// Array of MFloatVectors data type
/**
  Implement an array of MFloatVectors data type.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MFloatVectorArray  
{

public:
	///
	MFloatVectorArray();
	///
	MFloatVectorArray( const MFloatVectorArray& other );
	///
	MFloatVectorArray( const MFloatVector vectors[], unsigned count );
	///
	MFloatVectorArray( const double vectors[][3], unsigned count );
	///
	MFloatVectorArray( const float vectors[][3], unsigned count );
	///
	MFloatVectorArray( unsigned initialSize, 
					   const MFloatVector &initialValue 
					   = MFloatVector::zero );
	///
	~MFloatVectorArray();

	///
 	const MFloatVector&	operator[]( unsigned index ) const;
	///
 	MFloatVector &		operator[]( unsigned index );
 	///
 	MFloatVectorArray &  operator=( const MFloatVectorArray & other );
	///
	bool			set( const MFloatVector& element, unsigned index );
	///
	bool			set( double element[3], unsigned index );
	///
	bool			set( float element[3], unsigned index );
	///
	MStatus			setLength( unsigned length );
	///
	unsigned		length() const;
	///
	bool			remove( unsigned index );
	///
	bool			insert( const MFloatVector & element, unsigned index );
	///
	bool			append( const MFloatVector & element );
 	///
 	MStatus         copy( const MFloatVectorArray& source );
	///
	bool			clear();
	///
	bool			get( double [][3] ) const;
	///
	bool			get( float [][3] ) const;
	///
	void			setSizeIncrement ( unsigned newIncrement );
	///
	unsigned		sizeIncrement () const;
	///
	friend OPENMAYA_EXPORT IOS_REF(ostream) &operator<<(IOS_REF(ostream) &os, 
											   const MFloatVectorArray &array);

protected:
// No protected members

private:
	MFloatVectorArray( void* );
	void * arr;
	bool   own;
	static const char* className();
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MFloatVectorArray */
