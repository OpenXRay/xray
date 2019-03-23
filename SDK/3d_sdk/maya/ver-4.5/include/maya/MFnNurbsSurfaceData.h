#ifndef LINUX
#pragma once
#endif
#ifndef _MFnNurbsSurfaceData
#define _MFnNurbsSurfaceData
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
// CLASS:    MFnNurbsSurfaceData
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnNurbsSurfaceData)
//
// MFnNurbsSurfaceData allows the creation and manipulation of NurbsSurface
// data objects for use in the dependency graph.
// 
// If a user written dependency node either accepts or produces Nurbs
// Surfaces, then this class is used to extract or create the data that
// comes from or goes to other dependency graph nodes. The
// MDataHandle::type method will return kNurbsSurface when data of this type
// is present.
//
// If a node is receiving a Nurbs Surface via an input attribute, the
// asNurbsSurface method of MDataHandle can be used to access that input Nurbs
// Surface.
//
// If a node is to create a Nurbs Surface and send it via an output attribute, a
// new MFnNurbsSurfaceData must be instantiated and then the create method
// called to build the actual data block as an MObject.  This MObject should
// be passed to the MFnNurbsSurface::create method as the parentOrOwner
// parameter so that the Nurbs Surface will be constructed inside the data
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

// CLASS DECLARATION (MFnNurbsSurfaceData)

/// Nurbs Surface function set for dependency node data
/**
  Create and manipulate Nurbs Surface dependency node data
*/

#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MFnNurbsSurfaceData : public MFnGeometryData 
{

	declareMFn(MFnNurbsSurfaceData, MFnGeometryData);

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
#endif /* _MFnNurbsSurfaceData */
