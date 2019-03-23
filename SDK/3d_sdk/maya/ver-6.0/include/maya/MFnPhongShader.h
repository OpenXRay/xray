
#ifndef _MFnPhongShader
#define _MFnPhongShader
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
