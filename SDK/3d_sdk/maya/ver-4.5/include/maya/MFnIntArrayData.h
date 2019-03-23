#ifndef LINUX
#pragma once
#endif
#ifndef _MFnIntArrayData
#define _MFnIntArrayData
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
// CLASS:    MFnIntArrayData
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnIntArrayData)
//
// MFnIntArrayData allows the creation and manipulation of MIntArray data
// objects for use in the dependency graph.  
//
// If a user written dependency node either accepts or produces MIntArrays,
// then this class is used to extract or create the data that comes from or
// goes to other dependency graph nodes.  The MDataHandle::type method will
// return kIntArray when data of this type is present.  To access it, the
// MDataHandle::data method is used to get an MObject for the data and this 
// should then be used to initialize an instance of MFnIntArrayData.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES

#include <maya/MFnData.h>

// *****************************************************************************

// DECLARATIONS

class MIntArray;

// *****************************************************************************

// CLASS DECLARATION (MFnIntArrayData)

/// int array function set for dependency node data
/**
  Create and manipulate MIntArray dependency node data.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MFnIntArrayData : public MFnData 
{

	declareMFn(MFnIntArrayData, MFnData);

public:
	///
	unsigned		length( MStatus* ReturnStatus = NULL ) const;
	///
	int             operator[]( unsigned index ) const;
	///
	int&	        operator[]( unsigned index );
	///
	MStatus			copyTo( MIntArray& ) const;
	///
	MStatus			set( const MIntArray& newArray );
	///
	MIntArray	    array( MStatus*ReturnStatus=NULL );
	///
	MObject			create( MStatus*ReturnStatus=NULL );
	///
	MObject			create( const MIntArray& in, MStatus*ReturnStatus=NULL );

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
#endif /* _MFnIntArrayData */
