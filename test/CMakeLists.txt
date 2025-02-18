# specify the minimum cmake version required
cmake_minimum_required(VERSION 3.10)

# declare a project
project(test VERSION 1.0)

# export compile_commands.json for the project
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SOURCE_FILES
    src/main.c
)

# create an executable
add_executable(test
    ${SOURCE_FILES}
)

# link engine with test
target_link_libraries(test
    PRIVATE engine
)

# specify compile definitions
target_compile_definitions(engine PRIVATE 
    _DEBUG=1
    KIMPORT=1
)
