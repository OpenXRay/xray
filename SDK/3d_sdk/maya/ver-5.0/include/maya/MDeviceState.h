
#ifndef _MDeviceState
#define _MDeviceState
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
// CLASS:    MDeviceState
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MDeviceState)
//
//	MDeviceState is a generic event class for input devices.
//	Input device classes (such as MPxMidiInputDevice) are responsible for
//	converting specific event types to an MDeviceState which Maya understands.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MTypes.h>

// *****************************************************************************

// DECLARATIONS

class MString;
class THeventInputDevice;

// *****************************************************************************

// CLASS DECLARATION (MDeviceState)

/// Input device state (OpenMayaUI)
/**

*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYAUI_EXPORT MDeviceState
{
public:
	///
	virtual ~MDeviceState();

	///
	int		devicePosition( const unsigned short int axis) const;
	///
	int		devicePosition( const MString & axisName ) const;
	///
	void	setDevicePosition( const int position,
							   const unsigned short int axis);
	///
	void	setDevicePosition( const int position,
							   const MString & axisName );

	///
	bool	buttonState( const unsigned short int button ) const;
	///
	bool	buttonState( const MString & buttonName ) const;
	///
	void	setButtonState( const bool state,
							const unsigned short int button );
	///
	void	setButtonState( const bool state,
							const MString & buttonName );

	///
	int		maxAxis() const;

	///
	bool	isNull();

protected:
// No protected members

private:
	MDeviceState( void * );
	void *   data();
	void * api_stateData;
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MDeviceState */
