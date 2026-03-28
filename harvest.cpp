#include<iostream>
using namespace std;
int main()
{
float vegetablePrice;
float fruitPrice;
int totalVegetableperkg,totalFruitperkg;
cout<<" enter vegetable price(in coins):";
cin>>vegetablePrice;
cout<<"enter fruit price(in coins):";
cin>>fruitPrice;
cout<<" enter total vegetable per kg:";
cin>>totalVegetableperkg;
cout<<" enter total fruit per kg:";
cin>>totalFruitperkg;
float totalCoins=(vegetablePrice*totalVegetableperkg)+(fruitPrice*totalFruitperkg);
float totalEarninginrupees= totalCoins / 1.94;
cout<<"total earning is :"<<totalEarninginrupees;



















































}
