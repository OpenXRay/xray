
#ifndef _MFnTypedAttribute
#define _MFnTypedAttribute
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
// CLASS:    MFnTypedAttribute
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnTypedAttribute)
//
//  MFnAttribute is the function set for typed dependency node attributes.  A
//  typed attribute accepts exactly one type of data.  The type that it accepts
//  is set when the attribute is created.
//
//  Once a typed attribute had been created, the data for it can be accessed 
//  using an MDataHandle while in your node's compute method.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MFnAttribute.h>
#include <maya/MFnData.h>
#include <maya/MObject.h>

// *****************************************************************************

// DECLARATIONS

class MTypeId; 
class MString;

// *****************************************************************************

// CLASS DECLARATION (MFnTypedAttribute)

/// Typed attribute function set 
/**
 Function set for type attributes of dependency nodes.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MFnTypedAttribute : public MFnAttribute 
{

	declareMFn(MFnTypedAttribute, MFnAttribute);

public:
	///
	MObject 	create( const MString& fullName,
						const MString& briefName,
						const MTypeId& id,
						MObject defaultData = MObject::kNullObj,
						MStatus* ReturnStatus = NULL );
	///
	MObject 	create( const MString& fullName,
						const MString& briefName,
						MFnData::Type type,
						MObject defaultData = MObject::kNullObj,
						MStatus* ReturnStatus = NULL );
	///
	MFnData::Type	attrType ( MStatus* ReturnStatus = NULL ) const;
	///
	MStatus		getDefault( MObject & defaultCustomData );
	///
	MStatus		setDefault( const MObject & defaultCustomData );
	/// OBSOLETE
	MObject 	create( const MString& fullName,
						const MString& briefName,
						MFnData::Type type,
						MStatus* ReturnStatus );

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
#endif /* _MFnTypedAttribute */
