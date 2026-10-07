#include <iostream>
#include <sstream>

#include "util/map.h"

int main()
{
	std::string input;
	std::cout << "Enter a command: ";
	std::getline(std::cin, input);

	std::istringstream inputStream(input);
	std::string commandName;
	inputStream >> commandName;
	std::string argument;
	std::getline(inputStream, argument);
	if (!argument.empty() && argument.front() == ' ')
	{
		argument.erase(0, 1);
	}

	const auto commandIt = commands.find(commandName);

	std::unique_ptr<BaseCommand> command = commandIt->second();
	command->input(argument);
	command->execute();
	return 0;
}