#include <iostream>
#include <string>

#include "../include/json.h"

int main() {
    std::string input = R"({"x": true, "y": null, "z": 12.5})";
    std::vector<Token> tokens = tokenize(input);

    size_t index = 1;
    ++index;
    ++index;

    JSONValue xVal = parseValue(tokens, index);

    if (std::holds_alternative<bool>(xVal.value)) {
        std::cout << "x= " << std::boolalpha << std::get<bool>(xVal.value) << std::endl;
    }
}