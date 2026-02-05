cmake_minimum_required(VERSION 3.10)
project(libx)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Android NDK configuration
if(ANDROID OR NOT ANDROID) # Always enable for our build
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -O3 -fvisibility=hidden")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -O3 -fvisibility=hidden -fno-rtti -DIMGUI_DISABLE_STB_RECT_PACK_IMPLEMENTATION -DIMGUI_DISABLE_STB_TRUETYPE_IMPLEMENTATION -DIMGUI_DISABLE_STB_TEXTEDIT_IMPLEMENTATION -DIMGUI_IMPL_OPENGL_ES3 -DANDROID")
    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--exclude-libs,ALL")
endif()

# Include directories
include_directories(
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/include/imgui
    ${CMAKE_SOURCE_DIR}/stubs
)

# Source files
set(SOURCES
    src/ESP.cpp
    src/GUI.cpp
    src/Player.cpp
    src/Game.cpp
    src/Drawing.cpp
    src/Aimbot.cpp
    src/Config.cpp
    src/main.cpp
)

# ImGui sources (if using ImGui)
set(IMGUI_SOURCES
    src/imgui.cpp
    src/imgui_draw.cpp
    src/imgui_widgets.cpp
    src/imgui_tables.cpp
    src/imgui_impl_opengl3.cpp
    src/imgui_impl_android.cpp
)

# Create shared library
add_library(x SHARED ${SOURCES})
# (Removed IMGUI_SOURCES)

# Link libraries
if(ANDROID)
    target_link_libraries(x
        android
        log
        EGL
        GLESv2
        GLESv3
    )
endif()

# Set output name
set_target_properties(x PROPERTIES
    OUTPUT_NAME "x"
    PREFIX "lib"
    SUFFIX ".so"
)

# Strip symbols in release mode
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    add_custom_command(TARGET x POST_BUILD
        COMMAND ${CMAKE_STRIP} --strip-unneeded $<TARGET_FILE:x>
    )
endif()
