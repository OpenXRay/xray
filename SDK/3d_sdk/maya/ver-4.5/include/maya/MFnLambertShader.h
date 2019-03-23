#ifndef LINUX
#pragma once
#endif
#ifndef _MFnLambertShader
#define _MFnLambertShader
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
// CLASS:    MFnLambertShader
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnLambertShader)
//
// MFnLambertShader facilitates creation and manipulation of dependency graph
// nodes representing lambertian shaders.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES

#include <maya/MObject.h>
#include <maya/MStatus.h>
#include <maya/MFnDependencyNode.h>
// *****************************************************************************

// DECLARATIONS

class MFnDependencyNode;
class MFltVector;
class MColor;

// *****************************************************************************

// CLASS DECLARATION (MFnLambertShader)

/// Manage Lambert shaders
/**
  Facilitate the creation and manipulation of Lambert shaders.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MFnLambertShader : public MFnDependencyNode
{

	declareMFn( MFnLambertShader, MFnDependencyNode );

public:
	///
	MObject     create( bool UIvisible = true, MStatus * ReturnStatus = NULL );
	///
	short       refractedRayDepthLimit( MStatus * ReturnStatus = NULL ) const;
	///
	MStatus     setRefractedRayDepthLimit( const short& new_limit );
	///
	float       refractiveIndex( MStatus * ReturnStatus = NULL ) const;
	///
	MStatus     setRefractiveIndex( const float& refractive_index );
	///
	bool        rtRefractedColor( MStatus * ReturnStatus = NULL ) const;
	///
	MStatus     setRtRefractedColor( const bool& rt_refracted_color );
	///
	float       diffuseCoeff( MStatus * ReturnStatus = NULL ) const;
	///
	MStatus     setDiffuseCoeff( const float& diffuse_coeff );
	///
	MColor      color( MStatus * ReturnStatus = NULL ) const;
	///
	MStatus     setColor( const MColor & col );
	///
	MColor      transparency( MStatus * ReturnStatus = NULL ) const;
	///
	MStatus     setTransparency( const MColor & transp );
	///
	MColor      ambientColor( MStatus * ReturnStatus = NULL ) const;
	///
	MStatus     setAmbientColor( const MColor & ambient_color );
	///
	MColor      incandescence( MStatus * ReturnStatus = NULL ) const;
	///
	MStatus     setIncandescence( const MColor & incand );
	///
	float       translucenceCoeff( MStatus * ReturnStatus = NULL ) const;
	///
	MStatus     setTranslucenceCoeff( const float& translucence_coeff );
	///
	float       glowIntensity( MStatus * ReturnStatus = NULL ) const;
	///
	MStatus     setGlowIntensity( const float& glow_intensity );
	///
	bool        hideSource( MStatus * ReturnStatus = NULL ) const;
	///
	MStatus     setHideSource( const bool& hide_source );

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
#endif /* _MFnLambertShader */
