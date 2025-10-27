set(CMAKE_C_COMPILER "${MingwSFML3}/bin/gcc.exe")
set(CMAKE_CXX_COMPILER "${MingwSFML3}/bin/g++.exe")
set(CMAKE_RC_COMPILER "${MingwSFML3}/bin/windres.exe")


# Find Ninja on PATH and derive NINJA_PATH automatically
find_program(NINJA_EXE NAMES ninja ninja.exe)
if(NOT NINJA_EXE)
    message(FATAL_ERROR "Ninja not found in PATH. Please install Ninja and ensure ninja/ninja.exe is available on PATH.")
endif()
get_filename_component(NINJA_PATH "${NINJA_EXE}" DIRECTORY)

# Use the detected Ninja as the make program
set(CMAKE_MAKE_PROGRAM "${NINJA_EXE}" CACHE FILEPATH "Path to Ninja executable" FORCE)

