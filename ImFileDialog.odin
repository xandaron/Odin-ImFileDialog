package ImFileDialog

import "core:c"

when ODIN_OS == .Windows {
    @(require) foreign import advapi32 "system:advapi32.lib"
	when ODIN_ARCH == .amd64 {foreign import lib "ImFileDialog_x64.lib"} else {foreign import lib "ImFileDialog_arm64.lib"}
} else {
	when ODIN_OS == .Linux {
		@(require) foreign import stdcpp "system:stdc++"
	}
	else ODIN_OS == .Darwin {
		@(require) foreign import stdcpp "system:c++"
	}
	when ODIN_ARCH == .amd64 {foreign import lib "ImFileDialog_x64.a"} else {foreign import lib "ImFileDialog_arm64.a"}
}

FileDialog :: distinct rawptr

CreateTexture :: #type proc "system" (data: ^c.uint8_t, width, height: c.int, format: c.char) -> rawptr
DeleteTexture :: #type proc "system" (imagePtr: rawptr)

@(default_calling_convention = "system")
@(link_prefix = "file_dialog_")
foreign lib {
	// Create a new FileDialog instance
	create :: proc(create: CreateTexture, destroy: DeleteTexture) -> FileDialog ---

	// Destroy a FileDialog instance
	destroy :: proc(dlg: FileDialog) ---

	save :: proc(dlg: FileDialog, key, title, filter, starting_dir: cstring) -> c.bool ---

	open :: proc(dlg: FileDialog, key, title, filter: cstring, is_multiselect: c.bool, starting_dir: cstring) -> c.bool ---

	is_done :: proc(dlg: FileDialog, key: cstring) -> c.bool ---

	has_result :: proc(dlg: FileDialog) -> c.bool ---

	get_result :: proc(dlg: FileDialog) -> cstring ---

	get_results :: proc(dlg: FileDialog, count: ^c.int) -> [^]cstring ---

	close :: proc(dlg: FileDialog) ---

	remove_favorite :: proc(dlg: FileDialog, path: cstring) ---

	add_favorite :: proc(dlg: FileDialog, path: cstring) ---

	get_favorites :: proc(dlg: FileDialog, count: ^c.int) -> [^]cstring ---

	set_zoom :: proc(dlg: FileDialog, zoom: c.float) ---

	get_zoom :: proc(dlg: FileDialog) -> c.float ---
}
