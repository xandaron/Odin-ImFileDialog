# Odin-ImFileDialog

Odin-ImFileDialog is an Odin wrapper for [ImFileDialog](https://github.com/dfranx/ImFileDialog/tree/main) that can be imported into your Odin project. This repo, necessarily, also includes a c wrapper for [ImFileDialog](https://github.com/dfranx/ImFileDialog/tree/main) that can be used to make wrappers for other lanuages such as Rust or Zig.

## Features

- Cross-platform support (Windows, Linux)
- Simple API for easy integration

## Installation

To install Odin-ImFileDialog, clone the repository and include it in your Odin project:

```sh
git clone https://github.com/yourusername/Odin-ImFileDialog.git
```

```odin
import ImFD "ImFileDialog"
```

A precompiled library has been provided for both windows and linux x64 platforms. For other target platforms this wrapper should still work but you'll need to compile the ImFileDialog library for yourself. Build scripts for both windows and linux have been provided if needes.

## Prerequisites

The ImFileDialog library doen't include an Imgui implementation meaning you will need to also import [Odin imgui](https://gitlab.com/L-4/odin-imgui).

> **Note:** As of the time of writing, [Odin imgui](https://gitlab.com/L-4/odin-imgui) builds agains an old version of imgui which will cause compatibility issues with this library. You should update the build script to use the newest imgui and dear-imgui versions as well as checking any other requirements before attempting to compile and use this repo.

## Demo

Here is a simple example demonstrating how to use Odin-ImFileDialog in your Odin application:

```odin
import "core:fmt"
import ImFD "ImFileDialog"

ImFDCreateImage: ImFD.CreateTexture : proc "system" (
    data: ^c.uint8_t,
    width, height: c.int,
    format: c.char,
) -> rawptr {
    /*
    Funciton specifics will vary based on which rendering backend you are using
    e.g. Vulkan, OpenGL, DirectX, etc...
    */
}

ImFDDeleteImage: ImFD.DeleteTexture : proc "system" (imagePtr: rawptr) {
    /*
    Funciton specifics will vary based on which rendering backend you are using
    e.g. Vulkan, OpenGL, DirectX, etc...
    */
}

main :: proc() {
    /*
    Init window (e.g. GLFW), backend (e.g. Vulkan) and imgui
    */

    // Initialize the file dialog
    ImFD.Init(ImFDCreateImage, ImFDDeleteImage)
    

    for !windowShouldClose {
        /*
        Other NewFrame() calls based on window and backend
        */
	    imgui.NewFrame()

        if imgui.Begin("Scene Editor", nil, {.MenuBar}) {
            if imgui.BeginMenuBar() {
                if imgui.BeginMenu("File") {
                    if imgui.MenuItem("Load") {
                        ImFD.Open(
                            "OpenDialog",
                            "Open a file",
                            "All files .*",
                            true,
                        )
                    }
                    imgui.EndMenu()
                }
                imgui.EndMenuBar()
            }
        }
        imgui.End()

        if ImFD.IsDone("OpenDialog") {
            if ImFD.HasResult() {
                filePath := ImFD.GetResult()
                fmt.println(filePath)
            }
            ImFD.Close()
        }
    }

    // Clean up
    dialog.Shutdown()

    /*
    Cleanup imgui and window
    */
}
```

This example initializes the file dialog, that opens when the user presses the "Open" button in the File submenu from the menu bar. It then prints the file that is returned by the file dialog.

## TODO

- [ ] Create a pyhton build script to make the process of building libs easier.
- [ ] Generate c and Odin wrappers automatically with a pyhton build script for easier updating. 

## Contributing

I'm not an expert on C/C++ and there are probably mistakes/improvements that could be made. Please feel free to make any improvements you can and open a pull request explaining why you have made your changes.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Contact

For any questions or suggestions, please open an issue.
