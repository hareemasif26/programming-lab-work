#include<iostream>
using namespace std;
int main()
{
    int n1,n2;
    cout<<"Enter the number of elements for 1st array(must be 2):";
    cin>>n1,n2;
    int arr1[n1];
    cout<<"enter 2 elements for the first array, one per line:"<<endl;
    for(int i = 0; i< n1; i++)
    {
        cin >> arr1[i];
    }
    cout<<"Enter the number of elements foe the 2nd array:";
    cin>>n2;
    int arr2[n2];
    cout<<"Enter"<<n2<<"elements for 2nd array, one per line:"<<endl;
    for(int i = 0; i < n2; i++)
    {
        cin>>arr2[i];
    }
    int result[n1 = n2];
    result[0] = arr1[0];
    for(int i = 0; i < n2; i++)
    {
        result[i + 1] = arr2[i];
    }
    result[n1 + n2 - 1] = arr1[1];
    cout<<"Resulting array:[";
     for(int i = 0; i<n1 + n2;i++)   
     {
     cout << result[i];
     if(i < n1 + n2 - 1)
     cout<<" ,";
     }
      cout<<  "]";
}