#ifndef LINUX
#pragma once
#endif
#ifndef _MRenderShadowData
#define _MRenderShadowData

//
// *****************************************************************************
//
// Copyright (C) 2000-2001 Alias|Wavefront Inc.
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
// CLASS:    MRenderShadowData
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MRenderShadowData)
//
// The shadow map can be changed by instanciating a MRenderCallback and
// overriding shadowCastCallback(). When this is invoked, a MRenderShadowData
// is passed as an argument; the depthMaps and midDistMaps members can then
// be changed by this API. Methods and data are provided to assist in
// transforming back and forth from world space to z buffer space. Paint
// Effects and Fur are two examples which use this mechanism to change the
// shadow map.
//
// To prevent self shadowing, Maya uses a mid distance map to resolve the
// ambiguity. Details of this technique can be obtained from Graphics Gems
// III, "The Shadow Depth Map Revisited".
//
// *****************************************************************************

#if defined __cplusplus

#include <maya/MFloatPoint.h>
#include <maya/MFloatMatrix.h>

/// Access Rendering Data (OpenMayaRender)
/**
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

/// Access Rendering Shadow Map Data (OpenMayaRender)
/**
*/
class OPENMAYARENDER_EXPORT MRenderShadowData {
public:
	///
						MRenderShadowData();

	///
    void                worldToZbuffer(
                            const MFloatPoint&  worldPoint,
                            MFloatPoint&        screenPoint) const;

	///
    void                zbufferToWorld(
                            const MFloatPoint& screenPoint,
                            MFloatPoint&        worldPoint) const;

    // in data
	/// set if the light has a perspective projection
    bool                perspective;
	/// set if the light generates a depth and midDist map
    bool                useMidDistMap;

    /// Light Types
    enum LightType
    {
        ///
        kInvalid,
		///
        kPoint,
		///
        kDirectional,
		///
        kSpot
    };

	/// the type of light the shadow map is generated for
    LightType           lightType;

	/// the x resolution of shadow map
    unsigned short      shadowResX;
	/// the y resolution of the shadow map
    unsigned short      shadowResY;
	/// position of the light in world space
    MFloatPoint         lightPosition;
	/// projection matrix for the light
    MFloatMatrix        projectionMatrix;
	/// perspective matrix for the light
    MFloatMatrix        perspectiveMatrix;
	///

    // out data
	/// the output depth map
    float               *depthMaps;
	/// the output mid distance map
    float               *midDistMaps;

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
#endif /* _MRenderShadowData */

