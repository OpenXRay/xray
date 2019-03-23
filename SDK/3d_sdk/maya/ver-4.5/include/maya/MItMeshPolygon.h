#ifndef LINUX
#pragma once
#endif
#ifndef _MItMeshPolygon
#define _MItMeshPolygon
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
// CLASS:    MItMeshPolygon
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MItMeshPolygon)
//
//	This class is the iterator for polygonal surfaces.
//
//	The iterator functions in two modes depending on whether a component
//	is specified. When a component is not given or is NULL the iteration
//	will be over all polygons for the surface.  When a component is given
//	this iterator will iterate over the polygons specified in the component.
//	When iterating over components a DAG path to the surface must also be
//	supplied.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES

#include <maya/MFnDagNode.h>
#include <maya/MObject.h>
#include <maya/MVector.h>
#include <maya/MPoint.h>
#include <maya/MColor.h>
#include <maya/MFloatArray.h>
#include <maya/MFloatVectorArray.h>
#include <maya/MVectorArray.h>
#include <maya/MColorArray.h>
#include <maya/MString.h>

// *****************************************************************************

// DECLARATIONS

class MPointArray;
class MDoubleArray;
class MIntArray;

// *****************************************************************************

// CLASS DECLARATION (MItMeshPolygon)

/// Polygon iterator
/**
  Iterate over polygonal surfaces
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MItMeshPolygon
{
public:
	///
    MItMeshPolygon( const MObject & polyObject, MStatus * ReturnStatus = NULL );
    ///
    MItMeshPolygon( const MDagPath &polyObject,
					MObject & component = MObject::kNullObj,
					MStatus * ReturnStatus = NULL );
	///
	virtual ~MItMeshPolygon();
    ///
    bool        isDone( MStatus * ReturnStatus = NULL );
    ///
    MStatus     next();
    ///
    MStatus     reset();
    ///
    MStatus     reset( const MObject & polyObject );
    ///
    MStatus     reset( const MDagPath &polyObject,
						MObject & component = MObject::kNullObj );
	// Count methods.
    ///
    int         count( MStatus * ReturnStatus = NULL );
	///
	int         polygonVertexCount( MStatus * ReturnStatus = NULL );


    ///
    MPoint      center( MSpace::Space space = MSpace::kObject,
						MStatus * ReturnStatus = NULL ) ;
	///
	MObject		polygon( MStatus * ReturnStatus = NULL );
    ///

    int         index( MStatus * ReturnStatus = NULL );
	///
	MStatus		setIndex(int index, int &prevIndex);


	// Vertex methods.
    ///
    int         vertexIndex( int index, MStatus * ReturnStatus = NULL );
	///
	MStatus		getVertices( MIntArray & vertices );
    ///
    MPoint      point( int index, MSpace::Space space = MSpace::kObject,
						MStatus * ReturnStatus = NULL );
	///
	void		getPoints(  MPointArray & pointArray, MSpace::Space space = MSpace::kObject,
						MStatus * ReturnStatus = NULL );
    ///
    MStatus     setPoint( const MPoint & point, unsigned int index,
						MSpace::Space space = MSpace::kObject );


	// Normal methods.
    ///
    int         normalIndex( int vertex, MStatus * ReturnStatus = NULL );
    ///
    MStatus     getNormal( MVector & normal,
							MSpace::Space space = MSpace::kObject );
    ///
    MStatus     getNormal( unsigned int Vertexindex, MVector & normal,
							MSpace::Space space = MSpace::kObject );
	///
	MStatus		getNormals( MVectorArray & vectorArray,
						  MSpace::Space space = MSpace::kObject );

	// Uv methods. 
	///
	bool		hasUVs( MStatus * ReturnStatus = NULL ) const;
    /// 
    bool        hasUVs( const MString & uvSet,
						MStatus * ReturnStatus = NULL ) const;						
	///
	MStatus		setUV( int vertexId, float2 & uvPoint,
					   const MString * uvSet = NULL);
	///
	MStatus		getUV( int vertexId, float2 & uvPoint,
					   const MString * uvSet = NULL) const;
	///
	MStatus 	setUVs( MFloatArray& uArray, MFloatArray& vArray,
						const MString * uvSet = NULL);
	///
	MStatus 	getUVs( MFloatArray& uArray, MFloatArray& vArray,
						const MString * uvSet = NULL) const;
    ///
    MStatus		getPointAtUV( MPoint &pt, float2 & uvPoint,
							  MSpace::Space space = MSpace::kObject,
							  const MString * uvSet = NULL);
    ///
    MStatus		getUVAtPoint( MPoint &pt, float2 & uvPoint,
							  MSpace::Space space = MSpace::kObject,
							  const MString * uvSet = NULL);
    ///
    MStatus     getUVIndex( int vertex, int & index, const MString *uvSet = NULL );
    ///
    MStatus     getUVIndex( int vertex, int & index, float & u, float & v,
							const MString *uvSet = NULL);

	// Color methods.
	///
	bool		hasColor(MStatus * ReturnStatus = NULL ) const;
	///
	bool		hasColor(int localVertexIndex, MStatus * ReturnStatus = NULL );
	///
	MStatus		getColor(MColor &color);
	///
	MStatus		getColor(MColor &color, int vertexIndex);
	///
	MStatus		getColors(MColorArray &colors);
	///
	MStatus		numColors( int &count );


	// Triangulation methods.
	///
	bool		hasValidTriangulation(MStatus * ReturnStatus = NULL) const;
    ///
    MStatus		numTriangles(int &count) const;
    ///
    MStatus		getTriangle( int localTriIndex, MPointArray & points,
							 MIntArray & vertexList,
							 MSpace::Space space = MSpace::kObject) const;
    ///
    MStatus		getTriangles(MPointArray & points,
							 MIntArray & vertexList,
							 MSpace::Space space = MSpace::kObject) const;

    ///
    MStatus     updateSurface();
    ///
    MStatus     geomChanged();

	// Info convinience methods.
	///
	MStatus		getEdges( MIntArray & edges );

	///
	MStatus		getConnectedFaces( MIntArray & faces);
	///
	MStatus		getConnectedEdges( MIntArray & edges );
	///
	MStatus		getConnectedVertices( MIntArray & vertices );
	///
	bool		isConnectedToFace( int index, MStatus * ReturnStatus = NULL);
	///
	bool		isConnectedToEdge( int index, MStatus * ReturnStatus = NULL);
	///
	bool		isConnectedToVertex( int index, MStatus * ReturnStatus = NULL);
	///
	MStatus		numConnectedFaces(int & faceCount ) const;
	///
	MStatus		numConnectedEdges(int & edgeCount) const;
	///
	bool        onBoundary(MStatus * ReturnStatus = NULL );
	///
	MStatus		getArea(double &area,
						MSpace::Space space = MSpace::kObject );
    ///
	bool		zeroArea(MStatus * ReturnStatus = NULL);
	///
	MStatus		getUVArea(double &area,
						  const MString * uvSet = NULL);
	///
	bool		zeroUVArea(MStatus * ReturnStatus = NULL);
	/// 
	bool		zeroUVArea(	const MString & uvSet,
							MStatus * ReturnStatus = NULL);
	///
	bool		isConvex(MStatus * ReturnStatus = NULL);
	///
	bool		isStarlike(MStatus * ReturnStatus = NULL);
	///
	bool		isLamina(MStatus * ReturnStatus = NULL);
	///
	bool		isHoled(MStatus * ReturnStatus = NULL);
	///
	bool		isPlanar(MStatus * ReturnStatus = NULL);

protected:
    bool		getUVSetIndex( const MString * uvSetName,
							   int & uvSet) const;

private:

    static const char*  className();
    void     *       f_it;
    MPtrBase *       f_shape;
    void 	 *       f_path;
    void 	 *       f_geom;
	void     *       fElements;
	int             fCurrentElement;
	int             fMaxElements;
	int			 fCurrentIndex;
	void	*		 f_face;
	void	*		 f_ref;
	bool			 fDirectIndex;
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MItMeshPolygon */
