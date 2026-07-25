cmake_minimum_required(VERSION 4.2)
project(FunkinPlusPlus VERSION 0.0.1 LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(DILIGENT_BUILD_TOOLS ON CACHE BOOL "" FORCE)
set(DILIGENT_BUILD_FX OFF CACHE BOOL "" FORCE)
set(DILIGENT_BUILD_SAMPLES OFF CACHE BOOL "" FORCE)
set(DILIGENT_BUILD_DOCS OFF CACHE BOOL "" FORCE)

set(DILIGENT_NO_METAL ON CACHE BOOL "" FORCE)
set(DILIGENT_NO_WEBGPU ON CACHE BOOL "" FORCE)
set(DILIGENT_NO_ARCHIVER ON CACHE BOOL "" FORCE)
set(DILIGENT_NO_RENDER_STATE_PACKAGER ON CACHE BOOL "" FORCE)

find_package(Vulkan REQUIRED)
add_subdirectory("funkin/libs/diligent")

if(MINGW AND TARGET Diligent-Win32Platform)
    target_compile_options(Diligent-Win32Platform PRIVATE
            -include "${CMAKE_SOURCE_DIR}/funkin/cmake/thread_desc_compat.h"
    )
endif()

file(GLOB_RECURSE ENGINE_SOURCES CONFIGURE_DEPENDS
        "funkin/src/*.cpp"
        "funkin/include/*.hpp"
)
add_executable(FunkinPlusPlus ${ENGINE_SOURCES})

set_target_properties(FunkinPlusPlus PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/export/$<CONFIG>"
)

target_compile_definitions(FunkinPlusPlus PRIVATE $<$<CONFIG:DEBUG>:FUNKIN_DEBUG>)
target_link_libraries(FunkinPlusPlus PRIVATE
        Diligent-Primitives
        Diligent-Common
        Diligent-GraphicsTools
        Diligent-GraphicsEngine
        Diligent-GraphicsEngineVk-static
)

if(MSVC)
    set_property(TARGET FunkinPlusPlus APPEND_STRING PROPERTY LINK_FLAGS_RELEASE " /INCREMENTAL:NO /PDBALTPATH:%_PDB%")
    set_property(TARGET FunkinPlusPlus APPEND_STRING PROPERTY LINK_FLAGS_MINSIZEREL " /INCREMENTAL:NO /PDBALTPATH:%_PDB%")
endif()

target_precompile_headers(FunkinPlusPlus PRIVATE
        "${CMAKE_SOURCE_DIR}/funkin/include/utils/pch.hpp"
)

target_include_directories(FunkinPlusPlus PRIVATE
        "${CMAKE_SOURCE_DIR}/funkin/include"
)