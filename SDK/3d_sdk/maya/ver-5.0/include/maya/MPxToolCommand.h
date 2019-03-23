
#ifndef _MPxToolCommand
#define _MPxToolCommand
//
// *****************************************************************************
//
// Copyright (C) 1997-2003 Alias|Wavefront Inc.
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
// CLASS:    MPxToolCommand
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MPxToolCommand)
//
// This is the base class for interactive tool commands.
//
// An interactive tool command is a command that can be invoked as a MEL command
// or from within a user defined context (see MPxContext).
//
// Tool commands have the same functionality as MPxCommands, but include several
// additional methods for use in interactive contexts:  cancel, finalize
// and doFinalize.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES



#include <maya/MStatus.h>
#include <maya/MTypes.h>
#include <maya/MPxCommand.h>

// *****************************************************************************

// DECLARATIONS

class MString;
class MFileObject;
class MArgList;

// *****************************************************************************

// CLASS DECLARATION (MPxToolCommand)

/// Base class for interactive tool commands (OpenMayaUI)
/**
  The base class for interactive tool commands
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYAUI_EXPORT MPxToolCommand : public MPxCommand
{
public:
	///
	MPxToolCommand(); // Called within a context

	///
	virtual ~MPxToolCommand();

	// The following are the methods for interactive use of a
    // MPxToolCommand object
	///
    virtual MStatus 	cancel();
	///
	virtual MStatus 	finalize();

protected:
	///
	MStatus				doFinalize( MArgList & command );

private:
// No private members
	virtual const char*	className() const;

};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MPxToolCommand */

