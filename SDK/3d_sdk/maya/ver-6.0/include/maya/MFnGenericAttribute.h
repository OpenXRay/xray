
#ifndef _MFnGenericAttribute
#define _MFnGenericAttribute
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
// CLASS:    MFnGenericAttribute
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnGenericAttribute)
// 
// MFnGenericAttribute is a function set for attributes that can accept
// several types of data.  A generic attribute is similar to a typed
// attribute (MFnTypedAttribute) except that it has a list of types that
// it considers valid.
// 
// If the attribute will only take one type of data then it is more
// efficient to use one of the other attribute function sets such as
// MFnTypedAttribute or MFnNumericAttribute.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MFnAttribute.h>
#include <maya/MFnData.h>
#include <maya/MFnNumericData.h>
class MTypeId;
class MString;

// *****************************************************************************

// DECLARATIONS

// *****************************************************************************

// CLASS DECLARATION (MFnGenericAttribute)

/// Generic attribute function set
/**
  Function set for generic attributes of a dependency node
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MFnGenericAttribute : public MFnAttribute 
{

	declareMFn(MFnGenericAttribute, MFnAttribute);

public:
    ///
	MObject 	create( const MString& full,
						const MString& brief,
						MStatus* ReturnStatus = NULL );
    ///
	MStatus		addAccept( MFnData::Type newType );
    ///
	MStatus		addAccept( MFnNumericData::Type newType );
    ///
	MStatus		addAccept( const MTypeId& id );
    ///
	MStatus		removeAccept( MFnData::Type oldType );
    ///
	MStatus		removeAccept( MFnNumericData::Type oldType );
    ///
	MStatus		removeAccept( const MTypeId& id );

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
#endif /* _MFnGenericAttribute */
