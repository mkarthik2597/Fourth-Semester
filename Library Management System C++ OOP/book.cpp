/*Class for storing all book related information*/
class book
{
  char name[25];
  char author[25];
  char ISBN[10];
  int NoCopies;
  float price;
public:
  book(){}
  void PrintBookDetails();
  char* getname();
  char* getauthor();
  char* getISBN();
  book(char*,char*,char*,float,int);
  friend class FDClass;
};

book* book_ptr[20];
int Bookct=0;

/*Parametrized constructor*/
book::book(char* name, char* author, char* ISBN, float price,int NoCopies)
{
  strcpy(this->name,name);
  strcpy(this->author,author);
  strcpy(this->ISBN,ISBN);
  this->price=price;
  this->NoCopies=NoCopies;
}

/*Print all details related to a book*/
void book::PrintBookDetails()
{
    cout<<"\n\n\t\t\t\t\t\t******************************\n";
    cout<<"\n\t\t\t\t\t\tName:"<<name<<endl;
    cout<<"\n\t\t\t\t\t\tAuthor:"<<author<<endl;
    cout<<"\n\t\t\t\t\t\tPrice:"<<price<<endl;
    cout<<"\n\t\t\t\t\t\tISBN:"<<ISBN<<endl;
    cout<<"\n\t\t\t\t\t\tTotal copies:"<<NoCopies<<endl;
    cout<<"\n";
}

/*Return book name*/
char* book::getname()
{
  return name;
}
/*Return book author*/
char* book::getauthor()
{
return author;
}
/*Return book ISBN*/
char* book::getISBN()
{
  return ISBN;
}
