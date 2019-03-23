#ifndef LINUX
#pragma once
#endif
#ifndef _MFnLightDataAttribute
#define _MFnLightDataAttribute
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
// CLASS:    MFnLightDataAttribute
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnLightDataAttribute)
//
// Function object for LightData attributes.  A LightData attribute describes
// a single light source, giving its direction and intensity, as well as
// specifying whether or not it contributes to the ambient, diffuse, and
// specular components of the shading model.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES

#include <maya/MFnAttribute.h>

// *****************************************************************************

// DECLARATIONS

// *****************************************************************************

class MString;

// CLASS DECLARATION (MFnLightDataAttribute)

/// Light data attribute function set
/**
  Function set for light data attributes.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MFnLightDataAttribute : public MFnAttribute 
{

	declareMFn(MFnLightDataAttribute, MFnAttribute);

public:
	///
	MObject    create( const MString& fullName,
					   const MString& briefName,
					   const MObject & direction,
					   const MObject & intensity,
					   const MObject & ambient,
					   const MObject & diffuse,
					   const MObject & specular,
					   const MObject & shadowFraciton,
					   const MObject & preShadowIntensity,
					   const MObject & blindData,
					   MStatus* ReturnStatus = NULL );

	///
	MStatus     setDefault( float defDirectionX, 
							float defDirectionY, 
							float defDirectionZ,
							float defIntensityR,
							float defIntensityG, 
							float defIntensityB,
							bool  defAmbient, 
							bool  defDiffuse, 
							bool  defSpecular,
							float defShadowFraction,
							float defPreShadowIntensity,
							unsigned int defBlindData);

	///
	MObject     child( unsigned index, MStatus* returnStatus );

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
#endif /* _MFnLightDataAttribute */



