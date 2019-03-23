#ifndef LINUX
#pragma once
#endif
#ifndef _MFnSingleIndexedComponent
#define _MFnSingleIndexedComponent
//
// *****************************************************************************
//
// Copyright (C) 1998-2001 Alias|Wavefront Inc.
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
// CLASS:    MFnSingleIndexedComponent
//
//    This function set allows you to create, edit, and query single indexed
//    components. Single indexed components store 1 dimensional index
//    values.
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnSingleIndexedComponent)
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

// CLASS DECLARATION (MFnSingleIndexedComponent)

/// Single indexed component function set
/**
*/

#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MFnSingleIndexedComponent : public MFnComponent 
{

	declareMFn( MFnSingleIndexedComponent, MFnComponent );

public:

	// Create a single indexed component of the given type.
	// Allowable types are
	//
	//    MFn::kCurveCVComponent
	//    MFn::kCurveEPComponent
	//    MFn::kCurveKnotComponent
	//    MFn::kMeshEdgeComponent
	//    MFn::kMeshPolygonComponent
	//    MFn::kMeshVertComponent
	//	  MFn::kMeshMapComponent
	//
	///
	MObject		create( MFn::Type compType, MStatus * ReturnStatus = NULL );

	///
    MStatus 	addElement( int element );
	///
    MStatus 	addElements( MIntArray& elements );

	///
    int			element( int index, MStatus * ReturnStatus = NULL ) const;
	///
    MStatus		getElements( MIntArray& elements ) const;

	///
	MStatus		setCompleteData( int numElements );
	///
	MStatus		getCompleteData( int & numElements ) const;

    
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
#endif /* _MFnSingleIndexedComponent */
