
#ifndef _MTrimBoundaryArray
#define _MTrimBoundaryArray
//
//-
// ==========================================================================
// Copyright (C) Alias Systems Corp., and/or its licensors ("Alias").  
// All rights reserved.  These coded instructions, statements, computer  
// programs, and/or related material (collectively, the "Material")
// contain unpublished information proprietary to Alias, which is
// protected by Canadian and US federal copyright law and by international
// treaties. This Material may not be disclosed to third parties, or be copied
// or duplicated, in whole or in part, without the prior written consent of
// Alias.  ALIAS HEREBY DISCLAIMS ALL WARRANTIES RELATING TO THE MATERIAL,
// INCLUDING, WITHOUT LIMITATION, ANY AND ALL EXPRESS OR IMPLIED WARRANTIES OF
// NON-INFRINGEMENT, MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
// IN NO EVENT SHALL ALIAS BE LIABLE FOR ANY DAMAGES WHATSOEVER, WHETHER DIRECT,
// INDIRECT, SPECIAL, OR PUNITIVE, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE
// OR OTHER TORTIOUS ACTION, OR IN EQUITY, ARISING OUT OF OR RELATED TO THE
// ACCESS TO, USE OF, OR RELIANCE UPON THE MATERIAL.
// ==========================================================================
//+
//
// CLASS:    MTrimBoundaryArray
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MTrimBoundaryArray)
//
//  This class implements an array of MObjects.  Common convenience functions
//  are available, and the implementation is compatible with the internal
//  Maya implementation so that it can be passed efficiently in and out of
//	Maya.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MStatus.h>
#include <vector>

// *****************************************************************************

// DECLARATIONS

// *****************************************************************************

// CLASS DECLARATION (MTrimBoundaryArray)

///  An array class for trim boundaries.  An MTrimBoundaryArray object contains a 
///  collection of edges on a trim boundary.  There can be more than one
///  MObjectArray contained in the MTrimBoundaryArray object.
/**

  Implement an array of MTrimBoundary data type.

  This class owns all of the MObjectArrays used in the class. It doesn't
  hold a reference to any other MObjectArray.

*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class MObjectArray;

class OPENMAYA_EXPORT MTrimBoundaryArray  
{

public:
	///
	MTrimBoundaryArray();
	///
	MTrimBoundaryArray(const MTrimBoundaryArray& other);
	///
	~MTrimBoundaryArray();


	///
	MStatus			reserve(unsigned length);
	///
 	unsigned		length() const;
	///
 	unsigned		size() const;

	///
 	const MObjectArray&	operator[](unsigned index) const;
	///
	const MObjectArray&	get( unsigned index ) const;

	///
 	MStatus	set(const MObjectArray& boundary, unsigned index); 
	///
 	MStatus	insert(const MObjectArray& boundary, unsigned index);
	///
 	MStatus	append(const MObjectArray& boundary);
	///
 	MStatus	remove(unsigned index);
	///
 	MStatus	clear();

	///
	MObject	getMergedBoundary(unsigned index, MStatus *status=NULL) const;

protected:
// No protected members

private:
 	MTrimBoundaryArray& operator = (const MTrimBoundaryArray&) const;
 	MTrimBoundaryArray& operator = (const MTrimBoundaryArray&);

	bool		fIsUVBoundary;
	void*		fBoundaryArray;

	static const char* className();
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MTrimBoundaryArray */
