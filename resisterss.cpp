#include<iostream>
using namespace std;
float calculateTotalresistance(float arr[] ,int size)
{
    float total = 0;
    for(int i = 0; i < size; i++)
    {
        total = total + arr[i];
    }
    return total;
}
int main(){
int n;
cout<<"enter the number of resistors in the series circuit:";
cin>>n;
float resistors[n];
cout<<"Enter the resistance values of the"<<n<<"resistors,one per line:"<<endl;
for(int i = 0; i < n; i++)
{
    cin>>resistors[i];
}
 float total = calculateTotalresistance(resistors,n);
 cout<<"The total resistance of the series circuit is"<<total<<"ohms";
}