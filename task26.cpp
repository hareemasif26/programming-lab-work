<<<<<<< HEAD
=======
<<<<<<< HEAD
#include<iostream>
using namespace std;
main()
{
    int sum = 0;
    for(int i = 10; i > 0; i-= 2){
        sum += i;
    }
    cout << sum;
=======
>>>>>>> 17c9e8dfdd9ddacd33ebacab28c156f58b7e3ba5
	#include <iostream>
using namespace std;

int main() {
    int num;
cout<<"enter number between 1 and 100 :";
cin>>num;
int num1 = num % 10;
int num2 = num / 10;
string t1 ="",t2="";
if(num1==0){t1="zero";}
if(num1==1){t1 ="one";}
if(num1==2){t1="two";}
if(num1==3){t1="three";}
if(num1==4){t1="four";}
if(num1==5){t1="five";}
if(num1==6){t1="six";}
if(num1==7){t1="seven";}
if(num1==8){t1="eight";}
if(num1==9){t1="nine";}


if(num== 10) cout<<"ten";
if(num==11) cout<<"eleven";
if(num==12)cout<<"twelve";
if(num==13) cout<<"thirteen";
if(num==14)cout<<"fourteen";
if(num==15)cout<<"fifteen";
if(num==16)cout<<"sixteen";
if(num==17)cout<<"seventeen";
if(num==18)cout<<"eighteen";
if(num==19)cout<<"ninteen";


if(num2==2){t2="twenty";}
if(num2==3){t2="thirty";}
if(num2==4){t2="fourty";}
if(num2==5){t2="fifty";}
if(num2==6){t2="sixty";}
if(num2==7){t2="seventy";}
if(num2==8){t2="eighty";}
if(num2==9){t2="ninty";}

if(num==100)
cout<<"hundred";
else
cout<<t2<<" "<<t1;
<<<<<<< HEAD
=======
>>>>>>> 994ddb26077fd239a022c943e4ae29b8438a20d0
>>>>>>> 17c9e8dfdd9ddacd33ebacab28c156f58b7e3ba5
}