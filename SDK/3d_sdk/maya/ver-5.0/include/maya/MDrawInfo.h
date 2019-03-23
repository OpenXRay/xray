
#ifndef _MDrawInfo
#define _MDrawInfo
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
// CLASS:    MDrawInfo
//
//    This class is used by the getDrawRequests method of MPxSurfaceShapeUI
//    to specify the current object drawing state for a user defined shape.
//
//    The getPrototype method is used to construct a draw request object
//    based on the current draw state for the object.
//
//    See MDrawRequest for more information.
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MDrawInfo)
//
// *****************************************************************************
//
#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MStatus.h>
#include <maya/MTypes.h>
#include <maya/MObject.h>
#include <maya/M3dView.h>
#include <maya/MDrawRequest.h>

// *****************************************************************************

// DECLARATIONS

class MSelectionMask;
class MSelectionTypeSet;
class MPoint;
class MPointArray;
class MVector;
class MSelectionList;
class MMatrix;

// *****************************************************************************

// CLASS DECLARATION (MDrawInfo)

/// Drawing state used in the draw methods of MPxSurfaceShapeUI (OpenMayaUI)
/**
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYAUI_EXPORT MDrawInfo
{
public:
	///
	MDrawInfo();
	///
	MDrawInfo( const MDrawInfo& in );
	///
	virtual ~MDrawInfo();


	// This method returns a partially filled in MDrawRequest
	///
	MDrawRequest			getPrototype(
								const MPxSurfaceShapeUI& drawHandler ) const;

	// Only really need camera path here
	///
	M3dView  				view() const;

	// path to object to draw
	///
	const MDagPath 			multiPath () const;

	// projection (camera) matrix
	///
	const MMatrix 			projectionMatrix() const;

	// world space inclusive matrix
	///
	const MMatrix 			inclusiveMatrix() const;

	// display appearance (this may change during traversal)
	///
	M3dView::DisplayStyle	displayStyle() const;

	// display status of object to draw
	///
	M3dView::DisplayStatus	displayStatus() const;

	///
	bool					inSelect() const;
	///
	bool					completelyInside() const;

	// convenience to test if component can be drawn
	///
	bool					canDrawComponent( bool isDisplayOn,
									const MSelectionMask & compMask ) const;

public:

	// Public accessor methods

protected:
// No protected members
	void*	 fData;

private:
	const char*	 className() const;
    MDrawInfo( void* in );
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MDrawInfo */
