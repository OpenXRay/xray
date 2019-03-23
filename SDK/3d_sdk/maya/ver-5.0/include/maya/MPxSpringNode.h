
#ifndef _MPxSpringNode
#define _MPxSpringNode
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
// CLASS:    MPxSpringNode
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MPxSpringNode)
//
// MPxSpringNode allows the creation and manipulation of dependency graph
// nodes representing springs.  This is the top level of a hierarchy of
// spring node function sets.  It permits manipulation of the attributes
// common to all types of springs.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MStatus.h>
#include <maya/MObject.h>
#include <maya/MPxNode.h>
#include <maya/MPointArray.h>
#include <maya/MVectorArray.h>
#include <maya/MDoubleArray.h>


// *****************************************************************************

// DECLARATIONS

// *****************************************************************************

// CLASS DECLARATION (MPxSpringNode)

/// Base class for user defined spring law (OpenMayaFX)
/**
*/


// Manage dependency graph nodes representing springs

#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYAFX_EXPORT MPxSpringNode : public MPxNode
{
public:
	///
	MPxSpringNode();
	///
	virtual ~MPxSpringNode();

	///
	virtual MPxNode::Type	type() const;

	///
	virtual MStatus	applySpringLaw( double stiffness,
						double damping, double restLength,
						double endMass1, double endMass2,
						const MVector &endP1, const MVector &endP2,
						const MVector &endV1, const MVector &endV2,
						MVector &forceV1, MVector &forceV2 );


	/////////////////////////
	// Inherited attributes
	/////////////////////////

	// General attributes for spring.
	//
	/// from end weight attribute
	static MObject	mEnd1Weight;
	/// to end weight attribute
	static MObject	mEnd2Weight;

	/// delta time attribute
	static MObject	mDeltaTime;

protected:
// No protected members

private:
// No private members

	static void			initialSetup();
	static const char*	className();

};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32


//****************************************************************************
#endif /* __cplusplus */
#endif /* _MPxSpringNode */

