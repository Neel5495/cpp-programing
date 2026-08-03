#include<iostream>
using namespace std;
int main()
{
int a,b;
cout<<"Enter any two numbers: "<<endl;
cin>>a>>b;
a=a+b;
b=a-b;
a=a-b;
cout<<"After Swapping:"<<endl;
cout<<a<<endl;
cout<<b<<endl;
return 0;
}

