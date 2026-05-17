#include<iostream>
using namespace std;
int main()     
{
  string username, usernames[3];
  int password;
  int loginSuccess = 0;
  for(int i = 0; i <3; i++)
  {
    cout<<"Enter Username:";
    cin>>username;
    cout<<"Enter Password:";
    cin>>password;
    usernames[i] = username;
     if(username == "admin" && password == 1234)
     {
        cout<<"Login successful\n";
        loginSuccess = 1;
        break;
     }
     else
     {
        cout<<"Invalid login\n";
     }
  }
  if(loginSuccess == 0)
  {
    cout<<"Too many incorrect attempts. Access Denied.\n";
  }
  string studentName[3];
  int studentAge[3];
  string courses[3];

  int studentCount = 0;
  int courseCount = 0;
  int choice;
  {
    cout<<"-----MENU-----"<<endl;
    cout<<"1. Add student"<<endl;
    cout<<"2. View students"<<endl;
    cout<<"3. Add course"<<endl;
    cout<<"4. View course"<<endl;
    cout<<"5. Exit"<<endl;
    cout<<"Enter choice"<<endl;
    cin>>choice;
    if(choice == 1)
    {
        if(studentCount < 3)
        {
            cout<<"Enter student Name:";
            cin>>studentName[studentCount];
            cout<<"Enter student Age:";
            cin>>studentAge[studentCount];
            studentCount++;
        }
        else
        {
            cout<<"Student limit reached";
        }
    }
    else if(choice == 2)
    {
        cout<<"Students list:";
        for(int i = 0; i < studentCount; i++)
        {
            cout<<studentName[i]<<"Age:"<<studentAge[i]<<endl;
        }
    }
    else if(choice == 3)
    {
        if(courseCount < 3)
        {
            cout<<"enter Course Name:";
            cin>>courses[courseCount];
            courseCount++;
        }
        else
        {
            cout<<"Course limit reached";
        }
    }
    else if(choice == 4)
    {
        cout<<"Courses List:";
        for(int i = 0; i < courseCount; i++)
        {
            cout<<courses[i]<<endl;
        }
    }
    else if(choice == 5)
    {
        cout<<"program ended";
    }
    else
    {
        cout<<"Invalid Choice";
    }
  } while(choice != 5);
}