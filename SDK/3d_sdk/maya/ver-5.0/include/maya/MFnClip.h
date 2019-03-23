
#ifndef _MFnClip
#define _MFnClip
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
// CLASS:    MFnClip
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnClip)
//
// MFnClip is the function set for clips.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MFnDependencyNode.h>
#include <maya/MObject.h>
// *****************************************************************************

// DECLARATIONS
class MObject;
class MTime;
class MDGModifier;

// *****************************************************************************

// CLASS DECLARATION (MFnClip)

/// clip function set (OpenMayaAnim)
/**
MFnClip is the function set for creating, querying and
editing animation clips.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYAANIM_EXPORT MFnClip : public MFnDependencyNode
{
	declareMFn(MFnClip, MFnDependencyNode);

public:
	///
	MObject		createSourceClip ( const MTime& sourceStart,
								   const MTime& sourceDuration,
								   MDGModifier& dgMod,
								   MStatus * ReturnStatus = NULL );
	///
	MObject		createInstancedClip ( MObject& sourceClip,
									  const MTime& start,
									  MDGModifier& dgMod,
									  MStatus * ReturnStatus = NULL,
									  bool absolute = 1,
									  double cycle = 1.0,
									  double weight = 1.0,
									  double scale = 1.0 );
	///
	bool 		isInstancedClip(MStatus *ReturnStatus = NULL);
	///
	bool		isPose(MStatus *ReturnStatus = NULL);
	///
	MObject 	sourceClip(MStatus *ReturnStatus = NULL);
	///
	double		getCycle(MStatus *ReturnStatus = NULL);
	///
	double		getWeight(MStatus *ReturnStatus = NULL);
	///
	double 		getScale(MStatus *ReturnStatus = NULL);
	///
	bool 		getAbsolute(MStatus *ReturnStatus = NULL);
	///
	bool 		getEnabled(MStatus *ReturnStatus = NULL);
	///
	MTime		getStartFrame(MStatus *ReturnStatus = NULL);
	///
	MTime		getSourceStart(MStatus *ReturnStatus = NULL);
	///
	MTime		getSourceDuration(MStatus *ReturnStatus = NULL);
	///
	MStatus		getMemberAnimCurves(MObjectArray& curves,
									MPlugArray& associatedAttrs);
	///
	MStatus		setPoseClip(bool state, MDGModifier* mod = NULL);
	///
	MStatus		setCycle(double cycle, MDGModifier* mod = NULL);
	///
	MStatus		setWeight(double wt, MDGModifier* mod = NULL);
	///
	MStatus		setScale(double scale, MDGModifier* mod = NULL);
	///
	MStatus		setAbsolute(bool abs, MDGModifier* mod = NULL);
	///
	MStatus		setEnabled(bool val, MDGModifier* mod = NULL);
	///
	MStatus		setStartFrame(const MTime& start, MDGModifier* mod = NULL);
	///
	MStatus		setSourceData(const MTime& start,const MTime& duration,
							  MDGModifier* mod = NULL);

protected:
// No protected members

private:

};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MFnClip */
