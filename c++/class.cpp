#include <iostream>
using namespace std;

class A{
public:
    A(){ cout << "A constructor" << endl;};
    virtual ~A() { cout << "A destructor" << endl; };
    virtual void pure_virtual_func() = 0;
    virtual void virtual_func(){cout << "A virtual_func()" << endl;}

private:

};

class B1 : public A{
public:
    B1(){ cout << "B1 constructor" << endl; }
    ~B1() { cout << "B1 destructor" << endl; }
    void pure_virtual_func() { cout << "B1 pure virtual func()" << endl; }
    virtual void virtual_func() { cout << "B1 virtual func()" << endl; }
    virtual void second_virtual_func() {cout << "B1 own virtual func" << endl; }
private:

};

class B2 : public A{
public:
    B2(){ cout << "B2 constructor" << endl; }
    B2(const B2& obj){}; // copy constructor
    ~B2() { cout << "B2 destructor" << endl; }
    void pure_virtual_func() { cout << "B2 pure virtual func()" << endl; }
private:

};

class C : public B1{
public:
    C(){ cout << "C constructor" << endl;}
    ~C() { cout << "C desctructor" << endl;}
    virtual void second_virtual_func() override {cout << "C own virtual func" << endl; }
};


int main(){
    // B1* b1 = new B1();
    // b1->virtual_func();
    // b1->pure_virtual_func();
    B1* c = new C();
    c->second_virtual_func();
    delete c;
    return 0;
}