#include<iostream>
using namespace std;
int main()
{
  int num;
  int sum = 0;

while(num>=0)
{
    cout<<"enter a number :";
    cin>>num;
    if(num<0)
    {
        break;
    }
    sum = sum + num;
}
    cout<<"total sum = "<<sum;
}