cmake_minimum_required(VERSION 2.8)

project( imagematcher )

add_definitions(-std=c++98)

find_package( OpenCV REQUIRED )
add_executable( imagematcher main.cpp image_match_table.cpp match.cpp folder_walk.cpp )
target_link_libraries( imagematcher ${OpenCV_LIBS} )

include(CheckIncludeFiles)
check_include_files(dirent.h HAVE_DIRENT_H)

# Write configuration to header file.
configure_file(
    "${PROJECT_SOURCE_DIR}/config.h.in"
    "${PROJECT_BINARY_DIR}/config.h"
)
