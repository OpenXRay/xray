
#ifndef _MFnExpression
#define _MFnExpression
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
// CLASS:    MFnExpression
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnExpression)
//
// Function set for expressions.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MFnDependencyNode.h>
#include <maya/MObject.h>
#include <maya/MString.h>

// *****************************************************************************

// DECLARATIONS

class MDoubleArray;
class MPtrBase;

// *****************************************************************************

// CLASS DECLARATION (MFnExpression)

/// expression function set
/**

*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MFnExpression : public MFnDependencyNode
{ 
	declareMFn( MFnExpression, MFnDependencyNode ); 

public:
	
	///
	enum UnitConversion {
		/// convert all units
		kAll,
		/// do not do any unit conversion
		kNone,
		/// only convert angular units
		kAngularOnly
	};

	///
	MObject  		create( const MString & expression,
							MObject & object = MObject::kNullObj,
							MStatus * ReturnStatus = NULL );

	///
	MStatus			getExpression( MString & expression );
	///
	MStatus			setExpression( MString & expression );

	///
	MStatus			getDefaultObject( MObject & object );
	///
	MStatus			setDefaultObject( MObject & object );
	///
	bool			isAnimated( MStatus * ReturnStatus = NULL );
	///
	MStatus			setAnimated( bool value = false );

	///
	MStatus			evaluate( MDoubleArray & result );

	///
	UnitConversion  unitConversion( MStatus * ReturnStatus = NULL ) const;
	///
	MStatus         setUnitConversion( UnitConversion conversion );
							

protected:
// No protected members

private:
// No private members

}; 

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

#endif /* __cplusplus */
#endif /* _MFnExpression */
