#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <vector>

#include "../include/json.h"

#define NPOS std::string::npos

void usageError(const std::string& exe) {
    size_t slpos1 = exe.find_last_of('\\');
    size_t slpos2 = exe.find_last_of('/');
    size_t slpos = NPOS;

    if (slpos1 != NPOS && slpos2 != NPOS) {
        slpos = std::max(slpos1, slpos2);
    } else if(slpos1 != NPOS) {
        slpos = slpos1;
    } else if(slpos2 != NPOS) {
        slpos = slpos2;
    }

    std::string result;
    if (slpos != NPOS) {
        result = exe.substr(slpos + 1);
    } else {
        result = exe;
    }

    std::cerr << "Usage: " << result << " -p <filename>\n";
    exit(1);
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        usageError(argv[0]);
    }
    bool found = false;
    std::string filename;
    for (int i=0; i<argc-1; ++i) {
        if (strcmp(argv[i], "-p") == 0 ||
            strcmp(argv[i], "-parse") == 0 ||
            strcmp(argv[i], "--parse") == 0) {
            filename = argv[i+1];
            found = true;
            break;
            }
    }

    if (!found) {
        std::cerr << "Missing required flag!\n";
        usageError(argv[0]);
    }


    std::ifstream file(filename);
    if (file.is_open()) {
        std::string content((std::istreambuf_iterator<char>(file)),
            std::istreambuf_iterator<char>()
        );
        if (content.empty()) {
            std::cerr << "Error: file is empty or could not be read.\n";
        }
        // MAIN
        std::vector<Token> tokens = tokenize(content);
        size_t index = 0;
        JSONValue root = parseValue(tokens, index);
        if (index < tokens.size() && tokens[index].type != TokenType::End) {
            std::cerr << "Warning: not all tokens were consumed during parsing!\n";
        }


        printJSONValue(root, 0);



        file.close();
    } else {
        std::cerr << "Unable to open file " << filename << " !\n";
        usageError(argv[0]);
    }
    return 0;


}