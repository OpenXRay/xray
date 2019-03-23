#ifndef _MDGModifier
#define _MDGModifier
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
// CLASS:    MDGModifier
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MDGModifier)
//
// An MDGModifier is used to change the structure of the dependency graph.  This
// includes adding nodes, making new connections, and removing existing
// connections.  An MDGModifier keeps track of all operations that it is
// used for, so that they can be undone or redone.  Calling undo causes an
// MDGModifier to undo all of the dependency graph changes that it has
// done.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES



#include <maya/MStatus.h>
#include <maya/MFnDependencyNode.h>

// *****************************************************************************

// DECLARATIONS

class MObject;
class MPlug;
class MTypeId;
class MString;

// *****************************************************************************

// CLASS DECLARATION (MDGModifier)

/// Dependency graph modifier
/**
  A class that is used to modify the dependency graph and also supports undo 
*/
#if defined(_WIN32)
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MDGModifier  
{
public:
    ///
	MDGModifier();
    ///
	virtual ~MDGModifier();    
    
    ///
    MObject     createNode( const MTypeId &typeId,
                            MStatus* ReturnStatus = NULL );
    ///
    MObject     createNode( const MString &type,
                            MStatus* ReturnStatus = NULL );
    /// 
    MStatus     deleteNode( const MObject & node );
    
    ///
    MStatus     renameNode( const MObject & node, const MString &newName );

	///
	MStatus		setNodeLockState( const MObject & node, bool newState ); 

    ///
	MStatus		connect(	const MObject & sourceNode,
							const MObject & sourceAttr,
							const MObject & destNode,	
							const MObject & destAttr );
    ///
	MStatus		disconnect(	const MObject & sourceNode,
							const MObject & sourceAttr,
							const MObject & destNode,
							const MObject & destAttr );
    ///
	MStatus		connect(	const MPlug& source, const MPlug& dest );
    ///
	MStatus		disconnect(	const MPlug& source, const MPlug& dest );

	///
    MStatus     addAttribute( const MObject& node, const MObject& attribute,
							  MFnDependencyNode::MAttrClass type 
									= MFnDependencyNode::kLocalDynamicAttr );
    ///
    MStatus     removeAttribute( const MObject& node, const MObject& attribute,
								 MFnDependencyNode::MAttrClass type 
									= MFnDependencyNode::kLocalDynamicAttr  );

    ///
	MStatus		commandToExecute( const MString& command );
    ///
	MStatus		doIt();
    ///
	MStatus		undoIt();


protected:
    MDGModifier( void * );
	MDGModifier( const MDGModifier & other );
	MDGModifier&	operator =( const MDGModifier & rhs );
	void*		  data;
	bool		  fOwn;

private:
	static const  char*	className();
};

#if defined(_WIN32)
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MDGModifier */
