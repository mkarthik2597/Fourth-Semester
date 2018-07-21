#include<cstdio>
#include<cstring>
#include "Department.cpp"

class College
{
  Department depts[15];
  int deptct;
  int code;
public:
  char name[20];
  void CollegeSpace();
  void RegisterDepts();
  void DisplayDepts();
  friend class Admin;
  friend void CollegeAccessControl();
};

College clg[10];
int Clgcount;

void College::RegisterDepts()
{
  printf("Enter the no. of departments in your college:");
  scanf("%d",&deptct);

  for(int i=0;i<deptct;i++)
  {
    printf("\nEnter department name:");
    scanf(" %s",depts[i].Deptname);
    printf("Enter department code(Integer):");
    scanf("%d",&depts[i].Deptcode);
    printf("Enter the number of quota seats and general seats:");
    scanf("%d%d",&depts[i].QuotaSeats,&depts[i].GeneralSeats);
    depts[i].VacQuotaSeats=depts[i].QuotaSeats;
    depts[i].VacGeneralSeats=depts[i].GeneralSeats;
  }
}

void College::CollegeSpace()
{
  repeat:
  printf("\n\n...College %s HomePage...\n\n",name);
  printf("Enter\n1 to go to a department\n2 to exit:");
  int i;
  scanf("%d",&i);

  switch(i)
  {
    case 1: printf("Enter department code(Integer):");
            int tempCode;
            scanf("%d",&tempCode);

            int i;
            for(i=0;i<deptct;i++)
            {
              if(depts[i].Deptcode==tempCode)
              {
                depts[i].DepartmentSpace();
                break;
              }
            }
            if(i==deptct)
            printf("Invalid department code!\n");
  }

  if(i!=2)
  goto repeat;
}

void College::DisplayDepts()
{
  printf("%s\n\n",name);
  for(int i=0;i<deptct;i++)
  {
    depts[i].ShowDetails();
  }
}
