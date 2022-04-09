#include "markov.hpp"

void markov_chain::read_file(char* path) {
    std::string word;

    std::ifstream file;
    file.open(path, std::ifstream::in);
    if(file.is_open()) {
        while (file >> word) {
            file_contents.push_back(word);
        }
    }
    file.close();
}

void markov_chain::build_chain() {
    edge_flag = -1;
    for(auto i = 0; i < file_contents.size(); i++) {
        std::vector<std::string>::iterator itr = std::find(words.begin(), words.end(), file_contents[i]);

        if (itr != words.end() && words.begin()!=words.end()-1 ) {
            edge_flag = std::distance(words.begin(), itr);
        } else {
            words.push_back(file_contents[i]);
        }

        if (i != file_contents.size()-1) {
            if (edge_flag == -1) {
                std::vector<std::string> temp;
                temp.push_back(file_contents[i+1]);
                edges.push_back(temp);
            } else { 
                edges[edge_flag].push_back(file_contents[i+1]);
                edge_flag = -1;
            }
        } else {
            // edges[edges.size()-1].push_back(file_contents[i]);
        }
    }
}

void markov_chain::print_data() {
    for (int i = 0; i < words.size(); i++) {
        std::cout << i << " " << words[i] << ": ";
        for (int j = 0; j < edges[i].size(); j++) {
            std::cout << edges[i][j] << ", ";
        }
        std::cout << std::endl;
    }
}