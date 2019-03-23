#ifndef LINUX
#pragma once
#endif
#ifndef _MItMeshEdge
#define _MItMeshEdge
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
// CLASS:    MItMeshEdge
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MItMeshEdge)
//
//	This class is the edge iterator for polygonal surfaces.
//
//	The iterator functions in two modes depending on whether a component
//	is specified. When a component is not given or is NULL the iteration
//	will be over all edges for the polygon.  When a component is given
//	this iterator will iterate over the edges specified in the component.
//	When iterating over components a DAG path to the polygon must also be
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

// *****************************************************************************

// DECLARATIONS

class MPointArray;
class MDoubleArray;
class MIntArray;

// *****************************************************************************

// CLASS DECLARATION (MItMeshEdge)

/// Polygon edge iterator
/**

*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MItMeshEdge
{
public:
    ///
    MItMeshEdge( MObject & polyObject, MStatus * ReturnStatus = NULL );
    ///
    MItMeshEdge( const MDagPath &polyObject,
					MObject & component = MObject::kNullObj,
					MStatus * ReturnStatus = NULL );
	///
	virtual ~MItMeshEdge();
    ///
    bool        isDone( MStatus * ReturnStatus = NULL );
    ///
    MStatus     next();
    ///
    MStatus     reset();
    ///
    MStatus     reset( MObject & polyObject );
    ///
    MStatus     reset( const MDagPath &polyObject,
						MObject & component = MObject::kNullObj );
    ///
    int        count( MStatus * ReturnStatus = NULL );
    ///
    MPoint      center( MSpace::Space space = MSpace::kObject,
						MStatus * ReturnStatus = NULL );
    ///
    MPoint      point( int index, MSpace::Space space = MSpace::kObject,
						MStatus * ReturnStatus = NULL );
    ///
    MStatus     setPoint( const MPoint & point, unsigned int index,
						MSpace::Space space = MSpace::kObject );
	///
	bool		isSmooth( MStatus * ReturnStatus = NULL ) const;
	///
	MStatus		setSmoothing( bool smooth = true );
	/// OBSOLETE
	MStatus		cleanupSmoothing();
    ///
    int         index( int index, MStatus * ReturnStatus = NULL );
    ///
    int         index( MStatus * ReturnStatus = NULL ) const;
	///
	MObject		edge( MStatus * ReturnStatus = NULL );
    ///
    MStatus     updateSurface();
    ///
    MStatus     geomChanged();
	///
	MStatus		setIndex(int index, int &prevIndex );
	///
	int			getConnectedFaces(MIntArray & faceList,
								  MStatus * ReturnStatus = NULL ) const;
	///
	int			getConnectedEdges(MIntArray & edgeList,
								  MStatus * ReturnStatus = NULL ) const;
	///
	MStatus		numConnectedFaces(int &faceCount ) const;
	///
	MStatus		numConnectedEdges(int &edgeCount ) const;
	///
	bool		connectedToFace( int index, MStatus * ReturnStatus = NULL);
	///
	bool		connectedToEdge( int index, MStatus * ReturnStatus = NULL);
	///
	bool		onBoundary(MStatus * ReturnStatus = NULL );
	///
	MStatus		getLength(double &length,
						MSpace::Space space = MSpace::kObject );

protected:
// No protected members

private:
    static const char*  className();
    void     *       f_it;
    MPtrBase *       f_shape;
    void	 *       f_path;
    void	 *       f_geom;
	void     *       fElements;
	int             fCurrentElement;
	int             fMaxElements;
	int			 fCurrentIndex;
	void	*		 f_edge;
	void	*		 f_ref;
	bool			 fDirectIndex;
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MItMeshEdge */
