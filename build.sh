#! /bin/bash
BASEDIR=$(dirname "$0")
clang++ -std=c++17 -Wall -Wextra -c $BASEDIR/c_wrapper.cpp $BASEDIR/ImFileDialog/ImFileDialog.cpp -I"$BASEDIR/imgui/imgui.h" -I"$BASEDIR/imgui/imgui_internal.h" -I"$BASEDIR/stb_image/stb_image.h"
ar rc $BASEDIR/ImFileDialog_linux_.a $BASEDIR/c_wrapper.o $BASEDIR/ImFileDialog.o
rm $BASEDIR/c_wrapper.o $BASEDIR/ImFileDialog.o