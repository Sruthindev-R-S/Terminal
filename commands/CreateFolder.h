#pragma once

#include "base.h"
#include <cstdlib>
#include <iostream>

class CreateFolder : public BaseCommand {
    public:
        CreateFolder(){
            base="mkdir";
        }
        void input(const std::string& value) override {
            
            argument = value;
        }

        void execute() override {
            if (argument.empty())
            {
                std::cout << "The argument is empty\n";
                return;
            }
            const std::string command = base + " " + argument;
            std::system(command.c_str());
        }

};