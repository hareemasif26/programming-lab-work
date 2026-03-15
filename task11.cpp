<<<<<<< HEAD
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







=======
#include<iostream>
using namespace std;
int main()
{
int number1,number2;
cout<<"enter the number:";
cin>>number1;
cout<<"enter the number:";
cin>>number2;
if(number1<number2){
cout<<"number"<<number2<<"is greater than"<<number1;
}
else{
cout<<"number"<<number1<<"is greater than"<<number2;
}




>>>>>>> 994ddb26077fd239a022c943e4ae29b8438a20d0
}