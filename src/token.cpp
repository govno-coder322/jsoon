#include <iostream>

#include "../include/json.h"


std::string tokenTypeToString(TokenType type) {
    switch (type) {
        case TokenType::String: return "string"; break;
        case TokenType::Number: return "number"; break;
        case TokenType::Colon: return ":"; break;
        case TokenType::Comma: return ","; break;
        case TokenType::LeftBrace: return "{"; break;
        case TokenType::RightBrace: return "}"; break;
        case TokenType::LeftBracket: return "["; break;
        case TokenType::RightBracket: return "]"; break;
        case TokenType::True: return "true"; break;
        case TokenType::False: return "false"; break;
        case TokenType::End: return "end"; break;
        default: return "Unknown"; break;
    }
}
void Printer::printTokens(const std::vector<Token>& tokens) {
    for (const Token& token : tokens) {
        std::cout << tokenTypeToString(token.type);
        if (!token.value.empty()) {
            std::cout << ":" << token.value;
        }
        std::cout << std::endl;
    }
}
