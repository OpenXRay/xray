
#ifndef _MUiMessage
#define _MUiMessage
//
// *****************************************************************************
//  Copyright (C) 1999-2003 Alias | Wavefront, Inc.
//
//  These coded instructions, statements and computer programs contain
//  unpublished information proprietary to Alias | Wavefront, Inc. and
//  are protected by the Canadian and US federal copyright law. They
//  may not be disclosed to third parties or copied or duplicated, in
//  whole or in part, without prior written consent of
//  Alias | Wavefront Inc.
//
//  Unpublished -- rights reserved under the Copyright Laws of
//  the United States.
//
// *****************************************************************************
//
// CLASS:    MUiMessage
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MUiMessage)
//
// This class is used to register callbacks for ui deleted messages.
// There is 1 add callback method which will add callbacks for the
// following message
//     UI Deleted
//
// To remove a callback use MMessage::removeCallback.
//
// All callbacks that are registered by a plug-in must be removed by that
// plug-in when it is unloaded. Failure to do so will result in a fatal error.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MMessage.h>

// *****************************************************************************

// DECLARATIONS


// *****************************************************************************

// CLASS DECLARATION (MUiMessage)

/// UI messages (OpenMayaUI)
/**
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYAUI_EXPORT MUiMessage : public MMessage
{
public:
	///
	static MCallbackId	addUiDeletedCallback(
								const MString& uiName,
								void (*func)( void* clientData ),
								void * clientData = NULL,
								MStatus * ReturnStatus = NULL );
	///
	static MCallbackId	addCameraChangedCallback(
								const MString& panelName,
								void (*func)( MString &panelName,
								MObject &camera, void* clientData ),
								void * clientData = NULL,
								MStatus * ReturnStatus = NULL );

private:
	static const char* className();
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************

#endif /* __cplusplus */
#endif /* _MUiMessage */
