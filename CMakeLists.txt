cmake_minimum_required(VERSION 3.10)
project(it LANGUAGES C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

file(GLOB LIB_SOURCES "src/*.c")

add_library(it ${LIB_SOURCES})

target_include_directories(it
  PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
  PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_compile_options(it PRIVATE
  $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
  $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic -Werror>
)

file(GLOB EXAMPLE_SOURCES "examples/*.c")

foreach(SOURCE_FILE ${EXAMPLE_SOURCES})
    # Extract the filename without the extension (e.g., 'hello_world')
    get_filename_component(EXAMPLE_NAME ${SOURCE_FILE} NAME_WE)
    add_executable(${EXAMPLE_NAME} ${SOURCE_FILE})
    target_compile_options(${EXAMPLE_NAME} PRIVATE
      $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
      $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic>
    )
    target_link_libraries(${EXAMPLE_NAME} PRIVATE it)
endforeach()
