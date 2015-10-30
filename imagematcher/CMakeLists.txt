cmake_minimum_required(VERSION 2.8)

project( imagematcher )

find_package( OpenCV REQUIRED )
add_executable( imagematcher main.cpp image_match_table.cpp match.cpp )
target_link_libraries( imagematcher ${OpenCV_LIBS} )
