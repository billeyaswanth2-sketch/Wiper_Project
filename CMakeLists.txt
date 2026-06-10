cmake_minimum_required(VERSION 3.10)
project(Washer_wiperTest_BCM C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

add_subdirectory(googletest)
add_subdirectory(Washer_wiperCtrl)
add_subdirectory(Washer_Hdlr)
add_subdirectory(Wiper_Hdlr)
add_subdirectory(test)

include_directories(Com)
include_directories(Core)
include_directories(Variant)
include_directories(Rte)