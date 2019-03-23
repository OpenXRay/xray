#ifndef LINUX
#pragma once
#endif
#ifndef _MRenderView
#define _MRenderView
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
// CLASS:    MRenderView
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MRenderView)
//
// MRenderView is a class which provides access to the Maya Render View window.
// It allows plugins to send image data to the window in the same way that the
// Maya renderer does.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************
// INCLUDED HEADER FILES

#include <maya/MDagPath.h>

// *****************************************************************************
// DECLARATIONS

// Declaration of the pixel data type.  Each channel must be a floating point
// value in the range 0 to 255.0.
//
typedef struct RV_PIXEL {
    float    r;
    float    g;
    float    b; 
    float    a;
} RV_PIXEL;


// *****************************************************************************
// CLASS DECLARATION (MRenderView)

/// Static class providing Render View API functions (OpenMayaRender)
/**
*/
class OPENMAYARENDER_EXPORT MRenderView
{
public:

	///
	static bool doesRenderEditorExist();

	///
	static MStatus setCurrentCamera( MDagPath& camera );

	///
	static MStatus getRenderRegion( unsigned int& left, 
 									unsigned int& right, 
									unsigned int& bottom, 
									unsigned int& top );

	///
	static MStatus startRender( unsigned int width, 
								unsigned int height );

	///
	static MStatus startRegionRender( unsigned int imageWidth, 
									  unsigned int imageHeight, 
									  unsigned int regionLeft, 
									  unsigned int regionRight, 
									  unsigned int regionBottom, 
									  unsigned int regionTop );

	///
	static MStatus updatePixels( unsigned int left, 
								 unsigned int right, 
								 unsigned int bottom, 
								 unsigned int top, 
								 RV_PIXEL* pPixels );

	///
	static MStatus refresh( unsigned int left, 
							unsigned int right, 
							unsigned int bottom, 
							unsigned int top );

	///
	static MStatus endRender();

private:

	// for API error reporting
	static const char *className() { return "MRenderView"; };

};

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MRenderView */
