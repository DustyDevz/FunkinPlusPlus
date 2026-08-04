option(FUNKIN_BUILD_EDITOR "" ON)

add_executable(Funkin
        src/main.cpp
)

if(FUNKIN_BUILD_EDITOR)
    file(GLOB_RECURSE GAME_EDITOR_SOURCES CONFIGURE_DEPENDS
            "${CMAKE_CURRENT_SOURCE_DIR}/src/editor/*.cpp"
    )
    target_sources(Funkin PRIVATE ${GAME_EDITOR_SOURCES})
    target_compile_definitions(Funkin PRIVATE FUNKIN_EDITOR=1)
endif()

file(GLOB_RECURSE GAME_SOURCES CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)
list(FILTER GAME_SOURCES EXCLUDE REGEX ".*/editor/.*")
list(REMOVE_ITEM GAME_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")
target_sources(Funkin PRIVATE ${GAME_SOURCES})

target_link_libraries(Funkin PRIVATE FunkinEngine)

set_target_properties(Funkin PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${FUNKIN_OUTPUT_DIR}"
)