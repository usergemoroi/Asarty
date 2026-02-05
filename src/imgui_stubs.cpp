#include "imgui.h"
#include <android/log.h>

namespace ImGui {
    bool Begin(const char*, bool*, ImGuiWindowFlags) { return true; }
    void End() {}
    bool BeginTabBar(const char*, ImGuiTabBarFlags) { return true; }
    void EndTabBar() {}
    bool BeginTabItem(const char*, bool*, ImGuiTabItemFlags) { return true; }
    void EndTabItem() {}
    void SeparatorText(const char*) {}
    bool Checkbox(const char*, bool*) { return true; }
    bool SliderFloat(const char*, float*, float, float, const char*, ImGuiSliderFlags) { return true; }
    void Text(const char*, ...) {}
    bool Combo(const char*, int*, const char*, int) { return true; }
    bool Button(const char*, const ImVec2&) { return true; }
    void OpenPopup(const char*, ImGuiPopupFlags) {}
    bool BeginPopup(const char*, ImGuiWindowFlags) { return true; }
    void EndPopup() {}
    void SameLine(float, float) {}
    void Separator() {}
    bool BeginChild(const char*, const ImVec2&, bool, ImGuiWindowFlags) { return true; }
    void EndChild() {}
    bool Selectable(const char*, bool, ImGuiSelectableFlags, const ImVec2&) { return true; }
    bool InputText(const char*, char*, size_t, ImGuiInputTextFlags, ImGuiInputTextCallback, void*) { return true; }
    bool InputInt(const char*, int*, int, int, ImGuiInputTextFlags) { return true; }
    ImGuiStyle& GetStyle() { static ImGuiStyle style; return style; }
    ImGuiIO& GetIO() { static ImGuiIO io; return io; }
    ImGuiContext* CreateContext(ImFontAtlas*) { return nullptr; }
    void DestroyContext(ImGuiContext*) {}
    void Render() {}
    ImDrawData* GetDrawData() { return nullptr; }
    void NewFrame() {}
}

void ImGui_ImplOpenGL3_RenderDrawData(ImDrawData*) {}
bool ImGui_ImplOpenGL3_Init(const char*) { return true; }
void ImGui_ImplOpenGL3_Shutdown() {}
void ImGui_ImplOpenGL3_NewFrame() {}
bool ImGui_ImplAndroid_HandleInputEvent(const AInputEvent*) { return true; }
