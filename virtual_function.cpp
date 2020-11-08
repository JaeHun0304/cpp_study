#include <iostream> 
using namespace std; 
  
class Base { 
public: 
    virtual void show() 
    { 
        cout << " In Base \n"; 
    } 
}; 
  
class Derived : public Base { 
public: 
    void show() 
    { 
        cout << "In Derived \n"; 
    } 
}; 
  
int main(void) 
{ 
    // allocate Derived object into the base class pointer
    Base* bp = new Derived; 
  
    // RUN-TIME POLYMORPHISM binded to Derived class
    bp->show(); 
  
    return 0; 
} 