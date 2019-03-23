
#ifndef _MMessage
#define _MMessage
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
// CLASS:    MMessage
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MMessage)
//
// This is the base class for message callbacks.
// 
// There are three types of messages in maya that are exposed through the
// API and they are the following:
// scene messages, dependency graph messages, and dependency node messages.
// can be registered for these messages using the addCallback
// methods of the MSceneMessage, MDGMessage, and MNodeMessage classes.
// 
// When a callback is added a number or id is returned. This id is used to
// keep track of the callback and is necessary for removing it.
// A callback id with the value 'NULL' represents an invalid callback.
// Use the removeCallback member function of this class for removing a
// callback.
//
// It is the user's responsibility to keep track of the callback id's
// and remove all callbacks for a plug-in when it is unloaded.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MStatus.h>

// *****************************************************************************

// DECLARATIONS

typedef unsigned int MCallbackId;

// Declaration for the callback table
typedef struct MMessageNode {
    void*           fClientPtr;
	void*			fServerPtr;
	void*           fSubClientPtr;
	MCallbackId		fId;
	bool			isValid;	// Unused
} * MMessageNodePtr;

// *****************************************************************************

// CLASS DECLARATION (MMessage)

class MIntArray;
class MObject;

/// Message base class
/**
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MMessage
{ 
public:	
	///
    static MStatus  removeCallback( MCallbackId id );
	///
    static MStatus  removeCallbacks( MIntArray &ids );
	///
	static MCallbackId	currentCallbackId( MStatus* ReturnStatus = NULL );
	///
	static MStatus	nodeCallbacks( MObject& node, MIntArray& ids );

protected:
    static void addNode( MMessageNodePtr node ); 
    static void removeNode( MMessageNodePtr node );

private:
	static const char* 		className();
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************

#endif /* __cplusplus */
#endif /* _MMessage */
