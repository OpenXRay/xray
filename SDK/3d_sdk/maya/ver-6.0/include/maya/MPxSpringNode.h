
#ifndef _MPxSpringNode
#define _MPxSpringNode
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

