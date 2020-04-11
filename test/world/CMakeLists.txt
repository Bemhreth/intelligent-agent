find_package(CxxTest)

if(CXXTEST_FOUND)
    include_directories(${CXXTEST_INCLUDE_DIR})
    enable_testing()
    CXXTEST_ADD_TEST(unittest_room room_test.cc
                      ${CMAKE_CURRENT_SOURCE_DIR}/room_test.h)
    target_link_libraries(unittest_room PRIVATE world)
endif()