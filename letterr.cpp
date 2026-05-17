#include<iostream>
using namespace std;
void showPositions(char word[])
{
    for(int i = 0; word[i] != '\0'; i++)
    {
     cout<<word[i]<<" found at position"<<i<<endl;
    }

}
int main()
{
    char word[100];
    cout<<"enter a word :";
    cin>>word;
    showPositions(word);
}