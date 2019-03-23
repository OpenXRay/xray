
#ifndef _MIkSystem
#define _MIkSystem
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
