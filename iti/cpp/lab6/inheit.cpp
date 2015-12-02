#include <iostream>
using namespace std;

class Base {
private:
    int x, y;
public:
    Base(int x = 0, int y = 0) {
        cout << "Base Constructor called!" << endl;
        this->x = x;
        this->y = y;
    }
    ~Base() {
        cout << "Base Destructor called!" << endl;
    }
    int calSum() {
        return x + y;
    }
};

class Derived: public Base {
private:
    int z;
public:
    Derived(int x = 0, int y = 0, int z = 0): Base(x, y) {
        cout << "Derived constructor called" << endl;
        this->z = z;
    }
    ~Derived(){
        cout << "Derived destructor called" << endl;
    }
    int calSum() {
        return Base::calSum() + z;
    }
};

int main () {
    Base base(3, 5);
    Derived der(6, 7, 8);
    cout << base.calSum() << endl;
    cout <<der.Base::calSum() << endl;
}
