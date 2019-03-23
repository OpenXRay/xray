#ifndef _MRampAttribute
#define _MRampAttribute
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
// CLASS:    MRampAttribute
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MRampAttribute)
//
// This class is used to manipulate ramp attributes.  You can add, delete, and set
// entries in both color and curve ramps.
// You can't create a ramp attribute from this class, you can only modifying existing 
// ramps.
//
// *****************************************************************************

#if defined __cplusplus

// INCLUDED HEADER FILES


#include <maya/MTypes.h>

// *****************************************************************************

// DECLARATIONS

// *****************************************************************************

class MString;
class MStatus;
class MPlug;
class MColor;
class MFloatArray;
class MColorArray;
class MIntArray;
class MObject;

// CLASS DECLARATION (MRampAttribute)


#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

/// Ramp data attribute function wrapper class
/**
  Wrapper class for ramp data attributes.
*/

class OPENMAYA_EXPORT MRampAttribute 
{

public:

	///
	MRampAttribute (const MRampAttribute& other);

	///
	MRampAttribute (const MPlug& obj, MStatus* ReturnStatus = NULL);

	///
	MRampAttribute (const MObject& node, const MObject& attr, MStatus* ReturnStatus = NULL);

	///
	MRampAttribute&    operator =( const MRampAttribute & other );

	///
	~MRampAttribute ();

	///
	enum MInterpolation	{	
	///
		kLinear = 0,
	///
		kNone = 1,
	///
		kSpline = 2,
	///
		kSmooth = 3
	};

	///
	void getEntries (MIntArray& indexes, 
		MFloatArray& positions,
		MFloatArray& values, 
		MIntArray& interps, 
		MStatus * returnStatus);
	///
	void getEntries (MIntArray& indexes, 
		MFloatArray& positions, 
		MColorArray& colors, 
		MIntArray& interps, 
		MStatus * returnStatus);
	///
	void addEntries (MFloatArray& positions, 
		MColorArray& values, 
		MIntArray& interps, 
		MStatus * returnStatus);
	///
	void addEntries (MFloatArray& positions, 
		MFloatArray& values, 
		MIntArray& interps, 
		MStatus * returnStatus);
	///
	void deleteEntries (MIntArray& indexes, 
		MStatus * returnStatus);
	///
	void setColorAtIndex (MColor& color, unsigned int index, MStatus * returnStatus);
	///
	void setValueAtIndex (float value, unsigned int index, MStatus * returnStatus);
	///
	void setPositionAtIndex (float position, unsigned int index, MStatus * returnStatus);
	///
	void setInterpolationAtIndex (MRampAttribute::MInterpolation interp, unsigned int index, MStatus * returnStatus);
	///
	bool isColorRamp(MStatus * returnStatus);
	///
	bool isCurveRamp(MStatus * returnStatus);

protected:
// No protected members


private:

	MRampAttribute ();
	static const char* className();
	const void * fData;
	bool fOwn;


};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MFnRampDataAttribute */



