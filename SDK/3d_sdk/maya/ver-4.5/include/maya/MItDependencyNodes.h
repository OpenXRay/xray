#ifndef LINUX
#pragma once
#endif
#ifndef _MItDependencyNodes
#define _MItDependencyNodes
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
// CLASS:    MItDependencyNodes
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MItDependencyNodes)
//
// Use the dependency node iterator to traverse all the nodes in Maya's
// Dependency Graph.
// 
// With filtering enabled, the iterator checks to see if the node is
// compatible with the type specified by the filter.  See MFn::Type for a
// list of all valid types.
// 
// Since MObjects may be compatible with more than one type (nodes are
// organised in a hierarchy) the MObject::hasFn() method can be used to
// further check for compatible types.
// 
// Any compatible Function Set can be attached to the retrieved object to
// query or or edit it.  Often you will want to use the dependency node
// function set (MFnDependencyNode), which is compatible with all
// dependency nodes, to perform queries on each node as the iterator
// Traverses the Dependency Graph.
// 
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES

#include <maya/MObject.h>
#include <maya/MStatus.h>

// *****************************************************************************

// DECLARATIONS

class MDagPath;
class MDagPathArray;
class MString;

// *****************************************************************************

// CLASS DECLARATION (MItDependencyNodes)

/// Dependency Node iterator
/**

Iterate over all nodes in the dependency graph.

*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MItDependencyNodes  
{
public:
    ///
				MItDependencyNodes( MFn::Type filter = MFn::kInvalid,
									MStatus * ReturnStatus = NULL );
	///
	virtual		~MItDependencyNodes();

    ///
	MStatus		reset( MFn::Type filter = MFn::kInvalid );
						 
    ///
	MObject		item( MStatus * ReturnStatus = NULL ) const;
    ///
	MStatus		next();
						
    ///
	bool		isDone( MStatus * ReturnStatus = NULL ) const; 


protected:
// No protected members

private:
	static const char* className();
	void*		f_data;
	MFn::Type	f_filter;
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MItDependencyNodes */
