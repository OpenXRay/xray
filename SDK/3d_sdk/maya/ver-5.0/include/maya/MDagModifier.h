
#ifndef _MDagModifier
#define _MDagModifier
//
// *****************************************************************************
//
// Copyright (C) 1998-2003 Alias|Wavefront Inc.
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
// CLASS:    MDagModifier
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MDagModifier)
//
// An MDagModifier is used to change the structure DAG.  This
// includes adding nodes, making new connections, and removing existing
// connections.  An MDagModifier keeps track of all operations that it is
// used for, so that they can be undone or redone.  Calling undo causes an
// MDagModifier to undo all of the dependency graph changes that it has
// done.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES



#include <maya/MStatus.h>
#include <maya/MFnDependencyNode.h>
#include <maya/MDGModifier.h>
#include <maya/MObject.h>

// *****************************************************************************

// DECLARATIONS

// *****************************************************************************

// CLASS DECLARATION (MDagModifier)

/// Dependency graph modifier
/**
  A class that is used to modify the DAG and also supports undo 
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MDagModifier : public MDGModifier
{
public:
    ///
	MDagModifier();
    ///
	~MDagModifier();
    
    ///
    MObject     createNode(     const MTypeId &typeId, 
                                const MObject & parent =  MObject::kNullObj,
                                MStatus* ReturnStatus = NULL );
    ///
    MObject     createNode(     const MString &type,
                                const MObject & parent =  MObject::kNullObj,
                                MStatus* ReturnStatus = NULL );
    ///
    MStatus     reparentNode(   const MObject & node, 
                                const MObject & newParent = MObject::kNullObj );
 

protected:
	MDagModifier(void*);
	MDagModifier( const MDagModifier & other );
	MDagModifier&	operator =( const MDagModifier & rhs );

private:
	static const  char*	className();
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MDagModifier */
