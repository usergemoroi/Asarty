#pragma once
namespace ImStb {
struct STB_TexteditState {
    int cursor;
    int select_start;
    int select_end;
    unsigned char has_preferred_x;
    unsigned char single_line;
    unsigned char undos_enabled;
    float preferred_x;
};
}
struct StbTexteditRow {
    float x0, x1;
    float baseline_y_delta;
    float ymin, ymax;
    int num_chars;
};
#define STB_TEXTEDIT_K_SHIFT 0x10000
inline void stb_textedit_initialize_state(ImStb::STB_TexteditState*, int) {}
inline void stb_textedit_click(void*, ImStb::STB_TexteditState*, float, float) {}
inline void stb_textedit_drag(void*, ImStb::STB_TexteditState*, float, float) {}
inline int stb_textedit_cut(void*, ImStb::STB_TexteditState*) { return 0; }
inline int stb_textedit_paste(void*, ImStb::STB_TexteditState*, char const*, int) { return 0; }
inline void stb_textedit_key(void*, ImStb::STB_TexteditState*, unsigned int) {}
