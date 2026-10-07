#pragma once

#include <string>

class BaseCommand {
protected:
    std::string base;
    std::string argument;

public:
    virtual void execute() = 0;
    virtual void input(const std::string& value) = 0;
    virtual ~BaseCommand() = default;
};