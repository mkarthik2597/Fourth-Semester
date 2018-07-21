#include<iostream>
using namespace std;

class GP
{
public:
  int a;
  void display(){cout<<a<<endl;}
};

class P1:public GP
{
public:
  void show(){cout<<a<<endl;}

};

class P2: public GP
{
public:
  void show(){cout<<a<<endl;}
};

class child:public P1, public P2
{

};

int main()
{
  child ch1;
  ch1.display();
}
