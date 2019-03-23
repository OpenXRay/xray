
#ifndef _MFnSingleIndexedComponent
#define _MFnSingleIndexedComponent
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
