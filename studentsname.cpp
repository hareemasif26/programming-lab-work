#include<iostream>
using namespace std;
int main()
{
    string students[5];

    cout<<"enter names of 5 students:"<<endl;
    for(int i = 0; i < 5; i++)
    {
        cin>>students[i];
    }
    cout<<"student names are:"<<endl;
    for(int i = 0; i < 5; i++)
    {
        cout << students[i] << endl;
    }
}