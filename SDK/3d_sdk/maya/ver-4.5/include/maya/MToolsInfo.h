#ifndef LINUX
#pragma once
#endif
#ifndef _MToolsInfo
#define _MToolsInfo
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
// CLASS:    MToolsInfo
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MToolsInfo)
//
// MToolsInfo is a caretaker class used to keep track of
// the dirty state of the current tool property sheet.
// The tool writer should make sure to call the 
// setDirtyFlag method when any of the values are 
// modified.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES

#include <maya/MTypes.h>

// *****************************************************************************

// DECLARATIONS

class MStatus;
class MPxContext;

// CLASS DECLARATION (MToolsInfo)

/// Tool information (OpenMayaUI)
/**
MToolsInfo provides methods for keeping track of the 
state of the current tool property sheet.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32


class OPENMAYAUI_EXPORT MToolsInfo {
public:
	///	
	static void		setDirtyFlag(const MPxContext &context);
	///	
	static void		resetDirtyFlag();
	///
	static bool		isDirty();

private:
	static const char *className();
};


#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MToolsInfo */
