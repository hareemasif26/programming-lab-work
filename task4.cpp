<<<<<<< HEAD
#include<iostream>
using namespace std;
int main() {
int n, count = 0;
cout <<"enter number :";
cin>> n;
for(int i = n; i > 0; i =i /10){
count = count +1;
}
cout<<"total number of digits :"<<count;




=======
#include<iostream>
using namespace std;
int main(){
int cost;
cout<<"enter the cost of dress:";
cin>>cost;
if(cost>1500){
 cout<<"buy the dress"; 
}
if(cost<1500){
cout<<"do not buy the dress";
}


>>>>>>> 994ddb26077fd239a022c943e4ae29b8438a20d0
}