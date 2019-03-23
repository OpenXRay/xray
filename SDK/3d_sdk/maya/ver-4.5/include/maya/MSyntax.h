#ifndef LINUX
#pragma once
#endif
#ifndef _MSyntax
#define _MSyntax
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
// CLASS:    MSyntax
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MSyntax)
//
//  This class is used to specify flags and arguments passed to commands.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES

#include <maya/MStatus.h>
#include <maya/MTypes.h>

// *****************************************************************************

// DECLARATIONS

// *****************************************************************************

// CLASS DECLARATION (MSyntax)

/// Syntax for Commands.
/**
This class is used to specify flags and arguments passed to commands.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32


class OPENMAYA_EXPORT MSyntax {
public:

	// argument type
	///
	enum MArgType {
		///
		kInvalidArgType,
		///
		kNoArg,
		///
		kBoolean,
		/// 
		kLong,
		///
		kDouble,
		///
		kString,
		///
		kUnsigned,
		///
		kDistance,
		///
		kAngle,
		///
		kTime,
		///
		kSelectionItem,
		///
		kLastArgType
	};

	// Object list type enum
	///
	enum MObjectFormat { 
		///
		kInvalidObjectFormat,
		///
		kNone,
		///
		kStringObjects,
		///
		kSelectionList,
		///
		kLastObjectFormat
	};

	///
		    MSyntax ();
	///
		    MSyntax ( const MSyntax& other );
	///
	virtual ~MSyntax();
	///
	MSyntax &operator=(const MSyntax &rhs);

	///
	MStatus	addFlag					(const char *shortName,
									 const char *longName,
									 MArgType argType1 = kNoArg,
									 MArgType argType2 = kNoArg,
									 MArgType argType3 = kNoArg,
									 MArgType argType4 = kNoArg,
									 MArgType argType5 = kNoArg,
									 MArgType argType6 = kNoArg);

	///
	MStatus	makeFlagMultiUse		(const char *flag);

	///
	MStatus	addArg					(MArgType arg);
	
	///
	void	useSelectionAsDefault	(bool useSelectionList = false);

	///
	MStatus	setObjectType			(MObjectFormat objectFormat, 
									 unsigned minimumObjects = 0);
	///
	MStatus	setObjectType			(MObjectFormat objectFormat, 
									 unsigned minimumObjects, 
									 unsigned maximumObjects);

	///
	void	setMinObjects			(unsigned minimumObjectCount);
	///
	void	setMaxObjects			(unsigned maximumObjectCount);
	///
	void	enableQuery				(bool supportsQuery = true);
	///
	void	enableEdit				(bool supportsEdit = true);

	///
	unsigned	minObjects			() const;
	///
	unsigned	maxObjects			() const;
	///
	bool		canQuery			() const;
	///
	bool		canEdit				() const;

protected:
// No protected members

private:
	const char *className() const;



	MSyntax(void *);
	MSyntax(const void *);
	bool fOwn;

	void * apiData;
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

#endif /* __cplusplus */
#endif /* _MSyntax */
