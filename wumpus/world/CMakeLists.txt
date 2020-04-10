add_library(world 
    src/world/room.hpp
    src/world/world.hpp
    src/world/world.cpp)

target_include_directories(world PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")