#include<iostream>
using namespace std;
int findLargestnumber(int arr[], int size)
{
    int largest = arr[0];
    for(int i = 1; i < size; i++)
    {
        if(arr[i] > largest)
        {
            largest = arr[i];
        }
    }
    return largest;
}
int main()
{
    int n;
    cout<<"Enter the number of elements:";
    cin>>n;
    int arr[n];
    cout<<"Enter"<<n<<"numbers,one per line:"<<endl;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int largest = findLargestnumber(arr,n);
    cout<<"The largest number entered is:"<<largest;
}