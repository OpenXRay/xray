#ifndef _MUint64Array
#define _MUint64Array
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
// CLASS:    MUint64Array
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MUint64Array)
//
//  This class implements an array of unsigned 64 bit integers.
//  Common convenience functions
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

// CLASS DECLARATION (MUint64Array)

/// Array of MUint64 data type
/**
  Implement an array of MUint64 data type.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MUint64Array  
{
public:
 	///
					MUint64Array();
 	///
					MUint64Array( const MUint64Array& other );
 	///
					MUint64Array( const MUint64 src[], unsigned count );
 	///
					MUint64Array( unsigned initialSize, 
								  MUint64 initialValue = 0 );
	///
					~MUint64Array();
	///
 	MUint64			operator[]( unsigned index ) const;
 	///
 	MUint64 &	 	operator[]( unsigned index );
 	///
 	MUint64Array &  operator=( const MUint64Array & other );
	///
	MStatus			set( MUint64 element, unsigned index );
	///
	MStatus			setLength( unsigned length );
	///
 	unsigned        length() const;
 	///
 	MStatus         remove( unsigned index );
 	///
 	MStatus         insert( MUint64 element, unsigned index );
 	///
 	MStatus         append( MUint64 element );
 	///
 	MStatus         copy( const MUint64Array& source );
 	///
 	MStatus		 	clear();
	///
	MStatus			get( MUint64[] ) const;
	///
	void			setSizeIncrement ( unsigned newIncrement );
	///
	unsigned		sizeIncrement () const;
	///
	friend OPENMAYA_EXPORT IOS_REF(ostream) &operator<<(IOS_REF(ostream) &os, 
											   const MUint64Array &array);

protected:
// No protected members

private:
	MUint64Array( void* );
 	void * fArray;
	bool   fOwn;
	static const char* className();
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MUint64Array */
