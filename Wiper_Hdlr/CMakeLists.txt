cmake_minimum_required(VERSION 3.10)
project(Wiper_Hdlr C CXX)

set(Sources
    ${CMAKE_CURRENT_SOURCE_DIR}/wiper_Hdlr.c
)

add_library(Wiper_Hdlr STATIC ${Sources})

target_include_directories(Wiper_Hdlr PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../Washer_wiperCtrl
    ${CMAKE_CURRENT_SOURCE_DIR}/../Rte
    ${CMAKE_CURRENT_SOURCE_DIR}/../Com
    ${CMAKE_CURRENT_SOURCE_DIR}/../Core
    ${CMAKE_CURRENT_SOURCE_DIR}/../Variant
)