#ifndef _MString
#define _MString
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
// CLASS:    MString
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MString)
//
//  The MString class implements a string class, and is used to pass
//  all string arguments to Maya API methods.

//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES



#include <maya/MTypes.h>
#include <maya/MStatus.h>

// *****************************************************************************

// DECLARATIONS

class MStringArray;

// *****************************************************************************

// CLASS DECLARATION (MString)

/// Manipulate strings.
/**
 Methods for handling strings.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MString  
{

public:
	///
				MString();
	///
				MString( const char* charString );
    ///
                MString( const char* charString, int charLength );
	///
				MString( const MString& other );
	///
	        	~MString();
	///
	MString&	operator += ( const MString& other );
	///
	MString&	operator += ( const char * other );
	///
	MString&	operator += ( double other );
	///
	MString&	operator += ( int other );
	///
	MString&	operator =  ( const MString& other );
	///
	MString&	operator =  ( const char * other );
	///
	MString&	operator =  ( double value );
	///
	bool		operator == ( const MString& other ) const;
	///
	bool		operator == ( const char * other ) const;
	///
	bool		operator != ( const MString& other ) const;
	///
	bool		operator != ( const char * other ) const;
	///
	MString     operator + (const MString& other ) const;
	///
	MString     operator + (const char * other ) const;
	///
	MString     operator + ( double value ) const;
	///
	MStatus		set( const char * charString );
    ///
    MStatus     set( const char * charString, int charLength );
	///
	MStatus		set( double value );
    ///
	MStatus		set( double value, int precision );
    ///
	const char*	asChar() const;
	///
	unsigned	length() const;
	///
	void		clear();
	///
	int			index(char) const;
	///
	int			rindex(char) const;
	///
	MStatus		split(char, MStringArray&) const;
	///
	MString		substring(int start, int end) const;
	///
	MString&	toUpperCase();
	///
	MString&	toLowerCase();
	///
	bool		isShort() const;
	///
	short		asShort() const;
	///
	bool		isInt() const;
	///
	int			asInt() const;
	///
	bool		isUnsigned() const;
	///
	unsigned	asUnsigned() const;
	///
	bool		isFloat() const;
	///
	float		asFloat() const;
	///
	bool		isDouble() const;
	///
	double		asDouble() const;
	///
	MString		expandEnvironmentVariablesAndTilde( MStatus * ReturnStatus = NULL );

	///
	friend OPENMAYA_EXPORT IOS_REF(ostream)& operator<<(IOS_REF(ostream)&, const MString& );
	///
	friend OPENMAYA_EXPORT MString operator+(const char *, const MString& );

protected:
// No protected members

private:
	void*	api_data;
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MString */
