#include <iostream>
#include <memory>
#include <thread>

#include "parser.h"
#include "reader.h"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Incorrect run configuration\n";
        return 1;
    }

    std::unique_ptr<Reader> reader;
    try {
        reader = std::make_unique<Reader>(argv[1]);
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << '\n';
        return 2;
    }

    std::unique_ptr<Parser> parser;
    try {
        parser = std::make_unique<Parser>(argv[2]);
    } catch (const std::regex_error& e) {
        std::cerr << e.what() << '\n';
        return 2;
    }

    std::thread producer{[&]() {
        while(!reader->eof()) {
            parser->parse(reader->readline());
        }
    }};

    producer.join();

    const auto results = parser->getResults();
    std::cout << results.size() << '\n';
    for (const auto& res : results) {
        std::cout << res.second << '\n';
    }
    return 0;
}
