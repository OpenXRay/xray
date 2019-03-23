
#ifndef _MPxGlBuffer
#define _MPxGlBuffer
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
// CLASS:    MPxGlBuffer
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MPxGlBuffer)
//
//  MPxGlBuffer allows the user to create OpenGL buffers that Maya
//	can draw into.  The base class as is defined will create a hardware
//	accellerated off-screen buffer for use on SGI hardware.
//
//  To create a custom buffer, derive from this class and override at
//	least the open, close, drawable, and context classes.  The customized
//	buffer may also require a constructor and destructor to initialize and
//	free its storage correctly.
//
// *****************************************************************************

#if defined __cplusplus

// ****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MStatus.h>
#include <maya/MTypes.h>

#if defined(__unix) || defined(LINUX)
#include <GL/glx.h>
#endif

// ****************************************************************************

// DECLARATIONS

class MString;
class M3dView;

// ****************************************************************************

// CLASS DECLARATION (MPxGlBuffer)

/// Base class for user defined GL buffers (OpenMayaUI)

/**
  Create user defined (off-screen) GL buffers.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYAUI_EXPORT MPxGlBuffer
{
public:
	///
	MPxGlBuffer();
	///
	MPxGlBuffer( M3dView &view );
	///
	virtual ~MPxGlBuffer();

#if defined(__unix) && !defined(LINUX)
	///
	virtual	MStatus			open( short width, short height,
								  GLXContext shareCtx = NULL );

	///
	virtual GLXDrawable	    drawable( MStatus * ReturnStatus = NULL );
	///
	virtual	GLXContext      context( MStatus * ReturnStatus = NULL );
#endif // __unix

	///
	virtual	MStatus			close();

protected:
	///
	bool					hasColorIndex;
	///
	bool					hasAlphaBuffer;
	///
	bool					hasDepthBuffer;
	///
	bool					hasAccumulationBuffer;

private:
	void   setData( void* );
	virtual const char*	className() const;
	void * 	data;

#if defined(LINUX)
public:
	///
	virtual	MStatus			open( short width, short height,
								  GLXContext shareCtx = NULL );

	///
	virtual GLXDrawable	    drawable( MStatus * ReturnStatus = NULL );
	///
	virtual	GLXContext      context( MStatus * ReturnStatus = NULL );
#endif // __linux
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MPxGlBuffer */
