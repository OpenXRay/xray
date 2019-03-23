
#ifndef _MFnDynSweptGeometryData
#define _MFnDynSweptGeometryData
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
