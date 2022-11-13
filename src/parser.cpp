#include "parser.h"

#include <algorithm>
#include <regex>
#include <string>

Parser::Parser(std::string mask):
    m_counter(0)
{
    std::replace(mask.begin(), mask.end(), '?', '.');
    m_regex = mask;
}

void Parser::parse(const std::string& source) {
    if (!source.empty()) {
        m_processors.emplace_back([&, source] (uint64_t num) {
            std::smatch match;
            if (std::regex_search(source, match,  m_regex)) {
                m_results.push_back({num - 1, std::to_string(num) + ' '
                    + std::to_string(match.position(0) + 1) + ' ' + match.str(0)});
            }}, ++m_counter);
    }
}

const Parser::results_t& Parser::getResults() {
    for (auto& processor : m_processors) {
        if (processor.joinable()) {
            processor.join();
        }
    }
    std::sort(m_results.begin(), m_results.end());
    m_processors.clear();
    return m_results;
}

Parser::~Parser() {
    for (auto& processor : m_processors) {
        if (processor.joinable()) {
            processor.join();
        }
    }
}
