#include<iostream>
using namespace std;
int & max(int &, int &);
main()
{
  cout<<"Enter two numbers:";
  int a,b;
  cin>>a>>b;

  max(a,b)=-1;
  cout<<a<<endl<<b<<endl;
}

int & max(int & a, int & b)
{
  return a>b?a:b;
}
