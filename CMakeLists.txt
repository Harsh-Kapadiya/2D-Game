cmake_minimum_required(VERSION 3.21)
project(2D-Game LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Prebuilt SFML 3.1.0 for Visual Studio (vc17, 64-bit) in External/SFML
find_package(SFML 3.1 REQUIRED COMPONENTS Graphics Audio Network
    PATHS "${CMAKE_SOURCE_DIR}/External/SFML" NO_DEFAULT_PATH)

# Every .cpp in "Source Files" is part of the game (new files get picked up automatically)
file(GLOB GAME_SOURCES CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/Source Files/*.cpp")
add_executable(2D-Game ${GAME_SOURCES})
target_link_libraries(2D-Game PRIVATE SFML::Graphics SFML::Audio SFML::Network)

# Copy the SFML DLLs next to the .exe so it runs from F5 or a double-click
add_custom_command(TARGET 2D-Game POST_BUILD
    COMMAND "${CMAKE_COMMAND}" -E copy_if_different $<TARGET_RUNTIME_DLLS:2D-Game> $<TARGET_FILE_DIR:2D-Game>
    COMMAND_EXPAND_LISTS)
