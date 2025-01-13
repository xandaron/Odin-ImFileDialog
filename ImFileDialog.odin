package ImFileDialog

import "core:c"

when ODIN_OS == .Windows {
	when ODIN_ARCH == .amd64 {foreign import lib "ImFileDialog_x64.lib"} else {foreign import lib "ImFileDialog_arm64.lib"}
} else when ODIN_OS == .Linux {
	when ODIN_ARCH == .amd64 {foreign import lib "ImFileDialog_x64.a"} else {foreign import lib "ImFileDialog_arm64.a"}
} else when ODIN_OS == .Darwin {
	when ODIN_ARCH == .amd64 {foreign import lib "ImFileDialog_x64.a"} else {foreign import lib "ImFileDialog_arm64.a"}
}

FileDialog :: distinct rawptr

CreateTexture :: #type proc([^]c.int8_t, c.int, c.int, c.char) -> rawptr
DeleteTexture :: #type proc(rawptr)

@(default_calling_convention = "c")
@(link_prefix = "file_dialog_")
foreign lib {
    // Singleton FileDialog instance
    instance :: proc() -> FileDialog ---

    // Set CreateTexture method for FileDialog instance
    set_create_texture :: proc(dlg: FileDialog, fnc: CreateTexture) ---

    // Set DeleteTexture method for FileDialog instance
    set_delete_texture :: proc(dlg: FileDialog, fnc: DeleteTexture) ---

    // Create a new FileDialog instance
    create :: proc() -> FileDialog ---

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