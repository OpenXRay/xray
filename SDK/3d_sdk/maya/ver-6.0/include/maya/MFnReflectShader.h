
#ifndef _MFnReflectShader
#define _MFnReflectShader
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
