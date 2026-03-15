<<<<<<< HEAD
=======
<<<<<<< HEAD
#include<iostream>
using namespace std;
main()
{
   int i = 5;
   while(i>0){
    cout<<i<<"  ";
    i--;
   }






}
=======
>>>>>>> 17c9e8dfdd9ddacd33ebacab28c156f58b7e3ba5
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





<<<<<<< HEAD
=======
>>>>>>> 994ddb26077fd239a022c943e4ae29b8438a20d0
>>>>>>> 17c9e8dfdd9ddacd33ebacab28c156f58b7e3ba5
