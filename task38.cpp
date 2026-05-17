#include<iostream>
using namespace std;
int main(){
    int choice;
    while(true){
        cout<<"---Resturant Manegment system---"<<endl;
        cout<<"1. view food menu"<<endl;
        cout<<"2.  Place order"<<endl;
        cout<<"3.  View order status"<<endl;
        cout<<"4. Generate Bill"<<endl;
        cout<<"5. contact staff"<<endl;
        cout<<"6. Exit\n"<<endl;
        cout<<"Enter your choice:";
        cin>>choice;


        if(choice==1)
        cout<<"you selected: View Food Menu"<<endl;


        else if(choice==2)
        cout<<" you selected: place order"<<endl;


        else if(choice==3)
        cout<<"you selected: view order status"<<endl;


        else if(choice==4)
      cout<<"you selected : Generate Bill"<<endl;


      else if(choice==5)
      cout<<"you selected : contact staff"<<endl;

      
      else if(choice==6){
        cout<<"exiting resturant manegment system. Thank You!"<<endl;
        break;
      }
      else
          cout<<"Invalid Choice";
    }
}