#ifndef LINUX
#pragma once
#endif
#ifndef _MAnimMessage
#define _MAnimMessage
//
// *****************************************************************************
//
// Copyright (C) 1998-2001 Alias|Wavefront Inc.
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
// CLASS:    MAnimMessage
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MAnimMessage)
//
// This class is used to register callbacks for animation messages.
// There is 1 add callback method which will add callbacks for the
// following message
//     Anim curve edited
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
#include <maya/MString.h>

// *****************************************************************************

// DECLARATIONS

class MObjectArray;

// *****************************************************************************

// CLASS DECLARATION (MAnimMessage)
 
/// Animation messages (OpenMayaAnim)
/**
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYAANIM_EXPORT MAnimMessage : public MMessage
{ 
public:
	/// AnimCurve edited callback
	static MCallbackId	addAnimCurveEditedCallback (
								void (*func)(MObjectArray &editedCurves,
											  void *clientData),
								void * clientData = NULL,
								MStatus * ReturnStatus = NULL);

private: 
	static const char* className();
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************

#endif /* __cplusplus */
#endif /* _MAnimMessage */
