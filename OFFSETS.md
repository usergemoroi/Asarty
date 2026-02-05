# Game Offsets and Structures

This document contains information extracted from the binary analysis of `libx.so`.

## 📊 Extracted Strings Analysis

### Menu Structure
Based on extracted strings, the menu has the following tabs:

#### Aimbot Tab (`menu.aimbotTab`)
- `menu.aimbotTab.Main.Name`
- `menu.aimbotTab.Main.Enable`
- `menu.aimbotTab.Main.FOVCheck`
- `menu.aimbotTab.Main.DrawFov`
- `menu.aimbotTab.Main.FireCheck`
- `menu.aimbotTab.Main.AutoFire`
- `menu.aimbotTab.Main.UntouchableCheck`
- `menu.aimbotTab.Main.Silent`
- `menu.aimbotTab.Main.Bones`
  - `menu.aimbotTab.Main.Bones.Head`
  - `menu.aimbotTab.Main.Bones.Neck`
  - `menu.aimbotTab.Main.Bones.Stomach`
  - `menu.aimbotTab.Main.Bones.Hands`
  - `menu.aimbotTab.Main.Bones.Legs`
  - `menu.aimbotTab.Main.Bones.Foots`
- `menu.aimbotTab.Settings.BoneFilter`
  - `menu.aimbotTab.Settings.BoneFilter.Damage`
  - `menu.aimbotTab.Settings.BoneFilter.Angle`
- `menu.aimbotTab.Settings.Speed`
- `menu.aimbotTab.Settings.HitChance`
- `menu.aimbotTab.Settings.Fov`

#### Visuals Tab (`menu.visualsTab`)
**Player ESP:**
- `menu.visualsTab.Player.Title`
- `menu.visualsTab.Player.Enable`
- `menu.visualsTab.Player.Box`
- `menu.visualsTab.Player.Fill`
- `menu.visualsTab.Player.HealthBar`
- `menu.visualsTab.Player.HealthAmount`
- `menu.visualsTab.Player.Name`
- `menu.visualsTab.Player.WeaponIcon`
- `menu.visualsTab.Player.Traces`
- `menu.visualsTab.Player.Skeleton`
- `menu.visualsTab.Player.Thickness`
- `menu.visualsTab.Player.Rounding`

**Chams:**
- `menu.visualsTab.Player.Chams.Title`
- `menu.visualsTab.Player.Chams.Enable`
- `menu.visualsTab.Player.Chams.Type`

**Weapons:**
- `menu.visualsTab.Weapons.Title`
- `menu.visualsTab.Weapons.Enable`
- `menu.visualsTab.Weapons.Name`
- `menu.visualsTab.Weapons.Ammo`

**Grenades:**
- `menu.visualsTab.Grenades.Title`
- `menu.visualsTab.Grenades.Enable`
- `menu.visualsTab.Grenades.Circle`
- `menu.visualsTab.Grenades.Timer`

**World:**
- `menu.visualsTab.World.Title`
- `menu.visualsTab.World.SkyBox`
- `menu.visualsTab.World.AtmosphereThickness`
- `menu.visualsTab.World.Exposure`
- `menu.visualsTab.World.BulletTracer`
- `menu.visualsTab.World.SceneColor`
- `menu.visualsTab.World.Fog`
- `menu.visualsTab.World.FogStart`
- `menu.visualsTab.World.FogEnd`

#### Exploits Tab (`menu.exploitsTab`)
**Weapon:**
- `menu.exploitsTab.Weapon.Title`
- `menu.exploitsTab.Weapon.FireRate`
- `menu.exploitsTab.Weapon.InfinityAmmo`

**Host:**
- `menu.exploitsTab.Host.Title`
- `menu.exploitsTab.Host.NoHost.Description`
- `menu.exploitsTab.Host.Autowin`
- `menu.exploitsTab.Host.CrashHost`

**Bomb:**
- `menu.exploitsTab.Bomb.Title`
- `menu.exploitsTab.Bomb.GetBomb`
- `menu.exploitsTab.Bomb.AutoWin`

**Premium:**
- `menu.exploitsTab.Premium.Title`
- `menu.exploitsTab.Premium.TPV`
- `menu.exploitsTab.Premium.Invisible`
- `menu.exploitsTab.Premium.ChatSpam`
- `menu.exploitsTab.Premium.AutoKill`
- `menu.exploitsTab.Premium.FastStrafe`
- `menu.exploitsTab.Premium.CrashEnemies`
- `menu.exploitsTab.Premium.CrashTeammates`

**Movement:**
- `menu.exploitsTab.Movement.Title`
- `menu.exploitsTab.Movement.AirJump`

