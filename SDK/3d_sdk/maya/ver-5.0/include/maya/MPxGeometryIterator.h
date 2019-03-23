
#ifndef _MPxGeometryIterator
#define _MPxGeometryIterator
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
// CLASS:    MPxGeometryIterator
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MPxGeometryIterator)
//
//  This is the base class for user defined geometry iterators.
//  Geometry iterator allow iterating over components in geometry
//  in a geometry independent manner. This base class defines
//  the interface to be used maya when a generic component iteration
//  is required.
//
//  This class is used in conjunction with MPxSurfaceShape to provide
//  an iterator for components in a user defined shape.
//  The main methods to override in this class are point and set point.
//  The reset, isDone, and next methods have a default implementation
//  and should only be overridden if the component being iterator on
//  is not a single indexed component type.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES



#include <maya/MStatus.h>
#include <maya/MTypes.h>
#include <maya/MObject.h>

// *****************************************************************************

// DECLARATIONS
 
class MPxSurfaceShape;
class MPoint;
class MObjectArray;

// *****************************************************************************

// CLASS DECLARATION (MPxGeometryIterator)

/// the base class for user defined geometry iterators
/**
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MPxGeometryIterator
{
public:
    ///
	MPxGeometryIterator( void * userGeometry, MObjectArray & components );
	///
	MPxGeometryIterator( void * userGeometry, MObject & components );
    ///
	virtual ~MPxGeometryIterator();

	/////////////////////////////////////////////////////////////////////////
	// Methods to overload

	// Item by item traversal methods
	//
	///
	virtual bool			isDone() const;
	///
	virtual void			next();
	///
	virtual void			reset();

	// component for Item 
	///
	virtual void			component( MObject &component );

	// Item's point info access methods
	//
	///
	virtual bool			hasPoints() const;
	///
	virtual int				iteratorCount() const;
	///
	virtual MPoint			point() const;
	///
	virtual void			setPoint( const MPoint & ) const;
	///
	virtual int				setPointGetNext( MPoint & );
	///
	virtual int				index() const;


	///
	virtual bool			hasNormals() const;

	///
	virtual int				indexUnsimplified() const;

	////////////////////////////////////////////////////////////////////////

	// Methods to access the iterator values.
	// These values are used when iterating over all components
	// of a shape when there are no components specified.
	///
	int						currentPoint() const;
	///
	void					setCurrentPoint( int );
	///
	int						maxPoints() const;
	///
	void					setMaxPoints( int );

		

	//	Method to (optionally) set object (to allow tweaking of history)
	//
	///
	void					setObject( MPxSurfaceShape & );

	///
	void*					geometry() const;
	
protected:
	  
private:
	static const char*	    className();
	void * instance;
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MPxGeometryIterator */
