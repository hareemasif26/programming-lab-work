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

}






