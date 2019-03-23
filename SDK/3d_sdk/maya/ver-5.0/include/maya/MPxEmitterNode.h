
#ifndef _MPxEmitterNode
#define _MPxEmitterNode
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
// CLASS:    MPxEmitterNode
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MPxEmitterNode)
//
// MPxEmitterNode allows the creation and manipulation of dependency graph
// nodes representing emitters.  This is the top level of a hierarchy of
// emitter node function sets.  It permits manipulation of the attributes
// common to all types of emitters.
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

// CLASS DECLARATION (MPxEmitterNode)

/// Base class for user defined particle emitters (OpenMayaFX)
/**
*/

#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32


class OPENMAYAFX_EXPORT MPxEmitterNode : public MPxNode
{
public:
	///
	MPxEmitterNode();
	///
	virtual ~MPxEmitterNode();
	///
	virtual MPxNode::Type	type() const;
	///
	virtual MStatus			compute(const MPlug& plug, MDataBlock& dataBlock);


	/////////////////////////
	// Inherited attributes
	/////////////////////////

	// General attributes for every emitter.
	//
	/// rate attribute
	static MObject	mRate;
	/// speed attribute
	static MObject	mSpeed;
	/// direction attribute
	static MObject	mDirection;
	/// X component of mDirection
	static MObject	mDirectionX;
	/// Y component of mDirection
	static MObject	mDirectionY;
	/// Z component of mDirection
	static MObject	mDirectionZ;

	// Attributes for ownership.
	// Connections made with the owner object.
	//
	/// owner postion attribute, multi
	static MObject	mOwnerPosData;
	/// owner velocity attribute, multi
	static MObject	mOwnerVelData;
	/// owner centroid attribute
	static MObject	mOwnerCentroid;
	/// X component of mOwnerCentroid
	static MObject	mOwnerCentroidX;
	/// Y component of mOwnerCentroid
	static MObject	mOwnerCentroidY;
	/// Z component of mOwnerCentroid
	static MObject	mOwnerCentroidZ;

	/// input swept geometry attribute
	static MObject	mSweptGeometry;

	/// world matrix attribute
	static MObject	mWorldMatrix;

	// Attributes for target particle object.
	// Connections with the target particle object.
	//
	/// start time attribute
	static MObject	mStartTime;
	/// delta time attribute
	static MObject	mDeltaTime;
	/// flag for maximum count attribute
	static MObject	mIsFull;
	/// inherit factor attribute
	static MObject	mInheritFactor;
	/// random seed attribute
	static MObject	mSeed;

	// Current time attribute.
	// Connection with time node.
	//
	/// current time attribute
	static MObject	mCurrentTime;

	// Output Attribute.
	// Connection with the target particle object.
	//
	/// output particle attribute, multi
	static MObject mOutput;

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
#endif /* _MPxEmitterNode */

