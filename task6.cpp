<<<<<<< HEAD
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

=======
#include<iostream>
using namespace std;
int main(){
 char going;
 cout<<"are your friends going?(press Y for yes N for no:)";
 cin>>going;
 if(going=='y')  {
cout<<"you are also going!";
 }
 if(going=='n'){
cout<<"you are not going!";
 }
>>>>>>> 994ddb26077fd239a022c943e4ae29b8438a20d0
}