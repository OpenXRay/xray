
#ifndef _MFnSubdNames
#define _MFnSubdNames
//
// *****************************************************************************
//
// Copyright (C) 1999-2003 Alias|Wavefront Inc.
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
