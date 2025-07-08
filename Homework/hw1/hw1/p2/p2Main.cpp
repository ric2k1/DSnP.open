/****************************************************************************
  FileName     [ p2Main.cpp ]
  PackageName  [ p2 ]
  Synopsis     [ Define main() function ]
  Author       [ Chung-Yang (Ric) Huang ]
  Copyright    [ Copyleft(c) 2016-present DVLab, GIEE, NTU, Taiwan ]
****************************************************************************/
#include "p2Json.h"

#include <cstdlib>
#include <iostream>
#include <string>
#include <utility>

int main()
{
    try {
        Json json;

        // Read in the csv file. Do NOT change this part of code.
        std::string jsonFile;
        std::cout << "Please enter the file name: ";
        std::cin >> jsonFile;
        if (json.read(jsonFile))
            std::cout << "File \"" << jsonFile
                      << "\" was read in successfully.\n";
        else {
            std::cerr << "Failed to read in file \"" << jsonFile << "\"!\n";
            std::exit(-1);  // jsonFile does not exist.
        }

        // C++17: Demonstrate structured bindings and modern features
        std::cout << "JSON contains " << json.size() << " elements\n";

        // Example of using structured bindings (if we had key-value pairs)
        for (const auto &elem : json) {
            const auto &[key, value] =
                std::make_pair(elem.getKey(), elem.getValue());
            std::cout << "Key: " << key << ", Value: " << value << '\n';
        }

        // Example of using std::optional
        if (auto result = json.find("example"); result.has_value()) {
            std::cout << "Found element: " << result.value() << '\n';
        }
        else {
            std::cout << "Element not found\n";
        }

        // TODO read and execute commands
        // std::cout << "Enter command: ";
        while (true) {
            // std::cout << "Enter command: ";
        }
    }
    catch (...) {
        std::cerr << "Unexpected error occurred\n";
        return 1;
    }
}
