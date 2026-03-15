#include<iostream>
using namespace std;
int main(){
int redRoses,whiteRoses,tulips;
double discount,price,payableAmount;
cout<<"enter number of red roses:";
cin>>redRoses;
cout<<"enter number of white roses:";
cin>>whiteRoses;
cout<<"enter number of tulips:";
cin>>tulips;
price = (redRoses * 2.0 )+ (whiteRoses * 4.10) + (tulips * 2.50);
if(price >200){
discount = price * 20/100;
payableAmount = price - discount;
cout<<"the price of flowers is : "<<price;
cout<<"price after discout is : "<<payableAmount;
}






}