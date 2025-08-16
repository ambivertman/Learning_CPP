#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using std::cin;
using std::cerr;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::ifstream;
using std::ofstream;
using std::istringstream;

typedef struct {
    string _word;
    int _freq;
}Record;

class Dict {
public:
    Dict()
        :_dict()
    {
        _dict.push_back({ "\0",0 });
    }

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
        std::sort(_dict.begin(),_dict.end(),
            [](const Record &a,const Record &b) {
                return a._freq > b._freq;
            });
        ofstream ofs(filename,std::ios_base::app);
        for (auto &rec : _dict) {
            ofs << rec._word << ":" << rec._freq << endl;
        }
    }

    void dumpline(const string &line) {
        string word;
        istringstream iss(line);
        while (iss >> word) {
            if (size_t index = find(word)) {
                ++_dict[index]._freq;
            }
            else {
                _dict.push_back({ word,1 });
            }
        }
    }

    size_t find(const string &word) const {
        for (size_t index = 1; index < _dict.size() + 1; ++index) {
            if (_dict[index]._word == word) {
                return index;
            }
        }
        return 0;
    }

private:
    vector<Record> _dict;
};

void test() {
    Dict dict;
    dict.read("./The_Holy_Bible.txt");
    dict.store("./wordFreq.txt");
}

int main() {

    test();

    return 0;
}

