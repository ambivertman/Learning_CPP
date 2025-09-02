#include <string.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>
#include <random>
#include <string>
using std::string;
using std::deque;
using std::vector;
using std::cout;
using std::cin;
using std::endl;


class Person {
public:
    Person(const string name)
        :_name(name)
    {
        random_scores();
    }

    void display() {
        cout << "Name:" << _name << endl;
        cout << "Scores:" << endl;
        for (int &score : _scores) {
            cout << score << " ";
        }
        cout << endl;
        cout << "Avg:" << avg() << endl;
        cout << endl;
    }

    float avg() {
        std::sort(_scores.begin(),_scores.end());
        int sum = 0;
        for (int &score : _scores) {
            sum += score;
        }
        float avg = (float)sum / _scores.size();
        return avg;
    }
private:
    void random_scores() {

        std::random_device rd;
        std::mt19937_64 gen(rd());

        std::uniform_int_distribution<> dist(60,100);
        for (int i = 0; i < 10; ++i) {
            _scores.push_back(dist(gen));
        }
        std::sort(_scores.begin(),_scores.end());
        _scores.pop_back();
        _scores.pop_front();
    }
    string _name;
    deque<int> _scores;
};

void test() {
    vector<string> names = { "Lily", "John", "Ambi", "Cooper", "Hachi" };
    vector<Person> people;
    people.reserve(names.size());
    for (string &name : names) {
        people.emplace_back(name);
    }

    for (Person &p : people) {
        p.display();
    }
}

int main() {
    test();
    return 0;
}

