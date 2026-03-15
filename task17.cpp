#include<iostream>
using namespace std;
int main()
{
char c;
cout<<"enter any character in lower case:";
cin>>c;
if(c >= '0' && c <+'9'){
cout<<"it is a number"<<endl;
}
 else if(c=='a'|| c=='e'||c=='i'||c=='o'||c=='u'){
cout<<"it is vowel"<<endl;
}
else if(c>='a' && c<='z' ){
cout<<"it is a consonant"<<endl;
}








}


