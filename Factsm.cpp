#include<iostream>
using namespace std;
int main()
{
int a;
int b=1;
cout<<"Enter number: "<<endl;
cin>>a;
for (int i=1;i<=a;i++)
{
b=b*i;
}
cout<<"Factorial: "<<b<<endl;
return 0;
}
