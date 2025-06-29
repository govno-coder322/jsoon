#include <iostream>
#include <string>

int main() {
    std::string input = R"({"key": "value", "num": 42, "arr": [1, 2, 3]})";
    auto result = parese_json(input);
    print_json(result);
}