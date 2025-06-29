#include <iostream>
#include <vector>
#include <string>

#include "../include/json.h"

std::vector<Token> tokenize(const std::string& input) {
    std::vector<Token> tokens;
    size_t i = 0;
    while (i < input.size()) {
        switch (input[i]) {
            case '{':
                tokens.push_back({ TokenType::LeftBrace, ""});
                ++i;
                break;
            default:
                ++i;
        }
    }
}