
#ifndef _MPolyMessage
#define _MPolyMessage
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
// CLASS:    MPolyMessage
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MPolyMessage)
//
// This class is used to register callbacks for poly messages.  Currently,
// you can use this class to listen to component id changes for vertices,
// edges and faces.
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

class MUintArray;
class MObject;

// *****************************************************************************

// CLASS DECLARATION (MPolyMessage)

/// Polygon component id change messages (OpenMaya)
/**
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MPolyMessage : public MMessage
{
public:
	enum
	{
		///
		kVertexIndex = 0,
		///
		kEdgeIndex = 1,
		///
		kFaceIndex = 2,
		///
		kLastErrorIndex = 3
	};
	
	///
	static MCallbackId	addPolyComponentIdChangedCallback (
								MObject& node,
								bool wantIdModifications[],
								unsigned int count,
								void (*func)(MUintArray componentIds[],
												unsigned int count,
												void *clientData),
								void * clientData = NULL,
								MStatus * ReturnStatus = NULL);
	///								
	static unsigned int deletedId( void );

private:
	static const char* className();
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************

#endif /* __cplusplus */
#endif /* _MPolyMessage */
