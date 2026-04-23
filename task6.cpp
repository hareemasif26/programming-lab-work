<<<<<<< HEAD
=======
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
>>>>>>> 17c9e8dfdd9ddacd33ebacab28c156f58b7e3ba5
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
<<<<<<< HEAD
=======
>>>>>>> 994ddb26077fd239a022c943e4ae29b8438a20d0
>>>>>>> 17c9e8dfdd9ddacd33ebacab28c156f58b7e3ba5
}