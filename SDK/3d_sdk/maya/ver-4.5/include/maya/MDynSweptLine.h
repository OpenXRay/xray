#ifndef LINUX
#pragma once
#endif
#ifndef _MDynSweptLine
#define _MDynSweptLine
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
// CLASS:    MDynSweptLine
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MDynSweptLine)
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

// *****************************************************************************

// CLASS DECLARATION (MDynSweptLine)

/// Class for evaluating curve segments as lines over time. (OpenMayaFX)
/**
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYAFX_EXPORT MDynSweptLine  
{
public:
	///
					MDynSweptLine();
	///
					~MDynSweptLine();

	// Time-Dependent Access Methods
	//
	///
	MVector			vertex( int vertexId, double t = 1.0 );
	///
	MVector			normal( double x, double y, double z, double t = 1.0 );
	///
	MVector			tangent( double t = 1.0 );
	///
	double			length( double t = 1.0 );

protected:
// No protected members

private:


	static const char* className();
	MDynSweptLine( void* );
	void * fData;
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MDynSweptLine */
