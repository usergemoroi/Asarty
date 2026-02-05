#include <jni.h>
#include <thread>
#include <chrono>
#include "ESP.h"
#include "GUI.h"
#include "Aimbot.h"
#include "Game.h"
#include <android/log.h>

void MainThread() {
    __android_log_print(ANDROID_LOG_INFO, "ModMenu", "Main thread started");
    
    // Initialize components
    if (Game::Init()) {
        g_ESP = new ESP();
        g_ESP->Init();
        
        g_GUI = new GUI();
        // GUI Init will be called when we have a window/context
        
        g_Aimbot = new Aimbot();
        g_Aimbot->Init();
        
        __android_log_print(ANDROID_LOG_INFO, "ModMenu", "Components initialized");
    }
    
    // Main loop (if needed)
    while (true) {
        if (g_Aimbot) g_Aimbot->Update();
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

extern "C" JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved) {
    __android_log_print(ANDROID_LOG_INFO, "ModMenu", "JNI_OnLoad called");
    
    std::thread(MainThread).detach();
    
    return JNI_VERSION_1_6;
}
