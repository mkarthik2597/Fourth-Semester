class College;
class Admin;

class Department
{
  char Deptname[20];
  int Deptcode;
  int QuotaSeats,GeneralSeats;
  int VacQuotaSeats,VacGeneralSeats;
public:
  void ChangeSeatNos();
  void EditPrimary();
  void DepartmentSpace();
  void ShowDetails();
  friend College;
  friend Admin;
};

void Department::ChangeSeatNos()
{
  repeat:
  printf("\n\n...Department %s HomePage...\n\n",Deptname);
  printf("Enter\n1 to change QuotaSeats\n2 to change GeneralSeats\n3 to exit:");
  int i;
  scanf("%d",&i);

  switch(i)
  {
    case 1: printf("The current QuotaSeats no is %d\n",QuotaSeats);
            printf("Enter new number:");
            scanf("%d",&QuotaSeats);
            VacQuotaSeats=QuotaSeats;
            printf("%d Updated\n",QuotaSeats);
            break;

    case 2: printf("The current GeneralSeats no is %d\n",GeneralSeats);
            printf("Enter new number:");
            scanf("%d",&GeneralSeats);
            VacGeneralSeats=GeneralSeats;
            printf("%d Updated\n",GeneralSeats);
  }

  if(i!=3)
  goto repeat;
}

void Department::DepartmentSpace()
{
  repeat:
  printf("Enter\n1 to change seat numbers\n2 to edit Dept name and Dept code\n3 to exit:");
  int i;
  scanf("%d",&i);
  switch(i)
  {
    case 1: ChangeSeatNos();
            break;
    case 2: EditPrimary();
            break;
  }
  if(i!=3)
  goto repeat;
}

void Department::EditPrimary()
{
  repeat:
  printf("Enter\n1 to change department name\n2 to change department code\n3 to exit:");
  int i;
  scanf("%d",&i);
  switch(i)
  {
    case 1: printf("Old department name is %s\n",Deptname);
            printf("Enter new department name:");
            scanf(" %s",Deptname);
            printf("Updated\n");
            break;

    case 2: printf("Old department code is %d\n",Deptcode);
            printf("Enter new department code(Integer):");
            scanf("%d",&Deptcode);
            printf("Updated\n");
  }
  if(i!=3)
  goto repeat;
}

void Department::ShowDetails()
{
  printf("%s\n",Deptname);
  printf("Quota seats=%d\nGeneral seats=%d\n\n",QuotaSeats,GeneralSeats);
}
