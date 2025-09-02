#include <iostream>
#include<set>
using std::set;
using std::cout;
using std::cin;
using std::endl;



void test(){
    int n, m;
    cin >> n >> m;
    set<int> s;
    int x;
    
    for (int i = 0; i < n; i++) {
        cin >> x;
        s.insert(x);
    }
    for (int i = 0; i < m; i++) {
        cin >> x;
        s.insert(x);
    }
    
    for (auto it = s.begin(); it != s.end(); ++it) {
        if (it != s.begin()) cout << " ";
        cout << *it;
    }
    cout << endl;
}

int main(){
    test();    
    return 0;
}

