
#ifndef _MFnDependencyNode
#define _MFnDependencyNode
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
// CLASS:    MFnDependencyNode
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnDependencyNode)
//
//  MFnDependencyNode allows the creation and manipulation of dependency
//  graph nodes.  Traversal of the dependency graph is possible using the
//  getConnections method.
//
//  This function set does not support creation or removal of connections.  
//  MDGModifier should be used for that purpose.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MFnBase.h>
#include <maya/MTypeId.h>
#include <maya/MString.h>

// *****************************************************************************

// DECLARATIONS

class MPlugArray;
class MPlug;
class MTypeId;
class MPxNode;
class MObjectArray;

// *****************************************************************************

// CLASS DECLARATION (MFnDependencyNode)

/// Dependency node function set
/**
 MFnNumericData allows the manipulation of nodes in the dependency graph
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MFnDependencyNode : public MFnBase 
{

	declareMFn(MFnDependencyNode, MFnBase);

public:
    ///
	enum MAttrClass {
        ///
		kGlobalDynamicAttr = 1,
        ///
		kLocalDynamicAttr,
		//
		kNormalAttr,
		//
		kInvalidAttr
	};
		
    ///
    MObject         create( const MTypeId &typeId,
								MStatus* ReturnStatus = NULL );
    ///
    MObject         create( const MTypeId &typeId,
								const MString& name,
								MStatus* ReturnStatus = NULL );

    ///
    MObject         create( const MString &type,
								MStatus* ReturnStatus = NULL );
    ///
    MObject         create( const MString &type,
								const MString& name,
								MStatus* ReturnStatus = NULL );
	
	///
	MTypeId         typeId( MStatus* ReturnStatus = NULL ) const;
	///
	MString         typeName( MStatus* ReturnStatus = NULL ) const;
	///
	MString			name( MStatus * ReturnStatus = NULL ) const;
	///
	MString			setName( const MString &name,
							 MStatus * ReturnStatus = NULL );
    ///
	MStatus			getConnections( MPlugArray& array ) const;
    ///
	unsigned		attributeCount( MStatus* ReturnStatus=NULL) const;
    ///
	MObject	        attribute(	unsigned index,
								MStatus* ReturnStatus=NULL) const;
    ///
	MObject	        reorderedAttribute(	unsigned index,
								MStatus* ReturnStatus=NULL) const;
    ///
	MObject	        attribute(	const MString& attrName,
								MStatus* ReturnStatus=NULL) const;
    ///
	MAttrClass		attributeClass(	const MObject& attr,
									MStatus* ReturnStatus=NULL) const;
	///
	MStatus			getAffectedAttributes ( const MObject& attr,
									MObjectArray& affectedAttributes ) const;
	///
	MStatus			getAffectedByAttributes ( const MObject& attr,
									MObjectArray& affectedByAttributes ) const;
    ///
	MPlug			findPlug(	const MObject & attr,
								MStatus* ReturnStatus=NULL) const;
    ///
	MPlug			findPlug(	const MString & attrName,
								MStatus* ReturnStatus=NULL) const;
    ///
	MStatus			addAttribute( const MObject & attr,
								MAttrClass type = kLocalDynamicAttr );
    ///
	MStatus			removeAttribute( const MObject & attr,
								MAttrClass type = kLocalDynamicAttr );
    ///
	MPxNode *  		userNode( MStatus* ReturnStatus=NULL ) const;
    ///
	bool			isFromReferencedFile(MStatus* ReturnStatus=NULL) const;
    ///
	bool			isShared(MStatus* ReturnStatus=NULL) const;
    ///
	bool			hasUniqueName(MStatus* ReturnStatus=NULL) const;
	///
	MString			parentNamespace(MStatus* ReturnStatus=NULL) const;
    ///
	bool			isLocked(MStatus* ReturnStatus=NULL) const;
	///
	MStatus			setLocked( bool locked );
	///
	static MString	classification( const MString & nodeTypeName );
	///
	bool			isNewAttribute( const MObject& attr,
								MStatus* ReturnStatus=NULL) const;
	///
	static unsigned	allocateFlag(
						const MString pluginName, MStatus* ReturnStatus=NULL
					);
	///
	static MStatus	deallocateFlag(const MString pluginName, unsigned flag);
	///
	static MStatus	deallocateAllFlags(const MString pluginName);
	///
	MStatus			setFlag(unsigned flag, bool state);
	///
	bool			isFlagSet(unsigned flag, MStatus* ReturnStatus=NULL) const;
	///
	bool			isDefaultNode(MStatus* ReturnStatus=NULL) const;
	///
	bool			canBeWritten(MStatus* ReturnStatus=NULL) const;

protected:
// No protected members

private:
// No private members

};
#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MFnDependencyNode */
