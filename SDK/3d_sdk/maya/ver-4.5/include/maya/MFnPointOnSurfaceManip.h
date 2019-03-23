#ifndef LINUX
#pragma once
#endif
#ifndef _MFnPointOnSurfaceManip
#define _MFnPointOnSurfaceManip
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
// CLASS:    MFnPointOnSurfaceManip
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnPointOnSurfaceManip)
//
// Function set for a base manipulator - the PointOnSurfaceManip
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES

#include <maya/MFnBase.h>
#include <maya/MFnManip3D.h>
#include <maya/MObject.h>

// *****************************************************************************

// DECLARATIONS

class MPoint;

// *****************************************************************************

// CLASS DECLARATION (MFnPointOnSurfaceManip)

/// PointOnSurfaceManip function set (OpenMayaUI)
/**
MFnPointOnSurfaceManip is the function set for point on surface manipulators.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYAUI_EXPORT MFnPointOnSurfaceManip : public MFnManip3D
{
	declareDagMFn(MFnPointOnSurfaceManip, MFnManip3D);

public:
	///
	MObject		create(MStatus *ReturnStatus = NULL);
	///
	MObject		create(const MString &manipName,
					   const MString &paramName,
					   MStatus *ReturnStatus = NULL);
	///
	MStatus		connectToSurfacePlug(MPlug &surfacePlug);
	///
	MStatus		connectToParamPlug(MPlug &paramPlug);
	///
	MStatus		setDrawSurface(bool state);
	///
	MStatus		setDrawArrows(bool state);
	///
	MStatus		setParameters(double u, double v);
	///
	MStatus		getParameters(double &u, double &v);
	///
	bool		isDrawSurfaceOn(MStatus *ReturnStatus = NULL) const;
	///
	unsigned	surfaceIndex(MStatus *ReturnStatus = NULL) const;
	///
	unsigned	paramIndex(MStatus *ReturnStatus = NULL) const;

protected:

private:

};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MFnPointOnSurfaceManip */
