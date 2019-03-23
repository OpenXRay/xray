
#ifndef _MFnArrayAttrsData
#define _MFnArrayAttrsData
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
// CLASS:    MFnArrayAttrsData
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnArrayAttrsData)
//
// MFnArrayAttrsData allows the creation and manipulation of MVectorArray and
// MDoubleArray data objects for use in the dependency graph.  
//
// If a user written dependency node either accepts or produces MVectorArrays,
// then this class is used to extract or create the data that comes from or
// goes to other dependency graph nodes.  The MDataHandle::type method will
// return kVectorArray when data of this type is present.  To access it, the
// MDataHandle::data method is used to get an MObject for the data and this 
// should then be used to initialize an instance of MFnArrayAttrsData.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MFnData.h>

// *****************************************************************************

// DECLARATIONS

class MVectorArray;
class MDoubleArray;
class MIntArray;
class MStringArray;

// *****************************************************************************

// CLASS DECLARATION (MFnArrayAttrsData)

/// Function set for multiple arrays of attributes for dependency node data.
/**
  Function set for multiple arrays of attributes for dependency node data.

*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MFnArrayAttrsData : public MFnData 
{
	declareMFn( MFnArrayAttrsData, MFnData );

public:
	enum Type {
	/// 
	kInvalid,
	/// use vectorArray() method to extract the attribute array.
	kVectorArray,
	/// use doubleArray() method to extract the attribute array.
	kDoubleArray,
	/// use intArray() method to extract the attribute array.
	kIntArray,
	/// use stringArray() method to extract the attribute array.
	kStringArray,
	///
	kLast
	};

	///
	MStatus			clear();

	///
	unsigned		count() const;

	///
	MStringArray	list( MStatus *ReturnStatus = NULL) const;

	///
	bool			checkArrayExist( const MString attrName,
									 Type &arrayType,
									 MStatus *ReturnStatus = NULL);

	///
	MVectorArray	vectorArray( const MString attrName,
									MStatus *ReturnStatus = NULL );
	///
	MDoubleArray	doubleArray( const MString attrName,
									MStatus *ReturnStatus = NULL );
	///
	MIntArray		intArray( const MString attrName,
									MStatus *ReturnStatus = NULL );
	///
	MStringArray	stringArray( const MString attrName,
									MStatus *ReturnStatus = NULL );

	///
	MObject			create( MStatus *ReturnStatus = NULL );

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
#endif /* _MFnArrayAttrsData */
