
#ifndef _MFnWireDeformer
#define _MFnWireDeformer
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
// CLASS:    MFnWireDeformer
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnWireDeformer)
//
// MFnWireDeformer is the function set for wire deformers.  Wire deformers
// modify geometry based on its proximity to controlling wire curves.  As
// the wire curves are modified, the parts of the geometry close to the
// curve will follow.
//
// The wire deformer is actually a small network of dependency nodes in
// the dependency graph.  This function set is provided to make
// manipulation of the network easier.  The main deformer node should be
// given to this function set as its object.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MFnDependencyNode.h>
#include <maya/MPoint.h>
// *****************************************************************************

// DECLARATIONS
class MDagPath;
class MObjectArray;

// *****************************************************************************

// CLASS DECLARATION (MFnWireDeformer)

/// wire deformer function set (OpenMayaAnim)
/**
 Function set for wire deformer
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYAANIM_EXPORT MFnWireDeformer : public MFnDependencyNode
{

	declareMFn(MFnWireDeformer, MFnDependencyNode );

public:

	///
	MObject  create( MStatus * ReturnStatus = NULL );


	///
	MStatus addGeometry( const MObject & object );
	///
	MStatus removeGeometry( const MObject & object );
	///
	MStatus getAffectedGeometry( MObjectArray & objects );

	///
	unsigned numWires( MStatus * ReturnStatus = NULL ) const;
	///
	MStatus  addWire( const MObject & object );
	///
	MObject  wire( unsigned wireIndex, MStatus * ReturnStatus = NULL );
	///
	float    wireDropOffDistance( unsigned wireIndex,
								  MStatus * ReturnStatus = NULL ) const;
	///
	MStatus  setWireDropOffDistance( unsigned wireIndex, float dropOff );
	///
	float    wireScale( unsigned wireIndex,
								  MStatus * ReturnStatus = NULL ) const;
	///
	MStatus  setWireScale( unsigned wireIndex, float scale );
	///
	MObject  holdingShape( unsigned wireIndex,
						          MStatus * ReturnStatus = NULL ) const;
	///
	MStatus  setHoldingShape( unsigned wireIndex, MObject holdingCurve );

	///
	float    envelope( MStatus * ReturnStatus = NULL ) const;
	///
	MStatus  setEnvelope( float envelope );
	///
	float    rotation( MStatus * ReturnStatus = NULL ) const;
	///
	MStatus  setRotation( float rotation );
	///
	float    localIntensity( MStatus * ReturnStatus = NULL ) const;
	///
	MStatus  setLocalIntensity( float localIntensity );
	///
	float    crossingEffect( MStatus * ReturnStatus = NULL ) const;
	///
	MStatus  setCrossingEffect( float crossingEffect );

	///
	unsigned numDropoffLocators( unsigned wireIndex,
								 MStatus * ReturnStatus = NULL ) const;
	///
	MStatus  setDropoffLocator( unsigned wireIndex, unsigned locatorIndex,
						         float param, float percentage );
	///
	MStatus  getDropoffLocator( unsigned wireIndex, unsigned locatorIndex,
						         float &param, float &percentage );
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
#endif /* _MFnWireDeformer */
