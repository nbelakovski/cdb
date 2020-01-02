#include <cdb/cdb.h>

namespace cdb
{

std::map<std::string, std::string> extract_vars(const std::string &vars)
{
    size_t index = 0;
    std::map<std::string, std::string> varvals;
    size_t pos = 0;
    while((pos = vars.find(';', index)) != std::string::npos)
    {
        const std::string varval = vars.substr(index, pos - index);
        index = pos+1;
        // now split on '='
        int pos2 = varval.find('=');
        const std::string var = varval.substr(0, pos2);
        const std::string val = varval.substr(pos2 + 1);
        varvals[var] = val;
    }
    // last one
    {
        const std::string varval = vars.substr(index);
        // now split on '='
        int pos2 = varval.find('=');
        const std::string var = varval.substr(0, pos2);
        const std::string val = varval.substr(pos2 + 1);
        varvals[var] = val;
    }
    return varvals;
}

} // close namespace cdb
