
#ifndef _MFnCurveSegmentManip
#define _MFnCurveSegmentManip
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
// CLASS:    MFnCurveSegmentManip
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnCurveSegmentManip)
//
// Function set for a base manipulator - the CurveSegmentManip.
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

// CLASS DECLARATION (MFnCurveSegmentManip)

/// CurveSegmentManip function set (OpenMayaUI)
/**
MFnCurveSegmentManip is the function set for curve segment manipulators.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYAUI_EXPORT MFnCurveSegmentManip : public MFnManip3D
{
	declareDagMFn(MFnCurveSegmentManip, MFnManip3D);

public:
	///
	MObject		create(MStatus *ReturnStatus = NULL);
	///
	MObject		create(const MString &manipName,
					   const MString &startParamName,
					   const MString &endParamName,
					   MStatus *ReturnStatus = NULL);
	///
	MStatus		connectToCurvePlug(MPlug &curvePlug);
	///
	MStatus		connectToStartParamPlug(MPlug &startParamPlug);
	///
	MStatus		connectToEndParamPlug(MPlug &endParamPlug);
	///
	MStatus		setStartParameter(double startParameter);
	///
	MStatus		setEndParameter(double endParameter);
	///
	double		startParameter(MStatus *ReturnStatus = NULL) const;
	///
	double		endParameter(MStatus *ReturnStatus = NULL) const;
	///
	unsigned	curveIndex(MStatus *ReturnStatus = NULL) const;
	///
	unsigned	startParamIndex(MStatus *ReturnStatus = NULL) const;
	///
	unsigned	endParamIndex(MStatus *ReturnStatus = NULL) const;

protected:

private:

};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MFnCurveSegmentManip */
