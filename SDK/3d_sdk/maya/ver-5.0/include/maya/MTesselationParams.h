
#ifndef _MTesselationParams
#define _MTesselationParams
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
// CLASS:    MTesselationParams
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MTesselationParams)
//
// This class provides control over the tesselation operation.
// This class is meant to be used in conjunction with the tesselate
// method of MFnNurbsSurface.
// 
// The tesselation operation works by building an initial mesh and then
// refining that mesh until certain subdivision criteria are met. This class
// provides control over both the method of construction of the initial
// mesh and also the criteria for subsequent refinement.
// The initial tesselation is specified by the polygon output type, and the
// isoparm type. The secondary tesselation (or subdivision) is specified by
// the tesselation format.
//
// *****************************************************************************
#if defined __cplusplus
// *****************************************************************************

// INCLUDED HEADER FILES

#include <maya/MStatus.h>
#include <maya/MTypes.h>

// *****************************************************************************

// FORWARD DECLARATIONS

class MMatrix;

// *****************************************************************************

// CLASS DECLARATION (MTesselationParams)

/// Tesselation parameters
/**

*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MTesselationParams  
{
public:
	
	/// Tesselation format
	enum TessFormat {
		///
		kTriangleCountFormat,
		///
		kStandardFitFormat,
		///
		kGeneralFormat
	};

	/// Output Types
	enum PolyType {
		///
		kTriangles,
		///
		kQuads
	};
	
	/// IsoparmType
	enum IsoparmType {
		///
		kSurface3DDistance,
		///
		kSurface3DEquiSpaced,
		///
		kSurfaceEquiSpaced,
		///
		kSpanEquiSpaced
	};
	
	/// Subdivision flags
	enum SubdivisionType {
		///
		kUseFractionalTolerance,
		///
		kUseChordHeightRatio,
		///
		kUseMinEdgeLength,
		///
		kUseMaxEdgeLength,
		///
		kUseMaxNumberPolys,
		///
		kUseMaxSubdivisionLevel,
		///
		kUseMinScreenSize,
		///
		kUseMaxUVRectangleSize,
		///
		kUseTriangleEdgeSwapping,
		///
		kUseRelativeTolerance,
		///
		kUseEdgeSmooth,
		///
		kLastFlag
	};


    ///
	MTesselationParams ( TessFormat format = kStandardFitFormat,
						PolyType = kTriangles );
	MTesselationParams ( const MTesselationParams & );
    ///
	~MTesselationParams ();


	// General parameters
	///
	void		setFormatType( TessFormat type );
	///
	void		setOutputType( PolyType type );


	//  Parameters for triangulization format
	///
	void		setTriangleCount( int );


	//  Parameters for standard fit  format
	///
	void		setStdChordHeightRatio( double );
	///
	void		setStdFractionalTolerance( double );
	///
	void		setStdMinEdgeLength( double );


	//  Parameters for general tesselation format
	///
	void		setSubdivisionFlag( SubdivisionType type, bool use );
	///
	void		setFitTolerance( double );
	///
	void		setChordHeightRatio( double );
	///
	void		setMinEdgeLength( double );
	///
	void		setMaxEdgeLength( double );
	///
	void		setMaxNumberPolys( int );
	///
	void		setMaxSubdivisionLevel( double );
	///
	void		setMinScreenSize( double, double );
	///
	void		setWorldspaceToScreenTransform( MMatrix & );
	///
	void		setMaxUVRectangleSize( double, double );
	///
	void		setRelativeFitTolerance( double );
	///
	void		setEdgeSmoothFactor( double );
	///
	void		set3DDelta( double );


	// U,V isoparm based parameters
	///
	void		setUIsoparmType( IsoparmType type );
	///
	void		setVIsoparmType( IsoparmType type );
	///
	void		setUNumber( int count );
	///
	void		setVNumber( int count );
	///
	void		setBoundingBoxDiagonal( double distance );
	///
	void		setUDistanceFraction( double value );
	///
	void		setVDistanceFraction( double value );

	///
	MTesselationParams &operator= ( const MTesselationParams &rhs);		

	
	// The default tesselation parameters
	///
	static	MTesselationParams 	fsDefaultTesselationParams;

protected:
// No protected members

private:
	friend class MFnNurbsSurface;
	const char*		 className() const;
	void * data;
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MTesselationParams */
