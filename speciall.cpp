#include<iostream>
using namespace std;
bool isSpecialarray(int arr[],int n)
{
 for(int i = 0; i < n; i++)
 {
    if(i % 2 == 0 && arr[i] % 2 !=0)
    return false;
    if(i % 2 ==1 && arr[i] % 2 != 1)
    return false;
 }
    return true;
}
 int main()
 {
    int n;
    cout<<"Enter size of array:";
    cin>>n;
    int arr[n];
    cout<<"Enter"<< n <<"elements of the array :\n";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if(isSpecialarray(arr,n))
    cout<<"The aray is special";
    else
    cout<<"The array is not special";
 }