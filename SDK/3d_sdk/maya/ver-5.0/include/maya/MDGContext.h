#ifndef _MDGContext
#define _MDGContext
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
// CLASS:    MDGContext
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MDGContext)
//
// This class provides methods for accessing dependency graph contexts.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MStatus.h>
#include <maya/MTypes.h>

// *****************************************************************************

// DECLARATIONS

class MObject;
class MTime;

// *****************************************************************************

// CLASS DECLARATION (MDGContext)

/// Dependency graph context class
/**
  Control the way in which dependency nodes are evaluated.
*/
#if defined(_WIN32)
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MDGContext  
{
public:

	// Normal
	///
	MDGContext( );

	// Timed
	///
	MDGContext( const MTime & when );

	///
	MDGContext( const MDGContext& in );

	///
	~MDGContext();



    // Method for determining whether the context is the "normal" one,
	// ie. the one used for normal evaluation
	///
	bool     	isNormal( MStatus * ReturnStatus = NULL ) const;

	///
	MStatus 	getTime( MTime & );

	///
	MDGContext&	operator =( const MDGContext& other );


	// Default context "Normal"
	///
	static		MDGContext	fsNormal;


protected:
// No protected members

private:
	const void * data;
	bool fOwn;
	friend class MPlug;
	friend class MDataBlock;
	const char* className() const;
	MDGContext( const void* );
};

#if defined(_WIN32)
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MDGContext */
