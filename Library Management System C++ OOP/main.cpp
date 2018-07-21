#include<bits/stdc++.h>
using namespace std;
int previous = 0;
#include "date.cpp"
#include "customer.cpp"
#include "Librarian.cpp"
#include "FrontDesk.cpp"
#include "login.cpp"

void setupCustomer(){
	cout<<"\n\t\t\t\t\t\tCustomer Records\n";
  int count = 0;
  ifstream is0("customer.txt",ios::binary);
  if(!is0){
    cout<<"\n\t\t\t\t\t\tcustomer count : "<<count<<endl;
  }
  else{
      while(!is0.eof()){
        customer_ptr[count] = new customerClass();
        is0.read(reinterpret_cast<char*>(customer_ptr[count]), sizeof(customerClass));
        if(is0.eof())
          break;
        previous = customer_ptr[count]->getid();
        ++count;
      }
  cout<<"\n\t\t\t\t\t\tcustomer count : "<<count<<endl;
  Customerct = count;
  }
}
void setupFD(){
	cout<<"\n\t\t\t\t\t\tFront Desk Records\n";
  int count = 0;
  ifstream is0("frontdesk.txt",ios::binary);
  if(!is0){
    cout<<"\n\t\t\t\t\t\tFront Desk count: "<<count<<endl;
  }
  else{
      while(!is0.eof()){
        fd[count] = new FDClass();
        is0.read(reinterpret_cast<char*>(fd[count]), sizeof(FDClass));
        if(is0.eof())
          break;
        ++count;
      }
  cout<<"\n\t\t\t\t\t\tFront Desk Count : "<<count<<endl;
  FDcount = count;
  }
}
void setupBook(){
	cout<<"\n\t\t\t\t\t\tBook Records\n";
  int count = 0;
  ifstream is0("book.txt",ios::binary);
  if(!is0){
    cout<<"\n\t\t\t\t\t\tbook count : "<<count<<endl;
  }
  else{
      while(!is0.eof()){
        book_ptr[count] = new book();
        is0.read(reinterpret_cast<char*>(book_ptr[count]), sizeof(book));
        if(is0.eof())
          break;
        ++count;
      }
  cout<<"\n\t\t\t\t\t\tbook count : "<<count<<endl;
  Bookct = count;
  }
}

int main()
{

  system("clear");

  cout<<"\n\n\t\t\t\t\t\tSystem is being set up...\n\n";

	/*Librarian should signup the first time he uses LibManager*/
  LibrarianSignup();
  cout<<"\n\n\t\t\t\t\t\tWelcome to the LibManager..\n\n";
  setupCustomer();
  setupBook();
  setupFD();
  int i;

	/*Primary Home Page of the system*/
  while(1)
	{
		cout<<"\n\n\t\t\t\t\t\t...PrimaryHomePage...\n\n";
		cout<<"\t\t\t\t\t\tEnter\n\n\t\t\t\t\t\t1 for librarian\n\n\t\t\t\t\t\t2 for customer\n\n\t\t\t\t\t\t3 for front-desk staff\n\n\t\t\t\t\t\t4 to exit:";
		cin>>i;
		switch(i)
		{
			case 1: LibrarianAccessControl();
							break;
			case 2: CustomerSpace();
							break;
			case 3: FrontDeskAccessControl();
					break;
			case 4 : exit(0);
			default: {cout<<"\n\n\t\t\t\t\t\tEnter valid option.\n";}
		}
  }
}
