//
// json-standard console app
//
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

struct Args {
    bool good;
    bool helpWanted;
    std::string inFileName;
};

void checkArgs(int argc, char *argv[], Args* result) {
    result->good = true;
    result->helpWanted = false;
    if (argc < 2) {
        result->good = false;
        return;
    }
    if (std::string("--help").compare(argv[1]) == 0) {
        result->good = false;
        result->helpWanted = true;
        return;
    }
    result->inFileName = argv[1];
    // TODO: later add more options; including support for [-o outFileName]
}

int main(int argc, char *argv[]) {
    Args args;
    checkArgs(argc, argv, &args);
    if (args.good) {
        std::ifstream f(args.inFileName);
        if ( !f.is_open() ) {
            std::cout <<"Could not open file '" << args.inFileName << "'." << std::endl;
            return 1;
        } else {
            json data = json::parse(f);  // TODO: add later support for file-not-json
        }
    } else {
        std::cout << "Usage: json-standard [FILE] [OPTIONS]" << std::endl;
        if (args.helpWanted) {
            std::cout << "Reformat a JSON text document's expression (format) to match the 'json-standard-1' standard." << std::endl;
            std::cout << "Details available at https://json-standard.codes ." << std::endl;
            std::cout << std::endl;
            std::cout << "Example: json-standard original.json -o standardized.json" << std::endl;
            std::cout << std::endl;
            std::cout << "Options:" << std::endl;
            std::cout << "-o                  output to a file rather than stdout." << std::endl;
        } else {
            std::cout << "try 'json-standard --help' for more information" << std::endl;
        }
    }
    return 0;
};

