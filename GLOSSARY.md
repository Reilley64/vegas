# vegas

The source of Fallout: New Vegas, rebuilt from the original release. It builds a native game for each build target.

## Language

**Original release**:
Fallout: New Vegas for PC, version 1.4.0.525, as Steam installs it. Its FalloutNV.exe is the program this source rebuilds.
_Avoid_: retail build, vanilla game, the image

**Build target**:
An operating system and processor pair that the game builds for: windows-x64, linux-x64 or macos-arm64.
_Avoid_: platform, port

**Game data**:
The plugins, BSAs, videos, music and other files in the Data folder of a player's own copy of the game.
_Avoid_: assets, game content

**Install folder**:
The folder of a player's copy of the game that holds FalloutNV.exe, the Data folder and Fallout_default.ini.
_Avoid_: game directory, install path, game root
