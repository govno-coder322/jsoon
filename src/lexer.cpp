#include <iostream>
#include <vector>
#include <string>
#include <cctype>

#include "../include/json.h"

std::vector<Token> tokenize(const std::string& input) {
    std::vector<Token> tokens;
    size_t i = 0;
    while (i < input.size()) {
        if (std::isspace(input[i])) {
            ++i; continue;
        }
        switch (input[i]) {
            case '{':
                tokens.push_back({ TokenType::LeftBrace, ""}); ++i; break;
            case '}':
                tokens.push_back({ TokenType::RightBrace, ""}); ++i; break;
            case ':':
                tokens.push_back({ TokenType::Colon, ""}); ++i; break;
            case ',':
                tokens.push_back({ TokenType::Comma, ""}); ++i; break;
            case ']':
                tokens.push_back({ TokenType::RightBracket, ""}); ++i; break;
            case '[':
                tokens.push_back({ TokenType::LeftBracket, ""}); ++i; break;
            default:
                if (input[i] == '"') { // STRING
                    ++i; //skip first "
                    std::string value;

                    while (i < input.size() && input[i] != '"') {
                        value += input[i];
                        ++i;
                    }

                    ++i; // skip end "
                    tokens.push_back({ TokenType::String, value});
                    break; //exit
                }
                if (std::isdigit(input[i])) { // INT
                    std::string value;

                    while (i < input.size() && std::isdigit(input[i]) || input[i] == '.') {
                        value += input[i]; ++i;
                    }
                    tokens.push_back({TokenType::Number, value}); break; //exit
                }
                if (std::isalpha(input[i])) { //TRUE, FALSE OR NULL
                    std::string value;

                    while (i < input.size() && std::isalpha(input[i])) {
                        value += input[i]; ++i;
                    }
                    if (value == "true") { //TRUE
                        tokens.push_back( {TokenType::True, value}); break;
                    }
                    else if (value == "false") { //FALSE
                        tokens.push_back( {TokenType::False, value}); break;
                    }
                    else if (value == "null") { //NULL
                        tokens.push_back( {TokenType::Null, value}); break;
                    }

                    else {
                        std::cerr << "Unknown literal: " << value << std::endl;
                        return {};
                    }
                }
        }
    }

    // TODO: handle escape sequences inside strings (e.g. \", \n, \\)

    tokens.push_back( {TokenType::End, ""});
    return tokens;
}