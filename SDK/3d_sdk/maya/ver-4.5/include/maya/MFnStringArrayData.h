#ifndef LINUX
#pragma once
#endif
#ifndef _MFnStringArrayData
#define _MFnStringArrayData
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
// CLASS:    MFnStringArrayData
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnStringArrayData)
//
// MFnStringArrayData allows the creation and manipulation of MStringArray data
// objects for use in the dependency graph.  
//
// If a user written dependency node either accepts or produces MStringArrays,
// then this class is used to extract or create the data that comes from or
// goes to other dependency graph nodes.  The MDataHandle::type method will
// return kStringArray when data of this type is present.  To access it, the
// MDataHandle::data method is used to get an MObject for the data and this 
// should then be used to initialize an instance of MFnStringArrayData.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES

#include <maya/MFnData.h>

// *****************************************************************************

// DECLARATIONS

class MString;
class MStringArray;

// *****************************************************************************

// CLASS DECLARATION (MFnStringArrayData)

/// string array function set for dependency node data
/**
  Create and manipulate MStringArray dependency node data.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MFnStringArrayData : public MFnData 
{

	declareMFn(MFnStringArrayData, MFnData);

public:
	///
	unsigned		length( MStatus* ReturnStatus = NULL ) const;
	///
	const MString&	operator[]( unsigned index ) const;
	///
	MString&	    operator[]( unsigned index );
	///
	MStatus			copyTo( MStringArray& ) const;
	///
	MStatus			set( const MStringArray& newArray );
	///
	MStringArray	array( MStatus*ReturnStatus=NULL );
	///
	MObject			create( MStatus*ReturnStatus=NULL );
	///
	MObject			create( const MStringArray& in, MStatus*ReturnStatus=NULL );

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
#endif /* _MFnStringArrayData */
