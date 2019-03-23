
#ifndef _MFnDoubleIndexedComponent
#define _MFnDoubleIndexedComponent
//
// *****************************************************************************
//
// Copyright (C) 1998-2003 Alias|Wavefront Inc.
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
// CLASS:    MFnDoubleIndexedComponent
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnDoubleIndexedComponent)
// 
//    This function set allows you to create, edit, and query double indexed
//    components. Double indexed components store 2 dimensional index
//    values.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MFnBase.h>
#include <maya/MString.h>
#include <maya/MFnComponent.h>

// *****************************************************************************

// DECLARATIONS

class MIntArray;

// *****************************************************************************

// CLASS DECLARATION (MFnDoubleIndexedComponent)

/// Double indexed component function set
/**
*/

#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MFnDoubleIndexedComponent : public MFnComponent 
{

	declareMFn( MFnDoubleIndexedComponent, MFnComponent );

public:

	// Create a double indexed component of the given type.
	// Allowable types are
	//
	//    MFn::kSurfaceCVComponent
	//    MFn::kSurfaceEPComponent
	//    MFn::kSurfaceKnotComponent
	//
	///
	MObject		create( MFn::Type compType, MStatus * ReturnStatus = NULL );

	///
    MStatus 	addElement( int uIndex, int vIndex );
	///
    MStatus 	addElements( const MIntArray& uIndexArray, 
							 const MIntArray& vIndexArray );

	///
    MStatus		getElement( int index, int & uIndex, int & vIndex ) const;
	///
    MStatus 	getElements( MIntArray& uIndexArray, 
							 MIntArray& vIndexArray ) const;

	///
	MStatus		setCompleteData( int maxU, int maxV );
	///
	MStatus		getCompleteData( int & maxU, int & maxV ) const;
    
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
#endif /* _MFnDoubleIndexedComponent */
