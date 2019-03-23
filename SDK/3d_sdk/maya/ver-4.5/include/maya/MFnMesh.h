#ifndef LINUX
#pragma once
#endif
#ifndef _MFnMesh
#define _MFnMesh
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
// CLASS:    MFnMesh
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnMesh)
//
//	Function set for polygonal objects.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES

#include <maya/MFnDagNode.h>
#include <maya/MVector.h>
#include <maya/MPoint.h>
#include <maya/MObject.h>
#include <maya/MObjectArray.h>
#include <maya/MColor.h>
#include <maya/MVectorArray.h>
#include <maya/MStringArray.h>
#include <maya/MColorArray.h>
#include <maya/MDGModifier.h>
#include <maya/MString.h>

// *****************************************************************************

// DECLARATIONS

class MPointArray;
class MFloatArray;
class MFloatPointArray;
class MFloatVectorArray;
class MIntArray;
class MDoubleArray;
class MSelectionList;

// Default tolerance
#define kMFnMeshTolerance 1.0e-3

// Point equivalent tolerance
#define kMFnMeshPointTolerance 1.0e-10

// *****************************************************************************

// CLASS DECLARATION (MFnMesh)

/// Polygonal surface function set
/**

*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MFnMesh : public MFnDagNode 
{

	declareDagMFn(MFnMesh, MFnDagNode);

public: 
    ///
    MObject     create( int numVertices, int numPolygons,
						const MFloatPointArray &vertexArray,
                        const MIntArray &polygonCounts,
                        const MIntArray &polygonConnects,
						MObject parentOrOwner = MObject::kNullObj,
						MStatus * ReturnStatus = NULL );

    ///
    MObject     create( int numVertices, int numPolygons,
						const MPointArray 	&vertexArray,
                        const MIntArray 	&polygonCounts,
                        const MIntArray 	&polygonConnects,
						MObject parentOrOwner  = MObject::kNullObj,
						MStatus * ReturnStatus = NULL );

    ///
    MObject     addPolygon( const MPointArray & vertexArray,
                        	bool 		mergeVertices = true,
                        	double 		pointTolerance = kMFnMeshPointTolerance,
							MObject 	parentOrOwner = MObject::kNullObj,
							MStatus * ReturnStatus = NULL );
    ///
    MObject     addPolygon( const MPointArray & vertexArray,
							int & 		faceIndex,
                        	bool 		mergeVertices = true,
                        	double 		pointTolerance = kMFnMeshPointTolerance,
							MObject 	parentOrOwner = MObject::kNullObj,
							MStatus * ReturnStatus = NULL );

    /// OBSOLETE
    MObject     addPolygon( MPointArray & vertexArray,
                        	double 		polyTolerance,
                        	bool     	mergeVertices = true,
                        	double 		pointTolerance = kMFnMeshPointTolerance,
                        	bool     	forceGeometry = true,
							MObject 	parentOrOwner = MObject::kNullObj,
							MStatus * ReturnStatus = NULL );

	///
	MStatus		deleteFace(int index, MDGModifier *modifier = NULL);
	///
	MStatus		deleteEdge(int index, MDGModifier *modifier = NULL);
	///
	MStatus		deleteVertex(int index, MDGModifier *modifier = NULL);
	///
	MStatus		lockVertexNormals(MIntArray & vertexList);
	///
	MStatus		lockFaceVertexNormals( MIntArray & faceList, MIntArray & vertexList);
	///
	MStatus		unlockVertexNormals(MIntArray & vertexList);
	///
	MStatus		unlockFaceVertexNormals( MIntArray & faceList, MIntArray & vertexList);


	// Counts
    ///
	int        numVertices( MStatus * ReturnStatus = NULL) const;
    ///
	int        numEdges( MStatus * ReturnStatus = NULL ) const;
    ///
	int        numPolygons( MStatus * ReturnStatus = NULL ) const;
    ///
	int		   numFaceVertices( MStatus * ReturnStatus = NULL ) const;
	///
	int        polygonVertexCount( int polygonId,
									MStatus * ReturnStatus = NULL ) const;
	///
	int		   numUVs( MStatus * ReturnStatus = NULL ) const;
	///
	int		   numUVs( const MString &uvSet, 
					   MStatus * ReturnStatus = NULL ) const;
	///
	int		   numNormals( MStatus * ReturnStatus = NULL ) const;


	// Intersection/getClosestPoint methods.
	///
	bool     	intersect( const MPoint & raySource,
                            const MVector & rayDirection,
							MPointArray & points,
                            double tolerance = kMFnMeshPointTolerance,
							MSpace::Space space = MSpace::kObject,
							MIntArray * polygonIds = NULL,
							MStatus * ReturnStatus = NULL ) const;        
	/// OBSOLETE
	bool     	intersect( MPoint & raySource, MVector & rayDirection,
							MPointArray & points,
							MStatus * ReturnStatus = NULL ) const;        

	/// OBSOLETE
	bool     	intersect( const MPoint & raySource,
                            const MVector & rayDirection,
							MPointArray & points,
							MStatus * ReturnStatus = NULL ) const;        
	///
    MStatus     getClosestPointAndNormal( const MPoint &  toThisPoint,
                			MPoint & theClosestPoint,
                			MVector & theNormal,
							MSpace::Space space = MSpace::kObject,
							int * closestPolygon = NULL ) const;
	///
    MStatus     getClosestPoint(const MPoint &toThisPoint,
                            MPoint &theClosestPoint,
							MSpace::Space space = MSpace::kObject,
							int * closestPolygon = NULL ) const;

	///
    MStatus     getClosestNormal(const MPoint &toThisPoint,
                            MVector & theNormal,
							MSpace::Space space = MSpace::kObject,
							int * closestPolygon = NULL ) const;


	// Shaders and membership methods.
	///
    MStatus     getConnectedShaders(
                            unsigned instanceNumber,
                            MObjectArray & shaders,
							MIntArray & indices ) const;
	///
	MStatus		getConnectedSetsAndMembers(
							unsigned instanceNumber,
							MObjectArray & sets,
							MObjectArray & comps,
							bool renderableSetsOnly ) const;

	///
	MObject		copy( const MObject & source,
					  MObject parentOrOwner = MObject::kNullObj,
					  MStatus * ReturnStatus = NULL );
    ///
	MStatus		updateSurface();
	///
	MStatus		syncObject();


	// Get/set methods for mesh vertices.
	///
	MStatus 	getPoints( MFloatPointArray & vertexArray,
							MSpace::Space space = MSpace::kObject ) const;
	///
	MStatus 	getPoints( MPointArray & vertexArray,
							MSpace::Space space = MSpace::kObject ) const;
	///
	MStatus 	setPoints( MFloatPointArray & vertexArray,
							MSpace::Space space = MSpace::kObject );
	///
	MStatus 	setPoints( MPointArray & vertexArray,
							MSpace::Space space = MSpace::kObject );
	///
	MStatus 	getPolygonVertices( int polygonId,
							MIntArray & vertexList ) const;
	///
	MStatus		setPoint( int vertexId, const MPoint & pos,
							MSpace::Space space = MSpace::kObject );
	///
	MStatus		getPoint( int vertexId, MPoint & pos,
							MSpace::Space space = MSpace::kObject ) const;


	// Methods for setting/getting Normals
	///
	MStatus 	getNormals( MFloatVectorArray& normals,
							MSpace::Space space = MSpace::kObject ) const;
	///
    MStatus     getFaceVertexNormal( int faceIndex, int vertexIndex,
                            MVector & normal,
                            MSpace::Space space = MSpace::kObject ) const;
    ///
    MStatus     getFaceVertexNormals( int faceIndex, MFloatVectorArray & normals,
                            MSpace::Space space = MSpace::kObject ) const;
    ///
    MStatus     getFaceNormalIds( int faceIndex, MIntArray &normals ) const;
	///
	MStatus		setFaceVertexNormal( MVector &normal,
									int faceIndex, int vertexIndex,
									MSpace::Space space = MSpace::kObject,
									MDGModifier *modifier = NULL);
	///
	MStatus		setVertexNormal( MVector &normal,
									int vertexIndex,
									MSpace::Space space = MSpace::kObject,
									MDGModifier *modifier = NULL);
	///
	MStatus		setFaceVertexNormals( MVectorArray & normalArray,
									MIntArray & faceList, MIntArray & vertexList,
									MSpace::Space space = MSpace::kObject );
	///
	MStatus		setVertexNormals( MVectorArray & normalArray,
									MIntArray & vertexList,
									MSpace::Space space = MSpace::kObject );
	///
	MStatus		getVertexNormal( int vertexId, MVector & normal,
							MSpace::Space space = MSpace::kObject ) const;
	///
	MStatus		getPolygonNormal( int polygonId, MVector & normal,
							MSpace::Space space = MSpace::kObject ) const;


	// Edge info methods.
	///
	MStatus 	getEdgeVertices( int edgeId, int2 & vertexList ) const;
	///
	bool		isEdgeSmooth( int edgeId, MStatus * ReturnStatus = NULL ) const;
	///
	MStatus		setEdgeSmoothing( int edgeId, bool smooth = true );
	///
	MStatus		cleanupEdgeSmoothing();


	// UVs operators and methods.
	///
	int			numUVSets( MStatus *ReturnStatus = NULL) const;
	///
	MStatus		createUVSet(MString &uvSetName,
							MDGModifier *modifier = NULL);
	///
	MStatus		copyUVSet(const MString &fromName, MString &toName,
						  MDGModifier *modifier = NULL);
	///
	MStatus		renameUVSet(const MString &origName,
							const MString &newName,
							MDGModifier *modifier = NULL);
	///
	MStatus		deleteUVSet(const MString &setName,
							 MDGModifier *modifier = NULL,
							 MSelectionList *currentSelection = NULL);
	///
	MStatus		setCurrentUVSetName(const MString &setName,
									 MDGModifier *modifier = NULL,
									MSelectionList *currentSelection = NULL);
	///
	MStatus		getCurrentUVSetName(MString &setName) const;
	///
	MStatus		getUVSetNames(MStringArray &setNames) const;
	///
	MStatus		getAssociatedUVSetTextures(const MString uvSetName,
										   MObjectArray & textures) const;
	///
	MStatus 	setUVs( const MFloatArray& uArray, const MFloatArray& vArray,
						const MString * uvSet = NULL );
	///
	MStatus 	setSomeUVs( const  MIntArray & uvIds, const MFloatArray& uArray,
						    const MFloatArray& vArray, const MString * uvSet = NULL );
	///
	MStatus 	getUVs( MFloatArray& uArray, MFloatArray& vArray,
						const MString * uvSet = NULL ) const;
	///
	MStatus		setUV( int uvId, float u, float v,
					   const MString * uvSet = NULL );
	///
	MStatus		getUV( int uvId, float & u, float & v,
					   const MString * uvSet = NULL ) const;
	///
	MStatus 	getPolygonUV( int polygonId, int vertexIndex, 
								float & u, float & v,
							  const MString * uvSet = NULL ) const;
	///
	MStatus 	getPolygonUVid( int polygonId, int vertexIndex, 
								int &uvId,
								const MString * uvSet = NULL ) const;
	///
	MStatus 	assignUV( int polygonId, int vertexIndex, int uvId,
						  const MString * uvSet = NULL );
	///
	MStatus		assignUVs( const MIntArray& uvCounts, const MIntArray& uvIds,
						   const MString * uvSet = NULL );
	///
	MStatus		clearUVs( const MString * uvSet = NULL );
	///
	MStatus		getAssignedUVs( MIntArray& uvCounts, MIntArray& uvIds,
								const MString * uvSet = NULL ) const;


	// Color Per Vertex Methods
	///
	MStatus		setFaceColor(MColor &color, int index);
	///
	MStatus		setVertexColor(MColor &color, int index, MDGModifier *modifier = NULL);
	///
	MStatus		setFaceVertexColor( MColor &color, int faceIndex, 
									int vertexIndex,  
									MDGModifier *modifier = NULL);
	///
	MStatus		setFaceColors(MColorArray &colors, MIntArray &faceList);
	///
	MStatus		setVertexColors(MColorArray &colors, MIntArray &vertexList,
								MDGModifier *modifier = NULL);
	///
	MStatus		setFaceVertexColors(MColorArray &colors, 
									MIntArray &faceList, MIntArray &vertexList,
									MDGModifier *modifier = NULL);
	///
	MStatus		removeFaceColors(MIntArray &faceList);
	///
	MStatus		removeVertexColors(MIntArray &vertexList);
	///
	MStatus		removeFaceVertexColors( MIntArray &faceList, MIntArray &vertexList);
	///
	MStatus		getVertexColors(MColorArray &colors);
	///
	MStatus		getFaceVertexColors(MColorArray &colors);
	///
	MStatus		getFaceVertexColorIndex(int faceIndex, int localVertexIndex,
										int &colorIndex);


	// Polygon Hole Query Method
	///
	int			getHoles( MIntArray& holeInfoArray, 
						  MIntArray& holeVertexArray, 
						  MStatus * ReturnStatus = NULL );



	// Blind Data Query Methods
	///
	bool		isBlindDataTypeUsed( int blindDataId,
								   MStatus * ReturnStatus = NULL ) const;
	///
	MStatus		createBlindDataType( int blindDataId,
									 MStringArray longNames,
									 MStringArray shortNames,
									 MStringArray formatNames);
	///
	bool		hasBlindData( int compID,
							  MFn::Type compType,
							  int blindDataId,
							  MStatus * ReturnStatus = NULL ) const;
	///
	bool		hasBlindData( MFn::Type compType,
							  int blindDataId,
							  MStatus * ReturnStatus = NULL ) const;
	///
	bool		hasBlindData( int compID,
							  MFn::Type compType,
							  MStatus * ReturnStatus = NULL ) const;
	///
	bool		hasBlindData( MFn::Type compType,
							  MStatus * ReturnStatus = NULL ) const;
	// Get Blind Data Methods.
	///
	MStatus		getBlindDataTypes(MFn::Type compType,
							MIntArray& typeArray ) const;

	/// OBSOLETE
	MStatus		getBlindDataAttrNames(int blindDataId,
							 MStringArray& longNames,
							 MStringArray& shortNames) const;

	///
	MStatus		getBlindDataAttrNames(int blindDataId,
							 MStringArray& longNames,
							 MStringArray& shortNames,
							 MStringArray& typeNames) const;

	///
	MStatus		getIntBlindData( int compID, MFn::Type compType,
							  int blindDataId, MString attrName,
							  int &data) const;
	///
	MStatus		getIntBlindData( MFn::Type compType,
							  int blindDataId, MString attrName,
							  MIntArray& compIDs, MIntArray& data) const;
	///
	MStatus		getFloatBlindData( int compID, MFn::Type compType,
							  int blindDataId, MString attrName,
							  float &data) const;
	///
	MStatus		getFloatBlindData( MFn::Type compType,
							  int blindDataId, MString attrName,
							  MIntArray& compIDs, MFloatArray& data) const;
	///
	MStatus		getDoubleBlindData( int compID, MFn::Type compType,
							  int blindDataId, MString attrName,
							  double &data) const;
	///
	MStatus		getDoubleBlindData( MFn::Type compType,
							  int blindDataId, MString attrName,
							  MIntArray& compIDs, MDoubleArray& data) const;
	///
	MStatus		getBoolBlindData( int compID, MFn::Type compType,
							  int blindDataId, MString attrName,
							  bool &data) const;
	///
	MStatus		getBoolBlindData( MFn::Type compType,
							  int blindDataId, MString attrName,
							  MIntArray& compIDs, MIntArray& data) const;
	///
	MStatus		getStringBlindData( int compID, MFn::Type compType,
							  int blindDataId, MString attrName,
							  MString &data) const;
	///
	MStatus		getStringBlindData( MFn::Type compType,
							  int blindDataId, MString attrName,
							  MIntArray& compIDs, MStringArray& data) const;
	///
	MStatus		getBinaryBlindData( int compID, MFn::Type compType,
							  int blindDataId, MString attrName,
							  MString &data) const;
	///
	MStatus		getBinaryBlindData( MFn::Type compType,
							  int blindDataId, MString attrName,
							  MIntArray& compIDs, MStringArray& data) const;

	// Set Blind Data Methods
	///
	MStatus		setIntBlindData( int compID, MFn::Type compType,
							  int blindDataId,
							  MString attrName,
							  int data);
	///
	MStatus		setIntBlindData( MIntArray& compIDs, MFn::Type compType,
							  int blindDataId,
							  MString attrName,
							  int data);
	///
	MStatus		setIntBlindData( MIntArray& compIDs, MFn::Type compType,
							  int blindDataId,
							  MString attrName,
							  MIntArray& data);
	///
	MStatus		setFloatBlindData( int compID, MFn::Type compType,
							  int blindDataId,
							  MString attrName,
							  float data);
	///
	MStatus		setFloatBlindData( MIntArray& compIDs, MFn::Type compType,
							  int blindDataId,
							  MString attrName,
							  float data);
	///
	MStatus		setFloatBlindData( MIntArray& compIDs, MFn::Type compType,
							  int blindDataId,
							  MString attrName,
							  MFloatArray &data);
	///
	MStatus		setDoubleBlindData( int compID, MFn::Type compType,
							  int blindDataId,
							  MString attrName,
							  double data);
	///
	MStatus		setDoubleBlindData( MIntArray& compIDs, MFn::Type compType,
							  int blindDataId,
							  MString attrName,
							  double data);
	///
	MStatus		setDoubleBlindData( MIntArray& compIDs, MFn::Type compType,
							  int blindDataId,
							  MString attrName,
							  MDoubleArray &data);
	///
	MStatus		setBoolBlindData( int compID, MFn::Type compType,
							  int blindDataId,
							  MString attrName,
							  bool data);
	///
	MStatus		setBoolBlindData( MIntArray& compIDs, MFn::Type compType,
							  int blindDataId,
							  MString attrName,
							  bool data);
	///
	MStatus		setBoolBlindData( MIntArray& compIDs, MFn::Type compType,
							  int blindDataId,
							  MString attrName,
							  MIntArray& data);
	///
	MStatus		setStringBlindData( int compID, MFn::Type compType,
							  int blindDataId,
							  MString attrName,
							  MString data);
	///
	MStatus		setStringBlindData( MIntArray& compIDs, MFn::Type compType,
							  int blindDataId,
							  MString attrName,
							  MString data);
	///
	MStatus		setStringBlindData( MIntArray& compIDs, MFn::Type compType,
							  int blindDataId,
							  MString attrName,
							  MStringArray &data);
	///
	MStatus		setBinaryBlindData( int compID, MFn::Type compType,
							  int blindDataId,
							  MString attrName,
							  MString data);
	///
	MStatus		setBinaryBlindData( MIntArray& compIDs, MFn::Type compType,
							  int blindDataId,
							  MString attrName,
							  MString data);
	///
	MStatus		setBinaryBlindData( MIntArray& compIDs, MFn::Type compType,
							  int blindDataId,
							  MString attrName,
							  MStringArray &data);
    ///
    MStatus     setBinaryBlindData( int compID, MFn::Type compType,
                              int blindDataId,
                              MString attrName,
                              char *data, int length);
	///
	MStatus     clearBlindData(int compID, MFn::Type compType,
							  int blindDataId,
							  MString attrName);
	///
	MStatus     clearBlindData(MFn::Type compType,
							  int blindDataId,
							  MString attrName);

	///
	MStatus		clearBlindData(MFn::Type compType);
	///
	MStatus     clearBlindData(int compID,
							  MFn::Type compType,
							  int blindDataId);
	///
	MStatus     clearBlindData(MFn::Type compType,
							  int blindDataId);


protected:  
	virtual bool objectChanged( MFn::Type tp, MStatus * ReturnStatus );
    bool		getUVSetIndex( const MString * uvSetName,
							   int & uvSet) const;

private:
// No private members
	void *f_meshRef;

};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MFnMesh */
