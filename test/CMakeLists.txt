# cmake_minimum_required(VERSION 3.10)
# project(Washer_wiperTest_BCM C CXX)

# set(CMAKE_C_STANDARD 99)
# set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# enable_testing()

# # googletest added ONCE here only
# add_subdirectory(googletest)

# add_subdirectory(Washer_wiperCtrl)
# add_subdirectory(Washer_Hdlr)
# add_subdirectory(Wiper_Hdlr)
# add_subdirectory(test)

# include_directories(Com)
# include_directories(Core)
# include_directories(Variant)
# include_directories(Rte)


cmake_minimum_required(VERSION 3.10)

set(Sources
    Washer_wiperTests.cpp
)

include_directories(
    ${CMAKE_SOURCE_DIR}/googletest/googletest/include
    ${CMAKE_SOURCE_DIR}/googletest/googlemock/include
    ${CMAKE_SOURCE_DIR}/Washer_wiperCtrl
    ${CMAKE_SOURCE_DIR}/Washer_Hdlr
    ${CMAKE_SOURCE_DIR}/Wiper_Hdlr
    ${CMAKE_SOURCE_DIR}/Com
    ${CMAKE_SOURCE_DIR}/Core
    ${CMAKE_SOURCE_DIR}/Rte
    ${CMAKE_SOURCE_DIR}/Variant
)

add_executable(Washer_wiperTest ${Sources})

target_link_libraries(Washer_wiperTest PRIVATE
    Washer_wiperCtrl
    Washer_Hdlr
    Wiper_Hdlr
    gtest_main
    gmock_main
    gtest
    gmock
)

add_test(NAME Washer_wiperTest COMMAND Washer_wiperTest)