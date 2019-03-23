#ifndef LINUX
#pragma once
#endif
#ifndef _MFnNonExtendedLight
#define _MFnNonExtendedLight
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
// CLASS:    MFnNonExtendedLight
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnNonExtendedLight)
//
// MFnNonExtendedLight facilitates manipulation of dependency graph nodes
// representing non-extended lights.  This includes point lights, directional
// lights, and spotlights.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES

#include <maya/MFnDagNode.h>
#include <maya/MObject.h>
#include <maya/MStatus.h>
#include <maya/MFnNonAmbientLight.h>

// *****************************************************************************

// DECLARATIONS

// *****************************************************************************

// CLASS DECLARATION (MFnNonExtendedLight)

/// Manage Non-extended Light dependency Nodes
/**
  Facilitate the creation and manipulation of non-extended light nodes.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MFnNonExtendedLight : public MFnNonAmbientLight 
{

	declareDagMFn(MFnNonExtendedLight,MFnNonAmbientLight);
public:
	///
	float         shadowRadius( MStatus * ReturnStatus = NULL ) const;
	///
	MStatus       setShadowRadius( const float& shadow_radius );
	///
	bool          castSoftShadows( MStatus * ReturnStatus = NULL ) const;
	///
	MStatus       setCastSoftShadows( const bool& cast_soft_shadows );
	///
	bool          useDepthMapShadows( MStatus * ReturnStatus = NULL ) const;
	///
	MStatus       setUseDepthMapShadows( const bool& use_depth_map );
	///
	short         depthMapFilterSize( MStatus * ReturnStatus ) const;
	///
	MStatus       setDepthMapFilterSize( const short& depth_map_filter_size );
	///
	short         depthMapResolution( MStatus * ReturnStatus ) const;
	///
	MStatus       setDepthMapResolution( const short& depth_map_resolution );
	///
	float         depthMapBias( MStatus * ReturnStatus ) const;
	///
	MStatus       setDepthMapBias( const float& depth_map_bias );

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
#endif /* _MFnNonExtendedLight */



