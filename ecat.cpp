#include<iostream>
using namespace std;
int main()
{ string name;
 float matric,inter,ecat,aggregate;
cout<<"enter name of student:";
cin>>name;
cout<<" enter matriculation marks(out of 1100):";
cin>>matric;
cout<<"enter intermediate marks(out of 555):";
cin>>inter;
cout<<"enter ecat marks(out of 400):";
cin>>ecat;
aggregate = (ecat / 400 * 50)+ (inter / 555 * 40) + (matric / 1100 * 10);
cout<<"aggregate score for"<< name <<"is=" << aggregate << " %";














































}