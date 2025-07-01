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



struct Token {
    TokenType type; //тип токена
    std::string value; // содержимое
};
std::vector<Token> tokenize(const std::string& input);
std::ostream& operator<<(std::ostream& os, const Token& token);
class Printer {
public:
    void printTokens(const std::vector<Token>& tokens);
};
JSONValue parseValue(const std::vector<Token>& tokens, size_t& index);
void printJSONValue(const JSONValue& value, int indent = 0);