#### Skins Tab (`menu.skinsTab`)
- `menu.skinsTab.Edit`
- `menu.skinsTab.AddSkin`
- `menu.skinsTab.Type`
- `menu.skinsTab.Stattrack`
- `menu.skinsTab.Pattern`
- `menu.skinsTab.Rare`
- `menu.skinsTab.Back`

#### Config Tab (`menu.configTab`)
- `menu.configTab.CfgList.CreatedBy`

#### Settings Tab (`menu.settingsTab`)
- `menu.settingsTab.Name`

## 🎮 Unity Components Detected

### Renderers
- `MeshRenderer` - Used for 3D model rendering
- `ParticleSystemRenderer` - Particle effects
- `RenderSettings` - Global rendering settings

### Other
- `Draw Origin Model` - Debug/visualization feature
- Various transformation and matrix operations

## 🔍 ImGui Debug Strings

The library uses Dear ImGui for the menu interface. Found debug strings:
- `SetActiveID() old:0x%08X (window "%s") -> new:0x%08X (window "%s")`
- `FocusItem(0x%08x) in window "%s"`
- `Table 0x%08X (%d columns, in '%s')`
- `Mesh: ElemCount: %d, VtxOffset: +%d, IdxOffset: +%d, Area: ~%0.f px`

## 🔢 Memory Structure Hints

### Offset Format Strings
Found format strings suggesting offset-based memory access:
- `Offset: %.2f, Width: %.2f/%.2f`
- `Offset: (%.1f,%.1f)`
- `Offset`

### Hex Address Patterns
- `0x%08X` - 32-bit addresses
- `ActiveId: 0x%08X/0x%08X`
- `NavId: 0x%08X`
- `Column %02d: OffsetNorm %.3f (= %.1f px)`

## 📱 Android-Specific

### Libraries Linked
- `libandroid.so` - Android framework
- `liblog.so` - Logging
- `libmediandk.so` - MediaCodec/MediaMuxer
- `libOpenSLES.so` - Audio
- `libEGL.so` - OpenGL context
- `libGLESv2.so`, `libGLESv3.so` - OpenGL ES

### Media Format Keys
- `AMEDIAFORMAT_KEY_BIT_RATE`
- `AMEDIAFORMAT_KEY_FRAME_RATE`
- `AMEDIAFORMAT_KEY_HEIGHT`
- `AMEDIAFORMAT_KEY_I_FRAME_INTERVAL`
- `AMEDIAFORMAT_KEY_MIME`
- `AMEDIAFORMAT_KEY_WIDTH`

## 🛠️ Reverse Engineering Notes

### Tools Used
```bash
# Extract strings
strings libx.so > strings.txt

# Analyze ELF structure
readelf -a libx.so > readelf.txt

# Disassemble
objdump -d libx.so > disasm.txt

# For deeper analysis
ghidra # or IDA Pro
```

### Key Functions to Reverse (Examples)
1. **Player List Iteration** - Find loop accessing player array
2. **World to Screen** - Matrix multiplication for 3D->2D projection
3. **Bone Position** - Transform hierarchy traversal
4. **Health Getter** - Memory offset read
5. **Team Getter** - Memory offset read

### Typical Unity IL2CPP Offset Pattern
```cpp
// Example pseudo-code
uintptr_t PlayerBase = *(uintptr_t*)(GameAssembly + 0xXXXXXXX);
uintptr_t PlayerArray = *(uintptr_t*)(PlayerBase + 0xXX);
int PlayerCount = *(int*)(PlayerBase + 0xXX + 0x4);

for (int i = 0; i < PlayerCount; i++) {
    uintptr_t player = *(uintptr_t*)(PlayerArray + (i * 0x8));
    float health = *(float*)(player + HealthOffset);
    // ... etc
}
```

## ⚠️ Important Notes

1. **Offsets Change**: Every game update may change offsets
2. **Version Specific**: These strings are from a specific binary version
3. **Anti-Cheat**: Game may have detection mechanisms
4. **Legal**: Educational purposes only

## 🔄 Update Process

When game updates:
1. Dump new `libx.so` from APK
2. Run `strings` and `readelf` analysis
3. Compare with old version
4. Update offsets in `Game.h`
5. Test in-game
6. Adjust if needed

## 📚 Resources

- [IL2CPP Dumper](https://github.com/Perfare/Il2CppDumper)
- [Unity IL2CPP Internals](https://docs.unity3d.com/Manual/IL2CPP.html)
- [ARM64 Instruction Set](https://developer.arm.com/documentation)
- [Android NDK](https://developer.android.com/ndk)

---

**Note**: This information is for educational and research purposes. Always respect game developers and terms of service.
