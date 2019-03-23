
#ifndef _MRenderData
#define _MRenderData

//
// *****************************************************************************
//
// Copyright (C) 2000-2003 Alias|Wavefront Inc.
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
// CLASS:    MRenderData
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MRenderData)
//
// The rendered image and depth map can be changed following the software
// render by instanciating a MRenderCallback and overriding renderCallback()
// or postProcessCallback(). When these methods are invoked, a MRenderData is
// passed as an argument; the rgbaArr and depthArr can then be changed by this
// API. Methods and data are provided to assist in transforming back and forth
// from world space to image space. Paint Effects and Fur are two examples
// which use this mechanism to change the rendered image.
//
// *****************************************************************************

#if defined __cplusplus


#include <maya/MFloatVector.h>
#include <maya/MFloatPoint.h>
#include <maya/MFloatMatrix.h>

#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

/// Access Rendering Data (OpenMayaRender)
/**
*/
class OPENMAYARENDER_EXPORT MRenderData {
public:
	///
						MRenderData();

	///
    void                worldToScreen(
                            const MFloatPoint&  worldPoint,
                            MFloatPoint&        screenPoint) const;

	///
    void                screenToWorld(
                            const MFloatPoint& screenPoint,
                            MFloatPoint&        worldPoint) const;

    // in data
    /// set if the camera has a perspective projection
    bool                perspective;
    /// the x resolution of the rendered image
    unsigned short      resX;
    /// the y resolution of the rendered image
    unsigned short      resY;

    /// the left (low) render region dimension
    unsigned short      left;
    /// the bottom (low) render region dimension
    unsigned short      bottom;
    /// the right (high) render region dimension
    unsigned short      right;
    /// the top (high) render region dimension
    unsigned short      top;

    /// number of bytes per channel of the rgbaArr
    unsigned short      bytesPerChannel;
    /// the actual x resolution of rgbaArr and depthArr
    unsigned short      xsize;
    /// the actual y resolution of rgbaArr and depthArr
    unsigned short      ysize;

    /// camera horizontal field of view in radians
    float               fieldOfView;
    /// camera pixel aspect ratio
    float               aspectRatio;

    /// view direction of the camera (object space)
    MFloatVector        viewDirection;
    /// position of the camera (object space)
    MFloatPoint         eyePoint;
    /// camera matrix to transform to eye space
    MFloatMatrix        worldToEyeMatrix;

    /// this is a 1d array representing the output image buffer.
	/// It is of size: resX * resY * 4 * bytesPerChannel.  The
	/// array is indexed as [(resX * x + y) * 4 * bytesPerChannel],
	/// where (x,y) is the current pixel coordinates.  The "4"
	/// multiplier is used for storing RGBA information, in the
	/// order of a,b,g,r.
    unsigned char       *rgbaArr;
    /// this is a 1d array representing the output depth buffer.
	/// It is of size: resX * resY, where each depth value is a
	/// single precision floating point vlue.  It is indexed as
	/// [resX * x + y], where (x,y) is the current pixel coordinates.
    float               *depthArr;

    // private
    const void*         internalData;

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
#endif /* _MRenderData */

