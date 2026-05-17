#include<iostream>
using namespace std;
int main(){
    int correctPin = 1234;
    int pin[3];
    int choice;
    int attempts;
    int balance = 1000;
    int amount;
    bool login = false;
    for(int i = 0; i<3;i++)
    {
        cout<<"Enter ATM PIN:";
        cin>>pin[i];
        if(pin[i] == correctPin)
        {
           login = true;
           cout<<"Login Successful\n";
           break;
        }
        else
        {
            cout<<"Incorrect Pin\n";
        }
    }
    //if login successful
    if(login == true)
    {
        while(true)
        {
            cout<<"---ATM Menu---"<<endl;
            cout<<"1. Check Balance"<<endl;
            cout<<"2. Deposit money"<<endl;
            cout<<"3. Withdraw Menu"<<endl;
            cout<<"4. Exit"<<endl;
            cout<<"Enter your choice:"<<endl;
            cin>>choice;
            if(choice == 1)
            {
                cout<<"Current balance:"<<balance<<endl;
            }
            else if(choice == 2)
            {
                cout<<"Enter amount to deposit:";
                cin>>amount;
                balance = balance + amount;
                cout<<"Update balance:"<<balance<<endl;
            }
            else if(choice == 3)
            {
                cout<<"Enter amount to withdraw:";
                cin>>amount;
                if(amount<= balance && amount >0)
                {
                    balance = balance - amount;
                    cout<<"Remaining balance:"<<balance<<endl;
                }
                else
                {
                    cout<<"Insufficent Balance\n";
                }
            }
            else if(choice == 4)
            {
                cout<<"Thank You for using ATM";
                break;
            }
            else if(attempts <=3)
            {
                cout<<"Invalid choice";
            }
            else
            {
                cout<<"Too many incorrect attempts.Access Denied\n";
            }
        
        
    
}
    }
}