<<<<<<< HEAD
=======
<<<<<<< HEAD
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
=======
>>>>>>> 17c9e8dfdd9ddacd33ebacab28c156f58b7e3ba5
#include<iostream>
using namespace std;
int main()
{
int num1,num2;
char op;
cout<<"welcome to calculator"<<endl;
cout<<"enter 1st number:";
cin>>num1;
cout<<"enter the operator:";
cin>>op;
cout<<"enter 2nd number:";
cin>>num2;
if(op=='+'){
cout<<num2<<"-"<< num1<< "="<<num2-num1;
}
 if(op=='-'){
cout<<num2<<"+"<<num1<<"="<<num2 +num1;
}
if(op=='*'){
cout<<num2<<"/"<<num1<<"="<<num2 / num1;
}
if(op=='/'){
    cout<<num2<<"*"<<num2<<"="<<num2 * num1;
}











<<<<<<< HEAD
=======
>>>>>>> 994ddb26077fd239a022c943e4ae29b8438a20d0
>>>>>>> 17c9e8dfdd9ddacd33ebacab28c156f58b7e3ba5
}