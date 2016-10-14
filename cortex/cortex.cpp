#include "cortex.hpp"

namespace cortex
{

void Cortex::run()
{
    auto is_brainfuck = [](const char c){
        return c == '+' || c == '-' || c == '>' || c == '<' || 
               c == '.' || c == ',' || c == '[' || c == ']';
    };
    while(true)
    {
        std::cout << "cortex)";
        std::string command;
        std::cin >> command;
        if(command == "exit" || command == "quit" || command == "bye")
        {
            break;
        }
        else if(command == "run")
        {
            this->interpreter_.clear_memory();
            this->interpreter_.exec(std::cin, std::cout);
            std::cout << std::endl;
        }
        else if(command == "dump")
        {
            this->interpreter_.dump(std::cerr);
        }
        else if(command == "run-stepwise")
        {
            this->interpreter_.clear_memory();
            interpreter_.init();
            while(this->interpreter_.step(std::cin, std::cout))
            {
                this->interpreter_.dump(std::cerr);
            }
            std::cout << std::endl;
        }
        else if(command == "clear")
        {
            interpreter_.clear();
        }
        else if(is_brainfuck(command.front()))
        {
            interpreter_.append(command);
        }
        else
        {
            std::cout << "cortex) cannot recognize command." << std::endl;
        }
    }
    return;
}

void Cortex::execute()
{
    interpreter_.exec(std::cin, std::cout);
}


} // cortex
