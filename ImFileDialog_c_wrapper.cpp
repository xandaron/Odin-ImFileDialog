#include "ImFileDialog_c_wrapper.h"
#include <cstring>

FileDialog* file_dialog_instance() {
    return &FileDialog::Instance();
}

void file_dialog_set_create_texture(FileDialog* dlg, CreateTextureFunc func) {
    dlg->CreateTexture = func;
}

void file_dialog_set_delete_texture(FileDialog* dlg, DeleteTextureFunc func) {
    dlg->DeleteTexture = func;
}

FileDialog* file_dialog_create(CreateTextureFunc create, DeleteTextureFunc destroy) {
    return new FileDialog;
}

void file_dialog_destroy(FileDialog* dlg) {
    delete dlg;
}

bool file_dialog_save(FileDialog* dlg, const char* key, const char* title, const char* filter, const char* starting_dir) {
    std::string startingDirStr = starting_dir ? starting_dir : "";
    return dlg->Save(key, title, filter, startingDirStr);
}

bool file_dialog_open(FileDialog* dlg, const char* key, const char* title, const char* filter, bool is_multiselect, const char* starting_dir) {
     std::string startingDirStr = starting_dir ? starting_dir : "";
    return dlg->Open(key, title, filter, is_multiselect, startingDirStr);
}

bool file_dialog_is_done(FileDialog* dlg, const char* key) {
    return dlg->IsDone(key);
}

bool file_dialog_has_result(FileDialog* dlg) {
    return dlg->HasResult();
}

const char* file_dialog_get_result(FileDialog* dlg) {
    //  Return a copy to avoid dangling pointers. Caller responsible for freeing.
    std::string result = dlg->GetResult().string();
    char* c_result = (char*)malloc(result.length() + 1);
    strcpy(c_result, result.c_str());
    return c_result;
}

char** file_dialog_get_results(FileDialog* dlg, int* count) {
    const std::vector<std::filesystem::path>& results = dlg->GetResults();
    *count = results.size();
    char** c_results = (char**)malloc(results.size() * sizeof(char*));
    for (int i = 0; i < *count; ++i) {
        std::string result = results[i].string();
        c_results[i] = (char*)malloc(result.length() + 1);
        strcpy(c_results[i], result.c_str());
    }
    return c_results;
}

void file_dialog_close(FileDialog* dlg) {
    dlg->Close();
}

void file_dialog_remove_favorite(FileDialog* dlg, const char* path) {
    dlg->RemoveFavorite(path);
}

void file_dialog_add_favorite(FileDialog* dlg, const char* path) {
    dlg->AddFavorite(path);
}

char** file_dialog_get_favorites(FileDialog* dlg, int* count) {
    const std::vector<std::string>& favorites = dlg->GetFavorites();
    *count = favorites.size();

    char** c_favorites = (char**)malloc(favorites.size() * sizeof(char*));
    for (int i = 0; i < *count; ++i) {
        c_favorites[i] = (char*)malloc(favorites[i].length() + 1);
        strcpy(c_favorites[i], favorites[i].c_str());
    }
    return c_favorites;
}

void file_dialog_set_zoom(FileDialog* dlg, float zoom) {
    dlg->SetZoom(zoom);
}

float file_dialog_get_zoom(FileDialog* dlg) {
    return dlg->GetZoom();
}
