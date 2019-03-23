#ifndef LINUX
#pragma once
#endif
#ifndef _MPxContextCommand
#define _MPxContextCommand
//
// *****************************************************************************
//
// Copyright (C) 1997-2001 Alias|Wavefront Inc.
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
// CLASS:    MPxContextCommand
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MPxContextCommand)
//
//  This is the command class used for creating proxy contexts.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES

#include <maya/MTypes.h>
#include <maya/MStatus.h>

// *****************************************************************************

// DECLARATIONS

class MPxContext;
class MArgParser;

// *****************************************************************************

// CLASS DECLARATION (MPxContextCommand)

/// Base class for context creation commands (OpenMayaUI)
/**
  The base class for context creation commands.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYAUI_EXPORT MPxContextCommand
{
public:
	///
							MPxContextCommand	();
	///
	virtual					~MPxContextCommand	();
	/// 
	virtual MStatus			doEditFlags			();
	///
	virtual MStatus			doQueryFlags		();
	///
	virtual MPxContext *	makeObj				();
	///
	virtual MStatus			appendSyntax		();
	///
	MStatus					setResult			(bool result);
	///
	MStatus					setResult			(int result);
	///
	MStatus					setResult			(double result);
	///
	MStatus					setResult			(const MString &result);

protected:
	///
	MSyntax	syntax(MStatus *ReturnStatus = NULL) const;
	///
	MArgParser parser(MStatus *ReturnStatus = NULL) const;

private:
	const char *className() const;

	void setData(void *ptr);

	void *instance;
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MPxContextCommand */
