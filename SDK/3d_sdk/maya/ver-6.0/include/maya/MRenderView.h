#ifndef _MRenderView
#define _MRenderView
//
//-
// ==========================================================================
// Copyright (C) Alias Systems Corp., and/or its licensors ("Alias").  
// All rights reserved.  These coded instructions, statements, computer  
// programs, and/or related material (collectively, the "Material")
// contain unpublished information proprietary to Alias, which is
// protected by Canadian and US federal copyright law and by international
// treaties. This Material may not be disclosed to third parties, or be copied
// or duplicated, in whole or in part, without the prior written consent of
// Alias.  ALIAS HEREBY DISCLAIMS ALL WARRANTIES RELATING TO THE MATERIAL,
// INCLUDING, WITHOUT LIMITATION, ANY AND ALL EXPRESS OR IMPLIED WARRANTIES OF
// NON-INFRINGEMENT, MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
// IN NO EVENT SHALL ALIAS BE LIABLE FOR ANY DAMAGES WHATSOEVER, WHETHER DIRECT,
// INDIRECT, SPECIAL, OR PUNITIVE, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE
// OR OTHER TORTIOUS ACTION, OR IN EQUITY, ARISING OUT OF OR RELATED TO THE
// ACCESS TO, USE OF, OR RELIANCE UPON THE MATERIAL.
// ==========================================================================
//+
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
								unsigned int height,
								bool doNotClearBackground = false,
								bool immediateFeedback = false );

	///
	static MStatus startRegionRender( unsigned int imageWidth, 
									  unsigned int imageHeight, 
									  unsigned int regionLeft, 
									  unsigned int regionRight, 
									  unsigned int regionBottom, 
									  unsigned int regionTop,
									  bool doNotClearBackground = false,
									  bool immediateFeedback = false );

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
