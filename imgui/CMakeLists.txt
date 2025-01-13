# imgui/CMakeLists.txt:
# This CMakeLists.txt should be inside your imgui directory
add_library(ImGui STATIC
    imgui.cpp imgui_draw.cpp imgui_tables.cpp imgui_widgets.cpp # ...all other ImGui .cpp files!
)

target_include_directories(ImGui PUBLIC .)