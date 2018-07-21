#include<iostream>
using namespace std;
const char* message(void);

main()
{
  cout<<message()<<endl;
}

inline const char* message(void)
{
  return "Hello World";
}
