
#ifndef _MFnDynSweptGeometryData
#define _MFnDynSweptGeometryData
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
// CLASS:    MFnDynSweptGeometryData
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnDynSweptGeometryData)
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MFnData.h>

// *****************************************************************************

// DECLARATIONS

class MDynSweptLine;
class MDynSweptTriangle;

// *****************************************************************************

// CLASS DECLARATION (MFnDynSweptGeometryData)

/// Swept Geometry function set for dependency node data (OpenMayaFX)
/**
	Access MDynSweptLine and MDynSweptTriangle dependency node data
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYAFX_EXPORT MFnDynSweptGeometryData : public MFnData
{

	declareMFn(MFnDynSweptGeometryData, MFnData);

public:
	///
	int					lineCount( MStatus* ReturnStatus = NULL ) const;
	///
	int					triangleCount( MStatus* ReturnStatus = NULL ) const;
	///
	MDynSweptLine		sweptLine( int index,
							MStatus* ReturnStatus = NULL ) const;
	///
	MDynSweptTriangle	sweptTriangle( int index,
							MStatus* ReturnStatus = NULL ) const;

	///
	MObject				create( MStatus* ReturnStatus=NULL );

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
#endif /* _MFnDynSweptGeometryData */
