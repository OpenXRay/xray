#ifndef _MMaterial
#define _MMaterial
//
// *****************************************************************************
// Copyright  (C)  Alias|Wavefront,  a division of Silicon Graphics  Limited.
// All rights  reserved.  These coded  instructions,  statements and computer
// programs contain unpublished information  proprietary to  Alias|Wavefront,
// a  division  of  Silicon  Graphics  Limited,  which  is  protected by  the
// Canadian  and  US federal copyright law and  may not be disclosed to third
// parties or  copied  or  duplicated,  in  whole  or in part,  without prior
// written consent of Alias|Wavefront, a division of Silicon Graphics Limited
// *****************************************************************************
//
// CLASS:    MMaterial
//
//    This class is used in the draw functions of user defined shapes
//    (see MPxSurfaceShapeUI) for setting up and querying materials
//    used in shaded mode drawing.
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MMaterial)
//
// *****************************************************************************
//
#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MStatus.h>
#include <maya/MTypes.h>
#include <maya/MObject.h>
#include <maya/M3dView.h>

// *****************************************************************************

// DECLARATIONS

class MDagPath;
class MVector;
class MDrawData;
class MPxHwShaderNode;
class MImage;

// *****************************************************************************

// CLASS DECLARATION (MMaterial)

/// Hardware shading material class used in MPxSurfaceShapeUI (OpenMayaUI)
/**
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYAUI_EXPORT MMaterial  
{
public:
	///
	MMaterial();
	///
	MMaterial( const MMaterial& in );
	///
	~MMaterial();

public:
	// Evaluation methods.
	///
	MStatus		evaluateMaterial(M3dView&, const MDagPath& );
	///
	MStatus		evaluateShininess();
	///
	MStatus		evaluateDiffuse();
	///
	MStatus		evaluateEmission();
	///
	MStatus		evaluateSpecular();
	///
	MStatus		evaluateTexture( MDrawData & data );
	///
	MStatus		evaluateTextureTransformation();

	///
	bool		materialIsTextured() const;

	// Draw methods.
    // Can call these after calling correct evaluate method above.
	///
	MStatus		setMaterial(const MDagPath&, bool hasTransparency);
	///
	MStatus		getShininess( float & );
	///
	MStatus		getDiffuse( MColor & );
	///
	MStatus		getEmission( MColor & );
	///
	MStatus		getSpecular( MColor & );
	///
    MStatus		getHasTransparency( bool & );
	///
	MStatus		getTextureTransformation(float& scaleU,
										 float& scaleV,
										 float& translateU,
										 float& translateV,
										 float& rotate);

	// This method sets the texture so that it can be used in
	// the specified view.
	///
	void		applyTexture( M3dView&, MDrawData& );

	// Channels which can be queried. Only Lambert, Phong,
	// PhongE, Blinn, and Anisotropic are supported
	typedef enum
	{
		kColor = 0,
		kTransparency,
		kAmbientColor,
		kIncandescence,
		kBumpMap,
		kDiffuse,
		kTransluscence,
		kRoughness,			// Available on PhongE only
		kHighlightSize,		// Available on PhongE only
		kWhiteness,			// Available on PhongE only
		kCosinePower,		// Available on Phong only
		kEccentricity,		// Available on Blinn only
		kSpecularRollOff,	// Available on Blinn only
		kSpecularColor,		// Available on Blinn and Phong(E) only
		kReflectivity,		// Available on Blinn and Phong(E) only
		kReflectedColor		// Available on Blinn and Phong(E) only

	} MtextureChannel;
	MStatus textureImage( MImage &image, MColor &color, 
						MtextureChannel chan, bool &mapped,
						MDagPath &dagPath,
						int xRes = -1, int yRes = -1);

	///
	MPxHwShaderNode *	getHwShaderNode( MStatus * ReturnStatus = NULL );

protected:
// No protected members

private:
	const char*	 className() const;
    MMaterial( void* in );

	void*	 fMaterial;
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MMaterial */
