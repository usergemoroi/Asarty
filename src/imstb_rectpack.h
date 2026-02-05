#pragma once
struct stbrp_context { int width; int height; int align; int init_mode; int num_nodes; struct stbrp_node* active_head; struct stbrp_node* free_head; struct stbrp_node extra[2]; };
struct stbrp_node { int x, y; struct stbrp_node* next; };
struct stbrp_rect { int id; int w, h; int x, y; int was_packed; };
inline void stbrp_init_target(stbrp_context*, int, int, stbrp_node*, int) {}
inline void stbrp_pack_rects(stbrp_context*, stbrp_rect*, int) {}
inline void stbrp_setup_allow_out_of_mem(stbrp_context*, int) {}
inline void stbrp_setup_heuristic(stbrp_context*, int) {}
