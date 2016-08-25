cmake_minimum_required(VERSION 3.0)
project(sdl2-boilerplate)

# Compiler settings
if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -std=c99")
endif()

# This brings in SDL2 path autodiscovery
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
find_package(SDL2 REQUIRED)

# Includes
include_directories(sdl2-boilerplate/include/
                    ${SDL2_INCLUDE_DIR})

# Globs
file(GLOB PROJECT_HEADERS sdl2-boilerplate/include/*.h)
file(GLOB PROJECT_SOURCES sdl2-boilerplate/src/*.c)
file(GLOB PROJECT_CONFIGS CMakeLists.txt
                          README.md
                         .gitignore
                         .gitmodules)

# Sources
source_group("Headers" FILES ${PROJECT_HEADERS})
source_group("Sources" FILES ${PROJECT_SOURCES})

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES} ${PROJECT_HEADERS}
                               ${PROJECT_CONFIGS})

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY})

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PROJECT_NAME})
