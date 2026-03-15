#include<iostream>
using namespace std;
main()
{
    int sum = 0;
    for(int i = 10; i > 0; i-= 2){
        sum += i;
    }
    cout << sum;
}