#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <string>
#include <vector>
#include <map>
#include <set>
using std::cin;
using std::map;
using std::set;
using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using std::string;
using std::ifstream;
using std::ofstream;
using std::istringstream;

class TextQuery{
public:
    void readFile(const string & filename){
        ifstream ifs(filename);
        if(!ifs){
            cerr << "file is not exist;" << endl;
        }

        string line;
        int lineNo = 0;
        while(getline(ifs, line)){
            ++lineNo;
            _lines.push_back(line);
            dumpline(line, lineNo);
        }
    }
    
    void dumpline(string line, int lineNo){
        string word;
        istringstream iss(line);
        while(iss >> word){
            ++_dict[word];
            _linesForWord[word].insert(lineNo);  
        }
    }

    void query(const string & word){
        auto search = _dict.find(word); 
        if(search != _dict.end()){
            cout << "---------------------------------------------" << endl;
            cout << word << " occurs " << (*search).second << " times." << endl;
            printLines(word);
            cout << "---------------------------------------------" << endl;
        }else{
            cout << word << " not found" << endl;
        }
    }


private:
    void printLines(const string &word){
        set<int> targetLines = _linesForWord[word];
        for(auto & lineNum : targetLines){
            cout << "(line " << lineNum << ") "
                 << _lines[lineNum - 1] << endl;
        }
    }
    vector<string> _lines;
    //匹配某个单词在哪些行出现了
    map<string, set<int>> _linesForWord;
    map<string, int> _dict;
};



int main(int argc, char *argv[]){
    string queryWord(argv[1]);
    TextQuery tq;
    tq.readFile("./china_daily.txt");
    tq.query(queryWord);    

    return 0;
}

