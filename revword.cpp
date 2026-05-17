#include<iostream>
using namespace std;
void reverseWord(char str[])
{
    int length = 0;
    while(str[length] !='\0')
    {
        length++;
    }
    cout<<"Reversed String:";
    for(int i=length - 1; i >=0; i--)
    {
        cout<<str[i];
    }
}
int main()
{
    char str[100];
    cout<<" Enter a string:";
    cin>>str;
    reverseWord(str);
}