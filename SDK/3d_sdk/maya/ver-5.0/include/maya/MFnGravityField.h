
#ifndef _MFnGravityField
#define _MFnGravityField
//
// *****************************************************************************
//
// Copyright (C) 1998-2003 Alias|Wavefront Inc.
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
// CLASS:    MFnGravityField
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnGravityField)
//
// Function set for Gravity Fields
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MFnField.h>
#include <maya/MVector.h>

// *****************************************************************************

// DECLARATIONS

// *****************************************************************************

// CLASS DECLARATION (MFnGravityField)

/// Function set for Gravity Fields (OpenMayaFX)
/**

*/

#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYAFX_EXPORT MFnGravityField : public MFnField
{

    declareDagMFn(MFnGravityField, MFnField);

public:
    ///
    MVector      direction          ( MStatus *ReturnStatus = NULL ) const;
    ///
    MStatus      setDirection       ( const MVector & gravityDirection );

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
#endif /* _MFnGravityField */
