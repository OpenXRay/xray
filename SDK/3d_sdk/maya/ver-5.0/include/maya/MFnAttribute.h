
#ifndef _MFnAttribute
#define _MFnAttribute
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
// CLASS:    MFnAttribute
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnAttribute)
//
//  MFnAttribute is the function set for dependency node attributes.  
//
//  An attribute of a dependency node describes a piece of data that belongs to 
//  nodes of that type.  For example, a node that makes a sphere might have a 
//  radius attribute.  A node's attributes describe connections sites on the
//  node that can be used in the dependency graph.
//
//  Attributes typically belong to a class of nodes, rather than to an
//  individual node.  For example, all sphere nodes have a radius.  Even though
//  a single attribute may be shared by all nodes of a given type, each node
//  will have  its own value for the attribute.
//
//  Attributes are heirarchical.  For example, the translate scale attribute
//  of a transform has x, y, and z child attributes.
//  
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MFnBase.h>
#include <maya/MFnData.h>

// *****************************************************************************

// DECLARATIONS

class MTypeId;
class MString;
class MStringArray;

// *****************************************************************************

// CLASS DECLARATION (MFnAttribute)

/// Dependency node attribute function set
/**
 Function set for attributes of dependency nodes.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MFnAttribute : public MFnBase 
{

	declareMFn(MFnAttribute, MFnBase);

public:

	///
	enum DisconnectBehavior {
		/// delete array element on disconnect (array attributes only)
		kDelete,
		/// reset the attribute to its default on disconnect
		kReset,
		/// do nothing to the attribute's value on disconnect
		kNothing
	};

	///
	bool		isReadable( MStatus* ReturnStatus=NULL ) const;
	///
	bool		isWritable( MStatus* ReturnStatus=NULL ) const;
	///
	bool		isConnectable( MStatus* ReturnStatus=NULL ) const;
	///
	bool		isStorable( MStatus* ReturnStatus=NULL ) const;
	///
	bool		isCached( MStatus* ReturnStatus=NULL ) const;
	///
	bool		isArray( MStatus* ReturnStatus=NULL ) const;
	///
	bool		indexMatters( MStatus* ReturnStatus=NULL ) const;
	///
	bool		isKeyable( MStatus* ReturnStatus=NULL ) const;
	///
	bool		isHidden( MStatus* ReturnStatus=NULL ) const; 
	///
	bool		isUsedAsColor( MStatus* ReturnStatus=NULL ) const;
	///
	bool		isIndeterminant( MStatus* ReturnStatus=NULL ) const;

	///
	bool		isRenderSource( MStatus* ReturnStatus=NULL ) const;

	///
	bool		isDynamic( MStatus* ReturnStatus=NULL ) const;

	///
	DisconnectBehavior disconnectBehavior( MStatus* ReturnStatus=NULL ) const;
	///
	bool        usesArrayDataBuilder( MStatus* ReturnStatus=NULL ) const;
	///
	bool     	internal( MStatus* ReturnStatus=NULL ) const;

	///
	MStatus		setReadable( bool state );
	///
	MStatus		setWritable( bool state ); 
	///
	MStatus		setConnectable( bool state );
	///
	MStatus	 	setStorable( bool state );
	///
	MStatus		setCached( bool state );
	///
	MStatus	 	setArray( bool state );
	///
	MStatus	 	setIndexMatters( bool state );
	///
	MStatus	 	setKeyable( bool state );
	///
	MStatus	 	setHidden( bool state );
	///
	MStatus     setUsedAsColor( bool state );
	///
	MStatus     setIndeterminant( bool state );

    ///
	MStatus		setRenderSource( bool state );

	///
	MStatus     setDisconnectBehavior( DisconnectBehavior behavior );
	///
	MStatus     setUsesArrayDataBuilder( bool state );
	///
	MStatus     setInternal( bool state );
	///
	bool		accepts( MFnData::Type type, MStatus* ReturnStatus=NULL ) const;
	///
	bool		accepts( const MTypeId& id, MStatus* ReturnStatus=NULL ) const;
	///
	MObject		parent(MStatus* ReturnStatus=NULL) const;
	///
	MStatus		setParent( const MObject & parent );
	///
    MString     name( MStatus* ReturnStatus=NULL ) const; 
	///
    MString     shortName( MStatus* ReturnStatus=NULL ) const; 
	///
	MString		getAddAttrCmd(
					bool			useLongName = false,
					MStatus*		status=NULL
				) const;

protected:
	void * ca[3];
	void setPtr( MPtrBase* );

private:
	virtual bool objectChanged( MFn::Type, MStatus * );
};
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MFnAttribute */
