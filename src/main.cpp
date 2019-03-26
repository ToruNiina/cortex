#include "cortex/cortex.hpp"
#include <fstream>

int main(int argc, char **argv)
{
    if(argc == 1)
    {
        cortex::Cortex ctx;
        ctx.run();
    }
    else if(argc == 2)
    {
        const std::string filename(argv[1]);
        std::ifstream ifs(filename);
        if(!ifs.good())
        {
            std::cerr << "file open error : " + filename << std::endl;
            return 1;
        }
        std::string content;
        while(!ifs.eof())
        {
            std::string buf;
            std::getline(ifs, buf);
            content += buf;
        }
        cortex::Instruction inst(content);
        cortex::Cortex ctx(inst);
        ctx.execute();
    }
    else
    {
        std::cerr << "usage: cortex [source file]" << std::endl;
        return 1;
    }
    return 0;
}
