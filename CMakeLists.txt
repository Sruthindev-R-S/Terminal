cmake_minimum_required(VERSION 3.16)

project(command_runner LANGUAGES CXX)

add_executable(command_runner
    main.cpp
)

target_compile_features(command_runner PRIVATE cxx_std_17)

target_include_directories(command_runner PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)
