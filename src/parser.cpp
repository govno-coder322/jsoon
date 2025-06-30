#include <iostream>
#include <vector>
#include <string>

#include "../include/json.h"

JSONValue parseValue(const std::vector<Token>& tokens, size_t& index) {
    switch (tokens[index].type) {
        case TokenType::String: {
            JSONValue value;
            value.value = tokens[index].value;

            ++index;
            return value;
        }
        case TokenType::Number: {
            try {
                double num = std::stod(tokens[index].value);
                JSONValue value;
                value.value = num;

                ++index;
                return value;
            } catch (const std::exception& e) {
                std::cerr << "Error in number conversion: " << e.what() << std::endl;
                exit(1);
            }
        }
        case TokenType::True: {
            bool exp = true;
            JSONValue value;
            value.value = exp;

            ++index;
            return value;
        }
        case TokenType::False: {
            bool exp = false;
            JSONValue value;
            value.value = exp;

            ++index;
            return value;
        }
        case TokenType::Null: {
            JSONValue value;
            value.value = nullptr;

            ++index;
            return value;
        }

    }

    // erorr
    std::cerr << "Unsupported token in func parseValue\n";
    exit(1);
}