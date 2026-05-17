#include<iostream>
using namespace std;
main(){
    while(true){
    int choice;

    cout<<"\n--------menu-------" <<endl;
    cout<<"1. Say hello" <<endl;
    cout<<"2. Say Goodbye"<<endl;
    cout<<"3. Exit" <<endl;
    cout<<"enter your choice:";
    cin>>choice;
    if(choice== 1){
        cout<<"Hello! Welcome to program"<<endl;
    }
     else if(choice == 2){
        cout<<"Goodbye! Have a nice day."<<endl;
     }
     else if(choice==3){
        cout<<"Program ended."<<endl;
        break;
     }
     else{
        cout<<"Invalid choice!"<<endl;
     }
    }
}