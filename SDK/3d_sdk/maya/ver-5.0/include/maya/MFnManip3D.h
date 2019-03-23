
#ifndef _MFnManip3D
#define _MFnManip3D
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
// CLASS:    MFnManip3D
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnManip3D)
//
// Function set for 3D manipulators.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MFnTransform.h>
#include <maya/MObject.h>

// *****************************************************************************

// DECLARATIONS

// *****************************************************************************

// CLASS DECLARATION (MFnManip3D)

/// 3D manipulator function set (OpenMayaUI)
/**
MFnManip3D is the function set for 3D manipulators.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32


class OPENMAYAUI_EXPORT MFnManip3D : public MFnTransform
{
	declareDagMFn(MFnManip3D, MFnTransform);
public:
	///
	bool 			isVisible(MStatus *ReturnStatus) const;
	///
	MStatus			setVisible(bool isVisible);
	///
	float			manipScale(MStatus *ReturnStatus) const;
	///
	MStatus			setManipScale(float size);
	///
	bool			isOptimizePlaybackOn(MStatus *ReturnStatus) const;
	///
	MStatus			setOptimizePlayback(bool optimizePlayback);
	///
	static float	globalSize();
	///
	static void		setGlobalSize(float size);
	///
	static float	handleSize();
	///
	static void		setHandleSize(float size);
	///
	static float	lineSize();
	///
	static void		setLineSize(float size);

protected:

private:
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MFnManip3D */
