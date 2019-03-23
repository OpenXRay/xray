#ifndef LINUX
#pragma once
#endif
#ifndef _MFnIkHandle
#define _MFnIkHandle
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
// CLASS:    MFnIkHandle
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnIkHandle)
//
//  This is the function set for inverse kinematics (IK) handles.
//  An ik handle specifies the joints in a skeleton that are effected
//  by an attached ik solver.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES

#include <maya/MFnTransform.h>
#include <maya/MObject.h>

// *****************************************************************************

// DECLARATIONS
 
class MObjectArray;

// *****************************************************************************

// CLASS DECLARATION (MFnIkHandle)

/// Function set for inverse kinematics (IK) handles (OpenMayaAnim)
/**

*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYAANIM_EXPORT MFnIkHandle : public MFnTransform 
{
	declareDagMFn( MFnIkHandle, MFn::kHandle );

public:
    ///
	enum Stickiness {
        ///
		kStickyOff,
        ///
		kStickyOn,
        ///
		kSuperSticky,
    };
    ///
	MObject   create( MDagPath& startJoint,
	                  MDagPath& effector,
					  MStatus * ReturnStatus = NULL );
    ///
	MStatus   getStartJoint( MDagPath &jointPath );
    ///
	MStatus   setStartJoint( const MDagPath &jointPath );
    ///
	MStatus   getEffector( MDagPath &effectorPath );
    ///
	MStatus   setEffector( const MDagPath &effectorPath );
    ///
	MStatus   setStartJointAndEffector( const MDagPath &jointPath,
										const MDagPath &effectorPath );
    ///
	unsigned  priority( MStatus * ReturnStatus = NULL );
    ///
	MStatus   setPriority( unsigned priority ); 
    ///
	Stickiness stickiness( MStatus * ReturnStatus = NULL );
    ///
	MStatus   setStickiness( Stickiness stickiness );
    ///
	double    weight( MStatus * ReturnStatus = NULL );
    ///
	MStatus   setWeight( double weight );
    ///
	double    poWeight( MStatus * ReturnStatus = NULL );
    ///
	MStatus   setPOWeight( double weight );
    ///
	MObject   solver( MStatus * ReturnStatus = NULL );
    ///
	MStatus   setSolver( const MObject &solver );
    ///
	MStatus   setSolver( const MString & solverName );

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
#endif /* _MFnIkHandle */
