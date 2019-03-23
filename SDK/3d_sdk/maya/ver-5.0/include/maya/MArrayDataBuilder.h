
#ifndef _MArrayDataBuilder
#define _MArrayDataBuilder
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
// CLASS:    MArrayDataBuilder
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MArrayDataBuilder)
//
//  An MArrayDataBuilder is used to construct data for attributes/plugs that 
//  have an array of data.  An array builder is used with an MArrayDataHandle
//  for managing data.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES



#include <maya/MStatus.h>
#include <maya/MTypes.h>
#include <maya/MDataHandle.h>
#include <maya/MArrayDataHandle.h>

// *****************************************************************************

// FORWARD DECLARATIONS

// *****************************************************************************

// CLASS DECLARATION (MArrayDataBuilder)

/// Array builder for arrays in data blocks
/**
 An MArrayDataBuilder is used to build array data for attributes/plugs
 that support arrays.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MArrayDataBuilder  
{

public:
    ///
	MArrayDataBuilder ( const MObject & attribute, unsigned numElements,
						MStatus * ReturnStatus = NULL );
    ///
	MDataHandle      addLast(MStatus * ReturnStatus = NULL);
    ///
	MDataHandle      addElement( unsigned index,
								 MStatus * ReturnStatus = NULL );
    ///
	MArrayDataHandle addLastArray(MStatus * ReturnStatus = NULL );
    ///
	MArrayDataHandle addElementArray( unsigned index,
									  MStatus * ReturnStatus = NULL  );
    /// 
	MStatus          removeElement( unsigned index );
    /// 
	unsigned         elementCount( MStatus * ReturnStatus = NULL ) const;
    /// 
	MStatus          growArray( unsigned amount );
    ///
	MStatus          setGrowSize( unsigned size );

    ///
    MArrayDataBuilder( const MArrayDataBuilder &other );
	///
	MArrayDataBuilder& operator=( const MArrayDataBuilder& other );
	///
    ~MArrayDataBuilder();

protected:
// No protected members

private: 
	const char*		className() const;
	friend class MArrayDataHandle;
	MArrayDataBuilder();
	MArrayDataBuilder( void* );
	char data[24];
	bool fIsNull;
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MArrayDataBuilder */
