
#ifndef _MEvent
#define _MEvent
//
// *****************************************************************************
//
// Copyright (C) 1997-2003 Alias|Wavefront Inc.
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
// CLASS:    MEvent
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MEvent)
//
// The MEvent class is used for querying system events such as mouse presses.
//
// Events are handled by an MPxContext derived class in which MEvents are passed
// and can be accessed.
// 
// Since Maya has default actions for several events, only a subset are
// available through the API.
// The events that can be accessed are:
//    buttonPress       - mouse button press event (left & middle only)
//    buttonRelease     - mouse buttons release event (left & middle only)
//    mouseDrag         - mouse button drag event (left & middle only)
//    hold              - mouse button hold event (left & middle only)
//    deleteEvent       - delete/backspace key event
//    commandCompletion - complete key event
// 
// Several modifiers for events are also accessible through the API.  Modifiers
// are actions that occur during an event.  For example, holding down the shift
// key while pressing a mouse button causes a button press event to occur with
// a shift modifier.
// 
// A modifier can be used to determine if two mouse events occur simulaneously.
// The second mouse event is registered as a modifier in the hold event of the 
// first mouse button.  So if you wanted to determine if both the left and
// middle buttons are pressed then you would query the modifier in the hold
// event of the first mouse button using the isModifierMiddleMouseButton() and
// isModifierLeftMouseButton() methods.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MStatus.h>

// *****************************************************************************

// DECLARATIONS

class MDeviceState;

// *****************************************************************************

// CLASS DECLARATION (MEvent)

/// System event information (OpenMayaUI)
/**

System event information class.

*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYAUI_EXPORT MEvent  
{
public:

	///
    enum ModifierType {
		///
        shiftKey    = 1<<0,
		///
        controlKey  = 1<<2
    };

	///
	enum MouseButtonType {
		///
		kLeftMouse		= 1<<6,
		///
		kMiddleMouse	= kLeftMouse<<1
	};

public:
	///
    MEvent();
	///
    virtual ~MEvent();

	///
    MStatus         getPosition( short& x_pos, short& y_pos ) const;
	///
    MStatus         setPosition( short& x_pos, short& y_pos );
	///
    MStatus         getWindowPosition( short& x_pos, short& y_pos ) const;
	///
    MouseButtonType mouseButton( MStatus * ReturnStatus = NULL ) const;
	///
    bool            isModifierKeyRelease( MStatus * ReturnStatus = NULL ) const;
	///
    ModifierType    modifiers( MStatus * ReturnStatus = NULL ) const;
	///
    MStatus         setModifiers( ModifierType& modType );
	///
    bool            isModifierNone( MStatus * ReturnStatus = NULL ) const;
	///
    bool            isModifierShift( MStatus * ReturnStatus = NULL ) const;
	///
    bool            isModifierControl( MStatus * ReturnStatus = NULL ) const;
	///
    bool            isModifierLeftMouseButton( MStatus * ReturnStatus = NULL )
					const;
	///
    bool            isModifierMiddleMouseButton( MStatus * ReturnStatus = NULL )
					const;

protected:
// No protected members

private:
    static const char* className();


    MEvent( const void * );
    const void * fEventPtr;
    void * fModifier;
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MEvent */
