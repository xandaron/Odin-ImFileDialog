@echo off

setlocal EnableDelayedExpansion

where /Q cl.exe || (
	set __VSCMD_ARG_NO_LOGO=1
	for /f "tokens=*" %%i in ('"C:\Program Files (x86)\Microsoft Visual Studio\Installer\vswhere.exe" -latest -requires Microsoft.VisualStudio.Workload.NativeDesktop -property installationPath') do set VS=%%i
	if "!VS!" equ "" (
		echo ERROR: Visual Studio installation not found
		exit /b 1
	)
	call "!VS!\VC\Auxiliary\Build\vcvarsall.bat" amd64 || exit /b 1
)

cl /EHsc /c .\c_wrapper.cpp .\ImFileDialog\ImFileDialog.cpp /std:c++17 /I"./imgui/imgui.h" /I"./imgui/imgui_internal.h" /I"./stb_image/stb_image.h" /link AdvAPI32.lib
lib /OUT:ImFileDialog_windows_.lib ImFileDialog.obj c_wrapper.obj
del "./*.obj"