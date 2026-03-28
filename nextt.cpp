#include<iostream>
using namespace std;
void nextLetter(char str[])
{
    for(int i = 0; str[i] != '\0'; i++)
    {
     if(str[i] == 'z')
     {
        str[i] = 'a';
     }
     else if(str[i] == 'Z')
     {
        str[i] = 'A';
     }
     else if(str[i]!=' ')
     {
        str[i] = str[i] + 1;
     }
    }
    cout<<"Shifted String :"<<str;
}
int main()
{
    char str[100];
    cout << "Enter a string:";
    cin.getline(str,100);
    nextLetter(str);
}