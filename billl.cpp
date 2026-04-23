#include<iostream>
using namespace std;
int main()
{
    int quarter,dime,nickel,pennies;
    float amount;
    cout<<"Enter quarter:";
    cin>>quarter;
    cout<<"Enter dime:";
    cin>>dime;
    cout<<"enter nickel:";
    cin>>nickel;
    cout<<"Enter pennies:";
    cin>>pennies;
    cout<<"Enter the due amount:";
    cin>>amount;
    float total = (quarter * 0.25) + (dime * 0.10) + (nickel * 0.05) + (pennies * 0.01);
    if(total>= amount){
        cout<<" Can you pay the amount? Yes!";
    }
    else
    cout<<"Can you pay the amount? nope!";
}