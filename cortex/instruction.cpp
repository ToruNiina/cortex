#include "instruction.hpp"
#include <stdexcept>

namespace cortex
{
Instruction::Instruction(const std::string& inst)
{
    auto is_brainfuck = [](const char c){
        return (c == '+') || (c == '-') || (c == '<') || (c == '>') ||
               (c == '.') || (c == ',') || (c == '[') || (c == ']');
    };
    for(auto iter = inst.cbegin(); iter != inst.cend(); ++iter)
        if(is_brainfuck(*iter))
            this->instructions_.push_back(*iter);
}

Instruction::const_iterator
Instruction::jump(const const_iterator bracket) const
{
    if(*bracket == '[')
    {
        std::size_t c = 0;
        for(auto iter = bracket; iter != this->cend(); ++iter)
        {
                 if(*iter == '[') ++c;
            else if(*iter == ']') --c;
            if(c==0) return iter;
        }
        throw std::runtime_error("syntax error");
    }
    else if(*bracket == ']')
    {
        std::size_t c = 0;
        for(auto iter = bracket; iter != this->cbegin(); --iter)
        {
                 if(*iter == ']') ++c;
            else if(*iter == '[') --c;
            if(c==0) return iter;
        }
        if(*(this->cbegin()) == '[') --c;
        if(c==0) return this->cbegin();

        throw std::runtime_error("syntax error");
    }
    else
    {
        throw std::invalid_argument("invalid instruction pointer");
    }
}

std::size_t Instruction::count(const char op) const
{
    std::size_t retval = 0;
    for(auto iter = this->cbegin(); iter != this->cend(); ++iter)
        if(*iter == op) ++retval;
    return retval;
}

std::size_t Instruction::count_memory() const
{
    std::size_t max = 0;
    std::size_t current = 1;
    for(auto iter = this->cbegin(); iter != this->cend(); ++iter)
    {
        if(*iter == '>')
            ++current;
        else if(*iter == '<')
            --current;
        if(current > max)
            max = current;
    }
    return max;
}

}// cortex
