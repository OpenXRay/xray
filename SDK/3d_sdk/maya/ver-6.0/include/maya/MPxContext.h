
#ifndef _MPxContext
#define _MPxContext
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
// CLASS:    MPxContext
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MPxContext)
//
//  This is the base class for contexts.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MStatus.h>
#include <maya/MTypes.h>
#include <maya/MEvent.h>
#include <maya/MString.h>
#include <maya/MSyntax.h>
#include <maya/MObject.h>

// *****************************************************************************

// DECLARATIONS

class MString;
class MDoubleArray;
class MIntArray;
class MPxToolCommand;
class MCursor;

// *****************************************************************************

// CLASS DECLARATION (MPxContext)

/// Base class for user defined contexts (OpenMayaUI)
/**
  The base class for user defined contexts
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYAUI_EXPORT MPxContext
{
public:
	enum ImageIndex {
		kImage1 = 0,
		kImage2,
		kImage3
	};

    ///
	MPxContext ();
    ///
	virtual	~MPxContext ();

    ///
	virtual void        toolOnSetup( MEvent & event );
    ///
	virtual void        toolOffCleanup();

    ///
	virtual MStatus		doPress ( MEvent & event );
    ///
	virtual MStatus		doRelease ( MEvent & event );
    ///
	virtual MStatus		doDrag ( MEvent & event );
    ///
	virtual MStatus		doHold ( MEvent & event );
    ///
	virtual MStatus 	doEnterRegion ( MEvent & event );
    ///
	virtual void		deleteAction();
    ///
	virtual void		completeAction();
	///
	virtual MStatus     addManipulator( const MObject & manipulator );
	///
	virtual MStatus     deleteManipulators();
	///
	MStatus				setImage( const MString & image, ImageIndex index );
	///
	MStatus				getImage( MString & image, ImageIndex index ) const;

protected:
    ///
	MStatus			    setHelpString( const MString & str );
    ///
	MStatus			    setTitleString( const MString & str );

    ///
	MStatus				setCursor( const MCursor & cursor );

    ///
	MStatus		        beginMarquee( MEvent & event );
    ///
	MStatus             dragMarquee( MEvent & event );
    ///
	MStatus             releaseMarquee( MEvent & event,
                                        short& top, short& left,
                                        short& bottom, short& right );

	// Create an instance of a tool command for use in
	// this context.
	//
	///
	virtual MPxToolCommand *	newToolCommand();

	virtual const char*	className() const;

public:
	// Temporarily putting these virtual functions at the end
	///
	virtual void		abortAction();
	///
	virtual bool		processNumericalInput( const MDoubleArray &values,
											   const MIntArray &flags,
											   bool isAbsolute );
	///
	virtual bool		feedbackNumericalInput() const;
	///
	virtual MSyntax::MArgType	argTypeNumericalInput( unsigned index ) const;
	///
	virtual	void		getClassName( MString & name ) const;

protected:
	///
	static bool 		ignoreEntry( const MIntArray &flags,
									 unsigned entry );

private:
	friend class MPxSelectionContext;
	friend class MToolsInfo;
	void setData( void * ptr );
	void * data;
	MString title;
	MString help;
	MString fImage;
	unsigned fImageIndex;
	MCursor * cursor;
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MPxContext */
