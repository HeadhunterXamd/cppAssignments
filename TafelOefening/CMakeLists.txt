cmake_minimum_required (VERSION 2.6)
project (TafelOefening)
file(GLOB_RECURSE Cpp_SOURCES "*.cpp")
file(GLOB_RECURSE Cpp_HEADERS "*.h")

set (Cpp_INCLUDE_DIRS "")
foreach (_headerFile ${Cpp_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND Cpp_INCLUDE_DIRS ${_dir})
endforeach()
list(REMOVE_DUPLICATES Cpp_INCLUDE_DIRS)

include_directories(${Cpp_INCLUDE_DIRS})
add_executable (TafelOefening ${Cpp_SOURCES})

