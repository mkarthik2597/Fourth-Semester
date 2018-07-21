#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

class Admin;

#define CLGCODE(i) PreferList[i][0]
#define DEPTCODE(i) PreferList[i][1]
#define ALLOCATED(i) PreferList[i][2]

class Student
{
  int PreferList[5][3];
  int Listct;
  char roll[10];
  int rank;
  char pass[10];
  int quota;
public:
  void EnterPreferList();
  void DisplayPreferList();
  void ViewSeatMatrix();
  void StudentSpace();
  void DisplayResults();

  friend class Admin;
  friend void StudentAcessControl();
};

Student stdnt[50];
int Stdcount;

void Student::StudentSpace()
{
  repeat:
  printf("\n\n...Student %s HomePage...\n\n",roll);
  printf("Enter\n1 to view seat matrix\n2 to setup preference list\n3 to display preference list\n4 to display results");
  printf("\n5 to exit:");
  int i;
  scanf("%d",&i);

  switch(i)
  {
    case 1: ViewSeatMatrix();
            break;
    case 2: EnterPreferList();
            break;
    case 3: DisplayPreferList();
            break;
    case 4: DisplayResults();
            break;
  }
  if(i!=5)
  goto repeat;
}

void Student::ViewSeatMatrix()
{
  for(int i=0;i<Clgcount;i++)
  {
    clg[i].DisplayDepts();
  }
}

void Student::EnterPreferList()
{
  printf("\nEnter the no. of choices you want to make(5 at the most:):");
  scanf("%d",&Listct);

  for(int i=0;i<Listct;i++)
  {
    printf("Enter college code and dept code for preference no %d:",i+1);
    scanf("%d%d",&CLGCODE(i),&DEPTCODE(i));
    ALLOCATED(i)=false;
  }

}

void Student::DisplayPreferList()
{
  if(Listct==0)
  {
    printf("\nYou haven't set up your list yet\n");
    return;
  }
  printf("\nCollegeCode    DeptCode\n");
  for(int i=0;i<Listct;i++)
  {
    printf("\n%d    %d\n",CLGCODE(i),DEPTCODE(i));
  }
}

void Student::DisplayResults()
{
  int i;
  for(i=0;i<Listct;i++)
  {
    if(ALLOCATED(i)==true)
    {
      printf("\nYou have been allocated %d %d\n",CLGCODE(i),DEPTCODE(i));
      break;
    }
  }

  if(i==Listct)
  printf("\nYou have not been allocated any seat\n");
}
