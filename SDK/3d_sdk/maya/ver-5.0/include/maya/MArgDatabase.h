
#ifndef _MArgDatabase
#define _MArgDatabase
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
// CLASS:    MArgDatabase
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MArgDatabase)
//
// This class is used to parse and store all of the flags, arguments
// and objects which are passed to a command.  The MArgDatabase accepts
// an MSyntax object, which describes the format for a command, and uses
// it to parse the command arguments into a form which is easy to query.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MStatus.h>
#include <maya/MTypes.h>
#include <maya/MArgParser.h>

// *****************************************************************************

// DECLARATIONS

class MSyntax;
class MSelectionList;
class MStringArray;
class MArgList;
class MDistance;
class MAngle;
class MTime;

// *****************************************************************************

// CLASS DECLARATION (MArgDatabase)

/// Command argument list parser.
/**
This class parses argument lists based on a syntax object (MSyntax) 
which describes the format for a command.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MArgDatabase : public MArgParser
{
public:
	///
			MArgDatabase		();
	///
			MArgDatabase		(const MSyntax &syntax,
								 const MArgList &argList,
								 MStatus *ReturnStatus = NULL);
	///
	virtual ~MArgDatabase();

	///
	MStatus getFlagArgument		(const char *flag, unsigned index, 
								 MSelectionList &result) const;
	///
	MStatus	getCommandArgument	(unsigned index, MSelectionList &result) const;

	///
	MStatus	getObjects			(MSelectionList &result) const;

	// Redeclarations of overloaded methods from MArgParser
	MStatus	getFlagArgument		(const char *flag, unsigned index, 
								 bool &result) const;
	MStatus	getFlagArgument		(const char *flag, unsigned index,
								 int &result) const;
	MStatus	getFlagArgument		(const char *flag, unsigned index, 
								 double &result) const;
	MStatus	getFlagArgument		(const char *flag, unsigned index, 
								 MString &result) const;
	MStatus getFlagArgument		(const char *flag, unsigned index, 
								 unsigned &result) const;
	MStatus	getFlagArgument		(const char *flag, unsigned index, 
								 MDistance &result) const;
	MStatus	getFlagArgument		(const char *flag, unsigned index, 
								 MAngle &result) const;
	MStatus	getFlagArgument		(const char *flag, unsigned index, 
								 MTime &result) const;
	MStatus	getCommandArgument	(unsigned index, bool &result) const;
	MStatus	getCommandArgument	(unsigned index, int &result) const;
	MStatus	getCommandArgument	(unsigned index, double &result) const;
	MStatus	getCommandArgument	(unsigned index, MString &result) const;
	MStatus	getCommandArgument	(unsigned index, MDistance &result) const;
	MStatus	getCommandArgument	(unsigned index, MAngle &result) const;
	MStatus	getCommandArgument	(unsigned index, MTime &result) const;
	MStatus	getObjects			(MStringArray &result) const;

protected:
// No protected members

private:
	const char *className() const;
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MArgDatabase */

