cmake_minimum_required(VERSION 3.10)
project(Washer_wiperCtrl C CXX)

set(Sources
    ${CMAKE_CURRENT_SOURCE_DIR}/washer_wiperCtrl.c
)

add_library(Washer_wiperCtrl STATIC ${Sources})

target_include_directories(Washer_wiperCtrl PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../Washer_Hdlr
    ${CMAKE_CURRENT_SOURCE_DIR}/../Wiper_Hdlr
    ${CMAKE_CURRENT_SOURCE_DIR}/../Rte
    ${CMAKE_CURRENT_SOURCE_DIR}/../Com
    ${CMAKE_CURRENT_SOURCE_DIR}/../Core
    ${CMAKE_CURRENT_SOURCE_DIR}/../Variant
)