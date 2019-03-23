
#ifndef _MFnComponent
#define _MFnComponent
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
// CLASS:    MFnComponent
//
//    This is the base class for all function sets which deal with
//    component objects.
//
//    Components are MObjects which hold index information for shapes.
//    The component object does not contain any information about the
//    shape, it just contains index values and type information.
//
//    Components can be marked as complete meaning that the component
//    represents a complete set of indices from 0 to numElements-1;
//
//    Components come is 3 varieties based upon the dimensions of the
//    index. The types are single, double, and triple indexed.
//    Examples of these types are mesh vertices (single indexed),
//    nurbs surface CVs (double indexed), and lattice points (triple indexed).
//
//    To create, edit, or query a specific type of component, use the
//    derived classes MFnSingleIndexedComponent, MFnDoubleIndexedComponent,
//    and MFnTripleIndexedComponent.
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnComponent)
// 
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MFnBase.h>
#include <maya/MString.h>

// *****************************************************************************

// DECLARATIONS

class MIntArray;

// *****************************************************************************

// CLASS DECLARATION (MFnComponent)

/// Base class for component function sets
/**
*/

#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MFnComponent : public MFnBase 
{

	declareMFnNoConstructor( MFnComponent, MFnBase );

public:
	///
	MFnComponent();
    ///
	int        elementCount( MStatus* ReturnStatus = NULL ); 
	///
	MFn::Type	type( MStatus * ReturnStatus = NULL );
	///
	bool		isEmpty( MStatus * ReturnStatus = NULL ) const;
	///
	bool		isEqual( MObject &, MStatus * ReturnStatus = NULL ) const;
	///
	bool		isComplete( MStatus * ReturnStatus = NULL ) const;
	///
	MStatus		setComplete( bool );
    
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
#endif /* _MFnComponent */
