#ifndef CORTEX_REGISTER
#define CORTEX_REGISTER
#include <algorithm>
#include <vector>
#include <ostream>
#include <iomanip>
#include <cstdint>

namespace cortex
{

class Registry
{
  public:
    using iterator       = std::vector<std::uint8_t>::iterator;
    using const_iterator = std::vector<std::uint8_t>::const_iterator;

  public:

    Registry() : registry_(30000, 0){}
    ~Registry() = default;
    Registry(const Registry&) = default;
    Registry(Registry&&) = default;
    Registry& operator=(const Registry&) = default;
    Registry& operator=(Registry&&) = default;

    void clear()
    {
        std::fill(this->begin(), this->end(), 0);
    }

    iterator       begin()        noexcept {return registry_.begin();}
    iterator       end()          noexcept {return registry_.end();}
    const_iterator cbegin() const noexcept {return registry_.cbegin();}
    const_iterator cend()   const noexcept {return registry_.cend();}

    std::uint8_t  at(const std::size_t i) const {return registry_.at(i);}
    std::uint8_t& at(const std::size_t i)       {return registry_.at(i);}
    std::uint8_t  operator[](const std::size_t i) const noexcept {return registry_[i];}
    std::uint8_t& operator[](const std::size_t i)       noexcept {return registry_[i];}

    template<typename charT, typename traits>
    std::basic_ostream<charT, traits>&
    dump(std::basic_ostream<charT, traits>& os) const;

  private:
    std::vector<std::uint8_t> registry_;
};

template<typename charT, typename traits>
std::basic_ostream<charT, traits>&
Registry::dump(std::basic_ostream<charT, traits>& os) const
{
    for(auto i = this->cbegin(), e = std::find_if(
            this->registry_.crbegin(), this->registry_.crend(),
            [](const std::uint8_t c) noexcept -> bool {
                return c != 0;
            }).base(); i!=e; ++i)
    {
        os << '|' << std::hex << std::setw(2) << std::setfill('0')
           << static_cast<int>(*i);
    }
    os << '|';
    return os;
}

} // cortex
#endif /* CORTEX_REGISTER */
