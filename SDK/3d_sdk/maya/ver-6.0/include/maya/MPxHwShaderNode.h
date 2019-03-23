
#ifndef _MPxHwShaderNode
#define _MPxHwShaderNode
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
// CLASS:    MPxHwShaderNode
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MPxHwShaderNode)
//
// MPxHwShaderNode allows the creation of user-defined hwShaders.  A hwShader
// is a node which takes any number of input geometries, deforms them and
// places the output into the output geometry attribute.
//
// For more information, please see the built-in documentation
// in MPxHwShaderNode.cpp.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES



#include <maya/MStatus.h>
#include <maya/MTypes.h>
#include <maya/MObject.h>
#include <maya/MPxNode.h>
#include <maya/MDrawRequest.h>
#include <maya/M3dView.h>

// *****************************************************************************

// DECLARATIONS

// *****************************************************************************

// CLASS DECLARATION (MPxHwShaderNode)

/// Base class for user defined hardware shaders (OpenMayaUI)
/**
  Create user defined hardware shaders.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYAUI_EXPORT MPxHwShaderNode : public MPxNode
{
public:
	///
	enum Writeable {
		///
		kWriteNone				= 0x0000,
		///
		kWriteVertexArray		= 0x0001,
		///
		kWriteNormalArray		= 0x0002,
		///
		kWriteColorArrays		= 0x0004,
		///
		kWriteTexCoordArrays	= 0x0008,
		///
		kWriteAll				= 0x000f
	};

    ///
	MPxHwShaderNode();

    ///
	virtual ~MPxHwShaderNode();

	///
	virtual MPxNode::Type type() const;

	// Methods to overload


	// Override this method to set up the OpenGL state
	//
	///
	virtual MStatus		bind( const MDrawRequest& request,
							  M3dView& view );

	// Override this method to return OpenGL to a sane state
	//
	///
	virtual MStatus		unbind( const MDrawRequest& request,
								M3dView& view );

	// Override this method to actually draw primitives on the display
	//
	///
	virtual MStatus		geometry( const MDrawRequest& request,
								  M3dView& view,
								  int prim,
								  unsigned int writable,
								  int indexCount,
								  const unsigned int * indexArray,
								  int vertexCount,
								  const int * vertexIDs,
								  const float * vertexArray,
								  int normalCount,
								  const float ** normalArrays,
								  int colorCount,
								  const float ** colorArrays,
								  int texCoordCount,
								  const float ** texCoordArrays);

	// As above, but these implement a more general purpose draw
    // that doesn't have Maya dependencies. This interface should be
    // prefered as it will handle both draw requests from Maya's 3D
    // view and the hardware renderer. Derived classes do not need
    // to implement the interface above as the default implementation
    // will invoke the methods below.
	//
    ///
	virtual MStatus     glBind  ( const MDagPath& shapePath );
    ///
	virtual MStatus	    glUnbind( const MDagPath& shapePath );
    ///
	virtual MStatus	    glGeometry( const MDagPath& shapePath,
                                  int glPrim,
								  unsigned int writeMask,
								  int indexCount,
								  const unsigned int* indexArray,
								  int vertexCount,
								  const int * vertexIDs,
								  const float * vertexArray,
								  int normalCount,
								  const float ** normalArrays,
								  int colorCount,
								  const float ** colorArrays,
								  int texCoordCount,
								  const float ** texCoordArrays);

	// Override this method to specify how many "normals" per vertex
	// the hardware shader would like.  Maya can provide from 0 to 3
	// normals per vertex.  The second and third "normal" will be
	// tangents.  If you do not override this method, Maya will
	// provide 1 normal per vertex.
	//
	///
	virtual	int		normalsPerVertex();

	// Override this method to specify how many colors per vertex the
	// hardware shader would like Maya to provide.  Maya may not provide
	// this many if they are not available.  If you do not override
	// this method, Maya will provide 0 colors per vertex.
	//
	///
	virtual int		colorsPerVertex();

	// Override this method to specify how many texture coordinates
	// per vertex the hardware shader would like Maya to provide.
	// Maya may not provide this many if they are not available.  If
	// you do not override this method, Maya will provide 0 texture
	// coordinates per vertex.
	//
	///
	virtual int		texCoordsPerVertex();

	// Override this method to specify an array of names of uvSets
	// that should be provided.  When Maya calls the geometry method,
	// the uv values from the nth name in the list will be passed in
	// the nth texCoordArray.
	//
	///
	virtual int		getTexCoordSetNames(MStringArray& names);

	// Specifies whether or not the hw shader uses transparency.  If
	// so, the objects that use this shader must be drawn after all
	// the opaque objects.
	//
	///
	virtual bool	hasTransparency();

	// Specifies whether or not the hw shader wants a map of the
	// vertex IDs in the vertexArray provided to the geomery method.
	//
	///
	virtual bool	provideVertexIDs();

	// Attributes inherited from surfaceShader
	/// output color value
	static MObject outColor;
	/// output color red
	static MObject outColorR;
	/// output color green
	static MObject outColorG;
	/// output color blue
	static MObject outColorB;

	/// output transparency value
	static MObject outTransparency;
	/// output transparency red
	static MObject outTransparencyR;
	/// output transparency green
	static MObject outTransparencyG;
	/// output transparency blue
	static MObject outTransparencyB;

	/// output matte opacity value
	static MObject outMatteOpacity;
	/// output matte opacity red
	static MObject outMatteOpacityR;
	/// output matte opacity green
	static MObject outMatteOpacityG;
	/// output matte opacity blue
	static MObject outMatteOpacityB;

	/// output glow color value
	static MObject outGlowColor;
	/// output glow color red
	static MObject outGlowColorR;
	/// output glow color green
	static MObject outGlowColorG;
	/// output glow color blue
	static MObject outGlowColorB;


protected:
// No protected members

private:
	static void				initialSetup();
	static const char*	    className();
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MPxNode */
