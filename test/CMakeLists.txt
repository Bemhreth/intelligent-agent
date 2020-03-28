cmake_minimum_required(VERSION 3.10)

project(intellegent-agent)

include_directories(../src/ functions/)

file( GLOB SOURCES "../src/*.cpp" "../functions/*.cpp" "../test/*.cpp")

add_executable(test_out ${SOURCES} )