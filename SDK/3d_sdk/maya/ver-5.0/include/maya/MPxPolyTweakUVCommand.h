#ifndef _MPxPolyTweakUVCommand
#define _MPxPolyTweakUVCommand
//
// ****************************************************************************
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
// ****************************************************************************
//
// CLASS:    MPxPolyTweakUVCommand
//
// ****************************************************************************
//
// CLASS DESCRIPTION (MPxPolyTweakUVCommand)
//
//  This is the command base class used for moving polygon UV's.
//
// ****************************************************************************

#if defined __cplusplus

// ****************************************************************************

// INCLUDED HEADER FILES

#include <maya/MTypes.h>
#include <maya/MStatus.h>
#include <maya/MPxCommand.h>

// ****************************************************************************

// DECLARATIONS

class MPxContext;
class MArgParser;
class MArgDatabase;
class MIntArray;
class MFloatArray;
class MFnMesh;

// ****************************************************************************

// CLASS DECLARATION (MPxPolyTweakUVCommand)

/// Base class used for moving polygon UV's (OpenMaya)

#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MPxPolyTweakUVCommand : public MPxCommand
{
public:
	///
							MPxPolyTweakUVCommand ();
	///
	virtual					~MPxPolyTweakUVCommand ();
	///
	virtual MStatus			parseSyntax (MArgDatabase &argData);
	///
	virtual MStatus			getTweakedUVs (const MFnMesh & mesh,
										   MIntArray & uvList,
										   MFloatArray & uPos,
										   MFloatArray & vPos);
	///
	static MSyntax			newSyntax ();

private:

	virtual MStatus			doIt(const class MArgList &);
	virtual MStatus			undoIt();
	virtual MStatus			redoIt();
	virtual bool			isUndoable() const;

	void * fData;
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// ****************************************************************************
#endif /* __cplusplus */
#endif /* _MPxPolyTweakUVCommand */
