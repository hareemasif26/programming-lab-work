<<<<<<< HEAD
#include<iostream>
using namespace std;
int main()
{
    int sum = 0;
    for(int i = 1; i <=100; i++)
    {
        sum = sum + i;
    }
    cout<<"sum of natural numbers ="<<sum;
}
=======
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

>>>>>>> 994ddb26077fd239a022c943e4ae29b8438a20d0
