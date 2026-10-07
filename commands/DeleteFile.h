#pragma once

#include <cstdlib>
#include <iostream>
#include "base.h"

class DeleteFile : public BaseCommand {
    public:
        DeleteFile(){
            base="rm";
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