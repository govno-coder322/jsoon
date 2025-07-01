#include <iostream>
#include <string>

#include "../include/json.h"

int main() {
    std::string input = R"(
        {
            "x": true,
            "y": null,
            "z": 12.5,
            "arr": [1, 2, 3],
            "obj": { "nested": "yes", "huy":"pizda" }
        }
    )";
    std::vector<Token> tokens = tokenize(input);

    for (size_t index = 1; index < tokens.size() - 1;) {
        if (tokens[index].type != TokenType::String) {
            ++index;
            continue;
        }

        std::string key = tokens[index].value;
        index += 2; // Skip the key and colon

        JSONValue val = parseValue(tokens, index);

        printJSONValue(val);
        // if (key == "x" && std::holds_alternative<bool>(val.value)) {
        //     std::cout << "x= " << std::boolalpha << std::get<bool>(val.value) << std::endl;
        // } else if (key == "y" && std::holds_alternative<std::nullptr_t>(val.value)) {
        //     std::cout << "y= null" << std::endl;
        // } else if (key == "z" && std::holds_alternative<double>(val.value)) {
        //     std::cout << "z= " << std::get<double>(val.value) << std::endl;
        // } else if (key == "arr" && std::holds_alternative<std::vector<JSONValue> >(val.value)) {
        //     std::cout << "arr= [ ";
        //     for (const auto &elem: std::get<std::vector<JSONValue> >(val.value)) {
        //         if (std::holds_alternative<double>(elem.value)) {
        //             std::cout << std::get<double>(elem.value) << " ";
        //         }
        //     }
        //     std::cout << "]" << std::endl;
        // } else if (key == "obj" && std::holds_alternative<std::map<std::string, JSONValue> >(val.value)) {
        //     auto obj = std::get<std::map<std::string, JSONValue> >(val.value);
        //     if (obj.contains("nested")) {
        //         std::cout << "nested= " << std::get<std::string>(obj["nested"].value) << std::endl;
        //     }
        // }
        //
        // if (tokens[index].type == TokenType::Comma) {
        //     ++index;
        // }


    }
}
