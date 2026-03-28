#include<iostream>
using namespace std;
int main(){
string countryName;
float discount,ticketPrice,finalPrice;
cout<<"enter the name of country :";
cin>>countryName;
cout<<"enter the ticket price(in dollars $):";
cin>>ticketPrice;
if(countryName =="ireland" )
{
discount = ticketPrice * 10/100;
}
else{
discount = ticketPrice * 5/100;
}
finalPrice = ticketPrice - discount;
cout<<"the final price price is :  "<<finalPrice;
}

