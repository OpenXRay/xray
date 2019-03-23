#ifndef LINUX
#pragma once
#endif
#ifndef _MDynSweptTriangle
#define _MDynSweptTriangle
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
// CLASS:    MDynSweptTriangle
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MDynSweptTriangle)
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MStatus.h>
#include <maya/MTypes.h>

// *****************************************************************************

// DECLARATIONS

class MVector;
class MPoint;

// *****************************************************************************

// CLASS DECLARATION (MDynSweptTriangle)

/// Class for evaluating surfaces as triangles over time. (OpenMayaFX)
/**
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYAFX_EXPORT MDynSweptTriangle  
{
public:
	///
					MDynSweptTriangle();
	///
					~MDynSweptTriangle();

	// Time-Dependent Access Methods
	//
	//
	///
	MVector			vertex( int vertexId, double t = 1.0 );

	///
	MVector			normal( double t = 1.0 );

	///
	MVector 		normalToPoint(double x, double y, double z, double t = 1.0);

	// Non-Time-Dependent Access Method
	//
	//
	///
	MVector			uvPoint( int vertexId );

protected:
// No protected members

private:


	static const char* className();
	MDynSweptTriangle( void* );
	void * fData;
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MDynSweptTriangle */
