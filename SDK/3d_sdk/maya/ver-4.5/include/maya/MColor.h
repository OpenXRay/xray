#ifndef LINUX
#pragma once
#endif
#ifndef _MColor
#define _MColor
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
// CLASS:    MColor
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MColor)
//
// This class provides a type used to get/set values of color attributes in
// dependency nodes.  It represents colors as an RGB triple.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES

#include <maya/MTypes.h>

// *****************************************************************************

// DECLARATIONS

// *****************************************************************************

// CLASS DECLARATION (MColor)

/// A color math class
/**
    This class is used to store values of color-related dependency graph node
    attributes.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MColor  
{
public:
	///
	enum MColorType {
		///
		kRGB,
		///
		kHSV,
		///
		kCMY,
		///
		kCMYK
	};

	///
					MColor();
	///
					MColor( const MColor&);
	///
					MColor( float rr, float gg, float bb=0.0, float aa=1.0 );
	///
					MColor( const float[3] );

	///
					MColor( MColorType colorModel,
							unsigned char, unsigned char, unsigned char,
							unsigned char alpha=255U );
	///
					MColor( MColorType colorModel,
							unsigned short, unsigned short, unsigned short,
							unsigned short alpha=65535U );
	///
					MColor( MColorType colorModel, float, float, float,
							float alpha=1.0 );
	///
					MColor( MColorType colorModel, double, double, double,
							double alpha=1.0 );

	///
					~MColor();
	///
 	MColor&		    operator= ( const MColor& src );
	///
 	float&      	operator()( unsigned i );
	///
 	float   		operator()( unsigned i ) const;
	///
 	float&      	operator[]( unsigned i );
	///
	float			operator[]( unsigned i )const;
	///
 	MColor&   		operator/=( float scalar );
	///
 	MColor     	    operator/( float scalar ) const;
	///
 	MColor& 		operator*=( float scalar );
	///
 	MColor   		operator*( float scalar ) const;
	///
 	friend OPENMAYA_EXPORT MColor	operator*( float, const MColor&);
	///
 	MColor   		operator+( const MColor& other) const;
	///
	MColor&		    operator+=( const MColor& other );
	///
 	MColor   		operator-() const;
	///
 	MColor   		operator-( const MColor& other ) const;
	///
 	MColor          operator*( const MColor& other ) const;
	///
	MColor&         operator*=( const MColor& other );
	///
 	bool          	operator!=( const MColor& other ) const;
	///
 	bool           	operator==( const MColor& other ) const;
	///
	bool			get( float[3] ) const;

	///
	friend OPENMAYA_EXPORT ostream& operator<<(ostream& os, const MColor& c);

    /// the red component of the color
	float r;
    /// the green component of the color
	float g;
    /// the blue component of the color
	float b;
	/// the alpha component of the color
	float a;


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
#endif /* _MColor */
