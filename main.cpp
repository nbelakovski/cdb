#include <iostream>
#include <map>

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>


int main (int argc, char * argv[])
{
    std::cout << "argc: " << argc << std::endl;
    // the first arg is of the form var1=value1;var2=value2, so we need to
    // split by ';', and then split again by '=' and generate a map of var-value pairs
    std::cout << argv[1][0] << argv[1][1] << std::endl;
    const std::string vars(argv[1]);
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
    char * line = nullptr;
    while( line = readline(") "))
    {
        add_history(line);
//        std::cout << ") ";
//        getline(std::cin, command);
        // todo: interpret up as previous command
        // right now just assume message(STATUS ${var})
        std::string command(line);
        size_t open_brace_pos = command.find('{');
        size_t close_brace_pos = command.find('}');
        const std::string var = command.substr(open_brace_pos + 1, close_brace_pos - open_brace_pos - 1);
        if (varvals.find(var) != varvals.end()) {
            std::cout << varvals[var] << std::endl;
        } else {
            std::cout << var << " not found" << std::endl;
        }
        free(line);
        line = nullptr;
    }
    return 0;
}

