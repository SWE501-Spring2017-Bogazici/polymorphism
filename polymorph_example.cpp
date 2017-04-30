#include <iostream>
#include <cstdlib>
using namespace std;

class Base {
private:
	Base* next;
public:
	virtual void print() = 0;

	Base* getNext() {
		return next;
	}

	void setNext(Base* next) {
		this->next = next;
	}
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

	Base* start= new Float(1.0);
	Base* prev= start;
	Base* temp;

	for (int i=0; i<20; i++) {
		if (i%3 == 0) {
			temp = new String(to_string(i*10));
		}
		else if(i%3 == 1) {
			temp = new Complex(i*3, -i*7.2);
		}
		else {
			temp = new Float(i*2.819381);
		}
		prev->setNext(temp);
		prev=temp;
	}


	start->print();
	temp=start;
	while(temp->getNext()) {
		temp->getNext()->print();
		temp=temp->getNext();
	}	

	return 0;
}
