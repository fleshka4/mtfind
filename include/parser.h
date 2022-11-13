#ifndef PARSER_H
#define PARSER_H

#include <list>
#include <regex>
#include <string>
#include <thread>
#include <vector>

class Parser {
public:
    using results_t = std::vector<std::pair<size_t, std::string>>;

    explicit Parser(std::string mask);

    void parse(const std::string& source);

    const results_t& getResults();

    ~Parser();

private:
    std::regex m_regex;
    std::list<std::thread> m_processors;
    results_t m_results;
    uint64_t m_counter;
};

#endif //PARSER_H
