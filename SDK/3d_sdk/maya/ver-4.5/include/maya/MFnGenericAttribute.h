#ifndef LINUX
#pragma once
#endif
#ifndef _MFnGenericAttribute
#define _MFnGenericAttribute
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
