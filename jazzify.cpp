#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter number of chords:";
    cin>>n;
    string chords[n];
    cout<<"Enter"<<n<<"chords , one per line:\n";
    for(int i = 0; i < n; i++)
    {
        cin>> chords[i];
    
        int len = chords[i].length();
        if(chords[i][len - 1] != '7')
        {
            chords[i] = chords[i] + "7";
        }
    }
    cout<<"Jazzified chords:[";
     for(int i = 0; i < n; i++)   
     {
       cout<< chords[i];
       if(i , n-1) cout<<", ";
     }
      cout<<   "]";
}