#include <functional>
#include <memory>
#include <string>
#include <unordered_map>

#include "../commands/CreateFolder.h"
#include "../commands/CreateFile.h"
#include "../commands/DeleteFile.h"
#include "../commands/DeleteFolder.h"
#include "../commands/WiteFile.h"

using CommandFactory = std::function<std::unique_ptr<BaseCommand>()>;

std::unordered_map<std::string, CommandFactory> commands = {
    {"CREATE_FOLDER", []() {
        return std::make_unique<CreateFolder>();
    }},
    {
        "CREATE_FILE",[](){
            return std::make_unique<CreateFile>();
        }
    },
    {"WRITE_FILE", []() {
        return std::make_unique<WriteFile>();
    }},
    {"DELETE_FILE", []() {
        return std::make_unique<DeleteFile>();
    }},
    {"DELETE_FOLDER", []() {
        return std::make_unique<DeleteFolder>();
    }}

};