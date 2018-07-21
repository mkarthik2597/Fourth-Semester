void LibrarianAccessControl();
void CustomerSpace();
void FrontDeskAccessControl();
void LibrarianSignup();
void SearchBooks();

/*Template function for login of librarian and front-desk staff*/
template<class T>
int login(T** ptr,int count)
{
  cout<<"\n\n\t\t\t\t\t\tEnter your username(String):";
  char tempName[10];
  cin>>tempName;
  int i;
  for(i=0;i<count;i++)
  {
    if(strcmp(tempName,ptr[i]->usrname)==0)
    {
      cout<<"\n\t\t\t\t\t\tEnter password(String):";
      char tempPass[10];
      cin>>tempPass;

      if(strcmp(tempPass,ptr[i]->pass)==0)
      {
        cout<<"\n\n\t\t\t\t\t\tAccess granted\n";
        return i;
        break;
      }
      else
      {
        cout<<"\n\n\t\t\t\t\t\tWrong password!\n";
        return -1;
      }
    }
  }

  if(i==count)
  {
    cout<<"\n\n\t\t\t\t\t\tInvalid username!\n";
    return -1;
  }
}

/*Template function for signup of librarian and front-desk staff*/
template<class T>
void signup(T** ptr,int count)
{
  char name[10];
  char usrname[10];
  char pass[10];
  char email[10];

  cout<<"\n\n\t\t\t\t\t\tEnter you name(String):";
  cin>>name;
  cout<<"\n\t\t\t\t\t\tEnter your email-ID(String):";
  cin>>email;
  cout<<"\n\t\t\t\t\t\tChoose your username:";
  cin>>usrname;
  cout<<"\n\t\t\t\t\t\tEnter a password:";
  cin>>pass;

  ptr[count]=new T(name,email,usrname,pass);
}

/*Librarian login page*/
void LibrarianAccessControl()
{
  repeat:
  cout<<"\n\n\t\t\t\t\t\t...LibrarianLoginPage...\n\n";
  cout<<"\t\t\t\t\t\tEnter\n\n\t\t\t\t\t\t1 to login\n\n\t\t\t\t\t\t2 to exit:";
  int i;
  cin>>i;

  switch(i)
  {
    case 1: if(login(&librarian_ptr,1)>=0)
            librarian_ptr->LibrarianSpace();
  }
  if(i!=2)
  goto repeat;
}

/*Front desk login page*/
void FrontDeskAccessControl()
{
  repeat:
  cout<<"\n\n\t\t\t\t\t\t...FrontDeskLoginPage...\n\n";
  cout<<"\n\t\t\t\t\t\tEnter\n\n\t\t\t\t\t\t1 to login\n\n\t\t\t\t\t\t2 to signup\n\n\t\t\t\t\t\t3 to exit:";
  int i;
  cin>>i;

  int x;

  switch(i)
  {
     case 1: x=login(fd,FDcount);
             if(x>=0)
             fd[x]->FrontDeskSpace();
             break;

     case 2: signup(fd,FDcount);
             fd[FDcount]->FrontDeskSpace();
             FDcount++;

             break;
  }
  if(i!=3)
  goto repeat;
}

/*Customer entry page*/
void CustomerSpace()
{
  cout<<"\n\t\t\t\t\t\tEnter your customer ID(int):";
  int i,tempID;
  cin>>tempID;

  for(i=0;i<Customerct;i++)
  {
    if(customer_ptr[i]->getid()==tempID)  /*No need for getid*/
    {
      customer_ptr[i]->SearchBooks();
      break;
    }
  }
  if(i==Customerct)
  cout<<"\n\t\t\t\t\t\tYou have not yet registered yourself with the librarian\n";
}

/*Librarian Signup function*/
void LibrarianSignup()
{
  char name[10];
  char usrname[10];
  char pass[10];
  char email[30];
  //
  // cout<<"Enter your name:";
  // cin>>name;
  // cout<<"Enter your email-ID:";
  // cin>>email;
  // cout<<"Choose a username:";
  // cin>>usrname;
  // cout<<"Choose a password:";
  // cin>>pass;
  librarian_ptr=new libClass((char *)"jose",(char *)"jose@gmail.com",(char *)"jose",(char *)"qwerty");
}
