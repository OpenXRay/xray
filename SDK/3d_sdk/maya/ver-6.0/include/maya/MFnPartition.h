
#ifndef _MFnPartition
#define _MFnPartition
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
// CLASS:    MFnPartition
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnPartition)
//
// MFnPartition is the function partition that is used for manipulating
// partitions of objects.  Partitions in Maya are dependency nodes, so it
// is possible for one partition to contain others.
// 
// A partition is a list of dependency nodes and dag nodes.  Partitions
// are useful for keeping track of lists of objects for many purposes such
// as selection or applying common rendering parameters.  Partitions in
// Maya are also dependency nodes, so it is possible for one partition to
// contain others..
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MFnDependencyNode.h>
#include <maya/MString.h>
#include <maya/MObject.h>

// *****************************************************************************

// DECLARATIONS
 
class MObjectArray;
class MSelectionList;
class MDagPath;


// *****************************************************************************

// CLASS DECLARATION (MFnPartition)

/// Function Partition for Partitions of Objects
/**
    Function partition for partitions of objects
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MFnPartition : public MFnDependencyNode 
{

	declareMFn(MFnPartition, MFnDependencyNode);

public:
	
	///
	enum Restriction { 
		///
		kNone,
		///
		kVerticesOnly,
		///
		kEdgesOnly,
		///
		kFacetsOnly,
		///
		kEditPointsOnly,
		///
		kRenderableOnly
	};

	///
	MObject     create( bool isRenderPartition = false,
						MStatus * ReturnStatus = NULL );
	///
	bool        isRenderPartition( MStatus * ReturnStatus = NULL ) const;
	///
	MStatus     addMember( const MObject &set );
	///
	MStatus     removeMember( const MObject &set );

protected:
// No protected members

private:
// No private members

};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MFnPartition */
