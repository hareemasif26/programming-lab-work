#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter number of flights:";
    cin>>n;
    int flightNumber[n];
    string destination[n];
    int seatsAvailable[n];
    for(int i = 0; i < n; i++){
        cout<<"Enter flight number :"<<i + 1<<" "<<endl;
        cin>>flightNumber[i];
        cout<<"Enter desination :"<<flightNumber[i]<<""<<endl;
        cin>>destination[i];
        cout<<"Enter seats available :"<<flightNumber[i]<<" "<<endl;
        cin>>seatsAvailable[i];
    }
    cout<<"Flight Information:";
    cout<<"---------------------";
    for(int i = 0; i < n; i++){
        cout<<"Flight"<<flightNumber[i] <<"to"<<destination[i]<<"has"<<seatsAvailable[i]<<"seats available..."<<endl;
    }
    cout<<"flightsnwith less than 5 seats available:"<<endl;
    cout<<"-------------------------------";
    bool found = false;
    for(int i = 0; i < n; i++){
        if(seatsAvailable[i]<5){
            cout<<"Flight"<<flightNumber[i] <<"to"<<destination[i]<<"has only"<<seatsAvailable[i]<<"seats left!"<<endl;
            found = true;
        }
    }if(found){
        cout<<"No flights with less than 5 seats available"<<endl;
    }
}