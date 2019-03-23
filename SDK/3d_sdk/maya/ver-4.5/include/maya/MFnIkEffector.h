#ifndef LINUX
#pragma once
#endif
#ifndef _MFnIkEffector
#define _MFnIkEffector
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
// CLASS:    MFnIkEffector
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnIkEffector)
// 
//  
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES

#include <maya/MFnTransform.h>
#include <maya/MObject.h>

// *****************************************************************************

// DECLARATIONS

// *****************************************************************************

// CLASS DECLARATION (MFnIkEffector)

/// Inverse kinematics end effector function set (OpenMayaAnim)
/**
  Function set for inverse kinematics end effectors
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYAANIM_EXPORT MFnIkEffector : public MFnTransform 
{
	declareDagMFn( MFnIkEffector, MFn::kEffector );

public:
    ///
	MObject create( MObject parent = MObject::kNullObj,
					MStatus * ReturnStatus = NULL );

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
#endif /* _MFnIkEffector */
