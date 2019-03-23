
#ifndef _MFnSpotLight
#define _MFnSpotLight
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



