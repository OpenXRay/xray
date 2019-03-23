#ifndef _MFloatMatrix
#define _MFloatMatrix
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
// CLASS:    MFloatMatrix
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFloatMatrix)
//
//  This class provides access to Maya's internal matrix math library allowing
//  matrices to be handled easily, and in a manner compatible with internal
//  Maya data structures.
//
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES



#include <maya/MStatus.h>
#include <maya/MTypes.h>

// *****************************************************************************

// DECLARATIONS

#define MFloatMatrix_kTol	1.0e-5F

// *****************************************************************************

// CLASS DECLARATION (MFloatMatrix)

/// A matrix math class for 4x4 matrices of floats
/**
  This class provides access to Maya's matrix math library
*/
#if defined(_WIN32)
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MFloatMatrix  
{

public:
	///
						MFloatMatrix();
	///
						MFloatMatrix( const MFloatMatrix & src );
	///
						MFloatMatrix( const double m[4][4] );
	///
						MFloatMatrix( const float m[4][4] );
	///
						~MFloatMatrix();
	///
 	MFloatMatrix&		operator = (const MFloatMatrix &);
	///
	float&				operator()(unsigned row, unsigned col );
	///
	float				operator()(unsigned row, unsigned col ) const;
	///
	float* 		    	operator[]( unsigned row );
	///
	const float* 		operator[]( unsigned row ) const;
	///
	MStatus				get( double dest[4][4] ) const;
	///
	MStatus				get( float dest[4][4] ) const;
	///
 	MFloatMatrix     	transpose() const;
	///
 	MFloatMatrix &   	setToIdentity();
	///
 	MFloatMatrix &   	setToProduct( const MFloatMatrix & left,
									  const MFloatMatrix & right );
	///
 	MFloatMatrix &   	operator+=( const MFloatMatrix & right );
	///
 	MFloatMatrix    	operator+ ( const MFloatMatrix & right ) const;
	///
 	MFloatMatrix &   	operator-=( const MFloatMatrix & right );
	///
 	MFloatMatrix  		operator- ( const MFloatMatrix & right ) const;
	///
 	MFloatMatrix &   	operator*=( const MFloatMatrix & right );
	///
 	MFloatMatrix     	operator* ( const MFloatMatrix & right ) const;
	///
 	MFloatMatrix &   	operator*=( float );
	///
 	MFloatMatrix     	operator* ( float ) const;
	///
 	friend OPENMAYA_EXPORT MFloatMatrix	operator* ( float,
												const MFloatMatrix & right );
	///
 	bool          		operator==( const MFloatMatrix & other ) const;
	///
 	bool           		operator!=( const MFloatMatrix & other ) const;
	///
 	MFloatMatrix     	inverse() const;
	///
 	MFloatMatrix     	adjoint() const;
	///
 	MFloatMatrix     	homogenize() const;
	///
 	float       		det4x4() const;
	///
 	float         		det3x3() const;
	///
 	bool           		isEquivalent( const MFloatMatrix & other,
									  float tolerance = MFloatMatrix_kTol )
 									  const;

	///
	friend OPENMAYA_EXPORT IOS_REF(ostream)& operator<< ( IOS_REF(ostream)& os,
												const MFloatMatrix& m );

	/// the matrix data
 	float matrix[4][4];

protected:
// No protected members

private:
	static const char* className();
};

#if defined(_WIN32)
#pragma warning(default: 4522)
#endif // _WIN32

inline float& MFloatMatrix::operator()(unsigned row, unsigned col )
{
	return matrix[row][col];
}

inline float MFloatMatrix::operator()(unsigned row, unsigned col ) const
{
	return matrix[row][col];
}

inline float* MFloatMatrix::operator[]( unsigned row )
{
	return matrix[row];
}

inline const float* MFloatMatrix::operator[]( unsigned row ) const
{
	return matrix[row];
}

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MFloatMatrix */
