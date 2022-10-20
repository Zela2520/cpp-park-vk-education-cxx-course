#include "utils.hpp"

FileOpen::FileOpen(const std::string &path_to_file) {
    fs.open(path_to_file);
}

FileOpen::~FileOpen() {
    fs.close();
}