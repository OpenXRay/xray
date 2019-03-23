#ifndef _MPxDragAndDropBehavior
#define _MPxDragAndDropBehavior
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
// CLASS:    MPxDragAndDropBehavior
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MPxDragAndDropBehavior)
//
//  Base class for user-defined drag and drop behaviors
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES

#include <maya/MStatus.h>
#include <maya/MTypes.h>
#include <maya/MObject.h>
#include <maya/MPlug.h>

// *****************************************************************************

// DECLARATIONS

class MString;

// *****************************************************************************

// CLASS DECLARATION (MPxDragAndDropBehavior)

/// Drag and Drop Behavior (OpenMayaUI)
/**

*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYAUI_EXPORT MPxDragAndDropBehavior
{
public:
	///
	MPxDragAndDropBehavior();
	///
	virtual ~MPxDragAndDropBehavior();

	///
	MPxDragAndDropBehavior( void * init );

	///
	virtual bool shouldBeUsedFor( MObject &sourceNode, MObject &destinationNode,
								  MPlug &sourcePlug, MPlug &destinationPlug);

	///
	virtual MStatus connectAttrToAttr( MPlug &sourcePlug, MPlug &destinationPlug, bool force );

	///
	virtual MStatus connectAttrToNode( MPlug &sourcePlug, MObject &destinationNode, bool force );

	///
	virtual MStatus connectNodeToAttr( MObject &sourceNode, MPlug &destinationPlug, bool force );

	///
	virtual MStatus connectNodeToNode( MObject &sourceNode, MObject &destinationNode, bool force );

protected:
	
private:
	void   setData( void* );
	virtual const char*	className() const;
	void * 	data;

};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MPxDragAndDropBehavior */
