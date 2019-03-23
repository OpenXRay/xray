
#ifndef _MFnStringData
#define _MFnStringData
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
// CLASS:    MFnStringData
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnStringData)
//
// MFnStringData allows the creation and manipulation of MString data objects
// for use in the dependency graph.
// 
// If a user written dependency node either accepts or produces MString, then
// this class is used to extract or create the data that comes from or goes to
// other dependency graph nodes. The MDataHandle::type method will return
// kStringData when data of this type is present. To access it, the
// MDataHandle::data method is used to get an MObject for the data and this
// should then be used to initialize an instance of MFnStringData.
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

// CLASS DECLARATION (MFnStringData)

/// String function set for dependency node data
/**
  Create and manipulate MString dependency node data
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MFnStringData : public MFnData 
{

	declareMFn(MFnStringData, MFnData);

public:
	///
	MString			string( MStatus* ReturnStatus = NULL ) const;
	///
	MStatus			set( const MString& newString );
	///
	MObject			create( const MString& str, MStatus* ReturnStatus = NULL );
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
#endif /* _MFnStringData */
