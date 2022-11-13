#ifndef READER_H
#define READER_H

#include <fstream>
#include <string>

class Reader {
public:
    explicit Reader(const std::string& path);

    ~Reader() = default;

    std::string readline();

    [[nodiscard]] bool eof() const noexcept;

private:
    std::ifstream input;
};

#endif //READER_H
