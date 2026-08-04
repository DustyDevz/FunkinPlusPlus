file(GLOB_RECURSE ENGINE_SOURCES CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c"
)

add_library(FunkinEngine SHARED ${ENGINE_SOURCES})

target_include_directories(FunkinEngine
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(FunkinEngine
        PUBLIC
        SDL3::SDL3-static
        Vulkan::Vulkan
        Diligent-Primitives
        Diligent-Common
        Diligent-GraphicsTools
        Diligent-GraphicsEngine
        Diligent-GraphicsEngineVk-static
)

target_compile_features(FunkinEngine PUBLIC cxx_std_23)

set_target_properties(FunkinEngine PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${FUNKIN_OUTPUT_DIR}"
)