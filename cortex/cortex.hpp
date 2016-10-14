#ifndef CORTEX_CORTEX
#define CORTEX_CORTEX
#include "interpreter.hpp"

namespace cortex
{

class Cortex
{
  public:
    Cortex() = default;
    ~Cortex() = default;
    Cortex(const Cortex&) = default;
    Cortex(Cortex&&) = default;

    Cortex(const Instruction& inst): interpreter_(inst){}

    void run();
    void execute();

  private:
    Interpreter interpreter_;
};

inline void Cortex::run()
{
    return;
}

inline void Cortex::execute()
{
    interpreter_.exec(std::cin, std::cout);
}

} // cortex
#endif /* CORTEX_CORTEX */
