#include <unordered_map>
#include <iostream>
#include <utility>
#include <list>
using std::cout;
using std::cin;
using std::endl;
using std::list;
using std::pair;
using std::unordered_map;

class LRUCache {
public:
    LRUCache(int capacity)
        :_cap(capacity)
    {    
        _map.reserve(capacity);
    }
    
    int get(int key) {
        /* if(!_map.count(key)){ */
        /*     return -1; */
        /* } */
        auto search = _map.find(key);
        if(search == _map.end()) return -1;
        reload(search->second);
        return search->second->second;
    }
    
    void put(int key, int value) {
        /* if(_map.count(key)){ */
        /*     _map[key]->second = value; */
        /*     reload(_map[key]); */
        
        auto search = _map.find(key);
        if(search != _map.end()){
            reload(search->second);
            search->second->second = value;
            return ;
        }

        if(_cap == _map.size()){
            int oldKey = _buffer.back().first;
            _buffer.pop_back();
            _map.erase(oldKey);
        }
        _buffer.emplace_front(key , value);
        _map.emplace(key , _buffer.begin());

    }



private:
    using Node = pair<int,int>;
    using ListIt = list<Node>::iterator;
    void reload(ListIt it){
        if(it != _buffer.begin()){
            _buffer.splice(_buffer.begin(), _buffer, it);
        }
    }

    int _cap;
    unordered_map <int, ListIt> _map;
    list<Node> _buffer;
};

void test(){

}

int main(){
    test();    
    return 0;
}

