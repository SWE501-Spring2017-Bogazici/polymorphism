

#include <iostream>
#include <cstdlib>
#include <list>
using namespace std;

class Base {
public:
	virtual void print() = 0;
};

class String : public Base {
protected:
	string s;
public:
	String(string x) : s(x) {};
	void print() {
		cout << "'" << s << "' ";
	}
};

class Float : public Base {
protected:
	float f;
public:
	Float(float x) : f(x) {};
	void print() {
		cout << f << " ";
	}
};

class Complex : public Base {
protected:
	float re;
	float im;
public:
	Complex(float a, float b) : re(a),im(b) {};
	void print() {
		cout << re << "+ j(" << im << ") ";
	}
};

int main () {
	list<Base*> mylist;
	Base* p;

	for (int i=0; i<20; i++) {
		if (i%3 == 0) {
			p = new String(to_string(i*10));
		}
		else if(i%3 == 1) {
			p = new Complex(i*3, -i*7.2);
		}
		else {
			p = new Float(i*2.819381);
		}
		mylist.push_back(p);
	}

	for (list<Base*>::iterator q = mylist.begin(); q!=mylist.end(); q++) {
		(*q)->print();
	}

	return 0;
}
