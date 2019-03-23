
#ifndef _MPxMidiInputDevice
#define _MPxMidiInputDevice
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
// CLASS:    MPxMidiInputDevice
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MPxMidiInputDevice)
//
//  Base class for user-defined midi input devices.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES

#ifdef SGI

#include <dmedia/midi.h>
#endif // SGI
#include <maya/MStatus.h>
#include <maya/MTypes.h>

// *****************************************************************************

// DECLARATIONS

class MDeviceState;
class MDeviceChannel;
class MString;

// *****************************************************************************

// CLASS DECLARATION (MPxMidiInputDevice)

/// Midi input device (OpenMayaUI)
/**

*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYAUI_EXPORT MPxMidiInputDevice
{
public:
	///
	MPxMidiInputDevice();
	///
	virtual ~MPxMidiInputDevice();

	///
	virtual	MStatus			openDevice();
	///
	virtual	void			closeDevice();

	///
	virtual	void			nameAxes();
	///
	virtual void			nameButtons();
	///
	virtual	MDeviceState* 	deviceState();
	///
#ifdef SGI
	virtual	MDeviceState* 	deviceState( MDevent& );
#endif // SGI

	///
	virtual MStatus 		sendMessage(	const char* const messageType,
											const char* const messageParams );
	///
	virtual char* 			getMessage(	const char* const messageType,
										char* messageResponse );

	///
	virtual void 			doButtonEvents( bool = true );
	///
	virtual void 			doMovementEvents( bool = true );

	///
	MPxMidiInputDevice( void * init );

protected:
	///
	MStatus		setNamedButton( MString &, unsigned short );
	///
	MStatus		addChannel( MDeviceChannel & );
	///
	MStatus 	setDegreesOfFreedom( int freedom );
	///
	MStatus 	setNumberOfButtons( int buttons );

private:
	void   setData( void* );
	virtual const char*	className() const;
	void * 	data;
	int 	degreesOfFreedom;
	int 	numberOfButtons;
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MPxMidiInputDevice */
