
#ifndef _MFnPhongShader
#define _MFnPhongShader
//
// *****************************************************************************
//
// Copyright (C) 1997-2003 Alias|Wavefront Inc.
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
// CLASS:    MFnPhongShader
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnPhongShader)
//
// MFnPhongShader facilitates the creation and manipulation of dependency graph
// nodes representing Phong shaders.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MObject.h>
#include <maya/MStatus.h>
#include <maya/MFnReflectShader.h>
// *****************************************************************************

// DECLARATIONS

class MFnReflectShader;

// *****************************************************************************

// CLASS DECLARATION (MFnPhongShader)

/// Manage Phong Shaders
/**
  Facilitate the creation and manipulation of Phong shaders.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MFnPhongShader : public MFnReflectShader
{

	declareMFn( MFnPhongShader, MFnReflectShader );

public:
	///
	MObject 	create( bool UIvisible = true, MStatus * ReturnStatus = NULL );	
	///
	float       cosPower( MStatus * ReturnStatus = NULL ) const;
	///
	MStatus     setCosPower( const float& cos_power );

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
#endif /* _MFnPhongShader */
