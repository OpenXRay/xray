#ifndef LINUX
#pragma once
#endif
#ifndef _MEventMessage
#define _MEventMessage
//
// *****************************************************************************
//  Copyright (C) 1999-2001 Alias | Wavefront, Inc.
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
// CLASS:    MEventMessage
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MEventMessage)
//
// This class is used to register callbacks for event messages.
// There is 1 add callback method which will add callbacks for the
// following message
//     Event occurred
//
// The list of available event names can be retrieved with the
// getEventNames method.
//
// To remove a callback use MMessage::removeCallback.
// All callbacks that are registered by a plug-in must be removed by that
// plug-in when it is unloaded. Failure to do so will result in a fatal error.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES

#include <maya/MMessage.h>
#include <maya/MStringArray.h>

// *****************************************************************************

// DECLARATIONS


// *****************************************************************************

// CLASS DECLARATION (MEventMessage)

/// Event messages 
/**
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MEventMessage : public MMessage
{ 
public:
	///
	static MCallbackId	addEventCallback(
								const MString& event,
								void (*func)( void* clientData ),
								void * clientData = NULL,
								MStatus * ReturnStatus = NULL );

	///
	static MStatus		getEventNames( MStringArray & names );

private: 
	static const char* className();
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************

#endif /* __cplusplus */
#endif /* _MEventMessage */
