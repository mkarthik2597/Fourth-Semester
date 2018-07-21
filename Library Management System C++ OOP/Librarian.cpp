#include<cstdio>

void writeRecordsCustomers()
{
  int i;
  ofstream os("customer.txt",ios::out|ios::trunc|ios::binary);//Open file in binary mode.
 	for(i=0;i<Customerct;++i)
    os.write(reinterpret_cast<char*>(customer_ptr[i]), sizeof(customerClass));
}

void writeRecordsBooks()
{
  int i;
  ofstream os("book.txt",ios::out|ios::trunc|ios::binary);//Open file in binary mode.
 	for(i=0;i<Bookct;++i)
    os.write(reinterpret_cast<char*>(book_ptr[i]), sizeof(book));
}

class libClass:public PersonClass
{
  char usrname[15];
  char pass[15];
public:
  libClass(char* name,char* email,char* usrname, char* pass):PersonClass(name,email)
  {
    strcpy(this->usrname,usrname);
    strcpy(this->pass,pass);
    //cout<<getname()<<" "<<getemail()<<" "<<usrname<<pass<<endl;
  }
  void LibrarianSpace();
  friend void LibrarianAccessControl();
  void AddBooks();
  void ViewAllBooks();
  void AddCustomer();
  void ViewAllCustomers();
  void RemoveCustomer();
  void copyCustomer(int,int);
  void copyBook(int,int);
  void RemoveBook();

  template<class T>
  friend int login(T** ptr,int count);

  template<class T>
  friend void signup(T** ptr,int count);
};

libClass* librarian_ptr;

/*Helper function for removing customer*/
void libClass::copyCustomer(int a1,int a2){
  customer_ptr[a1] = customer_ptr[a2];
}
/*Helper function for removing customer*/
void libClass::copyBook(int a1,int a2){
  book_ptr[a1] = book_ptr[a2];
}

/*Main function for librarian which invokes other functions*/
void libClass::LibrarianSpace()
{
  repeat:
  cout<<"\n\n\t\t\t\t\t\tEnter\n\n\t\t\t\t\t\t1 to add books to library\n\n\t\t\t\t\t\t2 to add customers\n\n\t\t\t\t\t\t3 to view all book details";
  cout<<"\n\n\t\t\t\t\t\t4 to remove customer\n\n\t\t\t\t\t\t5 to remove book\n\n\t\t\t\t\t\t6 to View customers\n\n\t\t\t\t\t\t7 to exit:";
  int i;
  cin>>i;

  switch(i)
  {
    case 1: AddBooks();
            break;
    case 2: AddCustomer();
            break;
    case 3: ViewAllBooks();
            break;
    case 4: RemoveCustomer();
            break;
    case 5: RemoveBook();
            break;
    case 6: ViewAllCustomers();
            break;
  }
  if(i!=7)
  goto repeat;
}

/*Add books to library*/
void libClass::AddBooks()
{
  char name[25];
  char author[25];
  char ISBN[25];
  float price;
  int NoCopies;

  cout<<"\n\n\t\t\t\t\t\tEnter title:";
  cin>>name;
  cout<<"\n\n\t\t\t\t\t\tEnter author:";
  cin>>author;
  cout<<"\n\n\t\t\t\t\t\tEnter ISBN:";
  cin>>ISBN;
  cout<<"\n\n\t\t\t\t\t\tEnter price:";
  cin>>price;
  cout<<"\n\n\t\t\t\t\t\tEnter number of copies:";
  cin>>NoCopies;

  book_ptr[Bookct]=new book(name,author,ISBN,price,NoCopies);
  Bookct++;
  writeRecordsBooks();

  cout<<"\n\t\t\t\t\t\tBook details have been stored successfully\n";
}

/*View all books in library*/
void libClass::ViewAllBooks()
{
  for(int i=0;i<Bookct;i++)
  book_ptr[i]->PrintBookDetails();
}

/*Add customers to library*/
void libClass::AddCustomer()
{
  char name[10];
  char mob[10];
  char email[30];

  cout<<"\n\n\t\t\t\t\t\tEnter customer name(String):";
  cin>>name;
  cout<<"\n\t\t\t\t\t\tEnter your email-ID(String):";
  cin>>email;
  cout<<"\n\t\t\t\t\t\tEnter your mobile no:";
  cin>>mob;

  customer_ptr[Customerct]=new customerClass(name,email,mob,previous+1);
  cout<<"\n\n\t\t\t\t\t\tCustomer ID generated : "<<previous+1<<"\n";
  Customerct++;
  previous++;
  writeRecordsCustomers();
}

/*List all customers registered with library*/
void libClass::ViewAllCustomers(){
  int i;
  for(i=0;i<Customerct;++i){
    customer_ptr[i]->PrintCustomerDetails();
  }
}

/*Remove customer from library*/
void libClass::RemoveCustomer()
{
  int key,i;
  cout<<"\n\n\t\t\t\t\t\tEnter id of customer to remove : ";
  cin>>key;
  int j;
  for(i=0;i<Customerct;++i)
  {
    if(customer_ptr[i]->getid() == key)
    {
        delete customer_ptr[i];
        cout<<"\n\n\t\t\t\t\t\tFound and Deleted\n";
        for(j=i+1;j<Customerct;++j)
        {
          copyCustomer(j-1,j);
        }
        --Customerct;
    }
  }
  writeRecordsCustomers();
}

/*Remove book from library*/
void libClass::RemoveBook()
{
  char key[25];
  int i;
  cout<<"\n\n\t\t\t\t\t\tEnter ISBN of book to remove : ";
  cin>>key;
  int j;
  for(i=0;i<Bookct;++i)
  {
    if(strcmp(book_ptr[i]->getISBN(),key) == 0)
    {
        delete book_ptr[i];
        cout<<"\n\n\t\t\t\t\t\tFound and Deleted\n";
        for(j=i+1;j<Bookct;++j)
        {
          copyBook(j-1,j);
        }
        --Bookct;
    }
  }
  writeRecordsBooks();
}
