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
}