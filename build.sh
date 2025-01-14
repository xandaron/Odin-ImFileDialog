#! /bin/bash
# BASEDIR=$(dirname "$0")
clang++ -std=c++17 -Wall -Wextra -c c_wrapper.cpp ImFileDialog/ImFileDialog.cpp -I"imgui/imgui.h" -I"imgui/imgui_internal.h" -I"stb_image/stb_image.h"
ar rc ImFileDialog_linux_.a c_wrapper.o ImFileDialog.o
rm c_wrapper.o ImFileDialog.o