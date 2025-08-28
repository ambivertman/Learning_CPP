#include<string.h>
#include<iostream>
#define LEN sizeof(int)
using std::cout;
using std::cin;
using std::endl;
using std::ostream;

class String {
public:
	String(const char* data)
		:_data(new char[strlen(data) + 1 + LEN]() + LEN)
	{
		strcpy(_data, data);
		*(int*)(_data - LEN) = 1;
	}
	
	String(const String& rhs)
		:_data(rhs._data)
	{
		++*(int*)(_data - LEN);
	}
	
	String& operator=(const String & rhs) {
		if (this != &rhs) {
			if (-- * (int*)(_data - LEN) == 0) {
				delete[] _data;
				_data = nullptr;
			}
			_data = rhs._data;
			++* (int *)(_data - LEN);
		}
		return *this;
	}

	~String() {
		if (-- * (int*)(_data - LEN) == 0) {
			delete [] (_data - LEN);
			_data = nullptr;
		}
	}

	int getRefCount() {
		return *(int *)(_data - LEN);
	}

private:
	class CharProxy {
	public:
		CharProxy(String& str, int index)
			:_str(str)
			,_index(index)
		{}

		void operator=(char rhs) {
			if (_str.getRefCount() > 1) {
				--* (int*)(_str._data - LEN);
				char* temp = new char[strlen(_str._data) + 1]() + LEN;
				strcpy(temp, _str._data);
				temp[_index] = rhs;
                *(int *)(temp - LEN) = 1;
				_str._data = temp;
			}
			_str._data[_index] = rhs;
		}
		friend ostream& operator<<(ostream& os, const String::CharProxy& rhs);
	private:
		String& _str;
		int _index;
	};
public:
	CharProxy operator[](int index) {
		return CharProxy(*this, index);
	}
	friend ostream& operator<<(ostream& os, String& str);
	friend ostream& operator<<(ostream& os, const String::CharProxy& rhs);
private:
	char* _data;
};

ostream& operator<<(ostream& os, String& str) {
	os << str._data;
	return os;
}

ostream& operator<<(ostream& os, const String::CharProxy& rhs) {
	os << rhs._str._data[rhs._index];
	return os;
}

void test() {
	String s1("hello");
	String s2 = s1;
	String s3(s1);

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s1.getRefCount() << s2.getRefCount() 
		 << s3.getRefCount() << endl;
    
    s1[0] = 'H';
    cout << s1 << s1.getRefCount() << endl;
    cout << s2.getRefCount() << endl;

}

int main() {
	test();
}
 
