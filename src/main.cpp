#include "markov.hpp"

int main(int argc, char **argv)  {
    /* -------------------------
        ARG HANDLING
    */

    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <file>" << std::endl;
        return 1;
    } 

    markov_chain chain;

    chain.read_file(argv[1]);
    chain.build_chain();
    chain.build_sentence(50);

    return 0;
}