
#ifndef _MItSurfaceCV
#define _MItSurfaceCV
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
// CLASS:    MItSurfaceCV
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MItSurfaceCV)
//
// Iterator class for NURBS surface CVs.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MFnDagNode.h>
#include <maya/MObject.h>
#include <maya/MPoint.h>
#include <maya/MVector.h>

// *****************************************************************************

// DECLARATIONS

class MPointArray;
class MDoubleArray;
class MPoint;
class MVector;
class MDagPath;
class MPtrBase;

// *****************************************************************************

// CLASS DECLARATION (MItSurfaceCV)

/// NURBS surface CV iterator
/**
  Iterate over CVs in a NURBS surface.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MItSurfaceCV
{
public:   
	///
	MItSurfaceCV( MObject & surface, bool useURows = true, 
				  MStatus * ReturnStatus = NULL );
	///
	MItSurfaceCV( const MDagPath & surface,
				  MObject & component = MObject::kNullObj,
				  bool useURows = true, 
				  MStatus * ReturnStatus = NULL );
	///
	virtual ~MItSurfaceCV();
	///
	bool     isDone( MStatus * ReturnStatus = NULL ) const;
	///
	bool     isRowDone( MStatus * ReturnStatus = NULL ) const;
	///
	MStatus  next(); 
	///
	MStatus  nextRow();
	///
	MStatus  reset();
	///
	MStatus  reset( MObject & surface, bool useURows = true );
	///
	MStatus  reset( const MDagPath & surface, MObject & component,
					bool useURows = true );
	///
	MPoint   position( MSpace::Space space = MSpace::kObject, 
					      MStatus * ReturnStatus = NULL ) const;
	///
	MStatus  setPosition( const MPoint & point, 
						  MSpace::Space space = MSpace::kObject );
	///
	MStatus  translateBy( const MVector & vector, 
						  MSpace::Space space = MSpace::kObject );
	///
	int     index(	MStatus * ReturnStatus = NULL ) const;
	///
	MStatus  getIndex( int& indexU, int& indexV ) const;
	///
	MObject  cv( MStatus * ReturnStatus = NULL ) const;

    ///
	bool     hasHistoryOnCreate( MStatus * ReturnStatus = NULL ) const;
	///
	MStatus  updateSurface();


protected:
// No protected members

private:
	static const char* 	className();
	inline void * updateGeomPtr() const;
	MPtrBase *		f_shape;
	MPtrBase *		f_geom;
	void *			f_path;
	unsigned		f_uindex;	
	unsigned		f_vindex;
	bool			f_in_u;
	void *			f_it;
}; 

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MItSurfaceCV */
