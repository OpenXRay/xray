#ifndef _MTimeArray
#define _MTimeArray
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
// CLASS:    MTimeArray
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MTimeArray)
//
//  This class implements an array of MTimes.  Common convenience functions
//  are available, and the implementation is compatible with the internal
//  Maya implementation so that it can be passed efficiently between plugins
//  and internal maya data structures.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MTime.h>
#include <maya/MStatus.h>

// *****************************************************************************

// DECLARATIONS

// *****************************************************************************

// CLASS DECLARATION (MTimeArray)

///  Array of MTime data type
/**
  Implement an array of MTime data type.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MTimeArray  
{

public:
    ///
					MTimeArray();
    ///
					MTimeArray( const MTimeArray& other );
    ///
					MTimeArray( const MTime src[], unsigned count );
	///
					MTimeArray( unsigned initialSize, 
								const MTime &initialValue );
    ///
					~MTimeArray();
    ///
 	const MTime&	operator[]( unsigned index ) const;
    ///
 	MTime&			operator[]( unsigned index ); 
    ///
 	MStatus			set( const MTime& element, unsigned index ); 
    ///
	MStatus			setLength( unsigned length );
	///
 	unsigned		length() const;
    ///
 	MStatus			remove( unsigned index );
    ///
 	MStatus			insert( const MTime & element, unsigned index );
    ///
 	MStatus			append( const MTime & element );
    ///
 	MStatus			clear();
    ///
	MStatus			get( MTime array[] ) const;
	///
	void			setSizeIncrement ( unsigned newIncrement );
	///
	unsigned		sizeIncrement () const;
	///
	friend OPENMAYA_EXPORT IOS_REF(ostream) &operator<<(IOS_REF(ostream) &os, 
											   const MTimeArray &array);

protected:
// No protected members

private:
 	MTimeArray& operator = (const MTimeArray&) const;
 	MTimeArray& operator = (const MTimeArray&);
 	void* fArray;
	static const char* className();
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32


// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MTimeArray */
