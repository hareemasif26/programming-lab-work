#include<iostream>
using namespace std;
int main()
{
    for(int i=1;i<=5;i++){
        for(int j=5;j>=6-i;j--){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}