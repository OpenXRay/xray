
#ifndef _MIkHandleGroup
#define _MIkHandleGroup
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
// CLASS:    MIkHandleGroup
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MIkHandleGroup)
//
//
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES



#include <maya/MTypes.h>
#include <maya/MObject.h>

// *****************************************************************************

// DECLARATIONS

// *****************************************************************************

// CLASS DECLARATION (MIkHandleGroup)

/// IK handle groups (OpenMayaAnim)
/**
  Ik handle group class.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYAANIM_EXPORT MIkHandleGroup
{
public:
 	///
					MIkHandleGroup();
 	///
					~MIkHandleGroup();

	///
	int			priority(MStatus *ReturnStatus = NULL) const;
	///
	int			solverID(MStatus *ReturnStatus = NULL) const;
	///
	int			solverPriority(MStatus *ReturnStatus = NULL) const;
	///
	MStatus			setPriority( int );
	///
	MStatus			setSolverID( int );
	///
	bool			checkEffectorAtGoal(MStatus *ReturnStatus = NULL);
	///
	MStatus			solve();


	///
	int 			dofCount(MStatus *ReturnStatus = NULL) const;
	///
	int				handleCount(MStatus *ReturnStatus = NULL) const;
	///
	MObject			handle( int ith, MStatus *ReturnStatus = NULL );



protected:
// No protected members

private:
	friend class MPxIkSolver;
	friend class MPxIkSolverNode;
	static const char* className();
	MIkHandleGroup( void * );
 	void * f_data;
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MIkHandleGroup */
