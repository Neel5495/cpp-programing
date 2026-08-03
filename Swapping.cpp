#include<iostream>
using namespace std;
int main()
{
int a,b,c;
cout<<"Enter any two numbers: "<<endl;
cin>>a>>b;
c=a;
a=b;
b=c;
cout<<"After Swapping:"<<endl;
cout<<a<<endl;
cout<<b<<endl;
return 0;
}

