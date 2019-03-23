#ifndef LINUX
#pragma once
#endif
#ifndef _MFnCharacter
#define _MFnCharacter
//
// *****************************************************************************
//
// Copyright (C) 2000-2001 Alias|Wavefront Inc.
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
// CLASS:    MFnCharacter
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnCharacter)
//
//  MFnCharacter is the function set that is used for manipulating characters.
//  Characters in Maya are dependency nodes used to manage any set of keyable
//  attributes. The attributes contained in a character can be manipulated
//  using clips, scheduled in a nonlinear manner by a clipScheduler node.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES

#include <maya/MString.h>
#include <maya/MFnSet.h>
#include <maya/MObject.h>

// *****************************************************************************

// DECLARATIONS
 
class MObjectArray;
class MSelectionList;
class MDagPath;
class TsetCmd;
class Tstring;
class MDGModifier;

// *****************************************************************************

// CLASS DECLARATION (MFnCharacter)

/// Function Set for Characters
/**
    Function set for characters
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYAANIM_EXPORT MFnCharacter : public MFnSet
{
	declareMFn(MFnCharacter, MFnSet);

public:
	///
	MStatus		attachSourceToCharacter( MObject& sourceClip,
										 MDGModifier& dgMod);
	///	
	MStatus		attachInstanceToCharacter( MObject& instanceClip,
										   MDGModifier& dgMod);
	///
	MStatus		addCurveToClip( MObject& curve,
								MObject& sourceClip,
								MPlug& characterPlug,
								MDGModifier& dgMod);
	///
	MObject		createBlend( MObject& instancedClip1,
							 MObject& instancedClip2,
							 MObject& blendAnimCurve,
							 MDGModifier& dgMod,
							 MStatus *ReturnStatus = NULL);
	///
	bool		blendExists(MObject& instancedClip1,
							MObject& instancedClip2,
							MObject& blendResult);
	///
	bool		removeBlend(MObject& instancedClip1,
							MObject& instancedClip2,
							MDGModifier& dgMod,							
							MStatus* ReturnStatus = NULL);

	///
	bool	getCharacterThatOwnsPlug(MPlug& plug, MObject& result) const;
	///
	MStatus getMemberPlugs(MPlugArray& result) const;
	///
	MStatus getSubCharacters(MSelectionList& result) const;
	///
	MObject getClipScheduler(MStatus * ReturnStatus = NULL);
	///
	int 	getScheduledClipCount(MStatus * ReturnStatus = NULL);
	///
	MObject	getScheduledClip(int index, MStatus * ReturnStatus = NULL);
	///
	int 	getSourceClipCount(MStatus * ReturnStatus = NULL);
	///
	MObject	getSourceClip(int index, MStatus * ReturnStatus = NULL);
	///
    int		getBlendCount(MStatus * ReturnStatus = NULL);
	///
    MObject getBlend(int index, MStatus * ReturnStatus = NULL);
	///
    MStatus getBlendClips(int index, MObject& clip1, MObject& clip2);
	
protected:
	virtual		Tstring setCommandString();
	virtual		TsetCmd* setCommand();	
private:
// No private members
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MFnCharacter */
