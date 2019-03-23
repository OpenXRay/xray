#ifndef LINUX
#pragma once
#endif
#ifndef _MFnMatrixData
#define _MFnMatrixData
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
// CLASS:    MFnMatrixData
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnMatrixData)
//
// MFnMatrixData allows the creation and manipulation of MMatrix data objects
// for use in the dependency graph.
//
// If a user written dependency node either accepts or produces MMatrix, then
// this class is used to extract or create the data that comes from or goes to
// other dependency graph nodes. The MDataHandle::type method will return
// kMatrix when data of this type is present. To access it, the
// MDataHandle::data method is used to get an MObject for the data and this
// should then be used to initialize an instance of MFnMatrixData.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES

#include <maya/MFnData.h>

// *****************************************************************************

// DECLARATIONS

class MMatrix;
class MTransformationMatrix;

// *****************************************************************************

// CLASS DECLARATION (MFnMatrixData)

/// Matrix function set for dependency node data
/**
  Create and manipulate MMatrix dependency node data
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MFnMatrixData : public MFnData 
{

	declareMFn(MFnMatrixData, MFnData);

public:
	///
	bool					isTransformation(
										MStatus* ReturnStatus = NULL ) const;
	///
	MTransformationMatrix	transformation(
										MStatus* ReturnStatus = NULL ) const;
	///
	const MMatrix&			matrix( MStatus* ReturnStatus = NULL ) const;
	///
	MStatus					set( const MTransformationMatrix& transformation );
	///
	MStatus					set( const MMatrix& matrix );
	///
	MObject					create( MStatus* ReturnStatus=NULL );
	///
	MObject					create( const MMatrix&,
									MStatus* ReturnStatus=NULL );
	///
	MObject					create( const MTransformationMatrix&,
									MStatus* ReturnStatus=NULL );

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
#endif /* _MFnMatrixData */
