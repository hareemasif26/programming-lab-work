#include<iostream>
using namespace std;
int main()
{
    int choice;
    string book;
    while(true){
        cout<<"---Library System----"<<endl;
        cout<<"1. Add Book"<<endl;
        cout<<"2. View Book"<<endl;
        cout<<"3. Borrow Book"<<endl;
        cout<<"4. Issue Book"<<endl;
        cout<<"5. Exit"<<endl;

        cout<<"Enter your Choice:";
        cin>>choice;
        if(choice==1){
            cout<<"Enter book Name:"<<endl;
            cin>>book;
            cout<<"You added a book:"<<book;
        }
        else if(choice==2)
        cout<<"Viewing Books..."<<endl;
        else if (choice==3)
        cout<<"Borrowing Books..."<<endl;
        else if(choice==4)
        cout<<"Issuing Books..."<<endl;
        else if(choice==5){
        cout<<"Exiting Library system...Goodbye!"<<endl;
        break;
    }
else
    cout<<"Invalid choice";
}

}