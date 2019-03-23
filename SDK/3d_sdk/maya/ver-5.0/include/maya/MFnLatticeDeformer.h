
#ifndef _MFnLatticeDeformer
#define _MFnLatticeDeformer
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
// CLASS:    MFnLatticeDeformer
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnLatticeDeformer)
//
//	MFnLatticeDeformer is the function set for lattice deformers.  Lattice
//	deformers use FFDs to deform geometry.
//
//	The lattice deformer is actually a small network of dependency nodes in
//	the dependency graph.  This function set is provided to make
//	manipulation of the network easier.  The main deformer node should be
//	given to this function set as its object.
//
//	There are two lattices associated with a lattice deformer.  There is a
//	base lattice that defines the start position for the lattice.  The
//	second lattice is the version that is modified to deform the geometry.
//	The difference between the two lattices defines the deformation that is
//	applied to the geometry.
//
//	The base lattice is a very simple shape that only defines a box in
//	space.  The base lattice should be modified by using the standard DAG
//	transformation support.  The second deformable lattice has geometry
//	that can be modified using the MFnLattice function set.
//
//	For a piece of geometry to be modified by this deformer, the geometry
//	must be attached to the deformer (use addGeometry method) and the
//	geometry must be contained within the base lattice.  The resetLattice
//	method can be used to make the lattice resize to the bounding box of
//	the attached geometry.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MFnDependencyNode.h>

// *****************************************************************************

// DECLARATIONS
class MDagPath;
class MObjectArray;

// *****************************************************************************

// CLASS DECLARATION (MFnLatticeDeformer)

/// FFD lattice deformer function set (OpenMayaAnim)
/**
 Function set for FFD lattice deformer
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYAANIM_EXPORT MFnLatticeDeformer : public MFnDependencyNode
{

	declareMFn(MFnLatticeDeformer, MFnDependencyNode );

public:

	///
	MObject create( unsigned xDiv, unsigned yDiv, unsigned zDiv,
					MStatus * ReturnStatus = NULL );

	///
	MStatus addGeometry( const MObject & object );
	///
	MStatus removeGeometry( const MObject & object );

	///
	MStatus getAffectedGeometry( MObjectArray & objects );

	///
	MStatus getDivisions( unsigned & x, unsigned & y, unsigned & z );
	///
	MStatus setDivisions( unsigned   x, unsigned   y, unsigned   z );

	///
	MStatus resetLattice( bool centerLattice = false );

	///
	MObject deformLattice( MStatus * ReturnStatus = NULL );
	///
	MObject baseLattice( MStatus * ReturnStatus = NULL );

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
#endif /* _MFnLatticeDeformer */
