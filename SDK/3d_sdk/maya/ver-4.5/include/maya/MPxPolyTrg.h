#ifndef LINUX
#pragma once
#endif
#ifndef _MPxPolyTrg
#define _MPxPolyTrg
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
// CLASS:    MPxPolyTrg
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MPxPolyTrg)
//
//     The parent class for user defined poly triangulation nodes.  
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES

#include <maya/MPxNode.h>
#include <maya/MStatus.h>

// *****************************************************************************

// DECLARATIONS

// *****************************************************************************

// CLASS DECLARATION (MPxPolyTrg)

/// User defined poly triangulation support.
/**

*/

// Base class for user defined face triangulation for polygons. 
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MPxPolyTrg : public MPxNode 
{
public:

    ///
	MPxPolyTrg();
    ///
	virtual ~MPxPolyTrg();
	
    ///
	virtual void		postConstructor();
    ///
	virtual MStatus		compute( const MPlug& plug,
								 MDataBlock& dataBlock );
	///                     
	virtual bool		isAbstractClass() const;


	// Type for the signature of the triangulate function
	/// 
	typedef void (*polyTrgFnct)( const float *vert,
								 const float *norm,
								 const int   *loopSizes, 
								 const int nbLoop, 
								 const int nbTrg, unsigned short *trg );

	///
	MStatus				registerTrgFunction( char *name, polyTrgFnct f );
	///
	MStatus				unregisterTrgFunction( char *name );

private:

};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MPxPolyTrg */
