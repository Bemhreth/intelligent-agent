add_library(util 
    src/util/functions_header.hpp
    src/util/value.hpp
    src/util/semantic.cpp
    src/util/value.cpp)

target_link_libraries(util PRIVATE world)
target_include_directories(util PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")