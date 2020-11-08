#include <bits/stdc++.h>

using namespace std;

class base
{
public:
  virtual void print () { cout << "print base class" << endl; }

  void show() { cout << "show base class" << endl; }
};

class derived:public base
{
public:
  // print() is already virtual function in derived class by default, we could also declared as virtual void print() explicitly
  void print() { cout << "print derived class" << endl; }

  void show() { cout << "show derived class" << endl; }
};

int main(){

  // pointer to base class object
  base *bptr;
  derived d;

  // now bptr points to object d
  bptr = &d;

  // use -> operator when accessing members since bptr is pointer
  // Virtual function, binded at run time ( this will point derived::print() since it is binded at runtime and we assign &d to base class pointer)
  bptr -> print();  

  // Non-virtual function, binded at compile time ( this will point base::show() since it is binded at compile time and does not changed after that)
  bptr -> show();

  return 0;
}