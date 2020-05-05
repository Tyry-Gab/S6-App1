#include <iostream>
#include <fstream>
#include <cstring>

int main(int argc, char** argv)
{
    std::ifstream file_in;

    if (argc >= 2 && (strcmp(argv[1], "-") != 0)) {
        file_in.open(argv[1]);
        if (file_in.is_open()) {
            std::cin.rdbuf(file_in.rdbuf());
            std::cerr << "Using " << argv[1] << "..." << std::endl;
        } else {
            std::cerr   << "Error: Cannot open '"
                        << argv[1] 
                        << "', using stdin (press CTRL-D for EOF)." 
                        << std::endl;
        }
    } else {
        std::cerr << "Using stdin (press CTRL-D for EOF)." << std::endl;
    }

    while (!std::cin.eof()) {

        std::string line;

        std::getline(std::cin, line, ' ');
        int val1 = 1 ;
        if (!line.empty()) {
            val1 = atoi(line.c_str());            
        }

        std::getline(std::cin, line);
        int val2 = 1 ;
        if (!line.empty()) {
            val2 = atoi(line.c_str());            
        }

        std::cout << val1 * val2 << std::endl;
    }

    if (file_in.is_open()) {
        file_in.close();
    }

    return 0;
}
