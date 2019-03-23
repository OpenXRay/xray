#ifndef LINUX
#pragma once
#endif
#ifndef _MPxDeformerNode
#define _MPxDeformerNode
//
// *****************************************************************************
//
// Copyright (C) 1998-2001 Alias|Wavefront Inc.
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
// CLASS:    MPxDeformerNode
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MPxDeformerNode)
// 
// MPxDeformerNode allows the creation of user-defined deformers.  A deformer
// is a node which takes any number of input geometries, deforms them and
// places the output into the output geometry attribute.
//
// For more information, please see the built-in documentation
// in MPxDeformerNode.cpp.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MStatus.h>
#include <maya/MTypes.h>
#include <maya/MObject.h>
#include <maya/MPxNode.h>


// *****************************************************************************

// DECLARATIONS

// *****************************************************************************

// CLASS DECLARATION (MPxDeformerNode)

class MItGeometry;
class MDagModifier;

/// Base class for user defined Deformers (OpenMayaAnim)
/**
  Create user defined Deformers.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYAANIM_EXPORT MPxDeformerNode : public MPxNode  
{
public:
    ///
	MPxDeformerNode();

    ///
	virtual ~MPxDeformerNode();

	///                     
	virtual MPxNode::Type type() const;

	// Methods to overload

	// deform is called by computePlug when an output geometry
	// value is evaluated
	//

	///
    virtual MStatus        deform(MDataBlock& block,
								  MItGeometry& iter,
								  const MMatrix& mat,
								  unsigned int multiIndex);

	// return the attribute that gets connected to the
	// deformer tool shape
	//
	///
	virtual MObject&    	accessoryAttribute() const;

	// called at creation time so that the node can create and attach any
	// that it needs in order to function
	//
	///
	virtual MStatus			accessoryNodeSetup(MDagModifier& cmd);

	// return the weight value for the given index pair
	//
	///
	float						weightValue( MDataBlock& mblock,
											 unsigned int multiIndex,
											 unsigned int wtIndex);
	
	// Inherited attributes
	/// input attribute, multi
	static MObject input;
	/// input geometry attribute
		static MObject inputGeom;
	/// input group id attribute
		static MObject groupId;
	/// geometry output attribute
	static MObject outputGeom;
	/// weight list attribute, multi
	static MObject weightList;
	/// weight attribute, multi
		static MObject weights;
	/// envelope attribute
	static MObject envelope;
protected:
// No protected members
	  
private:
	static void				initialSetup();
	static const char*	    className();



};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MPxNode */
