
#ifndef _MFnSkinCluster
#define _MFnSkinCluster
//
// *****************************************************************************
//
// Copyright (C) 1998-2003 Alias|Wavefront Inc.
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
// CLASS:    MFnSkinCluster
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnSkinCluster)
//
// MFnSkinCluster is the function set for skinClusters.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MFnGeometryFilter.h>
#include <maya/MObject.h>
// *****************************************************************************

// DECLARATIONS
class MObject;
class MDagPath;
class MIntArray;
class MFloatArray;
class MObjectArray;
class MSelectionList;
class MString;
class MDagPathArray;

// *****************************************************************************

// CLASS DECLARATION (MFnSkinCluster)

/// skinCluster function set (OpenMayaAnim)
/**
MFnSkinCluster is the function set for editing the weights of
skinClusters.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYAANIM_EXPORT MFnSkinCluster : public MFnGeometryFilter
{
	declareMFn(MFnSkinCluster, MFnGeometryFilter);

public:
	///
	MStatus		getWeights(const MDagPath& path,
						   const MObject& components,
						   unsigned influenceIndex,
						   MFloatArray& weights) const;
	///
	MStatus		getWeights(const MDagPath& path,
						   const MObject& components,
						   MFloatArray& weights,
						   unsigned& influenceCount) const;

	///
	MStatus		setWeights(const MDagPath& path,
						   const MObject& components,
						   unsigned jointIndex,
						   float value,
						   bool normalize = true,
						   MFloatArray *oldValues = NULL);
	///
	MStatus		setWeights(const MDagPath& path,
						   const MObject& components,
						   MIntArray& influenceIndices,
						   MFloatArray& values,
						   bool normalize = true,
						   MFloatArray *oldValues = NULL);
	///
	MStatus		getPointsAffectedByInfluence(const MDagPath& path,
											 MSelectionList& result,
											 MFloatArray& weights);
	///
	unsigned 	indexForInfluenceObject(const MDagPath& path,
										MStatus *ReturnStatus) const;
	///
	unsigned 	influenceObjects(MDagPathArray& paths,
								 MStatus *ReturnStatus) const;

protected:
// No protected members

private:
	MStatus		getWeightsHelper(bool useInfluenceIndex,
								 unsigned influenceIndex,
								 const MDagPath& path,
								 const MObject& components,
								 unsigned& influenceCount,
								 MFloatArray& weights) const;

	MStatus		setWeightsHelper(const MDagPath& path,
								 const MObject& components,
								 bool useInfluenceIndex,
								 unsigned influenceIndex,
								 const MIntArray& infArray,
								 const MFloatArray& wtArray,
								 bool normalize /* = true */,
								 MFloatArray *oldValues /* = NULL */);

};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MFnSkinCluster */
