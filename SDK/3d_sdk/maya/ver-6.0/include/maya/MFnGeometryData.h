
#ifndef _MFnGeometryData
#define _MFnGeometryData
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
// CLASS:    MFnGeometryData
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnGeometryData)
// 
// This class is the function set for geometry data.
//
// Geometry data adds matrix and grouping (set) information to regular data
// and is used to pass geometry types such as mesh, lattice, and NURBS shape
// data through DG connections.
//
// User defined geometry data types (MPxGeometryData) are also supported 
// by this class.
//
// The matrix within geometry data is the matrix used to convert the object
// into local space.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MFnData.h>

// *****************************************************************************

// DECLARATIONS

class MMatrix;

// *****************************************************************************

// CLASS DECLARATION (MFnGeometryData)

#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

/// 
/**
*/
class OPENMAYA_EXPORT MFnGeometryData : public MFnData 
{

    declareMFn( MFnGeometryData, MFnData );

public:

    ///
    MStatus        setMatrix( const MMatrix & );
    ///
    MStatus        getMatrix ( MMatrix & ) const;
    ///
    bool           matrixIsIdentity( MStatus * ReturnStatus = NULL ) const;
    ///
    bool           matrixIsNotIdentity( MStatus * ReturnStatus = NULL ) const;
    
    // methods to add/remove object groups
    //
    ///
    bool           hasObjectGroup( unsigned id,
                                   MStatus* ReturnStatus = NULL  ) const;
    ///
    MStatus        addObjectGroup( unsigned );
    ///
    MStatus        removeObjectGroup( unsigned );
    ///
    MStatus        changeObjectGroupId( unsigned , unsigned );

    // methods to get the i'th object group
    //
    ///
    unsigned       objectGroupCount( MStatus * ReturnStatus = NULL ) const;
    ///
    unsigned       objectGroup( unsigned index,
                                MStatus* ReturnStatus = NULL ) const;

    // method to get the type of component stored by an object group
    //
    ///
    MFn::Type      objectGroupType( unsigned,
                                    MStatus* ReturnStatus = NULL ) const;

    // methods to access and edit members of object group
    //
    ///
    MObject        objectGroupComponent( unsigned,
                                         MStatus* ReturnStatus = NULL ) const;
    ///
    MStatus        setObjectGroupComponent( unsigned, MObject & );
    ///
    MStatus        addObjectGroupComponent( unsigned, MObject & );
    ///
    MStatus        removeObjectGroupComponent( unsigned, MObject & );

    // Method to copy object groups from the geometry data sent in.
    //
    ///
    MStatus        copyObjectGroups( MObject & inGeom );


protected:
// No protected members

private:
// No Private members
 
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MFnGeometryData */
