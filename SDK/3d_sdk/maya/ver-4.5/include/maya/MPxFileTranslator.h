#ifndef LINUX
#pragma once
#endif
#ifndef _MPxFileTranslator
#define _MPxFileTranslator
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
// CLASS:    MPxFileTranslator
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MPxFileTranslator)
//
//  This class provides a base class from which one derives in order to
//  implement Maya "File Translator Plug-Ins."  A file translator plug-in
//  allows Maya to read or write 3rd party file formats.
//  
//  The identifyFile method is called whenever Maya's file save or restore
//  dialogs are run, and identifyFile uses the filename and first few bytes
//  of the file to determine whether it is of a type supported by the
//  translator.  If it is, then Maya will display the file with the "name"
//  and "icon" specified as arguments to MFnPlugin::registerFileTranslator.
//  
//  If an attempt is made to read the file, the "reader" method in the
//  derived class is called, if an attempt is made to write the file, the
//  "writer" method is called.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MStatus.h>
#include <maya/MString.h>
#include <maya/MTypes.h>
#include <maya/MFileObject.h>

// *****************************************************************************

// DECLARATIONS

// *****************************************************************************

// CLASS DECLARATION (MPxFileTranslator)

/// Base Class for creating Maya File Translators
/**
  This class provides the connection to Maya by which user written file
  translators can be added as plug-ins.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MPxFileTranslator  
{

public:
	///
	enum MFileKind {
		/// Translator understands how to read/write this file
		kIsMyFileType,
		/// Translator is not best available to read/write this file
		kCouldBeMyFileType,
		/// Translator does not understand how to read/write this file
		kNotMyFileType
	};
	///
	enum FileAccessMode {
		/// Unknown file access mode
		kUnknownAccessMode,
		/// Import data into new scene
		kOpenAccessMode,
		/// Import data into current scene
		kImportAccessMode,
		/// Save data
		kSaveAccessMode,
		/// Export data
		kExportAccessMode,
		/// Export active (selected) data
		kExportActiveAccessMode
	};
	///
						MPxFileTranslator ();
	///
	virtual				~MPxFileTranslator ();	
	///
	virtual MStatus		reader ( const MFileObject& file,
								 const MString& optionsString,
								 FileAccessMode mode);
	///
	virtual MStatus		writer ( const MFileObject& file,
								 const MString& optionsString,
								 FileAccessMode mode);
	///
	virtual bool		haveReadMethod () const;
	///
	virtual bool		haveWriteMethod () const;
	///
	virtual MString     defaultExtension () const;
	///
	virtual bool        canBeOpened () const;
	///
	virtual MPxFileTranslator::MFileKind identifyFile (	const MFileObject& file,
														const char* buffer,
														short size) const;

protected:
// No protected members

private:

	void*				data;

};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MPxFileTranslator */
