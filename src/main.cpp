#include <iostream>
#include <vector>
#include <fstream>

int main(int argc, char **argv)  {
    /* -------------------------
        ARG HANDLING
    */

    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <file>" << std::endl;
        return 1;
    }

    std::ifstream file (argv[1], std::ifstream::in);
    if (file.fail()) {
        std::cerr << "Failed to read file " << argv[1] << " (does it exist?)" << std::endl;
        return 1;
    }



    return 0;
}