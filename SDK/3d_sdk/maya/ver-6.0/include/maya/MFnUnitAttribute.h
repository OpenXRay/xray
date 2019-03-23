
#ifndef _MFnUnitAttribute
#define _MFnUnitAttribute
//
//-
// ==========================================================================
// Copyright (C) Alias Systems Corp., and/or its licensors ("Alias").  
// All rights reserved.  These coded instructions, statements, computer  
// programs, and/or related material (collectively, the "Material")
// contain unpublished information proprietary to Alias, which is
// protected by Canadian and US federal copyright law and by international
// treaties. This Material may not be disclosed to third parties, or be copied
// or duplicated, in whole or in part, without the prior written consent of
// Alias.  ALIAS HEREBY DISCLAIMS ALL WARRANTIES RELATING TO THE MATERIAL,
// INCLUDING, WITHOUT LIMITATION, ANY AND ALL EXPRESS OR IMPLIED WARRANTIES OF
// NON-INFRINGEMENT, MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
// IN NO EVENT SHALL ALIAS BE LIABLE FOR ANY DAMAGES WHATSOEVER, WHETHER DIRECT,
// INDIRECT, SPECIAL, OR PUNITIVE, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE
// OR OTHER TORTIOUS ACTION, OR IN EQUITY, ARISING OUT OF OR RELATED TO THE
// ACCESS TO, USE OF, OR RELIANCE UPON THE MATERIAL.
// ==========================================================================
//+
//
// CLASS:    MFnUnitAttribute
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnUnitAttribute)
//
//	MFnUnitAttribute is the function set for dependency nodes attributes
//	that store one of the fundamental types of Maya data.  The currently
//	supported types are MAngle, MDistance, and MTime.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MFnAttribute.h>

// *****************************************************************************

// DECLARATIONS

class MString;
class MTime;
class MAngle;
class MDistance;

// *****************************************************************************

// CLASS DECLARATION (MFnUnitAttribute)

/// Unit attribute Function set
/**
  Function set for unit attributes of dependency nodes.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MFnUnitAttribute : public MFnAttribute 
{

	declareMFn(MFnUnitAttribute, MFnAttribute);

public:
    ///
	enum Type {
        ///
		kInvalid,
        /// Angular attribute
		kAngle,		// defaults as kDouble
        /// Distance (linear) attribute
		kDistance,	// defaults as kDouble
        /// Time attribute
		kTime,		// defaults as MTime
        ///
		kLast
	};
    ///
	MObject 	create( const MString& fullName,
						const MString& briefName,
						MFnUnitAttribute::Type unitType,
						double defaultValue = 0.0,
						MStatus* ReturnStatus = NULL );
    ///
	MObject 	create( const MString& fullName,
						const MString& briefName,
						const MTime& defaultValue,
						MStatus* ReturnStatus = NULL );
    ///
	MObject 	create( const MString& fullName,
						const MString& briefName,
						const MAngle& defaultValue,
						MStatus* ReturnStatus = NULL );
    ///
	MObject 	create( const MString& fullName,
						const MString& briefName,
						const MDistance& defaultValue,
						MStatus* ReturnStatus = NULL );
    ///
	MFnUnitAttribute::Type	unitType( MStatus* ReturnStatus = NULL ) const;
    ///
	bool		hasMin( MStatus* ReturnStatus = NULL) const;
    ///
	bool		hasMax( MStatus* ReturnStatus = NULL) const;
    ///
	bool		hasSoftMin( MStatus* ReturnStatus = NULL) const;
    ///
	bool		hasSoftMax( MStatus* ReturnStatus = NULL) const;
    ///
	MStatus		getMin( double& minValue ) const;
    ///
	MStatus		getMin( MTime& minValue ) const;
    ///
	MStatus		getMin( MAngle& minValue ) const;
    ///
	MStatus		getMin( MDistance& minValue ) const;
    ///
	MStatus		getMax( double& maxValue ) const;
    ///
	MStatus		getMax( MTime& maxValue ) const;
    ///
	MStatus		getMax( MAngle& maxValue ) const;
    ///
	MStatus		getMax( MDistance& maxValue ) const;
    ///
	MStatus		getSoftMin( double& minValue ) const;
    ///
	MStatus		getSoftMin( MTime& minValue ) const;
    ///
	MStatus		getSoftMin( MAngle& minValue ) const;
    ///
	MStatus		getSoftMin( MDistance& minValue ) const;
    ///
	MStatus		getSoftMax( double& maxValue ) const;
    ///
	MStatus		getSoftMax( MTime& maxValue ) const;
    ///
	MStatus		getSoftMax( MAngle& maxValue ) const;
    ///
	MStatus		getSoftMax( MDistance& maxValue ) const;
    ///
	MStatus		setMin( double minValue );
    ///
	MStatus		setMin( const MTime &minValue );
    ///
	MStatus		setMin( const MAngle &minValue );
    ///
	MStatus		setMin( const MDistance &minValue );
    ///
	MStatus		setMax( double maxValue );
    ///
	MStatus		setMax( const MTime &maxValue );
    ///
	MStatus		setMax( const MAngle &maxValue );
    ///
	MStatus		setMax( const MDistance &maxValue );
    ///
	MStatus		setSoftMin( double minValue );
    ///
	MStatus		setSoftMin( const MTime &minValue );
    ///
	MStatus		setSoftMin( const MAngle &minValue );
    ///
	MStatus		setSoftMin( const MDistance &minValue );
    ///
	MStatus		setSoftMax( double maxValue );
    ///
	MStatus		setSoftMax( const MTime &maxValue );
    ///
	MStatus		setSoftMax( const MAngle &maxValue );
    ///
	MStatus		setSoftMax( const MDistance &maxValue );
    ///
	MStatus		getDefault( double & defaultValue );
    ///
	MStatus		getDefault( MTime & defaultValue );
	///
	MStatus     getDefault( MAngle & defaultValue );
	///
	MStatus     getDefault( MDistance & defaultValue );
    ///
	MStatus		setDefault( double defaultValue );
    ///
	MStatus		setDefault( const MTime& defaultValue );
	///
	MStatus     setDefault( const MAngle& defaultValue );
	///
	MStatus     setDefault( const MDistance& defaultValue );

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
#endif /* _MFnUnitAttribute */
