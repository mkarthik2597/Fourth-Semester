#include "BasePerson.cpp"
#include "book.cpp"

/*CustomerClass is inherited from PersonClass*/
class customerClass:public PersonClass
{
  int id;
  char mob[10];
  book borroweBooks[10];
  date Issue[10];
  date Return[10];
  int bookCount;
public:
  customerClass(char* name,char* email,char* mob,int id):PersonClass(name,email)
  {
    this->id=id;
    strcpy(this->mob,mob);
    bookCount = 0;
  }
  customerClass(){}
  void PrintCustomerDetails();
  friend void CustomerSpace();
  friend class FDClass;
  int getid();
  void SearchBooks();

};

customerClass* customer_ptr[20];
int Customerct=0;

/*Return customer ID*/
int customerClass::getid()
{
  return id;
}

/*Print customer related details*/
void customerClass::PrintCustomerDetails()
{
  cout<<"\n\t\t\t\t\t\t----------------------------------------\n";
  printPersonDetails();
  cout<<"\n\t\t\t\t\t\tMobile : "<<mob<<endl;
  cout<<"\n\t\t\t\t\t\tID : "<<id<<endl;
  cout<<"\n\t\t\t\t\t\tBorrowed Books are : \n";
  for(int i=0;i<bookCount;i++)
  {
      borroweBooks[i].PrintBookDetails();
      cout<<"\n\t\t\t\t\t\tIssue Date  : "<<Issue[i]<<"\n";
      cout<<"\n\t\t\t\t\t\tReturn Date : "<<Return[i]<<"\n";
  }
  cout<<"\n\t\t\t\t\t\t----------------------------------------\n";
}

/*Function to search books by author or by title*/
void customerClass::SearchBooks()
{
	cout<<"\n\t\t\t\t\t\tSearch by title-(0) or author-(1) ?\n\n\t\t\t\t\t\tEnter choice 0 or 1 : ";
	int choice;
	cin>>choice;
	int i;
	if(choice == 0){
		char tempName[25];
		cout<<"\n\n\t\t\t\t\t\tEnter name of book to search : ";
		cin>>tempName;
		for(i=0;i<Bookct;++i){
			if(strcmp(book_ptr[i]->getname(),tempName)==0){
				book_ptr[i]->PrintBookDetails();
				break;
			}
		}
		if(i==Bookct){
            cout<<"\n\n\t\t\t\t\t\tBook not Found\n";
        }
	}
	else if(choice == 1){
		char tempauthor[25];
		cout<<"\n\n\t\t\t\t\t\tEnter author of book to search : ";
		cin>>tempauthor;
		int found = 0;
		for(i=0;i<Bookct;++i){
			if(strcmp(book_ptr[i]->getauthor(),tempauthor)==0){
				book_ptr[i]->PrintBookDetails();
				found = 1;
			}
		}
		if(found == 0) {
            cout<<"\n\t\t\t\t\t\tBook not Found\n";
        }
	}
	else cout<<"\n\n\t\t\t\t\t\t\nInvaild choice\n";
}
