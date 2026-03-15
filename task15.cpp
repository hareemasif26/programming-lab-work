<<<<<<< HEAD
#include<iostream>
using namespace std;
main()
{
      char choice = 'y';
      while(choice != 'N' && choice != 'n')
      {
         cout<<"I am happy !"<<endl;
         cout<<"enter your choice :";
         cin>>choice;

      }
=======
#include<iostream>
using namespace std;
int main()
{
int salary = 10000;
int laptopPrice = 50000;
int advanceSalary;
int monthRequired;
advanceSalary = salary * 0.5;
if(advanceSalary>= laptopPrice){
cout<<"ali can buy the laptop";
}
else{
monthRequired = laptopPrice/advanceSalary;
cout<<"months required to buy laptop :"<<monthRequired;
}




>>>>>>> 994ddb26077fd239a022c943e4ae29b8438a20d0
}