
#ifndef _MItGeometry
#define _MItGeometry
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
// CLASS:    MItGeometry
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MItGeometry)
//
//	This class is the iterator class for iterating over the points/CVs/vertices
//  of a geometry.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MObject.h>

// *****************************************************************************

// DECLARATIONS

class MPoint;
class MDataHandle;
class MDagPath;

// *****************************************************************************

// CLASS DECLARATION (MItGeometry)

/// Iterator class for geometry data.

/**
  Iterate over points/CV's/vertices of a geometry shape such as a mesh,
  nurbs surface, nurbs curve, subdivision surface or lattice.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MItGeometry
{
public:
	///
	MItGeometry( const MDagPath& dagPath,
				 MStatus * ReturnStatus = NULL);
    ///
    MItGeometry( const MDagPath& dagPath,
                 MObject & component,
                 MStatus * ReturnStatus = NULL );
    ///
    MItGeometry( MObject& dagObject,
                 MStatus * ReturnStatus = NULL );
    ///
    MItGeometry( MDataHandle& dataHandle,
                 unsigned int groupId,
                 bool readOnly = true,
                 MStatus * ReturnStatus = NULL );
    ///
    MItGeometry( MDataHandle& dataHandle,
                 bool readOnly = true,
                 MStatus * ReturnStatus = NULL );
    ///
    virtual ~MItGeometry();
    ///
    bool        isDone( MStatus * ReturnStatus = NULL ) const;
    ///
    MStatus     next();
    ///
    MPoint      position( MSpace::Space space = MSpace::kObject,
                          MStatus * ReturnStatus = NULL ) const;
    ///
    MStatus     setPosition( const MPoint& point,
                             MSpace::Space space = MSpace::kObject  );
    ///
    int	    index( MStatus * ReturnStatus = NULL ) const;
	///
	MObject		component( MStatus * ReturnStatus = NULL ) const;
	///
	int		count( MStatus * ReturnStatus = NULL ) const;
	///
	MStatus		reset( );

protected:
// No protected members

private:
	// internal : called by the dataHandle constructors to set up the iterator
	//
	void 		createIterator(MDataHandle& dataHandle,
							   bool useComponents,
							   void* comps = NULL,
							   unsigned int groupId = 0,
							   bool readOnly = true,
							   MStatus* status = NULL);
	
private:
	void *      f_it;
    void *      f_path;
    void *      f_matrix;
    void *      f_clist;
	bool        f_readOnly;
	bool        f_own;
    
    static const char* className();    
	MItGeometry( void * ptr );
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MItGeometry */
