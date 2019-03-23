
#ifndef _MDataBlock
#define _MDataBlock
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
// CLASS:    MDataBlock
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MDataBlock)
//
//   An MDataBlock provides storage for the data being received by or sent by
//   the node.  It is the data for the plugs and attributes of the node.  The
//   data block is only valid during the compute method of the depend node,
//   and should not be stored.
//
//   Access to the data in an MDataBlock is done using an MDataHandle or an
//   MArrayDataHandle.
//  
//
// *****************************************************************************
#if defined __cplusplus
// *****************************************************************************

// INCLUDED HEADER FILES

#include <maya/MStatus.h>
#include <maya/MTypes.h>
#include <maya/MDataHandle.h>
#include <maya/MArrayDataHandle.h>

// *****************************************************************************
// FORWARD DECLARATIONS
class MObject;
class MPlug;
class MDGContext;
// *****************************************************************************

// CLASS DECLARATION (MDataBlock)

/// Dependency node data block
/**
  The storage for the data of all of a node's plugs and attributes.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MDataBlock  
{

public:

    ///
	virtual		     ~MDataBlock ();
    ///
	MDataHandle      inputValue ( const MPlug & plug, 
								        MStatus * ReturnStatus = NULL );
    ///
	MDataHandle      inputValue ( const MObject & attribute, 
								        MStatus * ReturnStatus = NULL ); 
    ///
	MDataHandle      outputValue ( const MPlug & plug, 
								        MStatus * ReturnStatus = NULL );
    ///
	MDataHandle      outputValue ( const MObject & attribute, 
								        MStatus * ReturnStatus = NULL );
    ///
	MArrayDataHandle inputArrayValue ( const MPlug & plug, 
								        MStatus * ReturnStatus = NULL );
    ///
	MArrayDataHandle inputArrayValue ( const MObject & attribute, 
								        MStatus * ReturnStatus = NULL );
    ///
	MArrayDataHandle outputArrayValue ( const MPlug & plug, 
										MStatus * ReturnStatus = NULL );
    ///
	MArrayDataHandle outputArrayValue ( const MObject & attribute, 
										MStatus * ReturnStatus = NULL );
    ///
	MStatus          setClean ( const MPlug & plug );
    ///
	MStatus          setClean ( const MObject & attribute );

    ///
	bool			isClean ( const MPlug & plug );
    ///
	bool			isClean ( const MObject & attribute, 
							  MStatus* ReturnStatus=NULL );

	///
	MDGContext       context ( MStatus * ReturnStatus = NULL );
	///
	MStatus          setContext ( const MDGContext & ctx );

protected:
// No protected members

private:
	const char*		 className() const;


	friend class MPxNode;
	MDataBlock( void * ptr ); 
	void * data;
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MDataBlock */
