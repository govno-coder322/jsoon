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
        case TokenType::LeftBracket: {
            ++index; //skip

            std::vector<JSONValue> value;
            while (tokens[index].type != TokenType::RightBracket) {
                JSONValue parsedValue = parseValue(tokens, index);
                value.push_back(parsedValue);

                if (tokens[index].type == TokenType::Comma) {
                    ++index;
                }
            }

            ++index;
            JSONValue result;
            result.value = value;
            return result;
        }
        case TokenType::LeftBrace: {
            ++index; //skip
            std::map<std::string, JSONValue> obj;
            while (tokens[index].type != TokenType::RightBrace) {
                // parse key
                if (tokens[index].type != TokenType::String) {
                    std::cerr << "Excepted string as object key\n";
                    exit(1);
                }
                //get key
                std::string key = tokens[index].value;
                ++index;

                //parse colon
                if (tokens[index].type != TokenType::Colon) {
                    std::cerr << "Excepted colon after key\n";
                    exit(1);
                }

                ++index; //skip colon

                // parse value
                JSONValue value = parseValue(tokens, index);
                obj[key] = value;

                // parse ,
                if (tokens[index].type == TokenType::Comma) {
                    ++index;
                }
                else if (tokens[index].type != TokenType::RightBrace) {
                    std::cerr << "Excepted comma or closing brace\n";
                    exit(1);
                }
            }

            ++index; //skip }
            JSONValue result;
            result.value = obj;
            return result;
        }

    }

    // erorr
    std::cerr << "Unsupported token in func parseValue\n";
    exit(1);
}