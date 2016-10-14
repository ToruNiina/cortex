#ifndef CORTEX_REGISTER
#define CORTEX_REGISTER
#include <vector>
#include <limits>
#include <iostream>
#include <iomanip>
#include <cstdint>

namespace cortex
{

class Registry
{
  public:
    using iterator = std::vector<std::uint8_t>::iterator;
    using const_iterator = std::vector<std::uint8_t>::const_iterator;

  public:
    Registry() : registry_(30000, 0){}
    ~Registry() = default;

    void clear();

    iterator       begin()        {return registry_.begin();}
    iterator       end()          {return registry_.end();}
    const_iterator cbegin() const {return registry_.cbegin();}
    const_iterator cend()   const {return registry_.cend();}

    std::uint8_t  at(const std::size_t i) const {return registry_.at(i);}
    std::uint8_t& at(const std::size_t i)       {return registry_.at(i);}
    std::uint8_t  operator[](const std::size_t i) const {return registry_[i];}
    std::uint8_t& operator[](const std::size_t i)       {return registry_[i];}

    template<typename charT, typename traits>
    std::basic_ostream<charT, traits>&
    make_hex(std::basic_ostream<charT, traits>& os, const std::uint8_t v) const;

    template<typename charT, typename traits>
    std::basic_ostream<charT, traits>&
    dump(std::basic_ostream<charT, traits>& os, const std::size_t n = size_max) const;

    Registry(const Registry&) = default;
    Registry(Registry&&) = default;
    Registry& operator=(const Registry&) = default;
    Registry& operator=(Registry&&) = default;

  private:
    constexpr static std::size_t size_max = std::numeric_limits<std::size_t>::max();
    std::vector<std::uint8_t> registry_;
};

inline void Registry::clear()
{
    for(auto iter = registry_.begin(); iter != registry_.end(); ++iter)
        *iter = 0;
    return;
}

template<typename charT, typename traits>
std::basic_ostream<charT, traits>&
Registry::make_hex(std::basic_ostream<charT, traits>& os, const std::uint8_t v) const
{
    const std::uint8_t second = v % 16;
    const std::uint8_t first = (v - second) / 16;
    auto hexagonal = [](const std::uint8_t v){
        return (v < 10) ? static_cast<charT>(v + 48) : static_cast<charT>(v + 55);
    };
    os << hexagonal(first) << hexagonal(second);
    return os;
}

template<typename charT, typename traits>
std::basic_ostream<charT, traits>&
Registry::dump(std::basic_ostream<charT, traits>& os, const std::size_t n) const
{
    const std::size_t e = std::min(n, this->registry_.size());

    for(std::size_t i = 0; i < e; ++i)
    {
        os << "|"; this->make_hex(os, this->registry_.at(i));
    }
    os << "|";
    return os;
}

} // cortex
#endif /* CORTEX_REGISTER */
