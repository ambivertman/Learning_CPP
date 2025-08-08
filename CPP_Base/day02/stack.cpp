#include <stdbool.h>
#include <iostream>
using std::cout;
using std::endl;

class Stack {
public:
    Stack(int size = 10)
        :_size(size),
        _top(0),
        _data(new int[_size * sizeof(int)]) {
    }
    ~Stack() {
        if (_data != nullptr) {
            delete[] _data;
            _data = nullptr;
        }
    }
    bool is_empty();
    bool is_full();
    void push(int);
    void pop();
    int get_top();
private:
    int _size;
    int _top;
    int *_data;
};

bool Stack::is_empty() {
    return _top == 0;
}

bool Stack::is_full() {
    return _top == _size;
}

void Stack::push(int data) {
    if (!is_full()) {
        _data[_top] = data;
        _top++;
    }
}

void Stack::pop() {
    if (!is_empty()) {
        _top--;
    }
}

int Stack::get_top() {
    return _data[_top - 1];
}


void test() {
    Stack s(5);
    cout << "is_empty:" << s.is_empty() << endl;
    cout << "is_full:" << s.is_full() << endl;

    s.push(5);
    cout << "top:" << s.get_top() << endl;

    for (int i = 0; i < 4; i++) {
        s.push(i);
        cout << "top:" << s.get_top() << endl;
    }

    cout << "is_empty:" << s.is_empty() << endl;
    cout << "is_full:" << s.is_full() << endl;

    s.pop();
    cout << "after pop top:" << s.get_top() << endl;
    cout << "is_full:" << s.is_full() << endl;
}

int main() {
    test();

    return 0;
}

