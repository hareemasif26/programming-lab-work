#include<iostream>
using namespace std;
int main()
{
    int n, count = 0;
    cout<<"enter number of customers:";
    cin>>n;

    string customers[n];
    cout<<"Enter the names of " << n << "customers:"<<endl;
    for(int i = 0; i < n; i++)
    {
        cin >> customers[i];
    }
    char letter;
    cout <<"enter a letter to check :";
    cin>>letter;
    for(int i = 0; i < n; i++)
    {
        if(customers[i][0] == letter)
        {
            count++;
        }
    }
    cout<<"Total names starting with "<<letter<<" "<<count<<endl;
}