
#ifndef _MImage
#define _MImage
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
// CLASS:    MImage
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MImage)
//
// MImage is a class which provides access to some of Maya's image manipulation
// functionality.
//
// MImage provides methods for loading and resizing image files in any 
// Maya-supported format, including but not limited to IFF, SGI, Softimage, 
// TIFF, Alias PIX, GIF, RLA, JPEG, EPS.
// 
// MImage stores the image as an uncompressed array of pixels, that can be read
// and manipulate directly. That format is either RGBA (depth=4), RGB (depth=3),
// or Luminance (depth=1).
//
// (NOTE: At the moment, all files are directly converted to RGBA regardless
// of their original format. This restriction might get lifted in the future if
// there is enough interest.)
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MObject.h>
#include <maya/MString.h>
#include <maya/MTypes.h>

// *****************************************************************************

// CLASS DECLARATION (MImage)

/// Image manipulation
/**
This class provides methods for reading file images stored on disk.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MImage  
{
public:
	// Possible source or target filter formats.
	///
	enum MImageFilterFormat {
		///
		kNoFormat,
		///
		kHeightFieldBumpFormat,
		///
		kNormalMapBumpFormat,
		///	
		kUnknownFormat
	};

	///
					MImage();
	///
					~MImage();
	///
					MStatus create(unsigned int width, unsigned int height);
	///
					MStatus readFromFile(MString pathname);
	///
					MStatus readFromTextureNode(const MObject& fileTextureObject);
	///
					MStatus getSize(unsigned int &width, unsigned int &height);
	///
					unsigned char* pixels();
	///
					unsigned int depth();
	///
					MStatus resize(int width, int height, bool preserveAspectRatio = true);
	///
					static bool filterExists(MImageFilterFormat sourceFormat, MImageFilterFormat targetFormat);
	///
					MStatus filter(MImageFilterFormat sourceFormat, MImageFilterFormat targetFormat, 
						double scale = 1.0, double offset = 0.0);
	///
					MStatus writeToFile(MString pathname, MString outputFormat = MString("iff"));
	///
					MStatus release();
	
protected:

private:
	// No protected members
	void set( void * );

	void *_pPixelMap;
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MImage */
