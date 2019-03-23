#ifndef LINUX
#pragma once
#endif
#ifndef _MPxNode
#define _MPxNode
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
// CLASS:    MPxNode
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MPxNode)
//
// MPxNode is the the parent class for user defined
// dependency nodes.  A dependency node is an object that resides in the 
// dependency graph.  It computes output attributes based on a set of input 
// attributes.  When an input changes, the compute method is called for each
// dependent output.
//
// The dependency graph is made up of nodes that have connections between  
// their attributes.  When an attribute changes, recomputation propagates
// through the graph until all affected values have been updated.
//
// When writing a dependency node, there is a very basic rule that should
// be observed.  The outputs should be calculated only using the values of
// the inputs.  All information about the world outside the node should 
// come from input attributes.  If this rule is not observed, then 
// the results may be unpredictable.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MStatus.h>
#include <maya/MTypes.h>
#include <maya/MObject.h>

#include <maya/MTypeId.h>
#include <maya/MDataHandle.h>
#include <maya/MDataBlock.h>
#include <maya/MPlug.h>
#include <maya/MString.h>
#include <maya/MDGContext.h>

// *****************************************************************************

// DECLARATIONS

// *****************************************************************************

// CLASS DECLARATION (MPxNode)

/// Base class for user defined dependency nodes
/**
  Create user defined dependency nodes.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MPxNode  
{
public:
    ///
	enum Type {
        ///
        kDependNode,
        ///
		kLocatorNode,
		///
		kDeformerNode,
		///
		kManipContainer,
		///
		kSurfaceShape,
		///
		kFieldNode,
		///
		kEmitterNode,
		///
		kSpringNode,
		///
		kIkSolverNode,
		///
		kHwShaderNode,
		///
		kTransformNode,
		///
		kLast
    }; 

    ///
	MPxNode();
    ///
	virtual ~MPxNode();
    ///
	virtual void			postConstructor();
    ///
	virtual MStatus			compute( const MPlug& plug,
									 MDataBlock& dataBlock );

	///
	virtual bool			getInternalValue( const MPlug&,
											  MDataHandle&);
	///
    virtual bool			setInternalValue( const MPlug&,
											  const MDataHandle&);
	
	///
    virtual void			copyInternalData( MPxNode* );
	
	///
	virtual MStatus			legalConnection( const MPlug& plug,
											 const MPlug& otherPlug,
											 bool asSrc,
											 bool& result ) const;
	///
	virtual MStatus			legalDisconnection( const MPlug& plug,
											 const MPlug& otherPlug,
											 bool asSrc,
											 bool& result ) const;
	///
	virtual MStatus			connectionMade( const MPlug& plug,
											 const MPlug& otherPlug,
											 bool asSrc );
	///
	virtual MStatus			connectionBroken( const MPlug& plug,
											 const MPlug& otherPlug,
											 bool asSrc );
    ///
	virtual MStatus			shouldSave( const MPlug& plug, bool& result );

    ///
	MTypeId					typeId() const;
    ///
	MString					typeName() const;
    ///
	MString					name() const; 
	///                     
	virtual Type            type() const;
	///                     
	virtual bool			isAbstractClass  () const;
	///
	MObject                 thisMObject() const;

	///
	static MStatus          addAttribute( const MObject & attr );
    ///
	static MStatus		    inheritAttributesFrom(
											const MString & parentClassName );
    ///
	static MStatus          attributeAffects( const MObject & whenChanges,
											  const MObject & isAffected );

	///
	MStatus					setExistWithoutInConnections( bool flag );
	///
	bool					existWithoutInConnections(
								MStatus* ReturnStatus = NULL ) const;
	///
	MStatus					setExistWithoutOutConnections( bool flag );
	///
	bool					existWithoutOutConnections(
								MStatus* ReturnStatus = NULL ) const;


	/// message attribute
	static MObject          message;
	/// is historically interesting attribute
	static MObject          isHistoricallyInteresting;
	/// caching attribute
	static MObject          caching;
	/// state attribute
	static MObject          state;

protected:
	///
	MDataBlock				forceCache( MDGContext& ctx=MDGContext::fsNormal );

	///
	void					setMPSafe ( bool flag );

	void*					instance;
	  
private:
	static void				initialSetup();
	static const char*	    className();



		// Please ignore
	static void*            initClass;
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MPxNode */
