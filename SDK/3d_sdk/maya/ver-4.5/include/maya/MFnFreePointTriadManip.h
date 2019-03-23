#ifndef LINUX
#pragma once
#endif
#ifndef _MFnFreePointTriadManip
#define _MFnFreePointTriadManip
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
// CLASS:    MFnFreePointTriadManip
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnFreePointTriadManip)
//
// Function set for a base manipulator - the FreePointTriadManip.
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

// CLASS DECLARATION (MFnFreePointTriadManip)

/// FreePointTriadManip function set (OpenMayaUI)
/**
MFnFreePointTriadManip is the function set for free point triad manipulators.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYAUI_EXPORT MFnFreePointTriadManip : public MFnManip3D
{
	declareDagMFn(MFnFreePointTriadManip, MFnManip3D);

public:
	///
	enum ManipPlane {
		/// Y-Z Plane
		kYZPlane = 0,
		/// X-Z Plane
		kXZPlane,
		/// X-Y Plane
		kXYPlane,
		/// View Plane
		kViewPlane
	};

	///
	MObject		create(MStatus *ReturnStatus = NULL);
	///
	MObject		create(const MString &manipName,
					   const MString &pointName,
					   MStatus *ReturnStatus = NULL);
	///
	MStatus		connectToPointPlug(MPlug &pointPlug);
	///
	MStatus		setDrawAxes(bool state);
	///
	MStatus		setSnapMode(bool state);
	///
	MStatus		setKeyframeAll(bool state);
	///
	MStatus		setDrawArrowHead(bool state);
	///
	MStatus		setGlobalTriadPlane(ManipPlane whichPlane);
	///
	bool		isDrawAxesOn(MStatus *ReturnStatus = NULL) const;
	///
	bool		isSnapModeOn(MStatus *ReturnStatus = NULL) const;
	///
	bool		isKeyframeAllOn(MStatus *ReturnStatus = NULL) const;
	///
	unsigned	pointIndex(MStatus *ReturnStatus = NULL) const;

protected:

private:

};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MFnFreePointTriadManip */
