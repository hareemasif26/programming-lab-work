#include<iostream>
using namespace std;
int main()
{
string my_password,user_enter;
my_password = "pass@123!";
cout<<"enter the password:";
cin>>user_enter;
if(user_enter== my_password){
cout<<"wow! you have cracked the code!";
}
else{
cout<<"it is not that simple, try again!";
}
}




