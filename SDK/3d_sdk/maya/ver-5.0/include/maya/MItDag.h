
#ifndef _MItDag
#define _MItDag
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
// CLASS:    MItDag
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MItDag)
//
// Use the DAG iterator to traverse the DAG either depth first or breadth
// first, visiting each node and, if desired, retrieving the node (as an
// MObject).  The DAG iterator provides a basic filtering capability, so
// that DAG node retrieval can be limited to a  specific type (MFn::Type)
// of node.  With filtering enabled the iterator checks to see if the node
// is compatible with the type of Function Set specified by the filter.
// See MFn::Type for a list of all valid Function set types.
// 
// Since each object, if retrieved, is returned as an MObject, the
// MObject::hasFn() method can be used to further check for compatible
// function set types since an MObjects may be compatible with more than
// one function set).
// 
// Any compatible Function Set can be attached to the retrieved object to
// query or or edit it.  Often you will want to use the DAG node Function
// Set (MFnDagNode), which is compatible with all DAG objects, to perform
// basic queries on each node as the iterator traverses the DAG.
// 
// The iterator also provides the capability to reset the root of the
// iteration, the type of traversal, and the filter.
// 
// Additionally, the iterator can be queried for the root, mode and type
// of traversal, and to determine if the the traversal has been completed.
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

// CLASS DECLARATION (MItDag)

/// DAG Iterator
/**

Class MItDag provides the capability to traverse the DAG and to retrieve
specific nodes for subsequent querying and editing using compatible
Function Sets.

*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MItDag  
{
public:
    /// Secondary Direction of Traversal (Vertical or Horizontal)
	enum TraversalType {
        ///
		kInvalidType = 0,
        ///
		kDepthFirst,
        ///
		kBreadthFirst
	};
    ///
	MItDag( TraversalType = kDepthFirst,
			MFn::Type = MFn::kInvalid,
			MStatus * ReturnStatus = NULL );
    ///
	MStatus       reset();
    ///
	MStatus       reset( const MObject & object,
						 TraversalType = kDepthFirst,
						 MFn::Type = MFn::kInvalid );
    ///
	MStatus       reset( const MDagPath & path,
						 TraversalType = kDepthFirst,
						 MFn::Type = MFn::kInvalid );
						 
    ///
	MObject       item( MStatus * ReturnStatus = NULL );
    ///
	MStatus       next();
						
    ///
	MStatus       prune();
    ///
	bool          isDone( MStatus * ReturnStatus = NULL ) const; 
    ///
	MObject       root( MStatus * ReturnStatus = NULL ); 
    ///
	unsigned      depth( MStatus * ReturnStatus = NULL ) const; 
    ///
	TraversalType getType( MStatus * ReturnStatus = NULL ) const; 

	///
	MStatus       getPath( MDagPath& path ) const;
	///
	MStatus       getAllPaths( MDagPathArray& paths ) const;
    ///
	MString       fullPathName(MStatus *ReturnStatus = NULL) const;
    ///
    MString       partialPathName(MStatus *ReturnStatus = NULL) const;
	///
	bool          isInstanced( bool indirect = true,
                               MStatus * ReturnStatus = NULL ) const;
	///
	unsigned int  instanceCount( bool total,
				                 MStatus * ReturnStatus = NULL ) const;
	///
	MStatus	      traverseUnderWorld( bool flag );
	///
	bool          willTraverseUnderWorld( MStatus * ReturnStatus = NULL ) const;

	///
	virtual ~MItDag();

protected:
// No protected members

private:
	static const char* className();
	void*		iterator_data;
	MFn::Type	type_filter;
    bool        df;
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MItDag */
