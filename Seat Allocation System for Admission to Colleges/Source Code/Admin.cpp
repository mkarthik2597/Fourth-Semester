#include<cstdio>
#include<cstring>

class Admin
{
  char usrname[10];
  char pwd[10];
public:
  friend void AdminAcessControl();
  void ExecuteAlgo();
  void SortRankBased();
  void DisplaySortedList();
  void AdminSpace();
};

Admin adm[3];
int Admcount;

void Admin::AdminSpace()
{
  repeat:
  printf("\n\n...Admin %s HomePage...\n\n",usrname);
  printf("Enter\n1 to run algorithm\n2 to sort student list\n3 to exit:");
  int i;
  scanf("%d",&i);

  switch(i)
  {
    case 1: ExecuteAlgo();
            break;
    case 2: SortRankBased();
            DisplaySortedList();
            break;
  }
  if(i!=3)
  goto repeat;
}

void Admin::ExecuteAlgo()
{
  SortRankBased();
  //printf("This is the sorted list:");
  //DisplaySortedList();

  for(int StI=0;StI<Stdcount;StI++)
  {  //printf("Student no %d\n",StI+1);
    for(int PLI=0;PLI<stdnt[StI].Listct;PLI++)
    { //printf("PLI no %d\n",PLI+1);
      for(int ClgI=0;ClgI<Clgcount;ClgI++)
      { //printf("Clg no %d\n",ClgI+1);
        if(clg[ClgI].code==stdnt[StI].CLGCODE(PLI))
        { //printf("College codes match..");
          for(int DeptI=0;DeptI<clg[ClgI].deptct;DeptI++)
          { //printf("Dept no %d\n",DeptI+1);
            if(clg[ClgI].depts[DeptI].Deptcode==stdnt[StI].DEPTCODE(PLI))
            { //printf("Department codes match..");
              if(clg[ClgI].depts[DeptI].VacGeneralSeats>0)
              {
                stdnt[StI].ALLOCATED(PLI)=true;
                //printf("%d has been allocated a seat\n",StI+1);
                clg[ClgI].depts[DeptI].VacGeneralSeats--;
                //printf("Going to next student..");
                //PLI=0;ClgI=0;DeptI=0;
                goto NextStI;
              }
              else if(stdnt[StI].quota==true && clg[ClgI].depts[DeptI].VacQuotaSeats>0)
              {
                stdnt[StI].ALLOCATED(PLI)=true;
                //printf("%d has been allocated a seat\n",StI);
                clg[ClgI].depts[DeptI].VacQuotaSeats--;
                //printf("Going to next student...");
                //PLI=0;ClgI=0;DeptI=0;
                goto NextStI;
              }
              //printf("Visiting next row..");
              goto NextPLI;
            }
          }
        }
      }
      NextPLI: ;
    }
    NextStI: ;
  }


  printf("\nResults are out.Check them out...\n\n");
}

void Admin::SortRankBased()
{
  Student temp;
  for(int pass=0;pass<Stdcount-1;pass++)
  for(int i=0;i<Stdcount-pass-1;i++)
  if(stdnt[i].rank>stdnt[i+1].rank)
  {
    temp=stdnt[i];
    stdnt[i]=stdnt[i+1];
    stdnt[i+1]=temp;
  }
}

void Admin::DisplaySortedList()
{
  for(int i=0;i<Stdcount;i++)
  printf("%d\n",stdnt[i].rank);
}
