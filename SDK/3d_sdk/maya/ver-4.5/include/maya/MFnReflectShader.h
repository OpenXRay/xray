#ifndef LINUX
#pragma once
#endif
#ifndef _MFnReflectShader
#define _MFnReflectShader
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
// CLASS:    MFnReflectShader
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnReflectShader)
//
// MFnReflectShader allows manipulation of dependency graph nodes representing
// reflective surface shaders.  This includes Phong and Blinn shaders. 
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES

#include <maya/MObject.h>
#include <maya/MStatus.h>
#include <maya/MFnLambertShader.h>
// *****************************************************************************

// DECLARATIONS


class MFnLambertShader;


class MColor;

// *****************************************************************************

// CLASS DECLARATION (MFnReflectShader)

/// Manage Reflective Surface Shaders
/**
  Facilitate the creation and manipulation of reflective surface shaders.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MFnReflectShader : public MFnLambertShader
{

	declareMFn( MFnReflectShader, MFn::kReflect );

public:
	///
	short       reflectedRayDepthLimit( MStatus * ReturnStatus = NULL ) const;
	///
	MStatus     setReflectedRayDepthLimit( const short& new_limit );
	///
	MColor      specularColor( MStatus * ReturnStatus = NULL ) const;
	///
	MStatus     setSpecularColor( const MColor& specular_color );
	///
	float       reflectivity( MStatus * ReturnStatus = NULL ) const;
	///
	MStatus     setReflectivity( const float& reflectivity );
	///
	MColor      reflectedColor( MStatus * ReturnStatus = NULL ) const;
	///
	MStatus     setReflectedColor( const MColor& reflected_color );

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
#endif /* _MFnReflectShader */
