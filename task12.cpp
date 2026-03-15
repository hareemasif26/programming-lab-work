#include<iostream>
using namespace std;
main()
{
    int i,j,rows;
    cout<<"Input number of rows :"<<endl;
    cin>>rows;
    for(i=1;i<=rows;i++)
    {
     for(j=1;j<=i;j++)
     cout<<"*";
     cout<<"\n";
    }


}