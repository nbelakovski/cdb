#include <iostream>
#include <map>

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

#include <cdb/cdb.h>

int main (int argc, char * argv[])
{
    // the first arg is of the form var1=value1;var2=value2, so we need to
    // split by ';', and then split again by '=' and generate a map of var-value pairs
    std::map<std::string, std::string> varvals = cdb::extract_vars(std::string(argv[1]));
    
    char * line = nullptr;
    using_history();
    const std::string history_filename = std::string(getenv("HOME")) + "/.cdb_history";
    int x = read_history(history_filename.c_str());
    std::cout << "Type ?, h, or help for a list of available commands" << std::endl;
    while( (line = readline(") ")) )
    {
        add_history(line);
        std::string command(line); // put it in an std::string for convenience
        free(line);
        line = nullptr;
        if(command == "exit" || command == "quit")
        {
            break;
        }
        else if(command == "dump")
        {
            for(const auto & pair : varvals)
            {
                std::cout << pair.first << "=" << pair.second << std::endl;
            }
        }
        else if(command == "help" || command == "?" || command == "h")
        {
            std::cout << "dump - print out all variables and their values" << std::endl;
            std::cout << "exit - exits the program. Can also be accomplished with 'quit' and Ctrl + D" << std::endl;
            std::cout << "${var} - prints out the value of var. If var does not exist, prints 'var not found'" << std::endl;
        }
        else
        {
            size_t open_brace_pos = command.find("${");
            size_t close_brace_pos = command.find('}');
            const std::string var = command.substr(open_brace_pos + 2, close_brace_pos - open_brace_pos - 2);
            if (varvals.find(var) != varvals.end()) {
                std::cout << varvals[var] << std::endl;
            } else {
                std::cout << var << " not found" << std::endl;
            }
        }
    }
    int y = write_history(history_filename.c_str());
    return 0;
}

