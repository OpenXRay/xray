
#ifndef _MFnManip3D
#define _MFnManip3D
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
	///
	static MStatus	deleteManipulator(MObject& manip);

protected:

private:
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MFnManip3D */
