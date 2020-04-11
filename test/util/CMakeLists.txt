find_package(CxxTest)

if(CXXTEST_FOUND)
    include_directories(${CXXTEST_INCLUDE_DIR})
    enable_testing()
    CXXTEST_ADD_TEST(unittest_converter room_converter.cc
                      ${CMAKE_CURRENT_SOURCE_DIR}/room_converter.h)
    target_link_libraries(unittest_room PRIVATE util)
endif()