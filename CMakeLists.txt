cmake_minimum_required(VERSION 3.15)
project(ImFileDialog)

add_subdirectory(imgui)

add_library(ImFileDialog STATIC
    ImFileDialog/ImFileDialog.cpp
    ImFileDialog_c_wrapper.cpp
)

target_link_libraries(ImFileDialog PRIVATE ImGui)

target_include_directories(ImFileDialog PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/ImFileDialog
    ${CMAKE_CURRENT_SOURCE_DIR}/imgui
    ${CMAKE_CURRENT_SOURCE_DIR}
)

if(WIN32)
    target_link_libraries(ImFileDialog PRIVATE Ws2_32)
endif()

target_compile_features(ImFileDialog PUBLIC cxx_std_17)