// The <bits/stdc++.h> is a header file. This file includes all standard library.
#include <bits/stdc++.h>

using namespace std;

// function overloading class example (compile time polymorphism)
class Funcoverload
{
public:

  // function with 1 int parameter
  void func(int x){
    cout << "value of x is " << x << endl;
  }

  // function with 1 double parameter, same function name "func" will be overloaded
  void func(double x){
    cout << "value of x is " << x << endl;
  }

  // function with 2 int parameters, same function name "func" will be overloaded
  void func(int x, int y){
    cout << "value of x and y are " << x << ", " << y << endl;
  }

};

// overlator overloading class example (compile time polymorphism)
class Complex
{
private:
  int real, imag;
public:
  // Constructor with 1 real and 1 imag int parameters
  Complex(int r = 0, int i = 0) {real = r; imag = i;}

  // Overload + operator with const reference to Complex object
  Complex operator + (Complex const &obj){
    Complex res;
    res.real = real + obj.real;
    res.imag = imag + obj.imag;
    return res;
  }

  //print method
  void print() { cout << real << " + i" << imag << endl; }

};

int main(){

  //instantitae class A with object a1
  Funcoverload a1;

  // 1st form of func
  a1.func(7);

  // 2nd form of func
  a1.func(9.132);

  // 3rd form of func
  a1.func(85, 64);

  Complex c1(10, 5), c2(2, 4);
  // '+' operator has been overloaded
  Complex c3 = c1 + c2;
  c3.print();

  return 0;
}