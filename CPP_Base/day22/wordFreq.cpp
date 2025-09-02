#include <ctype.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <string>
#include <unordered_map>
using std::unordered_map;
using std::cin;
using std::cerr;
using std::cout;
using std::endl;
using std::pair;
using std::string;
using std::ifstream;
using std::ofstream;
using std::istringstream;

class Dict {
public:
    Dict()
        :_dict()
    {}

    void read(const char *filename) {
        ifstream ifs(filename);
        if (!ifs) {
            cerr << "file is not exist;" << endl;
        }

        string line;
        while (getline(ifs,line)) {
            dumpline(line);
        }
    }

    void store(const char *filename) {
        ofstream ofs(filename,std::ios_base::app);
        for (auto &rec : _dict) {
            ofs << rec.first << ":" << rec.second << endl;
        }
    }

    void dumpline(const string &line) {
        string word;
        istringstream iss(line);
        while (iss >> word) {
            if (isdigit(word[0])) {
                continue;
            }
            ++_dict[word];
        }
    }

private:
    unordered_map<string,int> _dict;
};

void test() {
    Dict dict;
    dict.read("../day07/The_Holy_Bible.txt");
    dict.store("./WordFreq.txt");
}

int main() {

    test();

    return 0;
}

