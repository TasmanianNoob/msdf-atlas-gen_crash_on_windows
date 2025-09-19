#include <iostream>
#include "msdf-atlas-gen/msdf-atlas-gen.h"

int main()
{
	if (msdfgen::FreetypeHandle* ft = msdfgen::initializeFreetype())
	{
		if (msdfgen::FontHandle *font = msdfgen::loadFont(ft, "C:\\Windows\\Fonts\\arial.ttf")) {
			//std::vector<msdf_atlas::GlyphGeometry> glyphs;
			msdf_atlas::FontGeometry fontGeometry;//(&glyphs);

			fontGeometry.loadCharset(font, 1.0, msdf_atlas::Charset::ASCII);

			std::vector<msdf_atlas::GlyphGeometry> glyphs(fontGeometry.getGlyphs().begin(), fontGeometry.getGlyphs().end());

			const double maxCornerAngle = 3.0;
			for (msdf_atlas::GlyphGeometry &glyph : glyphs)
				glyph.edgeColoring(&msdfgen::edgeColoringInkTrap, maxCornerAngle, 0);

			msdf_atlas::TightAtlasPacker packer;
			packer.setDimensionsConstraint(msdf_atlas::DimensionsConstraint::SQUARE);
			packer.setMinimumScale(24.0);
			packer.setPixelRange(2.0);
			packer.setMiterLimit(1.0);
			packer.pack(glyphs.data(), static_cast<int>(glyphs.size()));

			int width = 0;
			int height = 0;
			packer.getDimensions(width, height);

			msdf_atlas::ImmediateAtlasGenerator<
				float, // pixel type of buffer for individual glyphs depends on generator function
				3, // number of atlas color channels
				msdf_atlas::msdfGenerator, // function to generate bitmaps for individual glyphs
				msdf_atlas::BitmapAtlasStorage<msdf_atlas::byte, 3> // class that stores the atlas bitmap
				// For example, a custom atlas storage class that stores it in VRAM can be used.
			> generator(width, height);
			msdf_atlas::GeneratorAttributes attributes;
			generator.setAttributes(attributes);
			generator.setThreadCount(4);
			generator.generate(glyphs.data(), static_cast<int>(glyphs.size()));

			msdfgen::destroyFont(font);
		}

		msdfgen::deinitializeFreetype(ft);
	}

	std::cout << "Hello, World!" << std::endl;
	return 0;
}
