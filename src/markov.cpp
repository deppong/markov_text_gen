#include "markov.hpp"

void markov_chain::read_file(char* path) {
    std::string word;

    std::ifstream file;
    file.open(path, std::ifstream::in);
    if(file.is_open()) {
        while (file >> word) {
            std::transform(word.begin(), word.end(), word.begin(), ::tolower);
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
        }
    }
}

void markov_chain::build_sentence(int length) {
    std::string sentence, word, temp;

    srand(time(0));

    int idx = rand() % words.size();
    word = words[idx];

    for (int i = 0; i < length; i++) {
        sentence.append(word + " ");
        // this is expensive i think and there is definitely a better way of doing this, but I don't really care
        idx = std::distance(words.begin(), std::find(words.begin(), words.end(), word));

        // if we are at the last word, just pick a new word. otherwise pick a random edge of the same index.
        if (!words.empty() && words.back() == word) {
            word = words[rand() % words.size()];
        } else {
            word = edges[idx][rand() % edges[idx].size()];
        }
    }

    std::cout << sentence << std::endl;

}

void markov_chain::print_data() {
    for (int i = 0; i < words.size(); i++) {
        std::cout << "[" << i << "]" << " " << words[i] << ": [";
        for (int j = 0; j < edges[i].size(); j++) {
            std::cout << edges[i][j] << ",";
        }
        std::cout << "]" << std::endl;
    }
}