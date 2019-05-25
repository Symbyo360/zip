cmake_minimum_required(VERSION 3.9)
project(zip VERSION 0.1.14 LANGUAGES C)
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

if (MSVC)
  # Use secure functions by defaualt and suppress warnings about "deprecated" functions
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /D _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES=1")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /D _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_COUNT=1")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /D _CRT_NONSTDC_NO_WARNINGS=1 /D _CRT_SECURE_NO_WARNINGS=1")
elseif ("${CMAKE_C_COMPILER_ID}" STREQUAL "GNU" OR
        "${CMAKE_C_COMPILER_ID}" STREQUAL "Clang" OR
        "${CMAKE_C_COMPILER_ID}" STREQUAL "AppleClang")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -Wall -Wextra -Werror -pedantic")
endif (MSVC)

# zip
set(SRC src/miniz.h src/zip.h src/zip.c)
add_library(${PROJECT_NAME} ${SRC})
target_include_directories(${PROJECT_NAME} INTERFACE src)

# make it reflect the same structure as the one on disk
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SRC})

# generate exports header file
include(GenerateExportHeader)
generate_export_header(zip
	EXPORT_FILE_NAME ${CMAKE_CURRENT_SOURCE_DIR}/src/Exports.h
)
