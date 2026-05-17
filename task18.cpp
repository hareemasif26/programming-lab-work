<<<<<<< HEAD
=======
<<<<<<< HEAD
#include<iostream>
using namespace std;
main()
{
 int sum = 0;
 for(int i = 1; i<=5; i = i+1)
{
      sum = sum + i;
}
cout <<sum<<endl;
                                                                  
=======
>>>>>>> 17c9e8dfdd9ddacd33ebacab28c156f58b7e3ba5
#include<iostream>
using namespace std;
int main()
{
string name1,name2,name3;
int age1,age2,age3;
cout<<"enter name of first brother:";
cin>>name1;
cout<<"enter age of 1st brother:";
cin>>age1;
cout<<"enter name of 2nd brother:";
cin>>name2;
cout<<"enter age of 2nd brother:";
cin>>age2;
cout<<"enter name of 3rd brother:";
cin>>name3;
cout<<"enter age of 3rd brother:";
cin>>age3;
if(age1<=age2 && age1<=age3){
cout<<"youngest brother is :"<<name1;
}
if(age2<= age1 && age2<=age3){
cout<<"youngest brother is :"<<name2;
}
if(age3<= age1 && age3<=age2){
cout<<"youngest brother is :"<<name3;
}













<<<<<<< HEAD
=======
>>>>>>> 994ddb26077fd239a022c943e4ae29b8438a20d0
>>>>>>> 17c9e8dfdd9ddacd33ebacab28c156f58b7e3ba5
}