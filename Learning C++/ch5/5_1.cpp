#include<iostream>
using namespace std;

class BankAc
{
  char name[20];
  char ac[20];
  char type;
  float balance;
public:
  void getdata(void)
  {
  //   cout<<"Name:\n";
  //   cin>>name;
  //   cout<<"ACno\n";
  //   cin>>ac;
  //   cout<<"AC type\n";
  //   cin>>type;
    cout<<"Balance\n";
    cin>>balance;

    display();
  }

  void display(void)
  {
    cout<<name<<endl<<ac<<endl<<type<<endl<<balance<<endl;
  }

  void deposit(float amount)
  {
    balance+=amount;
    cout<<balance<<endl;
  }

  void withdraw(float amount)
  {
    if(balance>=amount)
    {
      balance-=amount;
      cout<<balance;
    }

    else
    cout<<"Balance is:"<<balance;
  }

  void add2ac(BankAc ac1)
  {
    cout<<balance+ac1.balance<<endl;
  }
};


// void add2ac(BankAc ac1, BankAc ac2)
// {
//   cout<<ac1.balance+ac2.balance<<endl;
// }
//


int main()
{
  BankAc arr[2];
  for(int i=0;i<2;i++)
  arr[i].getdata();

  arr[0].add2ac(arr[1]);

}
