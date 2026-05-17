#include<iostream>
using namespace std;
int main(){
int choice;
double a,b;
while(true){
    cout<<"----Simple Calculator----"<<endl;
    cout<<"1. Addition"<<endl;
    cout<<"2. substraction"<<endl;
    cout<<"3. Multiplication"<<endl;
    cout<<"4. Division"<<endl;
    cout<<"5. clear screen"<<endl;
    cout<<"6. Exit"<<endl;
    cout<<"enter your choice:";
    cin>>choice;
    if(choice>=1 && choice <=4){
        cout<<"enter first number :";
        cin>>a;
        cout<<"enter 2nd number :";
        cin>>b;
    }
    if(choice==1)
    cout<<"result :"<<a+b;
    else if(choice==2)
    cout<<"result :"<<a-b;
    else if(choice==3)
    cout<<"result :"<<a * b<<endl;
    else if (choice==4){
    if(b==0)
    cout<<"divison by zero not allowed";
    else 
    cout<<"result :"<<a/b;
}
else if (choice==5){
    cout<<"Exiting calculator GoodBye!";
    break;
}
else

cout<<"Invalid choice";

}


}




