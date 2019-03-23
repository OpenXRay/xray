#ifndef _MBoundingBox
#define _MBoundingBox
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
// CLASS:    MBoundingBox
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MBoundingBox)
//
//	This class provides an implementation of a bounding box.  A bounding box
//  describes a volume in space that bounds a piece of geometry.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MTypes.h>
#include <maya/MPoint.h>

// PDB
#if defined(_WIN32)
#undef min
#undef max
#endif // _WIN32

// *****************************************************************************

// DECLARATIONS 

class MMatrix;

// *****************************************************************************

// CLASS DECLARATION (MBoundingBox)

/// implementation of a 3D bounding box
/**
  This class implements a 3D bounding box
*/
#if defined(_WIN32)
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MBoundingBox  
{
public:
	///
    MBoundingBox();  
	///
	MBoundingBox( const MBoundingBox & src );  
	///
	MBoundingBox( const MPoint &corner1, const MPoint &corner2 );

	///
	~MBoundingBox();

	///
	void	clear();

	///  
    void	transformUsing ( const MMatrix &matrix );
	///
	void	expand( const MPoint & point );
	/// 
	void	expand( const MBoundingBox & box );
	
	/// 
	bool	contains( const MPoint & point ) const;
	///
	double	width() const;
	///
	double	height() const;
	///
	double	depth() const;
	///
	MPoint	center() const;
	///
	MPoint	min() const;
	///
	MPoint	max() const;

	///
	MBoundingBox & operator=( const MBoundingBox & other );

protected:
// No protected members

private: 
#if defined(OSMac_)
	char data[52];
#else
	double data[6];
#endif
};

#if defined(_WIN32)
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MBoundingBox */
