
#ifndef _MFnScaleManip
#define _MFnScaleManip
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
// CLASS:    MFnScaleManip
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnScaleManip)
//
// Function set for a base manipulator - the ScaleManip.
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

// CLASS DECLARATION (MFnScaleManip)

/// ScaleManip function set (OpenMayaUI)
/**
	MFnScaleManip is the function set for the standard Maya scale tool.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYAUI_EXPORT MFnScaleManip : public MFnManip3D
{
	declareDagMFn(MFnScaleManip, MFnManip3D);

public:
	///
	MObject		create(MStatus *ReturnStatus = NULL);
	///
	MObject		create(const MString &manipName,
					   const MString &scaleName,
					   MStatus *ReturnStatus = NULL);
	///
	MStatus		connectToScalePlug(const MPlug &scalePlug);
	///
	MStatus		connectToScaleCenterPlug(const MPlug &scaleCenterPlug);
	///
	MStatus		setInitialScale(const MVector& scale);
	///
	MStatus		displayWithNode(const MObject& node);
	///
	MStatus		setSnapMode(bool snapEnabled);
	///
	bool		isSnapModeOn() const;
	///
	MStatus		setSnapIncrement(double snapInc);
	///
	double		snapIncrement() const;
	///
	unsigned	scaleIndex(MStatus *ReturnStatus = NULL) const;
	///
	unsigned	scaleCenterIndex(MStatus *ReturnStatus = NULL) const;

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
#endif /* _MFnScaleManip */
