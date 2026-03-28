#include<iostream>
using namespace std;
main()
{
  double money;
  int year;
  cout<<"enter money:";
  cin>>money;
  cout<<"enter year:";
  cin>>year;

  double neededMoney = 0;
  int age = 18;
  for(int i = 1800; i<= year; i++)
{
    if(i % 2 == 0)
    {
        neededMoney += 12000;
    }
    else
    {
        neededMoney += 12000 + 50 * age;
    }
    age++;
}
if(money >= neededMoney)
{
    cout<<"yes! He will live a carefree life and will have"<<money - neededMoney  << "dollars left" ;
}
else{
 cout<<"he will need "<<neededMoney - money<<    "dollars to survive";
}
}