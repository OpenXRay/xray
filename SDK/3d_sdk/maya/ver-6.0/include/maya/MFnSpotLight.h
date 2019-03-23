
#ifndef _MFnSpotLight
#define _MFnSpotLight
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
// CLASS:    MFnSpotLight
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnSpotLight)
//
// MFnSpotLight facilitates creation and manipulation of dependency graph nodes
// representing spotlights.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MFnDagNode.h>
#include <maya/MObject.h>
#include <maya/MStatus.h>
#include <maya/MFnNonExtendedLight.h>

// *****************************************************************************

// DECLARATIONS

class MFltMatrix;

// *****************************************************************************

// CLASS DECLARATION (MFnSpotLight)

/// Manage Spot Light dependency Nodes
/**
  Facilitate the creation and manipulation of spot light nodes
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MFnSpotLight : public MFnNonExtendedLight 
{

	declareDagMFn(MFnSpotLight,MFnNonExtendedLight);
public:
	///
	enum MBarnDoor { kLeft,
					 kRight,
					 kTop,
					 kBottom };
	///
	enum MDecayRegion { kFirst,
						kSecond,
						kThird };
	///
	MObject     create( bool UIvisible = true, MStatus * ReturnStatus = NULL );
	///
	MObject     create( const MObject& parent, bool UIvisible = true,
						MStatus * ReturnStatus = NULL );
	///
	double      coneAngle( MStatus * ReturnStatus = NULL ) const;
	///
    MStatus     setConeAngle( const double& coneAngle );
	///
	double      penumbraAngle( MStatus * ReturnStatus = NULL ) const;
	///
	MStatus     setPenumbraAngle( const double& penumbraAngle );
	///
	double      dropOff( MStatus * ReturnStatus = NULL ) const;
	///
	MStatus     setDropOff( const double& dropOff );
	///
	bool        barnDoors( MStatus * ReturnStatus = NULL ) const;
	///
	MStatus     setBarnDoors( const bool& barnDoors );
	///
	double      barnDoorAngle( MBarnDoor which_door,
						MStatus * ReturnStatus = NULL ) const;
	///
	MStatus     setBarnDoorAngle( MBarnDoor which_door,
						const double& barn_door_angle );
	///
	bool        useDecayRegions( MStatus * ReturnStatus = NULL ) const;
	///
	MStatus     setUseDecayRegions( const bool& use_decay_regions );
	///
	float       startDistance( MDecayRegion which_region,
						MStatus * ReturnStatus = NULL ) const;
	///
	MStatus     setStartDistance( MDecayRegion which_region,
						const float& start_distance );
	///
	float       endDistance( MDecayRegion which_region,
						MStatus * ReturnStatus = NULL ) const;
	///
	MStatus     setEndDistance( MDecayRegion which_region,
						const float& end_distance );

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
#endif /* _MFnSpotLight */



