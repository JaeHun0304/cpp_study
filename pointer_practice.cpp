#include <iostream>

using namespace std;

int main(){

  int *ptr, a;
  ptr = new int;
  *ptr = 1;

  ptr = &a;
  a = 7;
  cout << *ptr << endl;
  cout << ptr << endl;

}