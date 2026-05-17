#include<iostream>
using namespace std;
int main()
{
string moviename;
cout<<" enter the moviename:";
cin>>moviename;


int adultticketprice;
cout<<" enter adultticketprice in dollars($):";
cin>>adultticketprice;


int childticketprice;
cout<<" enter childticketprice in dollars($):";
cin>>childticketprice;


int childticketsold;
cout<<" enter childticketsold:";
cin>>childticketsold;


int adultticketsold;
cout<<"enter adultticketsold:";
cin>>adultticketsold;

int charitydonation;
cout<<"enter percentage(%) of charity:";
cin>>charitydonation;

int totalmoney = (adultticketsold*adultticketprice)+(childticketsold*childticketprice);

float charityamount = totalmoney*(charitydonation/100.0);

float remainingmoney = totalmoney-charityamount;

cout<<"moviename :"<<moviename;
cout<<"total money :"<<totalmoney;
cout<<"charity donation(%):"<<charityamount;
cout<<"remaining money:"<<remainingmoney;














































}