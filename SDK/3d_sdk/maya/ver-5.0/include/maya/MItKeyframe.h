
#ifndef _MItKeyframe
#define _MItKeyframe
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
// CLASS:    MItKeyframe
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MItKeyframe)
//
//	In Maya Animation Curves (Anim Curve) are implemented as Dependency Graph
//	(DG) Nodes.  Each Node has multiple ordered and indexed keyframes.
//
//	The Keyframe Iterator provides methods for iterating over, querying and
//	editing the keyframes of a Anim Curve Node.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MFn.h>
#include <maya/MStatus.h>
#include <maya/MTime.h>

// *****************************************************************************

// DECLARATIONS

class MObject;
class MPtrBase;

// *****************************************************************************

// CLASS DECLARATION (MItKeyframe)

///  Keyframe Iterator (OpenMayaAnim)
/**

Iterate over the keyframes of a particular Anim Curve Node, and query
and edit the keyframe to which the iterator points.

Determine the time and value of the keyframe, as well as the x,y values
and type of the tangent to the curve entering (in tangent) and leaving
(out tangent) the keyframe.

Set the time and value of the keyframe, and the type of the tangents.

*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYAANIM_EXPORT MItKeyframe {
public:
	///
	enum TangentType {
		///
		kTangentGlobal = 0,
		///
		kTangentFixed,
		///
		kTangentLinear,
		///
		kTangentFlat,
		///
		kTangentSmooth,
		///
		kTangentStep,
		///
		kTangentSlow,
		///
		kTangentFast,
		///
		kTangentClamped
	};
	///
	MItKeyframe( MObject & animCurveNode, MStatus * ReturnStatus = NULL );
	///
	~MItKeyframe();
	///
	MStatus     reset( MObject & animCurveNode );
	///
	MStatus     reset();
	///
	MStatus     next();
	///
	bool        isDone( MStatus * ReturnStatus = NULL );
	///
	MTime       time( MStatus * ReturnStatus = NULL );
	///
	MStatus     setTime( MTime time );
	///
	double      value( MStatus * ReturnStatus = NULL );
	///
	MStatus     setValue( double value );
	///
	TangentType inTangentType( MStatus * ReturnStatus = NULL );
	///
	TangentType outTangentType( MStatus * ReturnStatus = NULL );
	///
	MStatus     setInTangentType( TangentType tangentType );
	///
	MStatus     setOutTangentType( TangentType tangentType );
	///
	MStatus     getTangentOut( float &x, float &y );
	///
	MStatus     getTangentIn( float &x, float &y );
	///
	bool		tangentsLocked( MStatus * ReturnStatus = NULL ) const;
	///
	MStatus		setTangentsLocked( bool locked );

protected:
// No protected members

private:
	static const char* className();
    MPtrBase *        f_ptr;
	unsigned          f_index;
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MItKeyframe */
