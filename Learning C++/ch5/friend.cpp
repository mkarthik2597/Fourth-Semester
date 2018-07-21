#include<iostream>
using namespace std;

class cls2;
class cls1
{
  int a;
public:
  cls1(){a=3;}
  void add(cls2 B);
};

class cls2
{
  int a;
public:
  cls2(){a=4;}
  friend void cls1::add(cls2);
};

void cls1::add(cls2 B)
{
  cout<<a+B.a<<endl;
}

int main()
{
  cls1 A;
  cls2 B;
  A.add(B);
}
