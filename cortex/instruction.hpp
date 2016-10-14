#ifndef CORTEX_INSTRUCTION
#define CORTEX_INSTRUCTION
#include <string>

namespace cortex
{

class Instruction
{
  public:

    using iterator = std::string::iterator;
    using const_iterator = std::string::const_iterator;

  public:
    Instruction() = default;
    Instruction(const std::string& str);
    ~Instruction() = default;

    // jump from [/] to ]/[
    const_iterator jump(const const_iterator bracket) const;
    void append(const std::string& operation);
    std::size_t count_memory() const;

    template<typename charT, typename traits>
    void dump(std::basic_ostream<charT, traits>& output) const;

    std::size_t size() const {return instructions_.size();}
    bool empty() const {return instructions_.empty();}
    void clear() {instructions_.clear();}
    std::size_t count(const char op) const;
    void resize(const std::size_t i) {instructions_.resize(i);}
    void reserve(const std::size_t i) {instructions_.reserve(i);}
    void push_back(const char c) {instructions_.push_back(c);}

    char  operator[](const std::size_t i) const {return instructions_[i];}
    char& operator[](const std::size_t i)       {return instructions_[i];}
    char  at(const std::size_t i) const {return instructions_.at(i);}
    char& at(const std::size_t i)       {return instructions_.at(i);}

    iterator       begin()        {return instructions_.begin();}
    iterator       end()          {return instructions_.end();}
    const_iterator cbegin() const {return instructions_.cbegin();}
    const_iterator cend()   const {return instructions_.cend();}

  private:
    std::string instructions_;
};

template<typename charT, typename traits>
inline void Instruction::dump(std::basic_ostream<charT, traits>& output) const
{
    output << this->instructions_;
    return;
}

} // cortex

#endif /* CORTEX_INSTRUCTION */
