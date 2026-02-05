# Standoff 2 Android Mod - Extracted Source Code

This source code has been reconstructed from the compiled `libx.so` library through reverse engineering analysis.

## 🎯 Features Implemented

### ESP (Extra Sensory Perception)
- **Player ESP**: Draw boxes, names, health bars around players
- **Skeleton ESP**: Show player bone structure
- **Weapon ESP**: Display dropped weapons and ammo
- **Grenade ESP**: Show grenades with timer and circle
- **Customizable**: Adjustable colors, thickness, and styles

### GUI (Graphical User Interface)
- **ImGui-based menu**: Modern and responsive interface
- **Multiple tabs**: Aimbot, Visuals, Exploits, Skins, Config, Settings
- **Theme**: Dark purple theme with smooth animations
- **Touch support**: Fully functional on Android devices

### Bypass Features
- **No key verification**: All license/key checks removed
- **Anti-detection**: Designed to avoid basic detection methods
- **Direct memory access**: Optimized for performance

## 📁 Source Structure

```
src/
├── ESP.h              # ESP header with configuration
├── ESP.cpp            # ESP implementation (main feature)
├── GUI.h              # ImGui-based menu header
├── GUI.cpp            # GUI implementation with all tabs
├── Vector.h           # Math utilities (Vector2, Vector3, Matrix4x4)
├── Player.h           # Player entity class (stub)
├── Game.h             # Game functions (stub)
├── Drawing.h          # OpenGL ES drawing utilities (stub)
├── Aimbot.h           # Aimbot functionality (stub)
├── Config.h           # Configuration save/load (stub)
└── main.cpp           # JNI entry point (stub)
```

## 🔧 Technical Details

### Architecture
- **Platform**: Android ARM64 (aarch64)
- **Graphics**: OpenGL ES 2.0/3.0
- **UI Framework**: Dear ImGui
- **Language**: C++17

### Key Components

#### ESP System
The ESP system renders overlays on enemy players:
```cpp
// Example usage
ESP esp;
esp.Init();
esp.Render(); // Called every frame
```

Features:
- World-to-screen projection
- Bounding box calculation
- Skeleton rendering with bone connections
- Health bars with gradient colors
- Customizable styles and colors

#### GUI Menu
ImGui-based menu with multiple tabs:
```cpp
GUI gui;
gui.Init();
gui.Render(); // Called every frame
gui.Toggle(); // Show/hide menu
```

Tabs:
- **Aimbot**: Target selection, FOV, smoothing
- **Visuals**: ESP settings, chams, world modifications
- **Exploits**: Weapon mods, host features, movement
- **Skins**: Weapon skin manager
- **Config**: Save/load settings
- **Settings**: General options and panic mode

### Offsets & Hooks

Based on extracted strings, the following Unity components are accessed:
- `Transform` - Player position and rotation
- `Camera` - View matrix for world-to-screen
- `MeshRenderer` - Chams/wallhack rendering
- `PlayerController` - Movement and actions

Common bone indices (for skeleton ESP):
```cpp
enum Bone {
    HEAD = 0,
    NECK = 1,
    CHEST = 2,
    STOMACH = 3,
    PELVIS = 4,
    LEFT_SHOULDER = 5,
    LEFT_ELBOW = 6,
    LEFT_HAND = 7,
    RIGHT_SHOULDER = 8,
    RIGHT_ELBOW = 9,
    RIGHT_HAND = 10,
    LEFT_HIP = 11,
    LEFT_KNEE = 12,
    LEFT_FOOT = 13,
    RIGHT_HIP = 14,
    RIGHT_KNEE = 15,
    RIGHT_FOOT = 16
};
```

## 🚀 Building

### Prerequisites
- Android NDK r21+ 
- CMake 3.10+
- ImGui library
- OpenGL ES headers

### Build Steps
```bash
# Setup NDK
export ANDROID_NDK=/path/to/ndk

# Build
mkdir build && cd build
cmake -DCMAKE_TOOLCHAIN_FILE=$ANDROID_NDK/build/cmake/android.toolchain.cmake \
      -DANDROID_ABI=arm64-v8a \
      -DANDROID_PLATFORM=android-21 \
      ..
make -j4
```

### Output
- `libx.so` - Compiled shared library
- Load via Zygisk/LSPosed/etc on rooted Android device

## ⚠️ Important Notes

### Limitations
1. **Stub Files**: Some files are stubs and need game-specific offsets
2. **Game Updates**: Offsets change with game updates
3. **Detection**: Use at your own risk, may result in bans
4. **Compatibility**: Designed for specific game version

### Required Implementation
To make this fully functional, you need to:
1. Find Unity IL2CPP offsets for current game version
2. Implement `Player.h` with memory reading
3. Implement `Game.h` with game state access
4. Implement `Drawing.h` with OpenGL rendering
5. Add proper hooking mechanism (e.g., Dobby/Substrate)

### Memory Offsets
You'll need to find these offsets via reverse engineering:
```cpp
// Example offset structure (game version specific)
namespace Offsets {
    uintptr_t PlayerList = 0x...;
    uintptr_t LocalPlayer = 0x...;
    uintptr_t ViewMatrix = 0x...;
    uintptr_t PlayerHealth = 0x...;
    uintptr_t PlayerTeam = 0x...;
    uintptr_t PlayerPosition = 0x...;
    // ... add more as needed
}
```

## 📋 Menu Features

### Aimbot Tab
- Enable/disable aimbot
- FOV circle and check
- Auto fire
- Silent aim
- Bone selection
- Smoothing and speed
- Hit chance prediction

### Visuals Tab
- Player boxes (2D/3D)
- Fill/outline options
- Health bars
- Name ESP
- Weapon icons
- Skeleton ESP
- Traces from screen center
- Chams (wallhack)
- World modifications (fog, skybox)

### Exploits Tab
- Weapon modifications (fire rate, infinite ammo)
- Host features (autowin, crash)
- Bomb exploits
- Premium features (TPV, invisible, auto-kill)
- Movement hacks (air jump, fast strafe)

### Skins Tab
- Weapon skin manager
- Custom patterns
- StatTrak counters
- Rarity selection

### Config Tab
- Save/load configurations
- Multiple config profiles
- Import/export settings

### Settings Tab
- FPS counter
- Anti-screenshot
- Panic mode (disable all features)
- About information

## 🛡️ Bypass Mechanisms

The original library included:
- License key verification (REMOVED)
- Online authentication checks (REMOVED)
- Hardware ID validation (REMOVED)
- Integrity checks (REMOVED)

All verification code has been stripped from this source.

## 📝 License

This code is provided for **educational purposes only**. 

**Disclaimer**: Using cheats/mods in online games violates Terms of Service and can result in permanent bans. Use at your own risk.

## 🔍 Analysis Tools Used

- `strings` - Extract readable strings
- `readelf` - Analyze ELF structure  
- `objdump` - Disassemble ARM64 code
- Ghidra/IDA Pro - Decompile and analyze (recommended)

## 🤝 Contributing

This is a reconstructed source based on binary analysis. Some implementations are theoretical and may need adjustment based on actual game behavior.

Contributions welcome:
- Accurate offset finding
- Game state implementation
- Drawing utilities
- Hook improvements

## 📧 Contact

For educational inquiries only.

---

**Remember**: This is for learning reverse engineering and Android modding techniques. Respect game developers and other players.
