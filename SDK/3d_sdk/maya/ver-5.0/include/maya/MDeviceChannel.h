
#ifndef _MDeviceChannel
#define _MDeviceChannel
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
