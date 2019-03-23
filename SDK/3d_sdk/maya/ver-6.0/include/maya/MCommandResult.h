
#ifndef _MCommandResult
#define _MCommandResult
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

#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

// CLASS DECLARATION (MCommandResult)

/// Result returned from executing a command.
/**
  An MCommandResult collects the result returned by MGlobal::executeCommand.
*/
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
