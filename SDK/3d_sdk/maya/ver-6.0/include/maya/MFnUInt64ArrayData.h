
#ifndef _MFnUInt64ArrayData
#define _MFnUInt64ArrayData
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
// CLASS:    MFnUInt64ArrayData
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnUInt64ArrayData)
//
// MFnUInt64ArrayData allows the creation and manipulation of MUint64Array data
// objects for use in the dependency graph.  
//
// If a user written dependency node either accepts or produces MUint64Arrays,
// then this class is used to extract or create the data that comes from or
// goes to other dependency graph nodes.  The MDataHandle::type method will
// return kUInt64ArrayData when data of this type is present.  To access it,
// the MDataHandle::data method is used to get an MObject for the data and
// this should then be used to initialize an instance of MFnUInt64ArrayData.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MFnData.h>

// *****************************************************************************

// DECLARATIONS

class MUint64Array;

// *****************************************************************************

// CLASS DECLARATION (MFnUInt64ArrayData)

/// MUint64 array function set for dependency node data
/**
  Create and manipulate MUint64Array dependency node data.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MFnUInt64ArrayData : public MFnData 
{

	declareMFn(MFnUInt64ArrayData, MFnData);

public:
	///
	unsigned		length( MStatus* ReturnStatus = NULL ) const;
	///
	MUint64          operator[]( unsigned index ) const;
	///
	MUint64&	        operator[]( unsigned index );
	///
	MStatus			copyTo( MUint64Array& ) const;
	///
	MStatus			set( const MUint64Array& newArray );
	///
	MUint64Array	array( MStatus*ReturnStatus=NULL );
	///
	MObject			create( MStatus*ReturnStatus=NULL );
	///
	MObject			create( const MUint64Array& in, MStatus*ReturnStatus=NULL );

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
#endif /* _MFnUInt64ArrayData */
