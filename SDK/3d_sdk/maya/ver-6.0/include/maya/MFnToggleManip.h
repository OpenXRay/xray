
#ifndef _MFnToggleManip
#define _MFnToggleManip
//
//-
// ==========================================================================
// Copyright (C) Alias Systems Corp., and/or its licensors ("Alias").  
// All rights reserved.  These coded instructions, statements, computer  
// programs, and/or related material (collectively, the "Material")
// contain unpublished information proprietary to Alias, which is
// protected by Canadian and US federal copyright law and by international
// treaties. This Material may not be disclosed to third parties, or be copied
// or duplicated, in whole or in part, without the prior written consent of
// Alias.  ALIAS HEREBY DISCLAIMS ALL WARRANTIES RELATING TO THE MATERIAL,
// INCLUDING, WITHOUT LIMITATION, ANY AND ALL EXPRESS OR IMPLIED WARRANTIES OF
// NON-INFRINGEMENT, MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
// IN NO EVENT SHALL ALIAS BE LIABLE FOR ANY DAMAGES WHATSOEVER, WHETHER DIRECT,
// INDIRECT, SPECIAL, OR PUNITIVE, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE
// OR OTHER TORTIOUS ACTION, OR IN EQUITY, ARISING OUT OF OR RELATED TO THE
// ACCESS TO, USE OF, OR RELIANCE UPON THE MATERIAL.
// ==========================================================================
//+
//
// CLASS:    MFnToggleManip
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnToggleManip)
//
// Function set for a base manipulator - the ToggleManip
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

// CLASS DECLARATION (MFnToggleManip)

/// ToggleManip function set (OpenMayaUI)
/**
MFnToggleManip is the function set for toggle manipulators.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYAUI_EXPORT MFnToggleManip : public MFnManip3D
{
	declareDagMFn(MFnToggleManip, MFnManip3D);

public:
	///
	MObject		create(MStatus *ReturnStatus = NULL);
	///
	MObject		create(const MString &manipName,
					   const MString &toggleName,
					   MStatus *ReturnStatus = NULL);
	///
	MStatus		connectToTogglePlug(MPlug &togglePlug);
	///
	MPoint		startPoint(MStatus *ReturnStatus = NULL) const;
	///
	MVector		direction(MStatus *ReturnStatus = NULL) const;
	///
	double		length(MStatus *ReturnStatus = NULL) const;
	///
	bool		toggle(MStatus *ReturnStatus = NULL) const;
	///
	unsigned	startPointIndex(MStatus *ReturnStatus = NULL) const;
	///
	unsigned	directionIndex(MStatus *ReturnStatus = NULL) const;
	///
	unsigned	lengthIndex(MStatus *ReturnStatus = NULL) const;
	///
	unsigned	toggleIndex(MStatus *ReturnStatus = NULL) const;
	///
	MStatus		setStartPoint(MPoint &startPoint);
	///
	MStatus		setDirection(MVector &direction);
	///
	MStatus		setLength(double length);
	///
	MStatus		setToggle(bool toggle);

protected:

private:

};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MFnToggleManip */
