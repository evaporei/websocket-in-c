cmake_minimum_required(VERSION 3.22)
project(Game VERSION 1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 11)

# Enable Clangd LSP integration with the project
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set default build type to Debug if none is specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif()

# Add the DEBUG macro when building in Debug mode
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_definitions(-DDEBUG)
endif()

# ------------------------------------------------------------------------------
# Third-party dependencies
# ------------------------------------------------------------------------------

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

set(THIRDPARTY_DIR "${CMAKE_SOURCE_DIR}/thirdparty")

# add_subdirectory("${THIRDPARTY_DIR}/raylib")

# add_library(stb_image INTERFACE)
# target_include_directories(stb_image INTERFACE thirdparty)

add_library(facil.io
  thirdparty/facil.io/src/fio.c
  thirdparty/facil.io/src/fio_cli.c
  thirdparty/facil.io/src/fio_siphash.c
  thirdparty/facil.io/src/fio_tls_missing.c
  thirdparty/facil.io/src/fio_tls_openssl.c
  thirdparty/facil.io/src/fiobj_ary.c
  thirdparty/facil.io/src/fiobj_data.c
  thirdparty/facil.io/src/fiobj_hash.c
  thirdparty/facil.io/src/fiobj_json.c
  thirdparty/facil.io/src/fiobj_mustache.c
  thirdparty/facil.io/src/fiobj_numbers.c
  thirdparty/facil.io/src/fiobj_str.c
  thirdparty/facil.io/src/fiobject.c
  thirdparty/facil.io/src/http.c
  thirdparty/facil.io/src/http1.c
  thirdparty/facil.io/src/http_internal.c
  thirdparty/facil.io/src/redis_engine.c
  thirdparty/facil.io/src/websockets.c
)
target_include_directories(facil.io PUBLIC thirdparty/facil.io/include)
# target_link_libraries(imgui PRIVATE glfw)

# ------------------------------------------------------------------------------
# Source files
# ------------------------------------------------------------------------------

set(MY_FLAGS "-std=c11" "-Wall")
set(SOURCE_FILES
    "${CMAKE_SOURCE_DIR}/src/main.c"
)

add_executable(game ${SOURCE_FILES})
target_compile_options(game PUBLIC ${MY_FLAGS})

target_link_libraries(game PUBLIC facil.io)
