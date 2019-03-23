#ifndef _MSceneMessage
#define _MSceneMessage
//
// *****************************************************************************
// Copyright  (C)  Alias|Wavefront,  a division of Silicon Graphics  Limited.
// All rights  reserved.  These coded  instructions,  statements and computer
// programs contain unpublished information  proprietary to  Alias|Wavefront,
// a  division  of  Silicon  Graphics  Limited,  which  is  protected by  the
// Canadian  and  US federal copyright law and  may not be disclosed to third
// parties or  copied  or  duplicated,  in  whole  or in part,  without prior
// written consent of Alias|Wavefront, a division of Silicon Graphics Limited
// *****************************************************************************
//
// CLASS:    MSceneMessage
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MSceneMessage)
//
// This class is used to register callbacks for scene related messages.
//
// The addCallback method registers a function that will be executed
// whenever the specified message occurs. An id is returned and is used
// to remove the callback.
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

// *****************************************************************************

// DECLARATIONS

// *****************************************************************************

// CLASS DECLARATION (MSceneMessage)

/// Scene messages
/**
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MSceneMessage : public MMessage
{
public:
	///
	enum Message {
		/// called after any operation that changes which files are loaded
		kSceneUpdate,
		/// called before a File > New operation
		kBeforeNew,
		/// called after a File > New operation
		kAfterNew,
		/// called before a File > Import operation
		kBeforeImport,
		/// called after a File > Import operation
		kAfterImport,
		/// called before a File > Open operation
		kBeforeOpen,
		/// called after a File > Open operation
		kAfterOpen,
		/// called before a File > Export operation
		kBeforeExport,
		/// called after a File > Export operation
		kAfterExport,
		/// called before a File > Save (or SaveAs)  operation
		kBeforeSave,
		/// called after a File > Save (or SaveAs)  operation
		kAfterSave,
        /// called before a File > Reference operation
        kBeforeReference,
        /// called after a File > Reference operation
        kAfterReference,
        /// called before a File > RemoveReference operation
        kBeforeRemoveReference,
        /// called after a File > RemoveReference operation
        kAfterRemoveReference,
		/// called before a File > ImportReference operation
		kBeforeImportReference,
		/// called after a File > ImportReference operation
		kAfterImportReference,
		/// called before a File > ExportReference operation
		kBeforeExportReference,
		/// called after a File > ExportReference operation
		kAfterExportReference,

		/// called before a Software Render begins
		kBeforeSoftwareRender,
		/// called after a Software Render ends
		kAfterSoftwareRender,
		/// called before each frame of a Software Render
		kBeforeSoftwareFrameRender,
		/// called after each frame of a Software Render
		kAfterSoftwareFrameRender,
		/// called when an interactive render is interrupted by the user
		kSoftwareRenderInterrupted,

		/// called on interactive or batch startup after initialization
		kMayaInitialized,
		/// called just before Maya exits
		kMayaExiting
   };

public:
	// Since there is no data associated with scene messages there
	// is a single "addCallback" function for all message types.
	//
	///
	static MCallbackId	addCallback( Message, void (*func)( void* clientData ),
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
#endif /* _MSceneMessage */
