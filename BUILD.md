# Build Instructions

## Prerequisites

### Required Software
- **Android NDK** r21 or later
- **CMake** 3.10 or later
- **Git** (for cloning dependencies)
- **Python** 3.6+ (optional, for automation scripts)

### Dependencies
- **Dear ImGui** - GUI framework
- **OpenGL ES** headers (included in NDK)
- **Android headers** (included in NDK)

## Setup

### 1. Install Android NDK

Download from: https://developer.android.com/ndk/downloads

```bash
# Example for Linux
wget https://dl.google.com/android/repository/android-ndk-r21e-linux-x86_64.zip
unzip android-ndk-r21e-linux-x86_64.zip
export ANDROID_NDK=$HOME/android-ndk-r21e
```

### 2. Clone Dear ImGui

```bash
cd /path/to/project
mkdir -p include/imgui
cd include/imgui

# Clone ImGui
git clone https://github.com/ocornut/imgui.git .

# Copy required files
cp imgui.cpp imgui.h imgui_internal.h imconfig.h \
   imgui_draw.cpp imgui_widgets.cpp imgui_tables.cpp \
   ../../src/

# Copy backends
cp backends/imgui_impl_opengl3.cpp backends/imgui_impl_opengl3.h \
   backends/imgui_impl_android.cpp backends/imgui_impl_android.h \
   ../../src/
```

## Building

### Method 1: Command Line Build

```bash
# Navigate to project directory
cd /path/to/project

# Create build directory
mkdir -p build/arm64-v8a
cd build/arm64-v8a

# Configure CMake
cmake ../.. \
  -DCMAKE_TOOLCHAIN_FILE=$ANDROID_NDK/build/cmake/android.toolchain.cmake \
  -DANDROID_ABI=arm64-v8a \
  -DANDROID_PLATFORM=android-21 \
  -DCMAKE_BUILD_TYPE=Release

# Build
make -j$(nproc)

# Output will be at: libx.so
```

### Method 2: Build All ABIs

```bash
#!/bin/bash
# build_all.sh

ABIS=("arm64-v8a" "armeabi-v7a" "x86" "x86_64")

for ABI in "${ABIS[@]}"; do
    echo "Building for $ABI..."
    mkdir -p build/$ABI
    cd build/$ABI
    
    cmake ../.. \
        -DCMAKE_TOOLCHAIN_FILE=$ANDROID_NDK/build/cmake/android.toolchain.cmake \
        -DANDROID_ABI=$ABI \
        -DANDROID_PLATFORM=android-21 \
        -DCMAKE_BUILD_TYPE=Release
    
    make -j$(nproc)
    cd ../..
    
    echo "Built: build/$ABI/libx.so"
done

echo "All builds complete!"
```

## Output

After successful build:
```
build/
├── arm64-v8a/
│   └── libx.so      # ARM 64-bit
├── armeabi-v7a/
│   └── libx.so      # ARM 32-bit
├── x86/
│   └── libx.so      # x86 32-bit (emulator)
└── x86_64/
    └── libx.so      # x86 64-bit (emulator)
```

## Installation

### Method 1: Manual Installation (Rooted Device)

```bash
# Push to device
adb push build/arm64-v8a/libx.so /data/local/tmp/

# On device (via adb shell)
adb shell
su
mount -o remount,rw /system
cp /data/local/tmp/libx.so /system/lib64/libx.so
chmod 755 /system/lib64/libx.so
```

### Method 2: Using Magisk Module

Create a Magisk module structure:
```
module/
├── META-INF/
│   └── com/
│       └── google/
│           └── android/
│               └── update-binary
│               └── updater-script
├── system/
│   └── lib64/
│       └── libx.so
├── module.prop
└── install.sh
```

### Method 3: Using Zygisk/LSPosed

1. Build as library
2. Create Xposed/LSPosed module
3. Inject library via hooking framework

## Testing

### 1. Verify Library

```bash
# Check architecture
file libx.so
# Output: libx.so: ELF 64-bit LSB shared object, ARM aarch64...

# Check symbols (should be stripped)
nm -D libx.so

# Check dependencies
readelf -d libx.so | grep NEEDED
```

### 2. Test on Device

