#ifndef _MFnParticleSystem
#define _MFnParticleSystem
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
// CLASS:    MFnParticleSystem
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnParticleSystem)
//
//  Particle object access class. Intended to be used by the software 
//	renderer for accessing relevant data from the particle object. The 
//	data stored in the particle object is a function of the particle 
//	render type. 
//
//	Safe to call these methods with any render type:
//
//	Method Name		Description
//	================================================================
//	isValid()		data is valid (predicate)
//	renderType()	object render type
//	count()			particle count at current frame
//	----------------------------------------------------------------
//
//
//	Use this table to determine which methods to call based on the
//	render type of the particle object.
//
//	Render Type		Valid Methods		Description
//	================================================================
//	kCloud			position()			particle position
//					radius()			particle radius
//					surfaceShading()	object surface shading value
//					betterIllum()		invoke thick cloud sampling
//					threshold()			object threshold
//					disableCloudAxis()	for internal use; do not call
//	----------------------------------------------------------------
//	kTube			position0()			particle start position
//					position1()			particle end position
//					radius0()			particle start radius
//					radius1()			particle end radius
//					tailSize()			length scale factor
//	----------------------------------------------------------------
//	kBlobby			position()			particle position
//					radius()			particle radius
//					threshold()			object threshold
//	----------------------------------------------------------------
//	kHardware		position()			particle position
//					radius()			particle radius
//	----------------------------------------------------------------
//	
//		
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MStatus.h>
#include <maya/MTypes.h>
#include <maya/MFnDagNode.h>


// *****************************************************************************

// DECLARATIONS

class MTime;
class MFnDagNode;
class MDoubleArray;
class MVectorArray;
class MIntArray;

// *****************************************************************************

// CLASS DECLARATION (MFnParticleSystem)

/// 
/**
	Class for obtaining information about a particle system. (OpenMayaFX)
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYAFX_EXPORT MFnParticleSystem : public MFnDagNode
{
    declareDagMFn(MFnParticleSystem, MFnDagNode);

public:

	///
	enum RenderType
	{
		///
		kCloud,
		///
		kTube,
		///
		kBlobby,
		///
		kHardware
	};

	///
	void			evaluateDynamics( MTime &to, bool runupFromStart );
	///
	bool			isValid			() const;
	///
	MString			particleName	() const;
	///
	unsigned int	count			() const;
	///
	RenderType		renderType		() const;
	///
	void			particleIds		( MIntArray& ) const;
	///
	void			position		( MVectorArray& ) const;
	///
	void			position0		( MVectorArray& ) const;
	///
	void			position1		( MVectorArray& ) const;
	///
	void			radius			( MDoubleArray& ) const;
	///
	void			radius0			( MDoubleArray& ) const;
	///
	void			radius1			( MDoubleArray& ) const;
	///
	double			surfaceShading	() const;
	///
	double			threshold		() const;
	///
	bool			betterIllum		() const;
	///
	bool			disableCloudAxis() const;
	///
	double			tailSize		() const;
	///
	void			age				( MDoubleArray& ) const;
	///
	void			lifespan		( MDoubleArray& ) const;
	///
	void			rgb				( MVectorArray& ) const;
	///
	void			opacity			( MDoubleArray& ) const;
	///
	void			emission		( MVectorArray& ) const;
	///
	bool			hasLifespan		() const;
	///
	bool			hasRgb			() const;
	///
	bool			hasOpacity		() const;
	///
	bool			hasEmission		() const;
	///
	bool			primaryVisibility	() const;
	///
	bool			visibleInReflections() const;
	///
	bool			visibleInRefractions() const;
	///
	bool			castsShadows		() const;
	///
	bool			receiveShadows		() const;
	
protected:

	virtual bool	objectChanged( MFn::Type, MStatus * );
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MFnParticleSystem */
