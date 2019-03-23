#ifndef LINUX
#pragma once
#endif
#ifndef _MFnBlinnShader
#define _MFnBlinnShader
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
// CLASS:    MFnBlinnShader
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnBlinnShader)
//
// MFnBlinnShader facilitates creation and manipulation of dependency graph 
// nodes representing Blinn shaders.
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

// CLASS DECLARATION (MFnBlinnShader)

/// Manage Blinn shaders.
/**
  Facilitate the creation and manipulation of Blinn shaders.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MFnBlinnShader : public MFnReflectShader
{

	declareMFn( MFnBlinnShader, MFnReflectShader );

public:
	///
	MObject 	create( bool UIvisible = true, MStatus * ReturnStatus = NULL );	
	///
	float       eccentricity( MStatus * ReturnStatus = NULL ) const;
	///
	MStatus     setEccentricity( const float& eccentricity );
	///
	float       specularRollOff( MStatus * ReturnStatus = NULL ) const;
	///
	MStatus     setSpecularRollOff( const float& specular_rolloff );

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
#endif /* _MFnBlinnShader */
