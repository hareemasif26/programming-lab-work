<<<<<<< HEAD
#include<iostream>
using namespace std;
main () 
{
int value;
cout<<"please enter a positive number:";
cin>>value;
while(value<=0)
{
cout<<"error :"<<  value  <<  "is not a positive number."<<endl;
cout<<"please enter a positive number:";
cin>>value;
}
cout<<"program ends" <<endl;







=======
#include<iostream>
using namespace std;
int main()
{
string name;
cout<<"please enter your name:";
cin>>name;
if(name=="ali"){
cout<<"welcome "<<name;
}
if(name!="ali"){
cout<<"try again!";
}

>>>>>>> 994ddb26077fd239a022c943e4ae29b8438a20d0
}