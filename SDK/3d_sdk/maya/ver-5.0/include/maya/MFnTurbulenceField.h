
#ifndef _MFnTurbulenceField
#define _MFnTurbulenceField
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
// CLASS:    MFnTurbulenceField
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnTurbulenceField)
//
// Function set for Turbulence Fields
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

// CLASS DECLARATION (MFnTurbulenceField)

/// Function set for Turbulence Fields (OpenMayaFX)
/**

*/

#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYAFX_EXPORT MFnTurbulenceField : public MFnField
{

    declareDagMFn(MFnTurbulenceField, MFnField);

public:
    ///
    double       frequency          ( MStatus *ReturnStatus = NULL ) const;
    ///
    MStatus      setFrequency       ( double value );
    ///
    double       phase              ( MStatus *ReturnStatus = NULL ) const;
    ///
    MStatus      setPhase           ( double value );

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
#endif /* _MFnTurbulenceField */
