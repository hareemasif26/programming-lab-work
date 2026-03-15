#include<iostream>
using namespace std;
int main()
{
 string username, password;
 string studentName = "";
 int studentAge = 0;
 string courseName = "";
  int choice;

  for(int i = 1; i <=3; i++)
  {
      cout<<"enter username :";
      cin>>username;

      cout<<"enter password :";
      cin>>password;

      if(username == "admin" && password == "1234")
      {
          cout<<"login succesful"<<endl;
          break;
      }
 else
 {
       cout<<"wrong login"<<endl;
 }
   if(i == 3 &&  username == "admin" && password == "1234")
    {
      cout<<" Too many attemts.Program Ends."<<endl;
    }

  }
    for(int i = 1; i<= 5; i++)
    {
        cout<< endl<<"----University Managment System----"<<endl;
        cout<<"1. Add Student"<<endl;
        cout<<"2. View Student"<<endl;
        cout<<"3. Add Course"<<endl;
        cout<<"4.  Exit" <<endl;

        cout<<"Enter Choice :";
        cin>>choice;

        if(choice == 1)
        {
            cout<<"enter student name:";
            cin>>studentName;
            cout<<"enter student age :";
            cin>>studentAge;
            cout<<"student added succesfully"<<endl;
        }
        else if(choice == 2)
        {
            if(studentName !="")
            {
                cout<<"student name:"<<studentName<<endl;
                cout<<"student age:"<<studentAge<<endl;
            }
            else
            {
                cout<<"No student record found"<<endl;
            }
        }
        else if(choice==3)
        {
            cout<<"enter course name:";
            cin>>courseName;
            cout<<"course added:"<<courseName<<endl;
        }
        else if(choice == 4)
        {
            cout<<"program Exit"<<endl;
            break;
        }
        else
        {
            cout<<"invalid choice"<<endl;
        }
    }




   }