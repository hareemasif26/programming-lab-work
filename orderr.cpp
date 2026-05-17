#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter number of students:";
    cin >> n;
    string names[n];
    cout<<"enter students names:"<<endl;
    for(int i = 0; i < n; i++)
    {
        cin >> names[i];
    }
    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(names[i] > names[j])
            {
                string t = names[i];
                names[i] = names[j];
                names[j] = t;
            }
        }
    }
    cout<<"names in alphabitcal order:"<<endl;
    for(int i = 0; i < n; i++)
    {
        cout<<names[i]<<endl;
    }
}