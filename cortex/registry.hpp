#ifndef CORTEX_REGISTER
#define CORTEX_REGISTER
#include <vector>
#include <limits>
#include <iostream>
#include <iomanip>
#include <algorithm>
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

    void clear()
    {
        std::fill(this->begin(), this->end(), 0);
    }

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
    dump(std::basic_ostream<charT, traits>& os) const;

    Registry(const Registry&) = default;
    Registry(Registry&&) = default;
    Registry& operator=(const Registry&) = default;
    Registry& operator=(Registry&&) = default;

  private:
    std::vector<std::uint8_t> registry_;
};


template<typename charT, typename traits>
std::basic_ostream<charT, traits>&
Registry::dump(std::basic_ostream<charT, traits>& os) const
{
    const std::size_t e = std::distance(std::find_if(
        this->registry_.crbegin(), this->registry_.crend(),
        [](const std::uint8_t c) noexcept -> bool {
            return c != 0;
        }), this->registry_.crend());

    for(std::size_t i = 0; i < e; ++i)
    {
        os << "|" << std::hex << std::setw(2) << std::setfill('0') << int(this->registry_.at(i));
    }
    os << "|";
    return os;
}

} // cortex
#endif /* CORTEX_REGISTER */
