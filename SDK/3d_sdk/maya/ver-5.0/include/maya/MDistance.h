
#ifndef _MDistance
#define _MDistance
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
// CLASS:    MDistance
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MDistance)
//
//	The MDistance class provides a fundamental type for the Maya API to hold
//	and manipulate linear data.  All API methods that require or return
//	linear information do so through variables of this type.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MStatus.h>
#include <maya/MTypes.h>

// *****************************************************************************

// DECLARATIONS

// *****************************************************************************

// CLASS DECLARATION (MDistance)

/// Manipulate Linear Data
/**
  Methods for setting and retreiving linear data in various unit systems 
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MDistance  
{
public:
	/// Available Unit Systems
	enum Unit
	{
		///
		kInvalid,
		/// Inches
		kInches,
		/// Feet
		kFeet,
		/// Yards
		kYards,
		/// Miles
		kMiles,
		/// Millimeters
		kMillimeters,
		/// Centimeters
		kCentimeters,
		/// Kilometers
		kKilometers,
		/// Meters
		kMeters,
		///
		kLast
	};
	///
					MDistance();
	///
					MDistance( double value, Unit unitSystem = kCentimeters );
	///
					MDistance( const MDistance& src );
	///
					~MDistance();  
	///
	MDistance&		operator=( const MDistance& src ); 
	///
	Unit			unit() const;
	///
	double			value() const;
	///
	MStatus			setUnit( Unit newUnit );
	///
	MStatus			setValue( double newValue );
	///
	double			as( Unit newUnit, MStatus *ReturnStatus = NULL ) const;
	///
	double			asInches() const;
	///
	double			asFeet() const;  
	///
	double			asYards() const;  
	///
	double			asMiles() const;  
	///
	double			asMillimeters() const;
	///
	double			asCentimeters() const;  
	///
	double			asKilometers() const;  
	///
	double			asMeters()  const;  
	///
	static Unit		uiUnit();
	///
	static MStatus	setUIUnit( Unit newUnit );
	///
	static Unit		internalUnit();
	///
	static double	internalToUI( double internalValue );
	///
	static double	uiToInternal( double uiValue );
	///OBSOLETE Changing the internal units is generally not a good idea and using this method may often produce unexpected results.
	static MStatus  setInternalUnit( Unit internalUnit );

protected:
	double			val;
	Unit			valUnit;

private:

	static const char* className();

};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MDistance */
