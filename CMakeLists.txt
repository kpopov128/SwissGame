cmake_minimum_required(VERSION 3.16)

project(MyGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML CONFIG REQUIRED COMPONENTS Graphics Window System)

file(GLOB_RECURSE SOURCES
    src/*.cpp
    src/*.h
    src/*.hpp
)

add_executable(MyGame ${SOURCES})

target_include_directories(MyGame PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)

target_link_libraries(MyGame PRIVATE
    SFML::Graphics
    SFML::Window
    SFML::System
)

source_group(TREE ${CMAKE_SOURCE_DIR}/src FILES ${SOURCES})

if (EXISTS "${CMAKE_SOURCE_DIR}/resources")
    add_custom_command(TARGET MyGame POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
            "${CMAKE_SOURCE_DIR}/resources"
            "$<TARGET_FILE_DIR:MyGame>/resources"
    )
endif()