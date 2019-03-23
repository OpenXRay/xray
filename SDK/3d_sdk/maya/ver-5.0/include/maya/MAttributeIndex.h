
#ifndef _MAttributeIndex
#define _MAttributeIndex
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
// CLASS:    MAttributeIndex
//
//    Class that provides access to the index part of an attribute
//    specification (MAttributeSpec).
//
//    See MAttributeSpec for more information.
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MAttributeIndex)
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES



#include <maya/MTypes.h>
#include <maya/MStatus.h>

// *****************************************************************************

// DECLARATIONS

// *****************************************************************************

// CLASS DECLARATION (MAttributeIndex)

/// The index information for an attribute specification
/**
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MAttributeIndex {
public:
	///
	enum MIndexType {
		///
		kInteger,
		///
		kFloat
	};

	///
	MAttributeIndex();
	///
	~MAttributeIndex();
	///
	MAttributeIndex( const MAttributeIndex & );
	///
	MAttributeIndex( int );
	///
	MAttributeIndex( double );

public:
	///
	MIndexType		type() const;
	///
	bool			hasRange() const;
	///
	bool			hasValidRange() const;

	///
	bool			hasLowerBound() const;
	///
	bool			hasUpperBound() const;
	///
	MStatus			getLower( int & ) const;
	///
	MStatus			getLower( double & ) const;
	///
	MStatus			getUpper( int & ) const;
	///
	MStatus			getUpper( double & ) const;

	///
	bool			isBounded() const;
	///
	MStatus			getValue( int & ) const;
	///
	MStatus			getValue( double & ) const;

public:
	///
	MStatus			setType( MIndexType );
	///
	MStatus			setValue( int );
	///
	MStatus			setValue( double );
	///
	MStatus			setLower( int );
	///
	MStatus			setLower( double );
	///
	MStatus			setUpper( int );
	///
	MStatus			setUpper( double );
	
public:
	///
	MAttributeIndex & operator=( const MAttributeIndex & );
	///
	bool			operator==( const MAttributeIndex & ) const;
	///
	bool			operator!=( const MAttributeIndex & ) const;

private:
	MAttributeIndex( void* );
	friend class MAttributeSpec;
	void*	data;
	bool	own;
	static const char* className();
};


#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MAttributeIndex */
