
#ifndef _MFnSubdNames
#define _MFnSubdNames
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
// CLASS:    MFnSubdNames
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnSubdNames)
//
//	The names (ids) utilities for the hierarchical subdivision surfaces
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MStatus.h>
#include <maya/MTypes.h>

// *****************************************************************************

// *****************************************************************************

// CLASS DECLARATION (MFnSubdNames)

/// Manipulate Subdivision Surface vertex, edge and face ids
/**

*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MFnSubdNames
{
public:
	///
					MFnSubdNames();
	///
					~MFnSubdNames();
	///
	static int		base( MUint64 id );
	///
	static int		first( MUint64 id );
	///
	static int		level( MUint64 id );
	///
	static int		path( MUint64 id );
	///
	static int		corner( MUint64 id );

	///
	static MStatus	fromMUint64( MUint64 id, int& base, int& first,
								 int& level, int& path, int& corner );
	///
	static MStatus	toMUint64( MUint64& id, int base, int first,
								 int level, int path, int corner );

	///
	static MUint64	baseFaceId( MUint64 id );
	/// OBSOLETE
	static long		baseFaceIndex( MUint64 id );
	///
	static unsigned	baseFaceIndexFromId( MUint64 id );
	///
	static MUint64	levelOneFaceId( MUint64 id );
	/// OBSOLETE
	static long		levelOneFaceAsLong( MUint64 id );
	///
	static unsigned	levelOneFaceIndexFromId( MUint64 id );

	/// OBSOLETE
	static MUint64	levelOneFaceIdFromLong( long one );
	///
	static MUint64	levelOneFaceIdFromIndex( unsigned index );

	/// OBSOLETE
	static MUint64	baseFaceIdFromLong( long base );
	///
	static MUint64	baseFaceIdFromIndex( unsigned index );

	///
	static MUint64	parentFaceId( MUint64 id );

	///
	static MStatus	nonBaseFaceVertices( MUint64 id,
										 MUint64& vertex1, MUint64& vertex2,
										 MUint64& vertex3, MUint64& vertex4 );
	///
	static MStatus	nonBaseFaceEdges( MUint64 id,
									  MUint64& edge1, MUint64& edge2,
									  MUint64& edge3, MUint64& edge4);


	///
	static MStatus	fromSelectionIndices( MUint64& id,
										  unsigned int firstIndex,
										  unsigned int secondIndex );

	///
	static MStatus	toSelectionIndices( MUint64 id,
										unsigned int& firstIndex,
										unsigned int& secondIndex );

protected:
// No protected members

private:
	static const char* className();
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MFnSubd */
