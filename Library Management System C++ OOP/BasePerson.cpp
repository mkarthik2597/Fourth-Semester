#include<cstring>
#include<iostream>
using namespace std;

/*PersonClass is a base class from which Front-desk help, customer and librarian classes
  are derived*/
class PersonClass
{
public:
  char name[20];
  char email[30];
  PersonClass(char* name, char* email)
  {
    strcpy(this->name,name);
    strcpy(this->email,email);
  }
  PersonClass(){}
  void printPersonDetails();
  char* getname();
  char* getemail();
};

/*Returns Person name*/
char* PersonClass::getname()
{
  return name;
}

/*Returns Person email-ID*/
char* PersonClass::getemail()
{
  return email;
}

/*Print name and email of Person*/
void PersonClass::printPersonDetails()
{
  cout<<"\n\t\t\t\t\t\tName : "<<name<<endl;
  cout<<"\n\t\t\t\t\t\tEmail : "<<email<<endl;
}
