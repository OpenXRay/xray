#ifndef LINUX
#pragma once
#endif
#ifndef _MIkSystem
#define _MIkSystem
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
// CLASS:    MIkSystem
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MIkSystem)
//
//  This class provides an interface to the inverse kinematics (IK) system.
//  The ik system is used to set/query the global snapping flag for handles,
//  set/query the global solve flag for solvers, and to find the ik solvers
//  available in maya.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MObject.h>
#include <maya/MStringArray.h>
#include <maya/MStatus.h>

// *****************************************************************************

// DECLARATIONS

// *****************************************************************************

// CLASS DECLARATION (MIkSystem)

/// Inverse kinematics (IK) system class (OpenMayaAnim)
/**
 
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYAANIM_EXPORT MIkSystem  
{

public:
	///
	static MObject	findSolver( MString name, MStatus * ReturnStatus = NULL );
	///
	static MStatus	getSolvers( MStringArray & names );
	///
	static bool		isGlobalSnap( MStatus * ReturnStatus = NULL );
	///
	static MStatus	setGlobalSnap( bool isSnap );
	///
	static bool		isGlobalSolve( MStatus * ReturnStatus = NULL );
	///
	static MStatus	setGlobalSolve( bool isSnap );
protected:
	static const char* className();

private:
// No private members

};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MIkSystem */
