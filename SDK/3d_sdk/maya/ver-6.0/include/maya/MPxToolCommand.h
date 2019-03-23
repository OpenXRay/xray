
#ifndef _MPxToolCommand
#define _MPxToolCommand
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

