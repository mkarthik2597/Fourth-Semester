void CollegeAccessControl();
void StudentAcessControl();
void AdminAcessControl();

void CollegeAccessControl()
{
  repeat:
  printf("\n...CollegeLoginPage...\n\n");
  printf("Enter\n1 to login\n2 to register\n3 to exit:");
  int i;
  scanf("%d",&i);

  switch(i)
  {
    case 1: printf("\nEnter your college name(String):");
            char tempName[20];
            scanf(" %s",tempName);

            int i;
            for(i=0;i<Clgcount;i++)
            {
              if(strcmp(tempName,clg[i].name)==0)
              {
                printf("Enter college code(Integer):");
                int tempCode;
                scanf("%d",&tempCode);

                if(tempCode==clg[i].code)
                {
                  printf("\nAccess granted\n:");
                  clg[i].CollegeSpace();
                  break;
                }
                else
                {
                  printf("Wrong password!\n");
                  break;
                }
              }
            }

            if(i==Clgcount)
            printf("\nInvalid college name  !\n");

            break;

     case 2: printf("\nEnter your college name(String):");
             scanf(" %s",clg[Clgcount].name);
             printf("Enter your college code(Integer):");
             scanf(" %d",&clg[Clgcount].code);

             clg[Clgcount].RegisterDepts();
             clg[Clgcount].CollegeSpace();
             Clgcount++;
             break;
  }
  if(i!=3)
  goto repeat;
}

void StudentAcessControl()
{
  repeat:
  printf("\n...StudentLoginPage...\n\n");
  printf("Enter\n1 to login\n2 to signup\n3 to exit:");
  int i;
  scanf("%d",&i);

  switch(i)
  {
    //Tested
    case 1: printf("\nEnter your roll no(String):");
            char tempRoll[10];
            scanf(" %s",tempRoll);
            int i;
            for(i=0;i<Stdcount;i++)
            {
              if(strcmp(tempRoll,stdnt[i].roll)==0)
              {
                printf("Enter password(String):");
                char tempPass[10];
                scanf(" %s",tempPass);

                if(strcmp(tempPass,stdnt[i].pass)==0)
                {
                  printf("\nAccess granted\n");
                  stdnt[i].StudentSpace();
                  break;
                }
                else
                {
                  printf("\nWrong password!\n");
                  break;
                }
              }
            }

            if(i==Stdcount)
            printf("\nInvalid Roll no!\n");

            break;

  //Tested
     case 2: printf("\nEnter you roll number(String):");
             scanf(" %s",stdnt[Stdcount].roll);
             printf("Enter your password(String):");
             scanf(" %s",stdnt[Stdcount].pass);
             printf("Enter your rank(Integer):");
             scanf("%d",&stdnt[Stdcount].rank);
             printf("Enter 1 if you have a quota, else 0:");
             scanf("%d",&stdnt[Stdcount].quota);

             stdnt[Stdcount].StudentSpace();
             Stdcount++;

             break;
  }
  if(i!=3)
  goto repeat;
}

void AdminAcessControl()
{
  repeat:
  printf("\n...AdminLoginPage...\n\n");
  printf("Enter\n1 to login\n2 to signup\n3 to exit:");
  int i;
  scanf("%d",&i);

  switch(i)
  {
    case 1: printf("\nEnter your username(String):");
            char tempUsr[10];
            scanf(" %s",tempUsr);

            int i;
            for(i=0;i<Admcount;i++)
            {
              if(strcmp(tempUsr,adm[i].usrname)==0)
              {
                printf("Enter password(String):");
                char tempPwd[10];
                scanf(" %s",tempPwd);

                if(strcmp(tempPwd,adm[i].pwd)==0)
                {
                  printf("\nAccess granted\n");
                  adm[i].AdminSpace();
                  break;
                }
                else
                {
                  printf("\nWrong password!\n");
                  break;
                }
              }
            }

            if(i==Admcount)
            printf("\nInvalid user name!\n");

            break;

     case 2: printf("\nEnter your user name(String):");
             scanf(" %s",adm[Admcount].usrname);
             printf("Enter your password(String):");
             scanf(" %s",adm[Admcount].pwd);

             adm[Admcount].AdminSpace();
             Admcount++;

             break;
  }
  if(i!=3)
  goto repeat;
}
