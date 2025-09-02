#include <string>
#include <utility>
#include <fstream>
#include <sstream>
#include <iostream>
#include <unordered_map>
using std::istringstream;
using std::unordered_map;
using std::ifstream;
using std::ofstream;
using std::string;
using std::pair;
using std::cout;
using std::cin;
using std::endl;

class Converter{
public:
    Converter(string configPath = "./map.txt")
        :_configPath(configPath)
    {
        init_rules();
    }
    void show_rules(){
        for(auto &elem : _rules){
            cout << elem.first << " : " << elem.second << endl;
        }
    } 
    void dumpline(ofstream &ofs,
                  const string &line, const string &destpath){
        string word;
        istringstream iss(line);
        while(iss >> word){
            if(_rules.count(word)){
                word = _rules[word];
            }
            ofs << word << " ";
        }
        ofs << endl;
    }


    void convert(const string &sourcepath, const string &destpath){  
        ifstream ifs(sourcepath);
        ofstream ofs(destpath, std::ios::app);
        string line;
        while(getline(ifs, line)){
            dumpline(ofs, line, destpath);
        }
    }
private:
     pair<string, string> dumprules(const string &line){
        size_t pos = line.find_first_of(' ');
        string key;
        string value; 
        if(pos != std::string::npos){
            key = line.substr(0, pos);
            value = line.substr(pos + 1);
         }

         return {std::move(key), std::move(value)};
    }


    void init_rules(){
        ifstream ifs(_configPath);
        string line;
        while(getline(ifs, line)){
            _rules.insert(dumprules(line));
        }
        ifs.close();
    }
    string _configPath;
    unordered_map<string , string> _rules; 
};

void test(){
    Converter ins;
    ins.show_rules();
    ins.convert("./file.txt", "./converted_file.txt");
}

int main(){
    test();    
    return 0;
}

