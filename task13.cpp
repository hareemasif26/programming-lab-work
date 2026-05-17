<<<<<<< HEAD
=======
<<<<<<< HEAD
#include<iostream>
using namespace std;
main()
{
    int i,j,n=5;
    for(i=1;i<=n;i++)
    {
    for(j=1;j<=n-i;j++)
    cout<<" ";
    for(j=1;  j<=2*i - 1;  j++)
    cout<<"*";
    cout<<endl;
    }
    for(i= n - 1;   i>=1; i--)
    {
        for(j=1;  j<=n-i;  j++)
        cout<<" ";
        for(j=1 ;  j<=2*i- 1; j++)
        cout<<"*";
        cout<<endl;
    }
}
=======
>>>>>>> 17c9e8dfdd9ddacd33ebacab28c156f58b7e3ba5
#include<iostream>
using namespace std;
int main()
{
string my_password,user_enter;
my_password = "pass@123!";
cout<<"enter the password:";
cin>>user_enter;
if(user_enter== my_password){
cout<<"wow! you have cracked the code!";
}
else{
cout<<"it is not that simple, try again!";
}
}




<<<<<<< HEAD
=======
>>>>>>> 994ddb26077fd239a022c943e4ae29b8438a20d0
>>>>>>> 17c9e8dfdd9ddacd33ebacab28c156f58b7e3ba5
