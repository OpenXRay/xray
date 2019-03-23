#ifndef LINUX
#pragma once
#endif
#ifndef _MAnimCurveClipboardItem
#define _MAnimCurveClipboardItem

//
//
//******************************************************************************
//
// Copyright (C) 1998-2001 Alias|Wavefront Inc.
//
// These coded instructions, statements and computer programs contain
// unpublished information proprietary to Alias|Wavefront Inc. and are 
// protected by Canadian and US federal copyright laws. They may not be 
// disclosed to third parties or copied or duplicated, in whole or in part, 
// without prior written consent of Alias|Wavefront Inc.
//
// Unpublished-rights reserved under the Copyright Laws of the United States.
//
//
//******************************************************************************
//
// CLASS:    MAnimCurveClipboardItem
//
//
//******************************************************************************
//
// CLASS DESCRIPTION (MAnimCurveClipboardItem)
//
//  This class provides a wrapper to the clipboard item used to hold
//  on to cut/copy/paste information
//
//******************************************************************************

#if defined __cplusplus

//******************************************************************************
// INCLUDED HEADER HILES
//******************************************************************************

#include <maya/MFnAnimCurve.h>
#include <maya/MObject.h>


//******************************************************************************
// DECLARATIONS
//******************************************************************************

//	CLASS DECLARATION (MAnimCurveClipboardItem)

///	Wrapper for a clipboard item. (OpenMayaAnim)
/**
	This class provides a wrapper to the clipboard item used to hold
	on to cut/copy/paste information
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYAANIM_EXPORT MAnimCurveClipboardItem
{
public:
	///
					MAnimCurveClipboardItem();
	///
					MAnimCurveClipboardItem( const MAnimCurveClipboardItem & );
	///
					~MAnimCurveClipboardItem();

	///
	const MObject		animCurve( MStatus * ReturnStatus = NULL ) const;
	///
	MStatus				getAddressingInfo( unsigned &rowCount, 
										   unsigned &childCount,
										   unsigned &attrCount) const;
	///
	const MString &		fullAttributeName( MStatus * ReturnStatus=NULL ) const;
	///
	const MString &		leafAttributeName( MStatus * ReturnStatus=NULL ) const;
	///
	const MString &		nodeName( MStatus * ReturnStatus=NULL ) const;
	///
	MFnAnimCurve::AnimCurveType	animCurveType( MStatus
												* ReturnStatus=NULL ) const;
	///
	MStatus				setAnimCurve( const MObject & curve );
	///
	MStatus				setAddressingInfo( unsigned rowCount,
										   unsigned childCount,
										   unsigned attributeCount );
	///
	MStatus				setNameInfo( const MString & nodeName, 
									 const MString & fullName, 
									 const MString & leafName );
	///
	MAnimCurveClipboardItem &operator =  (const MAnimCurveClipboardItem &);
	///
	bool	 				operator == (const MAnimCurveClipboardItem &) const;
	
protected:
// No protected members

private:
	void *							fCurve;
	MFnAnimCurve::AnimCurveType		fAnimCurveType;

	unsigned						fRowCount;
	unsigned						fChildCount;
	unsigned						fAttrCount;
	MString							fFullAttrName;
	MString							fLeafAttrName;
	MString							fNodeName;
	static const char*				className();
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

//******************************************************************************
#endif /* __cplusplus */
#endif /* _MAnimCurveClipboardItem */
