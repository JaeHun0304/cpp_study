#include <iostream>

using namespace std;
/*
class A
{
public:
  A(){ cout << "1";}
  A(const A &a1){ cout << "2";}
};
class B : public A
{
public:
  B(){ cout << "3";}
  B(const B &b1){ cout << "4";}
};
class C : public A
{
public:
  C(){ cout << "5";}
  C(const C &c1){ cout << "6";}
};
class D : public B, public C
{
public:
  D(){ cout << "7"; }
  D(const D &d1){ cout << "8";}
};
*/

// What's the different between two? "virtual"
// The class A will be instantiated only one time! This can solve ambiguity
// https://www.geeksforgeeks.org/multiple-inheritance-in-c/

class A
{
public:
  A(){ cout << "1";}
  A(const A &a1){ cout << "2";}
};
class B : virtual public A
{
public:
  B(){ cout << "3";}
  B(const B &b1){ cout << "4";}
};
class C : virtual public A
{
public:
  C(){ cout << "5";}
  C(const C &c1){ cout << "6";}
};
class D : public B, public C
{
public:
  D(){ cout << "7"; }
  D(const D &d1){ cout << "8";}
};

int main(){

  D d1;
  cout << "\n";
  D d2(d1);
}