
#ifndef _MFnLambertShader
#define _MFnLambertShader
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
