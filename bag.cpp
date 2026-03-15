#include<iostream>
using namespace std;
int main()
{
int weight,cost,area;
float pricePerpound,pricePersquarefoot;
cout<<" enter weight of fertilizer bag:";
cin>>weight;
cout<<"enter cost of bags:";
cin>>cost;
cout<<" enter area of bag can cover:";
cin>>area;
pricePerpound = cost / weight;
pricePersquarefoot = cost / area;
cout<<"price of fertilizer per pound :$"<<pricePerpound;
cout<<" price of fertilizer per square foot:$"<<pricePersquarefoot;


















































}