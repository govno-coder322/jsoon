#pragma once
#include <string>
#include <variant>
#include <vector>
#include <map>

struct JSONValue;

using JSONVariant = std::variant<
    std::nullptr_t, // null
    bool,// true or false
    double, // число
    std::string, // строка
    std::vector<JSONValue>, // [1, 2, "name"]
    std::map<std::string, JSONValue> // {"key": value}
>;

struct JSONValue {
    JSONVariant value;
};

enum class TokenType {
    LeftBrace,
    RightBrace,
    LeftBracket,
    RightBracket,
    Colon,
    Comma,
    String,
    Number,
    True,
    False,
    Null,
    End
};


std::vector<Token> tokenize(const std::string& input);
struct Token {
    TokenType type; //тип токена
    std::string value; // содержимое
};
