#pragma once
struct stbtt_fontinfo { int dummy; };
struct stbtt_pack_context { int dummy; };
struct stbtt_packedchar { unsigned short x0, y0, x1, y1; float xoff, yoff, xadvance; float xoff2, yoff2; };
struct stbtt_pack_range { float font_size; int first_unicode_codepoint_in_range; int* array_of_unicode_codepoints; int num_chars; stbtt_packedchar* chardata_for_range; unsigned char h_oversample, v_oversample; };
inline int stbtt_PackBegin(stbtt_pack_context*, unsigned char*, int, int, int, int, void*) { return 0; }
inline void stbtt_PackEnd(stbtt_pack_context*) {}
inline int stbtt_PackFontRanges(stbtt_pack_context*, unsigned char const*, int, stbtt_pack_range*, int) { return 0; }
inline void stbtt_PackSetOversampling(stbtt_pack_context*, unsigned int, unsigned int) {}
inline void stbtt_GetPackedQuad(stbtt_packedchar const*, int, int, int, float*, float*, struct stbtt_aligned_quad*, int) {}
struct stbtt_aligned_quad { float x0, y0, s0, t0, x1, y1, s1, t1; };
