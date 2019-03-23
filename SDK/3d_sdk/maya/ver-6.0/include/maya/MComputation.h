#ifndef _MComputation
#define _MComputation
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
// CLASS:    MComputation
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MComputation)
//
// An MComputation allows long computations to check for user interrupts.  It is
// very simple to use.  Create a new MComputation object and call the
// beginComputation method at the beginning of the computation and call
// the endComputation method when you finish.  Then, during the computation,
// use the isInterruptRequested method to check if the user has requested
// that the computation terminate.
// 
// Example:
// 
//     MComputation computation;
//     computation.beginComputation();
//     for (int i= 1; i<1000; i++) {
//         Computation();  // Some expensive operation
//         if  (computation.isInterruptRequested()) break ;
//     }
//     computation.endComputation();			
//
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MTypes.h>

// *****************************************************************************
// FORWARD DECLARATIONS
// *****************************************************************************

// CLASS DECLARATION (MComputation)

/// Interupt monitor for long computations
/**
 An MComputation is used to monitor user-interupts during int computations.
*/

#if defined(_WIN32)
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MComputation {

public:  
	///
			MComputation();
	///
	virtual	~MComputation();
	///
    void	beginComputation();
	///
    bool	isInterruptRequested();
	///
    void	endComputation();

protected:
// No protected members

private:
    const char* className() const;
	void *f_data;
};

#if defined(_WIN32)
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MComputation */
