#include "ImFileDialog.h"

#ifdef __cplusplus
extern "C" {
#endif

// Typedefs for the function pointers
typedef void* (*CreateTextureFunc)(uint8_t*, int, int, char);
typedef void (*DeleteTextureFunc)(void*);

// Setters for the function pointers
void file_dialog_set_create_texture(CreateTextureFunc func);
void file_dialog_set_delete_texture(DeleteTextureFunc func);

// Instance()
// Singleton instance
FileDialog* file_dialog_instance();

// FileDialog();
// Create a new FileDialog instance
FileDialog* file_dialog_create();

// ~FileDialog();
// Destroy a FileDialog instance
void file_dialog_destroy(FileDialog* dlg);

// bool Save(const std::string& key, const std::string& title, const std::string& filter, const std::string& startingDir = "");
// C wrapper for FileDialog::Save
bool file_dialog_save(FileDialog* dlg, const char* key, const char* title, const char* filter, const char* starting_dir);

// bool Open(const std::string& key, const std::string& title, const std::string& filter, bool isMultiselect = false, const std::string& startingDir = "");
// C wrapper for FileDialog::Open
bool file_dialog_open(FileDialog* dlg, const char* key, const char* title, const char* filter, bool is_multiselect, const char* starting_dir);

// bool IsDone(const std::string& key);
// C wrapper for FileDialog::IsDone
bool file_dialog_is_done(FileDialog* dlg, const char* key);

// inline bool HasResult() { return m_result.size(); }
// C wrapper for FileDialog::HasResult
bool file_dialog_has_result(FileDialog* dlg);

// inline const std::filesystem::path& GetResult() { return m_result[0]; }
// C wrapper for FileDialog::GetResult (single result)
const char* file_dialog_get_result(FileDialog* dlg);

// inline const std::vector<std::filesystem::path>& GetResults() { return m_result; }
// C wrapper for FileDialog::GetResults (multi-select)
char** file_dialog_get_results(FileDialog* dlg, int* count);

// void Close();
// C wrapper for FileDialog::Close
void file_dialog_close(FileDialog* dlg);

// void RemoveFavorite(const std::string& path);
// Remove a favorite path
void file_dialog_remove_favorite(FileDialog* dlg, const char* path);

// void AddFavorite(const std::string& path);
// Add a favorite path
void file_dialog_add_favorite(FileDialog* dlg, const char* path);

// inline const std::vector<std::string>& GetFavorites() { return m_favorites; }
// C wrapper for FileDialog::GetFavorites
char** file_dialog_get_favorites(FileDialog* dlg, int* count);

// inline void SetZoom(float z) { 
//     m_zoom = std::min<float>(25.0f, std::max<float>(1.0f, z)); 
//     m_refreshIconPreview();
// }
// C wrapper for FileDialog::SetZoom
void file_dialog_set_zoom(FileDialog* dlg, float zoom);

// inline float GetZoom() { return m_zoom; }
// C wrapper for FileDialog::GetZoom
float file_dialog_get_zoom(FileDialog* dlg);

#ifdef __cplusplus
}
#endif