#ifndef LINUX
#pragma once
#endif
#ifndef _MFnNonAmbientLight
#define _MFnNonAmbientLight
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
// CLASS:    MFnNonAmbientLight
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnNonAmbientLight)
//
// MFnNonAmbientLight facilitates modification of dependency graph nodes 
// representing non-ambient lights.  This includes area lights, linear lights,
// and non-extended lights.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES

#include <maya/MFnDagNode.h>
#include <maya/MObject.h>
#include <maya/MStatus.h>
#include <maya/MFnLight.h>

// *****************************************************************************

// DECLARATIONS

// *****************************************************************************

// CLASS DECLARATION (MFnNonAmbientLight)

/// Manage Non-ambient Light dependency Nodes
/**
  Facilitate the creation and manipulation of non-ambient light nodes.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MFnNonAmbientLight : public MFnLight 
{

	declareDagMFn(MFnNonAmbientLight,MFnLight);
public:
	///
	short		decayRate( MStatus * ReturnStatus = NULL ) const;
	///
	MStatus		setDecayRate( const short& decay_rate );


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
#endif /* _MFnNonAmbientLight */
