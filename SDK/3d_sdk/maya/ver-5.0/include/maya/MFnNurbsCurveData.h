
#ifndef _MFnNurbsCurveData
#define _MFnNurbsCurveData
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
// CLASS:    MFnNurbsCurveData
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnNurbsCurveData)
//
//	MFnNurbsCurveData allows the creation and manipulation of NurbsCurve
//	data objects for use in the dependency graph.
//
// If a user written dependency node either accepts or produces Nurbs Curves,
// then this class is used to create data blocks into which Nurbs Curves can
// be constructed before being passed to other dependency graph nodes.  The
// MDataHandle::type method will return kNurbsCurve when data of this type is
// present.
//
// If a node is receiving a Nurbs Curve via an input attribute, the
// asNurbsCurve method of MDataHandle can be used to access that input Nurbs
// Curve.
//
// If a node is to create a Nurbs Curve and send it via an output attribute, a
// new MFnNurbsCurveData must be instantiated and then the create method
// called to build the actual data block as an MObject.  This MObject should
// be passed to the MFnNurbsCurve::create method as the parentOrOwner
// parameter so that the Nurbs Curve will be constructed inside the data
// block.  The MDataHandle::set routine is then used to pass the data block
// down the connection.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MFnGeometryData.h>

// *****************************************************************************

// DECLARATIONS

// *****************************************************************************

// CLASS DECLARATION (MFnNurbsCurveData)

/// Nurbs Curve function set for dependency node data
/**
  Create and manipulate Nurbs Curve dependency node data
*/

#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MFnNurbsCurveData : public MFnGeometryData 
{

	declareMFn(MFnNurbsCurveData, MFnGeometryData);

public:
	///
	MObject		create( MStatus* ReturnStatus = NULL );

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
#endif /* _MFnNurbsCurveData */
