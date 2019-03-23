
#ifndef _MDeviceChannel
#define _MDeviceChannel
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
// CLASS:    MDeviceChannel
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MDeviceChannel)
//
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MStatus.h>

// *****************************************************************************

// DECLARATIONS

class MDeviceState;
class MString;

// *****************************************************************************

// CLASS DECLARATION (MDeviceChannel)

/// Input device channel (OpenMayaUI)
/**


*/

#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYAUI_EXPORT MDeviceChannel
{
public:
	///
	MDeviceChannel( const MString&, MDeviceChannel* = NULL, int = -1 );

	///
	~MDeviceChannel();


	///
	MString 			name() const;
	///
	MString 			longName() const;

	///
	int				axisIndex() const;

	///
	bool     			hasChildren() const;
	///
	MDeviceChannel	 	parent() const;
	///
	MDeviceChannel 		childByIndex( int );
	///
	int					numChildren() const;

protected:
	// no protected members

private:
	friend class MPxMidiInputDevice;
	MDeviceChannel( void * );
	void * data;
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MDeviceChannel */
