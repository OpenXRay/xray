
#ifndef _MAnimUtil
#define _MAnimUtil
//
// *****************************************************************************
//-
// Copyright (C) 1999-2003 Alias|Wavefront Inc.
//
// These coded instructions, statements and computer programs contain
// unpublished information proprietary to Alias|Wavefront Inc. and
// are protected by the Canadian and US federal copyright law. They
// may not be disclosed to third parties or copied or duplicated, in
// whole or in part, without prior written consent of
// Alias|Wavefront Inc.
//
// Unpublished -- rights reserved under the Copyright Laws of
// the United States.
//+
// *****************************************************************************
//
// CLASS:    MAnimUtil
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MAnimUtil)
//
// MAnimUtil is a static class which provides helper methods for determining
// whether or not an object is animated, which attributes for the object are
// animated, and finally there is a method which will find all the animation
// curves for a given attribute.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MObject.h>

// *****************************************************************************

// DECLARATIONS

class MPlug;
class MPlugArray;
class MObjectArray;
class MSelectionList;
class MDagPath;

// *****************************************************************************

// CLASS DECLARATION (MAnimUtil)

/// Static class providing common animation helper methods (OpenMayaAnim)

class OPENMAYAANIM_EXPORT MAnimUtil
{
public:
	///
	static bool		isAnimated(	const MObject &node,
								bool checkParent = false,
								MStatus * ReturnStatus = NULL );
	///
	static bool		isAnimated(	const MDagPath &path,
								bool checkParent = false,
								MStatus * ReturnStatus = NULL );
	///
	static bool		isAnimated(	const MPlug &plug,
								bool checkParent = false,
								MStatus * ReturnStatus = NULL );
	///
	static bool		isAnimated(	const MSelectionList &selectionList,
								bool checkParent = false,
								MStatus * ReturnStatus = NULL );
	///
	static bool		findAnimatedPlugs(	const MObject &node,
										MPlugArray &animatedPlugs,
										bool checkParent = false,
										MStatus * ReturnStatus = NULL );
	///
	static bool		findAnimatedPlugs(	const MDagPath &path,
										MPlugArray &animatedPlugs,
										bool checkParent = false,
										MStatus * ReturnStatus = NULL );
	///
	static bool		findAnimatedPlugs(	const MSelectionList &selectionList,
										MPlugArray &animatedPlugs,
										bool checkParent = false,
										MStatus * ReturnStatus = NULL );
	///
	static bool		findAnimation(	const MPlug &plug,
									MObjectArray &animation,
									MStatus * ReturnStatus = NULL );
protected:
	static const char* className();
private:
	~MAnimUtil();
#ifdef __GNUC__
	friend class shutUpAboutPrivateDestructors;
#endif
};

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MAnimUtil */
