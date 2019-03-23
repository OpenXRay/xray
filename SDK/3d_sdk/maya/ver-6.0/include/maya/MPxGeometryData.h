
#ifndef _MPxGeometryData
#define _MPxGeometryData
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
// CLASS:    MPxGeometryData
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MPxGeometryData)
//
// This class is used to provide a wrapper or container for some arbitrary
// geometry type that you have defined. This allows your data type to exist as
// typed attributes on dependency nodes and to be passed through dependency
// graph connections.
// 
// MPxGeometryData is similar to MPxData but includes methods to support sets
// (also known as groups) and component iteration.
// 
// For user defined shapes (MPxSurfaceShape derived classes), in order to
// support maya's deformers you must declare an MPxGeometryData class as well
// as a geometry iterator (MPxGeometryIterator).
// 
// To register geometry data use MFnPlugin::registerData with the type argument
// equal to MPxData::kGeometryData.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES



#include <maya/MPxData.h>
#include <maya/MMatrix.h>

// *****************************************************************************

// DECLARATIONS

class MPxGeometryIterator;
class MObjectArray;
class MIntArray;

// *****************************************************************************

// CLASS DECLARATION (MPxGeometryData)

///  Base Class for User-defined Dependency Graph Geometry Data Types
/**

*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MPxGeometryData : public MPxData
{
public:
	///
	MPxGeometryData();
	///
	virtual ~MPxGeometryData();

	// Methods to provide a component iterator for the geometry
	//
	///
	virtual MPxGeometryIterator* iterator( MObjectArray & componentList,
											MObject & component,
											bool useComponents);

	///
	virtual MPxGeometryIterator* iterator( MObjectArray & componentList,
											MObject & component,
											bool useComponents,
											bool world) const;

	///
	virtual bool	updateCompleteVertexGroup( MObject & component ) const;

	///
	virtual bool	deleteComponent( const MObjectArray& compList );
	///
	virtual bool	deleteComponentsFromGroups( const MObjectArray& compList,
												MIntArray& groupIdArray,
												MObjectArray& groupComponentArray );

	///
	virtual void	smartCopy( const MPxGeometryData *srcGeom );
	///
	virtual	void			copy( const MPxData& src ) = 0;

	///
	virtual MTypeId         typeId() const = 0;
	///
	virtual MString         name() const = 0;

	///
	void			setMatrix(const MMatrix &);
	///
	const MMatrix		&matrix() const;
	///
	bool			matrix(MMatrix &) const;

protected:
// No protected members

private:
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MPxGeometryData */
