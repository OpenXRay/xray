
#ifndef _MArrayDataHandle
#define _MArrayDataHandle
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
// CLASS:    MArrayDataHandle
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MArrayDataHandle)
//
//	An MArrayDataHandle is a smart pointer into a data block (MDataBlock) that 
//  handles access to array data.  MArrayDataHandle supports attributes that
//  can have an array of data.
//
//  The array indices do not have to be continuous.  The array can be sparse.
//  Thus, an array could have four elements with the indicies 1, 6, 8, and 10.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MStatus.h>
#include <maya/MTypes.h>
#include <string.h>
#include <maya/MArrayDataBuilder.h>
#include <maya/MDataHandle.h>
#include <maya/MArrayDataHandle.h>

// *****************************************************************************
// FORWARD DECLARATIONS
class MArrayDataBuilder;
// *****************************************************************************

// CLASS DECLARATION (MArrayDataHandle)

/// Data block handle for array data
/**
  An MArrayDataHandle is a smart pointer into an MDataBlock that
  handles array data.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MArrayDataHandle {

public:
	///
	MArrayDataHandle( const MDataHandle & in, MStatus * ReturnStatus = NULL );

	///
	MDataHandle       inputValue(MStatus *ReturnStatus = NULL);
	///
	MDataHandle       outputValue(MStatus *ReturnStatus = NULL);
	///
	MArrayDataHandle  inputArrayValue( MStatus * ReturnStatus = NULL );
	///
	MArrayDataHandle  outputArrayValue( MStatus * ReturnStatus = NULL );
	///
    MStatus           next();
	///
	unsigned          elementCount(MStatus *ReturnStatus = NULL);
	///
	unsigned          elementIndex(MStatus *ReturnStatus = NULL);
	///
    MStatus           jumpToElement( unsigned index ); 
	/// 
    MStatus           setClean();
	/// 
    MStatus           setAllClean();
	///
	MArrayDataBuilder builder(MStatus *ReturnStatus = NULL);
	///
	MStatus           set( MArrayDataBuilder & );

	///
    MArrayDataHandle( const MArrayDataHandle &other );
	///
	MArrayDataHandle& operator=( const MArrayDataHandle& other );

protected:
// No protected members

private:
	const char*		className() const;
	friend class MDataBlock;
	friend class MArrayDataBuilder;
	MArrayDataHandle( void* );
	MArrayDataHandle();
	char data[20];
	bool fIsNull;
};

inline MArrayDataHandle::MArrayDataHandle( const MArrayDataHandle &other )
{
	memcpy( this, &other, sizeof(MArrayDataHandle) ); 
}

inline MArrayDataHandle& MArrayDataHandle::operator=(
											const MArrayDataHandle &other )
{
	memcpy( this, &other, sizeof(MArrayDataHandle) ); 
	return *this;
}

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MArrayDataHandle */
