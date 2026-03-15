<<<<<<< HEAD
=======
<<<<<<< HEAD
#include<iostream>
using namespace std;
int main(){
int sum = 0;
for (int i =1; i<=5; i++){
    sum += i;

}

cout <<sum;

=======
>>>>>>> 17c9e8dfdd9ddacd33ebacab28c156f58b7e3ba5
#include<iostream>
using namespace std;
int main(){
int redRoses,whiteRoses,tulips;
double discount,price,payableAmount;
cout<<"enter number of red roses:";
cin>>redRoses;
cout<<"enter number of white roses:";
cin>>whiteRoses;
cout<<"enter number of tulips:";
cin>>tulips;
price = (redRoses * 2.0 )+ (whiteRoses * 4.10) + (tulips * 2.50);
if(price >200){
discount = price * 20/100;
payableAmount = price - discount;
cout<<"the price of flowers is : "<<price;
cout<<"price after discout is : "<<payableAmount;
}






<<<<<<< HEAD
=======
>>>>>>> 994ddb26077fd239a022c943e4ae29b8438a20d0
>>>>>>> 17c9e8dfdd9ddacd33ebacab28c156f58b7e3ba5
}