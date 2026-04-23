#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter number of products:";
    cin>>n;
    string productNames[n];
    double prices[n];
    int quantity[n];
    for(int i = 0; i < n; i++){
        cout<<"enter names of product" << i + 1 << " ";
        cin>>productNames[i];
        cout<<"Enter price of" << productNames[i] <<" ";
        cin>> prices[i];
        cout<<"Enter quantity of" << productNames[i] <<" ";
        cin >> quantity[i];
    }
    cout<<"Product Inventory report";
    cout<<"---------------------------------------";
    for(int i = 0; i < n; i++)
    {
        double totalValue = prices[i] * quantity[i];
        cout<< productNames[i] <<":$"<<fixed<<prices[i] <<" "<<quantity[i]<<"In stock, Total value:$"<<totalValue<<endl;
    }
}