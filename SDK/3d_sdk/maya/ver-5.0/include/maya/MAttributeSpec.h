
#ifndef _MAttributeSpec
#define _MAttributeSpec
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
// CLASS:    MAttributeSpec
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MAttributeSpec)
//
//		Class that encapsulates component/attribute information
//		for generating selection items.
//
//      This class is used by MPxSurfaceShape::matchComponent for validating
//      attributes specified as strings and converting that specification to
//      a component object.
//
//		The attribute specification ".foo.bar[3].x" would be
//		expressed like this (using a pseudo-structure description):
//
//		MAttributeSpecArray[0..3] {
//			MAttributeSpec[0] {
//				name      = "foo"
//				dimension = 0
//			}
//			MAttributeSpec[1] {
//				name      = "bar"
//				dimension = 1
//				MAttributeIndex[0] = {
//					type      = kInteger
//					isRange   = false
//					isBounded = true
//					value     = 3
//				}
//			}
//			MAttributeSpec[2] {
//				name      = "x"
//				dimension = 0
//			}
//		}
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES



#include <maya/MTypes.h>

// *****************************************************************************

// DECLARATIONS

class MAttributeIndex;
class MString;

// *****************************************************************************

// CLASS DECLARATION (MAttributeSpec)

/// An attribute specification
/**
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MAttributeSpec {
public:
	///
	MAttributeSpec();
	///
	MAttributeSpec( const char * );
	///
	MAttributeSpec( const MString & );
	///
	MAttributeSpec( const MAttributeSpec & );
	///
	~MAttributeSpec();

public:
	///
	const MString 			name() const;
	///
	int						dimensions() const;
	///
	void					setName( const MString & );
	///
	void					setDimensions( int );

public:
	///
	MAttributeSpec &		operator =(const MAttributeSpec &);
	///
	const MAttributeIndex	operator [](int) const;
	///
	MAttributeIndex 		operator[](int);
	///
	bool					operator==(const MAttributeSpec &) const;

private:
	MAttributeSpec( void* );
	void*	data;
	bool	own;
	static const char* className();
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MAttributeSpec */
