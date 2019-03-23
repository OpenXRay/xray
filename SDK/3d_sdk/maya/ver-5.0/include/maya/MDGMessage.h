#ifndef _MDGMessage
#define _MDGMessage
//
// *****************************************************************************
//
// Copyright (C) 1998-2003 Alias|Wavefront Inc.
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
// CLASS:    MDGMessage
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MDGMessage)
//
// This class is used to register callbacks for dependency graph messages.
// There are 4 add callback methods which will add callbacks for the
// following messages
//     Time change
//     Node Added
//     Node Removed
//     Connection made or broken
//
// A filter can be specified for node added/removed messages. The default 
// node type is "dependNode" which matches all nodes.
// Each method returns an id which is used to remove the callback.
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

class MTime;
class MObject;
class MPlug;

#define kDefaultNodeType "dependNode"

// *****************************************************************************

// CLASS DECLARATION (MDGMessage)

/// Dependency graph messages 
/**
*/
#if defined(_WIN32)
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MDGMessage : public MMessage
{ 
public:
	/// TimeChange callback
	static MCallbackId	addTimeChangeCallback(
								void (*func)( MTime& time,
											  void * clientData ),
								void * clientData = NULL,
								MStatus * ReturnStatus = NULL );

	/// ForceUpdate callback
	static MCallbackId  addForceUpdateCallback(
								void (*func)( MTime& time,
								void * clientData ),
								void * clientData = NULL,
								MStatus * ReturnStatus = NULL );

	/// NodeAdded callback
	static MCallbackId	addNodeAddedCallback(
								void (*func)( MObject& node,
											  void* clientData ),
								const MString& nodeType = kDefaultNodeType,
								void * clientData = NULL,
								MStatus * ReturnStatus = NULL );

	/// NodeRemoved callback
	static MCallbackId	addNodeRemovedCallback(
								void (*func)( MObject& node,
											  void* clientData ),
								const MString& nodeType = kDefaultNodeType,
								void * clientData = NULL,
								MStatus * ReturnStatus = NULL );

	/// Connection callback
	static MCallbackId	addConnectionCallback(
								void (*func)( MPlug& srcPlug,
											  MPlug& destPlug,
											  bool made,
											  void* clientData ),
								void * clientData = NULL,
								MStatus * ReturnStatus = NULL );

private: 
	static const char* className();
};

#if defined(_WIN32)
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************

#endif /* __cplusplus */
#endif /* _MDGMessage */
