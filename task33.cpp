#include <iostream>
using namespace std;
main()
{
int a,b,i,gcd;
cout<<"enter 1st number :";
cin>>a;
cout<<"enter 2nd number :";
cin>>b;
for(i = 1; i <= a && i <= b; i++)
{
    if(a % i == 0 && b % i ==0)
    {
        gcd = i;
    }
}
     cout << "GCD is : "   <<gcd << endl;
     cout << "LCM is : "   <<(a*b)/gcd;







}