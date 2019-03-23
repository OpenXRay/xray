#ifndef LINUX
#pragma once
#endif
#ifndef _MItSelectionList
#define _MItSelectionList
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
// CLASS:    MItSelectionList
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MItSelectionList)
//
// Class for iterating over the items in an MSelection list.
// A filter can be specified so that only those items of interest on a selection
// list can be obtained.
// 
// If a filter is specified then the children of DAG selection items will be
// searched if the selection item does not match the filter.
// For example, if filter = MFn::kNurbsCurve and a transform is selected
// then the underlying shape for the transform will be in the iteration if it
// is a nurbs curve.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MStatus.h>
#include <maya/MObject.h>
#include <maya/MSelectionList.h>
#include <maya/MStringArray.h>

// *****************************************************************************

// DECLARATIONS

class MDagPath;

// *****************************************************************************

// CLASS DECLARATION (MItSelectionList)

/// Iterate over the items in the selection list.
/**
  Class for iterating over the items in an MSelection list.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MItSelectionList
{
public:
    ///
	enum selItemType{
        ///
		kUnknownItem = -1,
        ///
		kDagSelectionItem,
        ///
		kAnimSelectionItem,
        ///
		kDNselectionItem
	};
    ///
	bool		isDone( MStatus * ReturnStatus = NULL ); 
    ///
	MStatus		next(); 
    ///
	MStatus		reset();
    ///
	MStatus		getDependNode( MObject &depNode );
    ///
	MStatus		getDagPath( MDagPath &dagPath, MObject &component );
	///
	MStatus     getDagPath( MDagPath &dagPath );
	///
	MStatus     getStrings( MStringArray & array );
    ///
	selItemType itemType( MStatus * ReturnStatus = NULL ); 
    ///
	MStatus		setFilter( MFn::Type filter );
	///
	bool		hasComponents( MStatus * ReturnStatus = NULL ) const;
    ///
	MItSelectionList( 	const MSelectionList & list, 
						MFn::Type = MFn::kInvalid,
						MStatus * ReturnStatus = NULL );
    ///
	virtual ~MItSelectionList();
protected:
// No protected members

private:
	static const char* 	className();
	MStatus				resetInner();
	void*				f_main_iter;
	void*				f_component_iter;
	void*				list_data;
	MFn::Type			f_filter;
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MItSelectionList */
