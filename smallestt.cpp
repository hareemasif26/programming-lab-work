#include<iostream>
using namespace std;
void findLargestsmallest(int arr[], int n)
{
    int largest = arr[0];
    int smallest = arr[0];

    for(int i = 1; i < n; i++)
    {
        if(arr[i] > largest)
        {
            largest = arr[i];
        }
        if(arr[i] < smallest)
        {
              smallest = arr[i];
        }
    }
    cout<<"Largest Number:" << largest <<endl;
    cout<<"Smallest Number:"<< smallest <<endl;
}
int main()
{
    int n;

    cout<<"Enter number of elements:";
    cin>>n;
    int arr[n];
    cout<<"Enter"<< n << " numbers:"<<endl;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    findLargestsmallest(arr,n);
}