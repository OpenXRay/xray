#ifndef LINUX
#pragma once
#endif
#ifndef _MFnGeometryFilter
#define _MFnGeometryFilter
//
// *****************************************************************************
//
// Copyright (C) 1998-2001 Alias|Wavefront Inc.
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
// CLASS:    MFnGeometryFilter
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnGeometryFilter)
// 
// MFnGeometryFilter is the function set for geometry filters (deformers)
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES

#include <maya/MFnDependencyNode.h>
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

// *****************************************************************************

// CLASS DECLARATION (MFnGeometryFilter)

///  geometry filter function set (OpenMayaAnim)
/**
MFnGeometryFilter is the function set for deformers.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYAANIM_EXPORT MFnGeometryFilter : public MFnDependencyNode
{
	declareMFn(MFnGeometryFilter, MFnDependencyNode);

public:
	///
	MStatus		getInputGeometry(MObjectArray &objects) const;
	///
	MStatus		getOutputGeometry(MObjectArray &objects) const;
	///
	MObject		inputShapeAtIndex(unsigned index,
								  MStatus *ReturnStatus = NULL) const;
	///
	MObject		outputShapeAtIndex(unsigned index,
								   MStatus *ReturnStatus = NULL) const;
	///
	unsigned	indexForOutputShape(const MObject &shape, 
									MStatus *ReturnStatus = NULL) const;
	///
	MStatus		getPathAtIndex(unsigned index, 
							   MDagPath &path) const;
	///
	unsigned	indexForGroupId(unsigned groupId, 
								MStatus *ReturnStatus = NULL) const;
	///
	unsigned	groupIdAtIndex(unsigned index, 
							   MStatus *ReturnStatus = NULL) const;
	///
	unsigned	numOutputConnections(MStatus *ReturnStatus = NULL) const;
	///
	unsigned	indexForOutputConnection(unsigned connectionIndex, 
										 MStatus *ReturnStatus = NULL) const;
	///
	MObject		deformerSet(MStatus *ReturnStatus = NULL) const;
	///
	float		envelope(MStatus *ReturnStatus = NULL) const;
	///
	MStatus		setEnvelope(float envelope);

protected:
// No protected members

private:
// No private members
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MFnGeometryFilter */
