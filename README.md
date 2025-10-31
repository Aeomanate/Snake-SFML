# Snake-SFML
Just my snake via SFML

Tools:
* SFML-3.0.2
* MinGW, CMake
* CLion, PVS-Studio plugin

# Windows installation
* Install:
   * MinGW [WinLibs UCRT 14.2.0 (64-bit)](https://github.com/brechtsanders/winlibs_mingw/releases/download/14.2.0posix-19.1.1-12.0.0-ucrt-r2/winlibs-x86_64-posix-seh-gcc-14.2.0-mingw-w64ucrt-12.0.0-r2.7z)
   * [CMake](https://cmake.org/download/) and add to PATH
   * [Ninja](https://github.com/ninja-build/ninja/releases) and add to PATH
  
    > [!IMPORTANT]
    > You should put to the toolchain_window.cmake file the path to the MinGW folder.
* Via `cmd.exe`:
```
git lfs install
git clone https://github.com/Aeomanate/Snake-SFML.git Snake-SFML
cd Snake-SFML
git lfs checkout

cmake ^
-S . ^
-DCMAKE_TOOLCHAIN_FILE=toolchain_window.cmake ^
-DCMAKE_BUILD_TYPE=Release ^
-DCMAKE_MAKE_PROGRAM=ninja.exe ^
-G "Ninja" ^
-B cmake-build-release

cmake --build cmake-build-release --target Snake -j
```

* Via `CLion`:

