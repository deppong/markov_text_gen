#ifndef MARKOV_HPP
#define MARKOV_HPP

#include <vector> 
#include <iostream>
#include <fstream>
#include <algorithm>

class markov_chain {
    public: 
        void read_file(char*);
        void build_chain();
        void build_sentence(int);
        void print_data();

    private:
        std::vector<std::string> file_contents;
        std::vector<std::string> words;
        std::vector<std::vector<std::string>> edges;
        int edge_flag;
};

#endif // MARKOV_HPP