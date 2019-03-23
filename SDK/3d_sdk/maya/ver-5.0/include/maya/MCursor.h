
#ifndef _MCursor
#define _MCursor
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
// CLASS:    MCursor
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MCursor)
//
//  The MCursor class implements a cursor class, and is used to pass
//  all cursor arguments to Maya API methods.
//  The data passed to the MCursor constructor is in xbm format.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES



#include <maya/MTypes.h>

// *****************************************************************************

// DECLARATIONS

// *****************************************************************************

// CLASS DECLARATION (MCursor)

/// Manipulate Cursors. (OpenMayaUI)
/**
 Implement a cursor.
*/

#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYAUI_EXPORT MCursor
{
public:
#ifdef _WIN32
	/// NT constructor
				MCursor( LPCSTR pszResource );
#else
	/// IRIX constructor
				MCursor(short width,
						short height,
						short hotSpotX,
						short hotSpotY,
						unsigned char * bits,
						unsigned char * mask );
#endif
	///
				MCursor(const MCursor& other);
	///
	        	~MCursor();

	///
	MCursor &	operator=(const MCursor &);
	///
	bool		operator==(const MCursor &) const;
	///
	bool		operator!=(const MCursor &) const;
	/// Maya default cursor, the left arrow.
	static		MCursor	defaultCursor;
	/// '+' cursor.
	static		MCursor	crossHairCursor;
	/// '+' cursor with double lines.
	static		MCursor	doubleCrossHairCursor;
	/// Wedge-shaped arrow pointing left.
	static		MCursor	editCursor;
	/// Pencil shape.
	static		MCursor	pencilCursor;
	/// Open hand shaped cursor.
	static		MCursor	handCursor;

protected:
// No protected members

private:
				MCursor();
				MCursor(const void *);
	const void*	apiData;
	const void* apiData2;
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32


// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MCursor */
