#include<iostream>
using namespace std;
int main()
{
    string statment,result;
    cout<<"Enter the statment:";
    getline(cin,statment);
    for(int i = 0; i < statment.length(); i++)
  {
     char ch = statment[i];

    if(ch !='a' &&  ch!= 'e' && ch!= 'i' && ch!= 'o' && ch!='u' && ch!='A' && ch!='E' && ch!='I' && ch!='O' && ch!='U')
{
    result = result + ch;
}
  }
cout<<"String with vowels removed:"<<" "<< result<<endl;

}
