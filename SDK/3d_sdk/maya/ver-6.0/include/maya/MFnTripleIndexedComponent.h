
#ifndef _MFnTripleIndexedComponent
#define _MFnTripleIndexedComponent
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
// CLASS:    MFnTripleIndexedComponent
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnTripleIndexedComponent)
// 
//    This function set allows you to create, edit, and query triple indexed
//    components. Triple indexed components store 3 dimensional index
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

// CLASS DECLARATION (MFnTripleIndexedComponent)

/// Triple indexed component function set
/**
*/

#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MFnTripleIndexedComponent : public MFnComponent 
{

	declareMFn( MFnTripleIndexedComponent, MFnComponent );

public:

	// Create a triple indexed component of the given type.
	// Allowable types are
	//
	//    MFn::klatticeComponent
	//
	///
	MObject		create( MFn::Type compType, MStatus * ReturnStatus = NULL );

	///
    MStatus 	addElement( int sIndex, int tIndex, int uIndex );
	///
    MStatus 	addElements( const MIntArray& sIndexArray, 
							 const MIntArray& tIndexArray,
							 const MIntArray& uIndexArray );

	///
    MStatus		getElement( int index,
							int & sIndex, int & tIndex, int & uIndex ) const;
	///
    MStatus 	getElements( MIntArray& sIndexArray, 
							 MIntArray& tIndexArray,
							 MIntArray& uIndexArray ) const;

	///
	MStatus		setCompleteData( int maxS, int maxT, int maxU );
	///
	MStatus		getCompleteData( int & maxS, int & maxT, int & maxU ) const;
    
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
#endif /* _MFnTripleIndexedComponent */
