#include<iostream>
#include<cstdio>
#include<cstring>

#include "College.cpp"
#include "Student.cpp"
#include "Admin.cpp"
#include "login.cpp"
using namespace std;

int main()
{
  repeat:
  printf("\n\n...PrimaryHomePage...\n\n");
  printf("Enter\n1 for student\n2 for college\n3 for system administrator\n4 to exit:");
  int i;
  scanf("%d",&i);

  switch(i)
  {
    case 1: StudentAcessControl();
            break;
    case 2: CollegeAccessControl();
            break;
    case 3: AdminAcessControl();
  }

  if(i!=4)
  goto repeat;
}
