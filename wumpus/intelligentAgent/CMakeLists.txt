add_library(agent SHARED
    src/intelligentAgent/agent.hpp
    src/intelligentAgent/agent.cpp)

target_link_libraries(agent PRIVATE world util)
target_include_directories(agent PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")