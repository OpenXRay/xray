#ifndef LINUX
#pragma once
#endif
#ifndef _MFnExpression
#define _MFnExpression
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
