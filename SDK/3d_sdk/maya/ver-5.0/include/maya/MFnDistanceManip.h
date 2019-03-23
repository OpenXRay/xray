
#ifndef _MFnDistanceManip
#define _MFnDistanceManip
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
// CLASS:    MFnDistanceManip
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnDistanceManip)
//
// Function set for a base manipulator - the DistanceManip
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

// *****************************************************************************

// CLASS DECLARATION (MFnDistanceManip)

/// DistanceManip function set (OpenMayaUI)
/**
MFnDistanceManip is the function set for distance manipulators.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYAUI_EXPORT MFnDistanceManip : public MFnManip3D
{
	declareDagMFn(MFnDistanceManip, MFnManip3D);

public:
	///
	MObject		create(MStatus *ReturnStatus = NULL);
	///
	MObject		create(const MString &manipName,
					   const MString &distanceName,
					   MStatus *ReturnStatus = NULL);
	///
	MStatus		connectToDistancePlug(MPlug &distancePlug);
	///
	MStatus		setStartPoint(const MPoint &point);
	///
	MStatus		setDirection(const MVector &vector);
	///
	MStatus		setDrawStart(bool state);
	///
	MStatus		setDrawLine(bool state);
	///
	MStatus		setScalingFactor(double scalingFactor);
	///
	bool		isDrawStartOn(MStatus *ReturnStatus = NULL) const;
	///
	bool		isDrawLineOn(MStatus *ReturnStatus = NULL) const;
	///
	double		scalingFactor(MStatus *ReturnStatus = NULL) const;
	///
	unsigned	distanceIndex(MStatus *ReturnStatus = NULL) const;
	///
	unsigned	directionIndex(MStatus *ReturnStatus = NULL) const;
	///
	unsigned	startPointIndex(MStatus *ReturnStatus = NULL) const;
	///
	unsigned	currentPointIndex(MStatus *ReturnStatus = NULL) const;

protected:

private:

};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MFnDistanceManip */
