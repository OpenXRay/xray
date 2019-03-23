#ifndef LINUX
#pragma once
#endif
#ifndef _MFnCircleSweepManip
#define _MFnCircleSweepManip
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
// CLASS:    MFnCircleSweepManip
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnCircleSweepManip)
//
// Function set for a base manipulator - the CircleSweepManip
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
class MVector;
class MAngle;

// *****************************************************************************

// CLASS DECLARATION (MFnCircleSweepManip)

/// CircleSweepManip function set (OpenMayaUI)
/**
MFnCircleSweepManip is the function set for circle sweep manipulators.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYAUI_EXPORT MFnCircleSweepManip : public MFnManip3D
{
	declareDagMFn(MFnCircleSweepManip, MFnManip3D);

public:
	///
	MObject		create(MStatus *ReturnStatus = NULL);
	///
	MObject		create(const MString &manipName,
					   const MString &angleName,
					   MStatus *ReturnStatus = NULL);
	///
	MStatus		connectToAnglePlug(MPlug &anglePlug);
	///
	MStatus		setCenterPoint(const MPoint &centerPoint);
	///
	MStatus		setStartPoint(const MPoint &startPoint);
	///
	MStatus		setEndPoint(const MPoint &endPoint);
	///
	MStatus		setNormal(const MVector &normal);
	///
	MStatus		setRadius(double radius);
	///
	MStatus		setAngle(MAngle angle);
	///
	MStatus		setDrawAsArc(bool state);
	///
	MPoint		startPoint(MStatus *ReturnStatus = NULL) const;
	///
	MPoint		endPoint(MStatus *ReturnStatus = NULL) const;
	///
	unsigned	centerIndex(MStatus *ReturnStatus = NULL) const;
	///
	unsigned	axisIndex(MStatus *ReturnStatus = NULL) const;
	///
	unsigned	angleIndex(MStatus *ReturnStatus = NULL) const;
	///
	unsigned	startCircleIndex(MStatus *ReturnStatus = NULL) const;
	///
	unsigned	endCircleIndex(MStatus *ReturnStatus = NULL) const;

protected:

private:

};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MFnCircleSweepManip */
