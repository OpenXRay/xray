
#ifndef _MFnTransform
#define _MFnTransform
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
// CLASS:    MFnTransform
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnTransform)
//
//	The Class Description section provides a textual description 
// 	of the class, from an external view.  The description is to 
//	be sufficient for a client of the class, or an implementor 
// 	of the class, to understand its purpose and nature.  
//	Important terms or concepts associated with the class are to 
// 	be described.  This description can be augmented with a 
//	diagram if the class is visual in nature.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MFnDagNode.h>
#include <maya/MTransformationMatrix.h>
#include <maya/MObject.h>

// *****************************************************************************

// DECLARATIONS

class MVector;
class MPoint;
class MQuaternion;
class MEulerRotation;

// *****************************************************************************

// CLASS DECLARATION (MFnTransform)

/// Create and access transform nodes.
/**
  Methods for creating and accessing transform nodes.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MFnTransform : public MFnDagNode 
{
	declareDagMFn( MFnTransform, MFn::kTransform );
public:
    ///
	MObject     create( MObject parent = MObject::kNullObj, 
						MStatus * ReturnStatus = NULL );
    ///
	MTransformationMatrix
	            transformation( MStatus * ReturnStatus = NULL ) const;
    ///
	MStatus		set ( const MTransformationMatrix& transform );
    ///
	MStatus 	getScale( double scale[3] ) const; 
    ///
	MStatus 	setScale( const double scale[3] );
    ///
	MStatus 	scaleBy( const double scale[3] ) ;
    ///
	MStatus 	getShear( double scale[3] ) const;
    ///
	MStatus 	setShear( const double shear[3] );
    ///
	MStatus 	shearBy( const double shear[3] );
    ///
	MStatus 	getRotation	( MQuaternion &quaternion,
							  MSpace::Space = MSpace::kTransform ) const;
    ///
	MStatus 	setRotation	( const MQuaternion &quaternion,
							  MSpace::Space = MSpace::kTransform );
    ///
	MStatus 	rotateBy	( const MQuaternion &quaternion,
							  MSpace::Space = MSpace::kTransform );
    ///
	MStatus 	getRotation	( MEulerRotation &rotation ) const;
    ///
	MStatus 	setRotation	( const MEulerRotation &rotation );
    ///
	MStatus 	rotateBy	( const MEulerRotation &rotation,
							  MSpace::Space = MSpace::kTransform );
    ///
	MStatus 	getRotationQuaternion( double &x, double &y,
									   double &z, double &w,
									   MSpace::Space = MSpace::kTransform)
                                       const;
    ///
	MStatus 	setRotationQuaternion( double x, double y, double z, double w,
									   MSpace::Space = MSpace::kTransform);
    ///
	MStatus 	rotateByQuaternion( double x, double y, double z, double w,
									MSpace::Space = MSpace::kTransform);
    ///
	MStatus 	getRotation( double rotation[3],
							 MTransformationMatrix::RotationOrder& order )
                             const;
    ///
	MStatus 	setRotation( const double rotation[3],
							 MTransformationMatrix::RotationOrder order );
    ///
	MStatus 	rotateBy( const double rotation[3],
						  MTransformationMatrix::RotationOrder order,
						  MSpace::Space = MSpace::kTransform);
    ///
	MVector		translation( MSpace::Space space,
							 MStatus * ReturnStatus = NULL ) const;
    ///
	MStatus 	setTranslation( const MVector & vec, MSpace::Space space );
    ///
	MStatus 	translateBy( const MVector & vec, MSpace::Space space );
    ///
	MPoint		scalePivot(MSpace::Space space,
						   MStatus * ReturnStatus = NULL ) const;
    ///
	MStatus 	setScalePivot( const MPoint& point, MSpace::Space space,
							   bool balance );
    ///
	MVector		scalePivotTranslation( MSpace::Space space ,
									   MStatus * ReturnStatus = NULL ) const;
    ///
	MStatus 	setScalePivotTranslation( const MVector& vec, 
										  MSpace::Space space );
    ///
	MPoint		rotatePivot(MSpace::Space space ,
							MStatus * ReturnStatus = NULL ) const;
    ///
	MStatus 	setRotatePivot( const MPoint& point, MSpace::Space space,
								bool balance );
    ///
	MVector		rotatePivotTranslation( MSpace::Space space,
										MStatus * ReturnStatus = NULL ) const;
    ///
	MStatus 	setRotatePivotTranslation( const MVector& vec, 
										   MSpace::Space space );
    ///
	MQuaternion		rotateOrientation(MSpace::Space space ,
							MStatus * ReturnStatus = NULL ) const;
    ///
	MStatus 	setRotateOrientation( const MQuaternion& quat, MSpace::Space space,
								bool balance );
    ///
	MTransformationMatrix::RotationOrder
                rotationOrder( MStatus* ReturnStatus = NULL ) const;
    ///
	MStatus 	setRotationOrder( MTransformationMatrix::RotationOrder order,
								  bool reorder );
    ///
	MTransformationMatrix
                restPosition( MStatus* ReturnStatus) const;
    ///
	MStatus		setRestPosition( const MTransformationMatrix& matrix );
    ///
	MStatus		resetFromRestPosition();
    ///
	MStatus		clearRestPosition();
	/// OBSOLETE
	MStatus 	getRotation( double rotation[3],
							 MTransformationMatrix::RotationOrder& order,
							 MSpace::Space)
                             const;
    /// OBSOLETE
	MStatus 	setRotation(const double rotation[3],
							MTransformationMatrix::RotationOrder order,
							MSpace::Space);

	///
	enum LimitType {
		///
		kScaleMinX,
		///
		kScaleMaxX,
		///
		kScaleMinY,
		///
		kScaleMaxY,
		///
		kScaleMinZ,
		///
		kScaleMaxZ,
		///
		kShearMinXY,
		///
		kShearMaxXY,
		///
		kShearMinXZ,
		///
		kShearMaxXZ,
		///
		kShearMinYZ,
		///
		kShearMaxYZ,
		///
		kRotateMinX,
		///
		kRotateMaxX,
		///
		kRotateMinY,
		///
		kRotateMaxY,
		///
		kRotateMinZ,
		///
		kRotateMaxZ,
		///
		kTranslateMinX,
		///
		kTranslateMaxX,
		///
		kTranslateMinY,
		///
		kTranslateMaxY,
		///
		kTranslateMinZ,
		///
		kTranslateMaxZ
	};

	///
	bool	isLimited( MFnTransform::LimitType type, 
						MStatus * ReturnStatus = NULL ) const;
	///
	double	limitValue ( MFnTransform::LimitType type,
						MStatus * ReturnStatus = NULL ) const;
	///
	MStatus	setLimit ( MFnTransform::LimitType type, double value);
					
	///
	MStatus	enableLimit ( MFnTransform::LimitType type, bool flag);
						


protected:
	virtual bool objectChanged( MFn::Type, MStatus * );

private:
// No private members

};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MFnTransform */
