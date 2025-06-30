#include <iostream>
#include <string>

#include "../include/json.h"

int main() {
    std::string input = R"({"key": "value", "num": 42, "arr": [1, 2, 3]})";
    std::vector<Token> vec = tokenize(input);

    Printer p;
    p.printTokens(vec);
}