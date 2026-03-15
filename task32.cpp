#include <iostream>
using namespace std;
int main()
{
long num;
int dig,endDigit,count =0;
cout<<"enter a number :";
cin>>num;
cout<<"enter digit:";
cin>>dig;
while(num >0)
{
endDigit = num % 10;
if(endDigit == dig)
{
    count++;
}
num = num / 10;

}
 cout<<"frequency of "<<dig<<"is : "<<count<<endl;

}