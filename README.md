Completely unsure why this crashes.

The application is compiled with MSVC 14.44.35207 (Latest at time of writing).

msdf-atlas-gen is locally cloned and compiled in includes/, https://github.com/Chlumsky/artery-font-format and https://github.com/Chlumsky/msdfgen are git cloned in as well. Freetype is included with vcpkg because I couldn't be bother doing otherwise.

I've tried using local glyphs and a provided std::vector of gylphs for FontGeometry but both crash.
local:
```
msdf_atlas::FontGeometry fontGeometry;

fontGeometry.loadCharset(font, 1.0, msdf_atlas::Charset::ASCII);

std::vector<msdf_atlas::GlyphGeometry> glyphs(fontGeometry.getGlyphs().begin(), fontGeometry.getGlyphs().end());
```

provided:
```
std::vector<msdf_atlas::GlyphGeometry> glyphs;
msdf_atlas::FontGeometry fontGeometry(&glyphs);
```

I tried adding ASAN which can be enabled in CMakeLists.txt by uncommenting all the commented lines. The issue with enabling ASAN is that the application no longer crashes which is just great. The application works fine on MacOS.
