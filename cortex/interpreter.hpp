#ifndef CORTEX_INTERPRETER
#define CORTEX_INTERPRETER
#include "instruction.hpp"
#include "registry.hpp"
#include <iostream>

namespace cortex
{

class Interpreter
{
  public:
    Interpreter() = default;
    Interpreter(const Interpreter&) = default;
    Interpreter(Interpreter&&) = default;
    ~Interpreter() = default;

    Interpreter(const Instruction& inst): instruction_(inst){}
    Interpreter(const Instruction& inst, const Registry& reg)
        : instruction_(inst), registry_(reg){}

    template<typename charT, typename traits>
    void exec(std::basic_istream<charT, traits>& input,
              std::basic_ostream<charT, traits>& output);

    template<typename charT, typename traits>
    bool step(std::basic_istream<charT, traits>& input,
              std::basic_ostream<charT, traits>& output);

    template<typename charT, typename traits>
    void dump(std::basic_ostream<charT, traits>& output) const;

  private:
    Instruction::const_iterator instruction_ptr;
    Registry::iterator          data_ptr;
    Instruction                 instruction_;
    Registry                    registry_;
};

template<typename charT, typename traits>
void Interpreter::exec(std::basic_istream<charT, traits>& input,
                       std::basic_ostream<charT, traits>& output)
{
    instruction_ptr = instruction_.cbegin();
    data_ptr = registry_.begin();
    while(this->step(input, output)){}
    return;
}

template<typename charT, typename traits>
bool Interpreter::step(std::basic_istream<charT, traits>& input,
                       std::basic_ostream<charT, traits>& output)
{
    switch(*instruction_ptr)
    {
        case '+':
            if(data_ptr < registry_.begin() || registry_.end() < data_ptr)
                throw std::out_of_range("data ptr out of range");
            ++(*data_ptr); ++instruction_ptr; break;
        case '-':
            if(data_ptr < registry_.begin() || registry_.end() < data_ptr)
                throw std::out_of_range("data ptr out of range");
            --(*data_ptr); ++instruction_ptr; break;
        case '>': ++data_ptr; ++instruction_ptr; break;
        case '<': --data_ptr; ++instruction_ptr; break;
        case '.':
            if(data_ptr < registry_.begin() || registry_.end() < data_ptr)
                throw std::out_of_range("data ptr out of range");
            output << *data_ptr; ++instruction_ptr; break;
        case ',':
            if(data_ptr < registry_.begin() || registry_.end() < data_ptr)
                throw std::out_of_range("data ptr out of range");
            input  >> *data_ptr; ++instruction_ptr; break;
        case '[':
            if(*data_ptr == 0)
                instruction_ptr = instruction_.jump(instruction_ptr);
            else ++instruction_ptr;
            break;
        case ']':
            if(*data_ptr != 0)
                instruction_ptr = instruction_.jump(instruction_ptr);
            else ++instruction_ptr;
            break;
        default:
            throw std::logic_error("invalid charactor in instruction");
    }
    return instruction_ptr != instruction_.cend();
}

template<typename charT, typename traits>
void Interpreter::dump(std::basic_ostream<charT, traits>& output) const
{
    output << std::endl;
    instruction_.dump(output);
    output << std::endl;
    // XXX this code is highly depends on the format of instruction.dump
    const std::size_t dist_inst =
        std::distance(instruction_.cbegin(), instruction_ptr);
    for(std::size_t i=0; i<dist_inst; ++i)
        output << ' ';
    output << '^' << std::endl;

    const std::size_t memory_length = instruction_.count_memory();
    registry_.dump(output, memory_length);
    output << std::endl;
    const Registry::const_iterator current = data_ptr;
    const std::size_t dist_data =
        std::distance(registry_.cbegin(), current);
    output << ' ';
    for(std::size_t i=0; i<dist_data; ++i)
        output << "   ";
    output << "^^" << std::endl;

    return;
}


} // cortex
#endif /* CORTEX_INTERPRETER */
