
#ifndef _MFnVectorArrayData
#define _MFnVectorArrayData
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
// CLASS:    MFnVectorArrayData
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnVectorArrayData)
//
// MFnVectorArrayData allows the creation and manipulation of MVectorArray data
// objects for use in the dependency graph.  
//
// If a user written dependency node either accepts or produces MVectorArrays,
// then this class is used to extract or create the data that comes from or
// goes to other dependency graph nodes.  The MDataHandle::type method will
// return kVectorArray when data of this type is present.  To access it, the
// MDataHandle::data method is used to get an MObject for the data and this 
// should then be used to initialize an instance of MFnVectorArrayData.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MFnData.h>

// *****************************************************************************

// DECLARATIONS

class MVectorArray;
class MVector;

// *****************************************************************************

// CLASS DECLARATION (MFnVectorArrayData)

/// int array function set for dependency node data
/**
  Create and manipulate MVectorArray dependency node data.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MFnVectorArrayData : public MFnData 
{

	declareMFn(MFnVectorArrayData, MFnData);

public:
	///
	unsigned		length( MStatus* ReturnStatus = NULL ) const;
	///
	const MVector&  operator[]( unsigned index ) const;
	///
	MVector&	    operator[]( unsigned index );
	///
	MStatus			copyTo( MVectorArray& ) const;
	///
	MStatus			set( const MVectorArray& newArray );
	///
	MVectorArray	array( MStatus*ReturnStatus=NULL );
	///
	MObject			create( MStatus*ReturnStatus=NULL );
	///
	MObject			create( const MVectorArray& in, MStatus*ReturnStatus=NULL );

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
#endif /* _MFnVectorArrayData */
