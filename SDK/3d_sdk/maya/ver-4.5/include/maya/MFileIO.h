#ifndef LINUX
#pragma once
#endif
#ifndef _MFileIO
#define _MFileIO
//
// *****************************************************************************
//
// Copyright (C) 1997-2001 Alias|Wavefront Inc.
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
// CLASS:    MFileIO
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFileIO)
//
//	The MFileIO class provides a set of global functions that can be used to
//	load and store scene elements into maya files.  Methods are also provided
//	to import elements from other files into the current scene, and export
//	elements of the current scene into files.  As well, references to other
//	files can be created and removed.
//	
//	This class implements only the most common operations from the full set
//	possible with the MEL command "file."  See the documentation of this
//	command for a complete listing of all the possiblities.  If more control
//	is required than provided by this class, a MEL command can be constructed
//	according to the instructions for the "file" command, and issued via the
//	executeCommand method of the MGlobal class.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES

#include <maya/MObject.h>
#include <maya/MPlugArray.h>
#include <maya/MStatus.h>
#include <maya/MString.h>
#include <maya/MStringArray.h>
#include <maya/MSelectionList.h>
#include <maya/MTypes.h>

// *****************************************************************************

// DECLARATIONS

// *****************************************************************************

// CLASS DECLARATION (MFileIO)

/// I/O operations on scene files.
/**
 Methods for opening, saving, importing, exporting and referencing files.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MFileIO  
{

public:
	///
						MFileIO ();
	///
						MFileIO ( const MString& fileName );
	///
	virtual				~MFileIO ();
	///
	static MString		currentFile ();
	///
	static MStatus		setCurrentFile ( const MString& fileName );
	///
	static MString		fileType();
	///
	static MStatus		getFileTypes ( MStringArray& types );
	///
	static MStatus		newFile ( bool force = false );
	///
	static MStatus		open ( const MString& fileName,
							   const char* type = NULL,
							   bool force = false );
	///
	static MStatus		save ( bool force = false );
	///
	static MStatus		saveAs ( const MString& fileName,
							     const char* type = NULL,
								 bool force = false );
	///
	static MStatus		import ( const MString& fileName,
								 const char* type = NULL);
	///
	static MStatus		exportSelected ( const MString& fileName,
								 const char* type = NULL);
	///
	static MStatus		exportAll ( const MString& fileName,
								 const char* type = NULL);
	///
	static MStatus		getReferences ( MStringArray& references );
	///
	static MStatus		getReferenceNodes ( const MString &fileName,
											MStringArray& nodes );
	///
	static MStatus		getReferenceConnectionsMade ( const MString &fileName,
													  MStringArray& connections );
	///
	static MStatus		getReferenceConnectionsBroken(
							const MString&	fileName,
							MStringArray&	connections
						);
	///
	static MStatus		getReferenceConnectionsBroken(
							const MString&	fileName,
							MPlugArray&		srcPlugs,
							MPlugArray&		destPlugs
						);
	///
	static MStatus		getReferenceConnectionsBroken(
							const MObject&	node,
							MStringArray&	connections,
							bool			append = false,
							bool			removeDuplicates = true
						);
	///
	static MStatus		getReferenceConnectionsBroken(
							const MObject&	node,
							MPlugArray&		srcPlugs,
							MPlugArray&		destPlugs,
							bool			append = false,
							bool			removeDuplicates = true
						);
	///
	static MStatus		reference ( const MString& fileName );
	///
	static MStatus		removeReference ( const MString& fileName );
	///
	static bool			isReadingFile();
	///
	static bool			isWritingFile();

protected:
// No protected members

private:
// No private members

};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MFileIO */
