#ifndef LINUX
#pragma once
#endif
#ifndef _MTime
#define _MTime
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
// CLASS:    MTime
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MTime)
//
// The MTime class provides a fundamental type for the Maya API to hold and
// manipulate animation timing information in various unit systems.  All
// API methods that require or return timing information do so through
// variables of this type.
// 
// If one desires to manipulate time in such a way that integer changes in
// an MTime instance result in integer changes in the frame displayed by
// the timeslider, then an MTime instance should be created that uses UI
// units.  This can be done either by using the default constructor, or by
// passing the return value of the static method uiUnit to the normal
// constructor.  Once such an MTime instance is created, its value will be
// equivalent to a frame on the timeslider.
// 
// It should be noted that while the timeslider displays frames, a
// seemingly unitless value, Maya internally is operating based on the
// desired frameRate (one of those specified by the MTime::Unit enum.  It
// is necessary for the API programmer to be aware of this as MTime
// instances are not unitless and allow the manipulation of time in any
// desired units.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES

#include <maya/MTypes.h>

// *****************************************************************************

// DECLARATIONS

// *****************************************************************************

// CLASS DECLARATION (MTime)

///	Set and retrieve animation time values.
/**
 Methods for setting and retreiving animation times in various unit systems.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MTime  
{

public:
	///
	enum Unit {
		///
		kInvalid,
		/// 3600 seconds
		kHours,                             //      3600    sec 
		/// 60 seconds
		kMinutes,                           //      60      sec
		/// 1 second
		kSeconds,                           //      1       sec
		/// 1/1000 of a second
		kMilliseconds,                      //      1/1000  sec
		/// 15 frames per second
		kGames,                             //      1/15    sec
		/// 24 frames per second
		kFilm,                              //      1/24    sec
		/// 25 frames per second
		kPALFrame,                          //      1/25 sec (approx)
		/// 30 frames per second
		kNTSCFrame,                         //      1/30 sec (approx)
		/// twice the speed of film (48 frames per second)
		kShowScan,                          //      1/48    sec
		/// twice the speed of PAL (50 frames per second)
		kPALField,                          //      1/50 sec (approx)
		/// twice the speed of NTSC (60 frames per second)
		kNTSCField,                         //      1/60 sec (approx)
		/// user defined units (not implemented yet)
		kUserDef,                           //      user defined
		///
		kLast
	};
	///
					MTime();
	///
					MTime( const MTime & );
	///
					MTime( double time_val, Unit = kFilm );
	///
					~MTime();
	///
 	Unit     		unit() const;
	///
 	double   		value() const;
	///
 	MStatus 	 	setUnit( Unit new_unit );
	///
 	MStatus 		setValue( double new_value );
	///
 	double    		as( Unit other_unit ) const;
	///
	static Unit		uiUnit();
	///
	static MStatus	setUIUnit( Unit new_unit);

	///
	MTime&			operator =  ( const MTime& rhs );
	///
	bool			operator == ( const MTime& rhs ) const;
	///
	bool			operator != ( const MTime& rhs ) const;
	///
	bool			operator <= ( const MTime& rhs ) const;
	///
	bool			operator >= ( const MTime& rhs ) const;
	///
	bool			operator <  ( const MTime& rhs ) const;
	///
	bool			operator >  ( const MTime& rhs ) const;
	///
	MTime			operator +  ( const MTime& rhs ) const;
	///
	MTime&			operator += ( const MTime& rhs );
	///
	MTime			operator +  ( double rhs ) const;
	///
	MTime&			operator += ( double rhs );
	///
	MTime&			operator ++ ();
	///
	MTime&			operator ++ (int);
	///
	MTime			operator -  ( const MTime& rhs ) const;
	///
	MTime&			operator -= ( const MTime& rhs );
	///
	MTime			operator -  ( double rhs ) const;
	///
	MTime&			operator -= ( double rhs );
	///
	MTime&			operator -- ();
	///
	MTime&			operator -- (int);
	///
	MTime			operator *  ( double rhs ) const;
	///
	MTime&			operator *= ( double rhs );
	///
	MTime			operator /  ( double rhs ) const;
	///
	MTime&			operator /= ( double rhs );

	///
	friend OPENMAYA_EXPORT ostream&	operator << ( ostream& os, const MTime& t );

protected:
	// No protected members

private:


	friend class MTimeHelper;
	MTime			( int );
	static const	char* className();
 	int	val;
 	Unit	valUnit;
	void*   data;
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MTime */
