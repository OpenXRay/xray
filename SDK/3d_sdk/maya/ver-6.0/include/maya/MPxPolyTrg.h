#ifndef _MPxPolyTrg
#define _MPxPolyTrg
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
// CLASS:    MPxPolyTrg
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MPxPolyTrg)
//
//     The parent class for user defined poly triangulation nodes.  
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES

#include <maya/MPxNode.h>
#include <maya/MStatus.h>

// *****************************************************************************

// DECLARATIONS

// *****************************************************************************

// CLASS DECLARATION (MPxPolyTrg)

/// User defined poly triangulation support.
/**

*/

// Base class for user defined face triangulation for polygons. 
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MPxPolyTrg : public MPxNode 
{
public:

    ///
	MPxPolyTrg();
    ///
	virtual ~MPxPolyTrg();
	
    ///
	virtual void		postConstructor();
    ///
	virtual MStatus		compute( const MPlug& plug,
								 MDataBlock& dataBlock );
	///                     
	virtual bool		isAbstractClass() const;


	// Type for the signature of the triangulate function
	/// 
	typedef void (*polyTrgFnct)( const float *vert,
								 const float *norm,
								 const int   *loopSizes, 
								 const int nbLoop, 
								 const int nbTrg, unsigned short *trg );

	///
	MStatus				registerTrgFunction( char *name, polyTrgFnct f );
	///
	MStatus				unregisterTrgFunction( char *name );

private:

};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MPxPolyTrg */
