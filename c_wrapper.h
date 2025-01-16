#include "ImFileDialog/ImFileDialog.h"

#ifdef __cplusplus
extern "C" {
#else
typedef struct FileDialog;
#endif

// Typedefs for the function pointers
typedef void* (*CreateTextureFunc)(uint8_t*, int, int, char);
typedef void (*DeleteTextureFunc)(void*);

// FileDialog();
// Create a new FileDialog instance
void FileDialogInit(CreateTextureFunc create, DeleteTextureFunc destroy);

// ~FileDialog();
// Destroy a FileDialog instance
void FileDialogShutdown();

// bool Save(const std::string& key, const std::string& title, const std::string& filter, const std::string& startingDir = "");
// C wrapper for FileDialog::Save
bool FileDialogSave(const char* key, const char* title, const char* filter, const char* starting_dir);

// bool Open(const std::string& key, const std::string& title, const std::string& filter, bool isMultiselect = false, const std::string& startingDir = "");
// C wrapper for FileDialog::Open
bool FileDialogOpen(const char* key, const char* title, const char* filter, bool is_multiselect, const char* starting_dir);

// bool IsDone(const std::string& key);
// C wrapper for FileDialog::IsDone
bool FileDialogIsDone(const char* key);

// inline bool HasResult() { return m_result.size(); }
// C wrapper for FileDialog::HasResult
bool FileDialogHasResult();

// inline const std::filesystem::path& GetResult() { return m_result[0]; }
// C wrapper for FileDialog::GetResult (single result)
const char* FileDialogGetResult();

void FileDialogFreeResult();

// inline const std::vector<std::filesystem::path>& GetResults() { return m_result; }
// C wrapper for FileDialog::GetResults (multi-select)
char** FileDialogGetResults(int* count);

void FileDialogFreeResults();

// void Close();
// C wrapper for FileDialog::Close
void FileDialogClose();

// void RemoveFavorite(const std::string& path);
// Remove a favorite path
void FileDialogRemoveFavorite(const char* path);

// void AddFavorite(const std::string& path);
// Add a favorite path
void FileDialogAddFavorite(const char* path);

// inline const std::vector<std::string>& GetFavorites() { return m_favorites; }
// C wrapper for FileDialog::GetFavorites
char** FileDialogGetFavorites(int* count);

// inline void SetZoom(float z) { 
//     m_zoom = std::min<float>(25.0f, std::max<float>(1.0f, z)); 
//     m_refreshIconPreview();
// }
// C wrapper for FileDialog::SetZoom
void FileDialogSetZoom(float zoom);

// inline float GetZoom() { return m_zoom; }
// C wrapper for FileDialog::GetZoom
float FileDialogGetZoom();

#ifdef __cplusplus
}
#endif