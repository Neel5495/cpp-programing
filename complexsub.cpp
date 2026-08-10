#include<iostream>
using namespace std;
class complex
{
int real,imag;
public:
void input()
{
cout<<"Enter real part:";
cin>> real;
cout<<"Enter imaginary part:";
cin>>imag;
}
void subtract(complex c)
{
cout<<"Subtraction="<<real-c.real<<"+"<<imag-c.imag<<"i";
}
};
int main()
{
complex c1,c2;
cout<<"Enter first complex number:\n";
c1.input();
cout<<"Enter second Complex number:\n";
c2.input();
c1.subtract(c2);
return 0;
}

