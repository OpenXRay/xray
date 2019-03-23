#ifndef LINUX
#pragma once
#endif
#ifndef _MCommandResult
#define _MCommandResult
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
// CLASS:    MCommandResult
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MCommandResult)
//
//	An MCommandResult collects the result returned by MGlobal::executeCommand.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES

#include <maya/MStatus.h>
#include <maya/MObject.h>

// *****************************************************************************
// FORWARD DECLARATIONS
class MIntArray;
class MDoubleArray;
class MString;
class MStringArray;
class MVector;
class MVectorArray;
class MMatrix;
// *****************************************************************************

// *****************************************************************************

// CLASS DECLARATION (MCommandResult)

/// Result returned from executing a command.

/**
  An MCommandResult collects the result returned by MGlobal::executeCommand.
*/

#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MCommandResult {

public:
    /// Itemize the mel command result types:
    enum Type {	
	  /// 
	  kInvalid = 0,
	  ///
	  kInt,
	  ///
	  kIntArray,
	  ///
	  kDouble,
	  ///
	  kDoubleArray,
	  ///
	  kString,
	  ///
	  kStringArray,
	  ///
	  kVector,
      ///
      kVectorArray,
	  ///
      kMatrix,
	  ///
      kMatrixArray
	};

    /// 
    MCommandResult(MStatus* ReturnStatus = NULL );
	///
	virtual         ~MCommandResult();
	///
	Type            resultType(MStatus* ReturnStatus = NULL) const;
	///
	MStatus         getResult( int& ) const;
	///
    MStatus         getResult( MIntArray& ) const;
	///
	MStatus         getResult( double& ) const;
	///
	MStatus         getResult( MDoubleArray& ) const;
	///
	MStatus         getResult( MString& ) const;
	///
	MStatus         getResult( MStringArray& ) const;
	///
	MStatus         getResult( MVector& ) const;
	///
	MStatus         getResult( MVectorArray& ) const;
	/// 
	MStatus         getResult( MDoubleArray& result,
							   int &numRows, int &numColumns) const;
protected:
// No protected members

private:

    const char* className() const;
    void *fResult;
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MCommandResult */
