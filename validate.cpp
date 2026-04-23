#include<iostream>
using namespace std;
bool isAlreadyEntered(int arr[],int size,int number)
{
    for(int i = 0; i < size; i++)
    {
        if(arr[i] == number)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    int n;
    cout<<"Enter the number of elements:";
    cin>>n;
    int arr[n];
    int count = 0;
    cout<<"Enter"<<n<<"numbers,one per line:"<<endl;
    for(int i = 0; i < n; i++)
    {
        int num;
        cin>> num;
        if(isAlreadyEntered(arr,count,num))
        {
            cout<<"Already entered:"<<num<<endl;
        }
        else{
      arr[count] = num;
      count++;
        }
    }
    cout<<"unique numbers entered:";
    for(int i = 0; i < count; i++)
    {
        cout<<arr[i]<<" ";
    }
}