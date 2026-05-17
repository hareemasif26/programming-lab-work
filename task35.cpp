#include<iostream>
using namespace std;
int main()
{
    int age,washingPrice,toyPrice;
    cout<<"enter lilly;s age:";
    cin>>age;
    cout<<"enter price of machine:";
    cin>>washingPrice;
    cout<<"enter price of each toy:";
    cin>>toyPrice;

    int toys = 0;
    int money = 0;
    int gift = 10;

    for(int i = 1; i<=age; i++){
        if(i % 2 == 0){
            money += gift ;
            money -= 1;
            gift += 10;
        }
        else{
            toys++;
        }
    }
    money += toys * toyPrice;
    if(money >= washingPrice)
  { cout<<"yes!"<<endl;
    cout<<money - washingPrice;
   }
    else
   { cout<<"No!"<<endl;
    cout<<washingPrice - money;
}


}