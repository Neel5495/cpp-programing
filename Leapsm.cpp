#include<iostream>
using namespace std;
int main()
{
int year;
cout<<"Enter year: "<<endl;
cin>>year;
if (year%4==0)
{ 
cout<<"Year is Leap year"<<endl;
}
else
{
cout<<"Year is not Leap year"<<endl;
}
return 0;
}
