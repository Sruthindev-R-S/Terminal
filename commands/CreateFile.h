#include <cstdlib>
#include <iostream>
#include "./base.h"

class CreateFile:public BaseCommand{
    public:
        CreateFile(){
            base="touch";
        }
        void input(const std::string& arg) override
        {
            argument=arg;
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