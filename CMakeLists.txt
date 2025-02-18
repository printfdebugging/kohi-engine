# specify minimum cmake version required 
cmake_minimum_required(VERSION 3.10)

project(game-engine VERSION 1.0)

# create compile_commands.json for the project
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


add_subdirectory(engine)
add_subdirectory(test)