```bash
# Check if library loads
adb logcat | grep "ESP\|GUI"

# Should see initialization messages
```

## Debugging

### Enable Debug Build

```cmake
# Change in CMakeLists.txt or command line
-DCMAKE_BUILD_TYPE=Debug
```

This will:
- Keep symbols for debugging
- Disable optimizations
- Add debug logging

### GDB Debugging

```bash
# On device
adb shell
gdbserver :5039 --attach $(pidof com.game.package)

# On host
$ANDROID_NDK/prebuilt/linux-x86_64/bin/gdb
target remote :5039
```

## Common Issues

### Issue: CMake can't find NDK

**Solution:**
```bash
export ANDROID_NDK=/path/to/ndk
export PATH=$ANDROID_NDK:$PATH
```

### Issue: Missing ImGui headers

**Solution:**
```bash
# Make sure imgui is in include/imgui/
ls -la include/imgui/
```

### Issue: Linking errors

**Solution:**
```bash
# Check that all libraries are available
# Add to CMakeLists.txt if needed:
target_link_libraries(x android log EGL GLESv2)
```

### Issue: App crashes on load

**Solution:**
- Check logcat for errors
- Verify ABI matches device architecture
- Ensure all dependencies are met
- Check SELinux context if needed

## Optimization

### Size Optimization

Add to CMakeLists.txt:
```cmake
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Os -ffunction-sections -fdata-sections")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--gc-sections")
```

Then:
```bash
# Strip symbols
$ANDROID_NDK/toolchains/llvm/prebuilt/linux-x86_64/bin/llvm-strip \
  --strip-unneeded libx.so

# Further compression (optional)
upx --best libx.so
```

### Performance Optimization

```cmake
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -flto -ffast-math")
```

## Advanced

### Custom Toolchain

If you need specific compiler flags:
```cmake
# Create custom toolchain file
set(CMAKE_C_COMPILER $ANDROID_NDK/toolchains/llvm/prebuilt/linux-x86_64/bin/clang)
set(CMAKE_CXX_COMPILER $ANDROID_NDK/toolchains/llvm/prebuilt/linux-x86_64/bin/clang++)
```

### Static Linking

To reduce dependencies:
```cmake
target_link_libraries(x 
    -static-libstdc++
    -static-libgcc
)
```

## CI/CD

### GitHub Actions Example

```yaml
name: Build

on: [push, pull_request]

jobs:
  build:
    runs-on: ubuntu-latest
    steps:
    - uses: actions/checkout@v2
    
    - name: Setup NDK
      run: |
        wget https://dl.google.com/android/repository/android-ndk-r21e-linux-x86_64.zip
        unzip -q android-ndk-r21e-linux-x86_64.zip
        export ANDROID_NDK=$PWD/android-ndk-r21e
    
    - name: Build
      run: |
        mkdir build && cd build
        cmake .. -DCMAKE_TOOLCHAIN_FILE=$ANDROID_NDK/build/cmake/android.toolchain.cmake \
                 -DANDROID_ABI=arm64-v8a
        make -j4
    
    - name: Upload
      uses: actions/upload-artifact@v2
      with:
        name: libx.so
        path: build/libx.so
```

## Troubleshooting

### Check Build Environment

```bash
# Verify NDK
echo $ANDROID_NDK
ls $ANDROID_NDK/build/cmake/android.toolchain.cmake

# Verify CMake
cmake --version

# Verify Clang
$ANDROID_NDK/toolchains/llvm/prebuilt/linux-x86_64/bin/clang --version
```

### Clean Build

```bash
# Remove build artifacts
rm -rf build/
rm -rf CMakeCache.txt
rm -rf CMakeFiles/

# Rebuild
mkdir build && cd build
cmake ..
make clean && make
```

## Support

For build issues:
1. Check error messages carefully
2. Verify all dependencies are installed
3. Ensure NDK version compatibility
4. Check Android platform version

## Resources

- [Android NDK Documentation](https://developer.android.com/ndk/guides)
- [CMake Documentation](https://cmake.org/documentation/)
- [ARM Assembly Reference](https://developer.arm.com/documentation)

---

**Last Updated**: Based on NDK r21e and CMake 3.10
