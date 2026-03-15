#include<iostream>
using namespace std;
int main()
{
float speed;
cout<<"enter the speed :";
cin>>speed;
if(speed == 10){
cout<<"slow";
}
if (speed>10 && speed <=50) {
cout<<"average";
}
if(speed>50 && speed <=150){
cout<<"fast";
}
if(speed>150 && speed<=1000){
cout<<"ultra fast";
}
if(speed>1000){
cout<<"extremely fast";
}













}