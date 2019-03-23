#ifndef LINUX
#pragma once
#endif
#ifndef _MConditionMessage
#define _MConditionMessage
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
// CLASS:    MConditionMessage
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MConditionMessage)
//
// This class is used to register callbacks for changes to specific
// conditions and/or to determine the current state of a condition.
// 
// The addConditionCallback method allows callbacks to be registered
// for the following messages:
// 	   Condition Changed
// 
// The first parameter passed to the add callback method is the 
// name of the condition that will trigger the callback.  The names of
// available conditions can be retrieved with the getConditionNames
// method.
// 
// Callbacks that are registered for conditions will be passed an
// bool parameter that is the state of the condition.
// 
// Each method returns an id which is used to remove the callback.
// 
// To remove a callback use MMessage::removeCallback.
// 
// All callbacks that are registered by a plug-in must be removed by that
// plug-in when it is unloaded. Failure to do so will result in a fatal error.
//
// The getConditionState method is used to return the current status
// of the specified condition.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES

#include <maya/MMessage.h>
#include <maya/MString.h>
#include <maya/MStringArray.h>

// *****************************************************************************

// DECLARATIONS


// *****************************************************************************

// CLASS DECLARATION (MConditionMessage)

/// Condition change messages 
/**
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MConditionMessage : public MMessage
{ 
public:
	///
	static MCallbackId	addConditionCallback(
								const MString& condition,
								void (*func)( bool state,
											  void* clientData ),
								void * clientData = NULL,
								MStatus * ReturnStatus = NULL );

	///
	static MStatus		getConditionNames( MStringArray & names );

	///
	static bool			getConditionState( const MString& condition,
										   MStatus * ReturnStatus = NULL );

private: 
	static const char* className();
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************

#endif /* __cplusplus */
#endif /* _MConditionMessage */
