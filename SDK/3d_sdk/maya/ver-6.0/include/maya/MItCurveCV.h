
#ifndef _MItCurveCV
#define _MItCurveCV
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
// CLASS:    MItCurveCV
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MItCurveCV)
//
//	This class is the iterator class for NURBS curve control vertices (CVs).
//	The iteration can be for a given curve or for a group of CVs.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MFnDagNode.h>
#include <maya/MObject.h>

// *****************************************************************************

// DECLARATIONS

class MPointArray;
class MDoubleArray;
class MVector;
class MPoint;
class MDagPath;
class MPtrBase;

// *****************************************************************************

// CLASS DECLARATION (MItCurveCV)

/// Iterator for NURBS curve CVs
/**
  Iterate over CVs of a NURBS curve.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MItCurveCV
{
public:
	///
    MItCurveCV( MObject & curve, MStatus * ReturnStatus = NULL );
    ///
    MItCurveCV( const MDagPath & curve,
				MObject & component = MObject::kNullObj,
                MStatus * ReturnStatus = NULL );
    ///
    virtual ~MItCurveCV();
    ///
    bool        isDone( MStatus * ReturnStatus = NULL ) const;
    ///
    MStatus     next();
    ///
    MStatus     reset();
    ///
    MStatus     reset( MObject & curve );
    ///
    MStatus     reset( const MDagPath & curve,
						MObject & component = MObject::kNullObj );
    ///
    MPoint      position( MSpace::Space space = MSpace::kObject,
                          MStatus * ReturnStatus = NULL ) const;
    ///
    MStatus     setPosition( const MPoint & pt,
							 MSpace::Space space = MSpace::kObject );
    ///
    MStatus     translateBy( const MVector & vec,
							 MSpace::Space space = MSpace::kObject );
    ///
    int	    index( MStatus * ReturnStatus = NULL ) const;
	///
	MObject		cv( MStatus * ReturnStatus = NULL ) const;

    ///
	bool        hasHistoryOnCreate( MStatus * ReturnStatus = NULL ) const;
    ///
    MStatus     updateCurve();

protected:
// No protected members

private:
    static const char* className();
	inline void * updateGeomPtr() const;
    MPtrBase * f_shape;
    MPtrBase * f_geom;
    void *     f_path;
	void *     f_it;
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MItCurveCV */
