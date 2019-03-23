
#ifndef _MPxMidiInputDevice
#define _MPxMidiInputDevice
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
