#include<iostream>
using namespace std;
int main(){
int holidays,workingDays,timeTosleep,timeToplay,minutes;
float timeInholidays,timeInworkingdays;
cout<<"enter the holidays :";
cin>>holidays;
workingDays = 365 - holidays;
timeInworkingdays = (workingDays * 63);
timeInholidays = (holidays * 127);
timeToplay = timeInworkingdays + timeInholidays;
int norm = 30000;
int diff = (norm - timeToplay);
int hours = diff / 60;
minutes = diff % 60;
if(timeToplay > norm)
{
cout<<"tom will run away"<<endl;
cout<<hours<<"hours and " <<minutes<<"minutes for play";
}
else{
cout<<"tom sleeps well" <<endl;
cout<<hours<<"hours and "<<minutes<<"minutes less for play";
}
}





