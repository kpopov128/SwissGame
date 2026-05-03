cmake_minimum_required(VERSION 3.16)

project(MyGame)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SFML_DIR "${CMAKE_SOURCE_DIR}/external/SFML-2.6.1/lib/cmake/SFML")
find_package(SFML 2.6 CONFIG REQUIRED COMPONENTS graphics window system)

file(GLOB_RECURSE SOURCES
    src/*.cpp
    src/*.h
    src/*.hpp
)

add_executable(MyGame ${SOURCES})

target_include_directories(MyGame BEFORE PRIVATE
    "${CMAKE_SOURCE_DIR}/external/SFML-2.6.1/include"
    "${CMAKE_SOURCE_DIR}/src"
)

target_link_libraries(MyGame PRIVATE
    sfml-graphics
    sfml-window
    sfml-system
)

source_group(TREE ${CMAKE_SOURCE_DIR}/src FILES ${SOURCES})

if (EXISTS "${CMAKE_SOURCE_DIR}/resources")
    add_custom_command(TARGET MyGame POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
            "${CMAKE_SOURCE_DIR}/resources"
            "$<TARGET_FILE_DIR:MyGame>/resources"
    )
endif()

add_custom_command(TARGET MyGame POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_SOURCE_DIR}/external/SFML-2.6.1/bin"
        "$<TARGET_FILE_DIR:MyGame>"
)