#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter how many numbers you want to enter : ";
    cin>>n;
    int numbers[n];
    for(int i = 0; i < n; i++)
    {
        cout<<"enter number :";
        cin>>numbers[i];
    }
    cout<<"Numbers stored in arrays are :";
    for(int i = 0; i < n; i++)
    {
        cout<<numbers[i]<<" ";
    }
}