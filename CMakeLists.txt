cmake_minimum_required(VERSION 3.11)
project(MyGraphViz VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON) 

set( GraphViz main )
add_executable( ${GraphViz} )

target_include_directories( ${GraphViz} PRIVATE
    "${CMAKE_SOURCE_DIR}/include"
)

set( GraphViz_SRC_DIR 
    "${CMAKE_SOURCE_DIR}/src" 
)

set( GraphViz_SRC_FILES
    "placement.cc"
    "geometry.cc"
    "main.cc"
)

foreach( FILE IN LISTS GraphViz_SRC_FILES )
    target_sources( ${GraphViz} PRIVATE "${GraphViz_SRC_DIR}/${FILE}" )
endforeach()

set( COMMON_FLAGS -I /usr/include/python3.8 -lpython3.8)
target_compile_options( ${GraphViz} PRIVATE ${COMMON_FLAGS} )

find_program(CLANG_TIDY "clang-tidy")
if (CLANG_TIDY)

    add_custom_target(clang_tidy
    COMMAND clang-tidy ${GraphViz_BOOL_SRC_DIR}/${GraphViz_BOOL_SRC} ${GraphViz_INCLUDES}/myGraphViz.hh --format-style=file -- -I${GraphViz_INCLUDES}
    )

    message(STATUS "clang-tidy target ON")

    else()
    message(STATUS "clang-tidy target OFF")

endif()

find_program(CLANG_FORMAT "clang-format")
if (CLANG_FORMAT)
    file(GLOB_RECURSE ALL_SOURCE_FILES *.cc *.hh)
        add_custom_target(
            format
            COMMAND clang-format
            -style=file
            -i
            ${ALL_SOURCE_FILES}
        )
        message(STATUS "clang-format target ON")
endif()


