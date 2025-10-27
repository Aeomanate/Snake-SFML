cmake_minimum_required(VERSION 3.12)
project(Snake)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++17 -pedantic -Wall -Wextra")

if (CMAKE_BUILD_TYPE MATCHES Release)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
    set(SFML_STATIC_LIBRARIES FALSE)
endif ()

# Adding ico to exe
if (MINGW)
    set(CMAKE_RC_COMPILER_INIT windres)
    ENABLE_LANGUAGE(RC)
    SET(CMAKE_RC_COMPILE_OBJECT "<CMAKE_RC_COMPILER> <FLAGS> <DEFINES> -o <OBJECT> <SOURCE>")
endif (MINGW)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.2
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM)
FetchContent_MakeAvailable(SFML)

# Project files
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/Executable/bin)

include_directories(SRC)
include_directories(Executable)

add_executable(${PROJECT_NAME}
        config.rc # Add ico to exe
        SRC/Icon/IconOpenGL.h # Icon for OpenGL window
        SRC/Icon/IconOpenGL.c

        SRC/main.cpp

        SRC/Utility/Coord/Coord.cpp
        SRC/Utility/Coord/Coord.hpp

        SRC/Utility/FatalError/FatalError.cpp
        SRC/Utility/FatalError/FatalError.hpp

        SRC/Utility/RandomGenerator/RandomGenerator.hpp
        SRC/Utility/RandomGenerator/RandomGenerator.cpp

        SRC/Utility/TextureStorage/TextureStorage.cpp
        SRC/Utility/TextureStorage/TextureStorage.hpp

        SRC/Utility/ThreadGuard/ThreadGuard.hpp
        SRC/Utility/ThreadGuard/ThreadGuard.cpp

        SRC/Utility/ThreadGuard/LiveStorage/LiveStorage.cpp
        SRC/Utility/ThreadGuard/LiveStorage/LiveStorage.hpp

        SRC/Utility/Trivials/Trivials.cpp
        SRC/Utility/Trivials/Trivials.hpp

        SRC/Utility/WindowForTests/WindowForTests.cpp
        SRC/Utility/WindowForTests/WindowForTests.hpp

        SRC/Utility/ListRunner.hpp
        SRC/Utility/Stopwatch.hpp
        SRC/Utility/TimeProfiler.hpp
        SRC/Utility/Timer.hpp
        SRC/Utility/RandomSort.hpp


        SRC/CellsPool/DefaultRectangle/DefaultRectangle.cpp
        SRC/CellsPool/DefaultRectangle/DefaultRectangle.hpp

        SRC/CellsPool/Cell/Filler/Filler.cpp
        SRC/CellsPool/Cell/Cell.cpp
        SRC/CellsPool/Cell/Cell.hpp

        SRC/CellsPool/NotFoundFreeCell/NotFoundFreeCell.cpp
        SRC/CellsPool/NotFoundFreeCell/NotFoundFreeCell.hpp

        SRC/CellsPool/Cell/Fillers/NullFiller.hpp

        SRC/CellsPool/Cell/Fillers/FreeCell.hpp
        SRC/CellsPool/Cell/Fillers/Eat.hpp
        SRC/CellsPool/Cell/Fillers/Head.hpp
        SRC/CellsPool/Cell/Fillers/BodyAngle.hpp
        SRC/CellsPool/Cell/Fillers/BodyStraight.hpp
        SRC/CellsPool/Cell/Fillers/Tail.hpp

        SRC/CellsPool/CellsPool.cpp
        SRC/CellsPool/CellsPool.hpp

        SRC/CellsPool/Cell/Filler/Filler.hpp


        SRC/Snake/Snake.cpp
        SRC/Snake/Snake.hpp
        SRC/Snake/EndGame.hpp


        SRC/BonusManager/BonusManager.cpp
        SRC/BonusManager/BonusManager.hpp

        SRC/BonusManager/Bonus/Bonus.cpp
        SRC/BonusManager/Bonus/Bonus.hpp

        SRC/BonusManager/AddChapter/AddChapter.cpp
        SRC/BonusManager/AddChapter/AddChapter.hpp

        SRC/BonusManager/SteppedOnBody/SteppedOnBody.cpp
        SRC/BonusManager/SteppedOnBody/SteppedOnBody.hpp

        SRC/BonusManager/SteppedOnHead/SteppedOnHead.cpp
        SRC/BonusManager/SteppedOnHead/SteppedOnHead.hpp

        SRC/BonusManager/Move/Move.cpp
        SRC/BonusManager/Move/Move.hpp

        SRC/BonusManager/SteppedOnBody/SteppedOnBody.cpp
        SRC/BonusManager/SteppedOnBody/SteppedOnBody.hpp

        SRC/BonusManager/SteppedOnHead/SteppedOnHead.cpp
        SRC/BonusManager/SteppedOnHead/SteppedOnHead.hpp


        SRC/AudioPlayer/AudioController.cpp
        SRC/AudioPlayer/AudioController.hpp

        SRC/AudioPlayer/MusicPlayer/MusicPlayer.cpp
        SRC/AudioPlayer/MusicPlayer/MusicPlayer.hpp

        SRC/AudioPlayer/SoundPlayer/SoundPlayer.cpp
        SRC/AudioPlayer/SoundPlayer/SoundPlayer.hpp

)

target_link_libraries(${PROJECT_NAME} PRIVATE SFML::System SFML::Window SFML::Graphics)
