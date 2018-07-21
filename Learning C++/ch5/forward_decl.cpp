#include<iostream>
using namespace std;

class cls2;

class cls1
{
  int a;
public:
  void fun(cls2);
};

class cls2
{
  int a;
public:
  cls2(){a=3;}
  friend void cls1::fun(cls2);
};

void cls1::fun(cls2 B)
  { 
    cout<<B.a<<endl;
  }
  
int main()
{
  cls1 A;
  cls2 B;
  
  A.fun(B);
}
  
