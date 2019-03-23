#ifndef LINUX
#pragma once
#endif
#ifndef _MFnComponentListData
#define _MFnComponentListData
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
// CLASS:    MFnComponentListData
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnComponentListData)
//
// MFnComponentListData allows the creation and manipulation of component list
// (represented as MObjects) data objects for use in the dependency graph.
// 
// If a user written dependency node either accepts or produces MObjects
// containing component lists, then this class is used to extract or
// create the data that comes from or goes to other dependency graph
// nodes.  To access it, the MDataHandle::data method is used to get an
// MObject for the data and this should then be used to initialize an
// instance of MFnComponentListData.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES

#include <maya/MFnData.h>

// *****************************************************************************

// DECLARATIONS

// *****************************************************************************

// CLASS DECLARATION (MFnComponentListData)

/// Component list function set for dependency node data
/**
  Create and manipulate Component Lists dependency node data.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MFnComponentListData : public MFnData 
{

	declareMFn(MFnComponentListData, MFnData);

public:
	///
	unsigned		length( MStatus* ReturnStatus = NULL ) const;
	///
	bool			has( const MObject& obj,
						 MStatus* ReturnStatus = NULL ) const;
	///
	MObject			operator[]( unsigned index) const;
	///
	MStatus			add( MObject& );
	///
	MStatus			remove( const MObject& );
	///
	MStatus			remove( unsigned index );
	///
	MStatus			clear();
	///
	MObject			create( MStatus* ReturnStatus = NULL );

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
#endif /* _MFnComponentListData */
