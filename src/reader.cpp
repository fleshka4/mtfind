#include "reader.h"

#include <stdexcept>
#include <string>

Reader::Reader(const std::string& path) {
    input.open(path);
    if (!input.is_open()) {
        throw std::runtime_error(path + " not opened");
    }
}

std::string Reader::readline() {
    std::string string;
    std::getline(input, string);
    return string;
}

bool Reader::eof() const noexcept {
    return input.eof();
}
