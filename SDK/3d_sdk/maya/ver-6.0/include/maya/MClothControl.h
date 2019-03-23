#ifndef _MClothControl
#define _MClothControl
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
// *****************************************************************************
//
// CLASS:    MClothControl
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MClothControl)
//
//  This class provides access to various cloth data. This includes UVs per
//	per cloth, UVs per panel, stitcher node of a cloth, solver node of a cloth,
//	face membership of a panel, etc.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


// MayaCloth Export
#ifdef _WIN32
#	ifndef MAYACLOTH_EXPORT
#		ifdef MAYACLOTH_DLL 
#			define MAYACLOTH_EXPORT _declspec( dllexport )
#		else
#			define MAYACLOTH_EXPORT _declspec( dllimport )
#		endif // MAYACLOTH_DLL
#	endif // MAYACLOTH_EXPORT
#else
#	ifndef MAYACLOTH_EXPORT
#		define MAYACLOTH_EXPORT
#	endif
#endif // _WIN32

// *****************************************************************************

// DECLARATIONS

class MObject;
class MIntArray;
class MDoubleArray;

// *****************************************************************************

// CLASS DECLARATION (MClothControl)

/// Access to cloth data
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class MAYACLOTH_EXPORT MClothControl
{
public:
	///
								MClothControl();
	///
	virtual						~MClothControl();
	///
	static MStatus				getUVs( const MString& cloth,
										const MString& panel,
										MDoubleArray& uvs );
	///
	static int					panelId( const MString& panel,
										 MStatus* ReturnStatus = NULL );
	///
	static MStatus				panelFaces( const MString& panel,
											MIntArray& faceIds );
	///
	static MObject				solverNode( const MString& cloth,
											MStatus* ReturnStatus = NULL );
	///
	static MObject				stitcherNode( const MString& cloth,
											  MStatus* ReturnStatus = NULL );

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
#endif /* _MClothControl */
