#ifndef LINUX
#pragma once
#endif
#ifndef _MFnCompoundAttribute
#define _MFnCompoundAttribute
//
// *****************************************************************************
//
// Copyright (C) 1997-2001 Alias|Wavefront Inc.
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
// CLASS:    MFnCompoundAttribute
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnCompoundAttribute)
// 
//  MFnCompoundAttribute is the function set for compound dependency node 
//  attributes.
//
//  Compound attributes allow the grouping of related attributes into a larger
//  unit.  It is possible to connect to a compound attribute as a whole, or 
//  to any of the individual children. 
//
//  For example, the three attributes RED, GREEN, and BLUE could be grouped
//  into a compound attribute of type COLOR.  It is then possible to connect
//  two COLOR attributes together.  This removes the need to connect each
//  child explicitly.
//
//  A second use for compound attributes is when there are multi attributes that
//  relate to each other on an element-by-element basis.  An example of this 
//  is the weighted matrix node that has a multi attribute with matrices that
//  must be matched with the multi attribute that provides the weights for each
//  matrix.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES

#include <maya/MFnAttribute.h>

// *****************************************************************************

// DECLARATIONS

class MString;

// *****************************************************************************

// CLASS DECLARATION (MFnCompoundAttribute)

/// Compound attribute function set
/**
   Function set for compound attributes of dependency nodes
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MFnCompoundAttribute : public MFnAttribute 
{

	declareMFn(MFnCompoundAttribute, MFnAttribute);

public:
    ///
	MObject 	create( const MString& full,
						const MString& brief,
						MStatus* ReturnStatus = NULL );
    ///
	MStatus		addChild( const MObject & child );
    ///
	MStatus		removeChild( const MObject & child );
    ///
	unsigned	numChildren( MStatus* ReturnStatus = NULL ) const;
    ///
	MObject 	child( unsigned index, MStatus* ReturnStatus = NULL ) const;
	///
	MStatus		getAddAttrCmds(
					MStringArray&	cmds,
					bool			useLongNames = false
				) const;

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
#endif /* _MFnCompoundAttribute */
