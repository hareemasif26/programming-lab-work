#include<iostream>
using namespace std;
int countEven(int arr[],int n)
{ 
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] % 2 == 0)
        {
            count++;
        }
    }
 return count;
}
int main()
{
    int n;
    cout<<"enter number of elements:";
    cin>>n;
    int arr[n];
    cout<<"Enter"<< n << "numbers:"<<endl;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
}
    int result = countEven(arr,n);
    cout <<"Total Even Numbers:"<<result;

}