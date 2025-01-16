#include "c_wrapper.h"
#include <cstring>

static FileDialog* dlg;

void FileDialogInit(CreateTextureFunc create, DeleteTextureFunc destroy) {
    dlg = new FileDialog();
    dlg->CreateTexture = create;
    dlg->DeleteTexture = destroy;
}

void FileDialogShutdown() {
    delete dlg;
}

bool FileDialogSave(const char* key, const char* title, const char* filter, const char* starting_dir) {
    std::string startingDirStr = starting_dir ? starting_dir : "";
    return dlg->Save(key, title, filter, startingDirStr);
}

bool FileDialogOpen(const char* key, const char* title, const char* filter, bool is_multiselect, const char* starting_dir) {
    static std::string startingDirStr = starting_dir ? starting_dir : "";
    return dlg->Open(key, title, filter, is_multiselect, startingDirStr);
}

bool FileDialogIsDone(const char* key) {
    return dlg->IsDone(key);
}

bool FileDialogHasResult() {
    return dlg->HasResult();
}

static char* result;

const char* FileDialogGetResult() {
    std::string resultStr = dlg->GetResult().string();
    result = new char[resultStr.length() + 1];
    strcpy(result, resultStr.c_str());
    return result;
}

void FileDialogFreeResult() {
    if (result != NULL) {
        free(result);
    }
}

static int strCount;
static char** results;

char** FileDialogGetResults(int* count) {
    const std::vector<std::filesystem::path>& resultsStrs = dlg->GetResults();
    strCount = resultsStrs.size();
    *count = strCount;
    char** results = new char*[strCount];
    for (int i = 0; i < strCount; i++) {
        std::string resultStr = resultsStrs[i].string();
        results[i] = new char[resultStr.length() + 1];
        strcpy(results[i], resultStr.c_str());
    }
    return results;
}

void FileDialogFreeResults() {
    if (results != NULL) {
        for (int i = 0; i < strCount; i++) {
            if (results[i] != NULL) {
                free(results[i]);
            }
        }
        free(results);
    }
}

void FileDialogClose() {
    dlg->Close();
}

void FileDialogRemoveFavorite(const char* path) {
    dlg->RemoveFavorite(path);
}

void FileDialogAddFavorite(const char* path) {
    dlg->AddFavorite(path);
}

char** FileDialogGetFavorites(int* count) {
    const std::vector<std::string>& favorites = dlg->GetFavorites();
    *count = favorites.size();

    char** c_favorites = (char**)malloc(favorites.size() * sizeof(char*));
    for (int i = 0; i < *count; ++i) {
        c_favorites[i] = (char*)malloc(favorites[i].length() + 1);
        strcpy(c_favorites[i], favorites[i].c_str());
    }
    return c_favorites;
}

void FileDialogSetZoom(float zoom) {
    dlg->SetZoom(zoom);
}

float FileDialogGetZoom() {
    return dlg->GetZoom();
}
