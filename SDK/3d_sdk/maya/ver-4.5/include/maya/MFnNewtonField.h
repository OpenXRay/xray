#ifndef LINUX
#pragma once
#endif
#ifndef _MFnNewtonField
#define _MFnNewtonField
//
// *****************************************************************************
//
// Copyright (C) 1998-2001 Alias|Wavefront Inc.
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
// CLASS:    MFnNewtonField
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnNewtonField)
// 
// Function set for Newton Fields
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES

#include <maya/MFnDagNode.h>
#include <maya/MFnField.h>

// *****************************************************************************

// DECLARATIONS

// *****************************************************************************

// CLASS DECLARATION (MFnNewtonField)

/// Function set for Newton Fields (OpenMayaFX)
/**

*/

#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYAFX_EXPORT MFnNewtonField : public MFnField
{

    declareDagMFn(MFnNewtonField, MFnField);

public:
    ///
    double       minDistance        ( MStatus *ReturnStatus = NULL ) const;
    ///
    MStatus      setMinDistance     ( double distance );

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
#endif /* _MFnNewtonField */
