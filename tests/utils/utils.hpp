#include <filesystem>
#include <fstream>
#include <string>

class FileOpen {
    public:
        explicit FileOpen(const std::string &path_to_file);
        ~FileOpen();
        std::ifstream fs;
};