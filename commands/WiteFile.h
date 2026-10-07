#pragma once

#include "base.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

class WriteFile : public BaseCommand {
    std::vector<std::string> text;

    public:
        WriteFile(){
            base="nano";
        }

        void input(const std::string& value) override {
            std::istringstream input(value);
            if (!(input >> argument)) {
                argument.clear();
                return;
            }

            text.clear();
            std::string line;
            std::getline(input, line);
            if (!line.empty()) {
                if (line.front() == ' ') {
                    line.erase(0, 1);
                }
                text.push_back(line);
            }

            while (std::getline(input, line)) {
                text.push_back(line);
            }

            while (std::getline(std::cin, line)) {
                text.push_back(line);
            }
        }

        void write(const std::string& line){
            text.push_back(line);
        }

        void execute() override {
            if (argument.empty())
            {
                std::cout << "The argument is empty\n";
                return;
            }
            std::ofstream file(argument);
            if (!file.is_open()) {
                std::cerr << "Unable to open file\n";
                return;
            }

            for (const std::string& line : text) {
                file << line << '\n';
            }

            file.close();
        }
};
