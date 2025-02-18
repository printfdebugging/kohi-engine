# specify the minimum cmake version required
cmake_minimum_required(VERSION 3.10)

# declare a project
project(engine VERSION 1.0)

# export compile_commands.json for the project
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# source files
set(SOURCE_FILES
    src/core/logger.c

    src/platform/platform_msw.c
    src/platform/platform_xorg.c
)

# header files
set(HEADER_FILES
    inc/core/asserts.h
    inc/core/defines.h
    inc/core/logger.h

    inc/platform/platform.h
)

# create a shared library
add_library(engine SHARED
    ${SOURCE_FILES}
    ${HEADER_FILES}
)

# specify the include directory path
target_include_directories(engine
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

# link libraries
if (UNIX)
    target_link_libraries(engine PRIVATE
        -lxcb
        -lX11
        -lX11-xcb
        -lxkbcommon
    )
elseif (WIN32)
endif()

# specify compile definitions
target_compile_definitions(engine PRIVATE 
    _DEBUG=1
    KEXPORT=1
)
