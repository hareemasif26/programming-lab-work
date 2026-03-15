#include<iostream>
using namespace std;
int main()
{
float discount,bill,finalBill;
cout<<"enter the bill:";
cin>>bill;
if (bill>5000){
discount = bill * 0.10;
}
else{
discount = bill * 0.05;
}
finalBill = bill - discount;
cout<<"your discounted bill is :"<<finalBill;


}



