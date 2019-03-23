#ifndef LINUX
#pragma once
#endif
#ifndef _MItInstancer
#define _MItInstancer
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
// CLASS:    MItInstancer
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MItInstancer)
//
// Use the particle instancer node iterator to traverse all instancer nodes in 
// Maya's Dependency Graph, and optionally 
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
#include <maya/MDagPath.h>
#include <maya/MMatrix.h>

// *****************************************************************************

// DECLARATIONS


// *****************************************************************************

// CLASS DECLARATION (MItInstancer)

/// Particle iterator.
/**

Iterate over all nodes in the dependency graph.

*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32


class OPENMAYA_EXPORT MItInstancer  
{
public:
    ///
				MItInstancer();
	///
	virtual		~MItInstancer();

    ///
	MStatus		reset();
	
	///
    MStatus		next();

	///
    MStatus   	nextParticle();

    ///
	MStatus		nextInstancer();

	///
    bool 		isDone() const;

	///
    MDagPath	path();

    ///
	MMatrix		matrix();

    ///
	int			 instancerId() const;

    ///
	unsigned int particleId() const;

    ///
	unsigned int pathId() const;

protected:
// No protected members

private:
	void *data;
	static const char* className();
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MItInstancer */
