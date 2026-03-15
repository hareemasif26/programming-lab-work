<<<<<<< HEAD
#include<iostream>
using namespace std;
main()
{
    int i = 0;
    while(i < 10){
        cout << i << " ";
        i += 3;
    }
=======
#include<iostream>
using namespace std;
int main(){
string shape;
float area,length,width,radius,base,height;
cout<<"enter name of shape :";
cin>>shape;
if(shape =="square"){
cout<<"enter length of its one side:";
cin>>length;
area = length * length;
cout<<"area of square is :"<<area;
}
if(shape == "rectangle"){
cout<<"enter length of its side:";
cin>>length;
cout<<"enter width of its side:";
cin>>width;
area = length * width;
cout<<"area of rectangle is :"<<area;
}
if(shape=="circle"){
cout<<"enter radius of circle:";
cin>>radius;
area = 3.14 *(radius*radius);
cout<<"area of circle is :"<<area;
}
if(shape =="triangle"){
cout<<"enter base of trinagle:";
cin>>base;
cout<<"enter height of triagle:";
cin>>height;
area = 0.5 * base * height;
cout<<"area of triangle is :"<<area;
}








>>>>>>> 994ddb26077fd239a022c943e4ae29b8438a20d0
}