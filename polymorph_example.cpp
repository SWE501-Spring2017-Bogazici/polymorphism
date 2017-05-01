#include <iostream>
#include <list>

using namespace std;

class Base {
    Base* next;

public:
    // pure virtual function
    virtual void print() = 0;

    Base() {
        next = nullptr;
    }

    Base* getNext() const {
        return next;
    }

    void setNext(Base *next) {
        Base::next = next;
    }
};

class String : public Base {
protected:
    string s;
public:
    String(string x) : s(x) {}

    void print() {
        cout << "'" << s << "' ";
    }
};

class Float : public Base {
protected:
    float f;
public:
    Float(float x) : f(x) {}

    void print() {
        cout << "'" << f << "' ";
    }
};

int main() {

    Base *p1 = new String("abc");
    Base *p = p1;

    for (int i = 0; i < 10; i++) {
        if (i % 2 == 1) {
            Base *p2 = new String("abc");
            p1->setNext(p2);
        } else {
            Base *p3 = new Float(i + 2.5f);
            p1->setNext(p3);
        }
        p1 = p1->getNext();
    }

    cout << " *** Print elements *** " << endl;

    while (p->getNext() != nullptr) {
        p->print();
        p = p->getNext();
    }

    return 0;
}
