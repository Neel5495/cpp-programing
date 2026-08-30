#include<iostream>
using namespace std;
class rectangle
{
private:
float length;
float breadth;
public:
rectangle()
{
length=0.0;
breadth=0.0;
}
rectangle(float l, float b)
{
length=l;
breadth=b;
}
rectangle(const rectangle &rect)
{
length=rect.length;
breadth=rect.breadth;
}
void display()
{
float area=length*breadth;
cout<<"Area of rectangle:"<<area<<endl;
}
};
int main()
{
cout<<"rectnagle 1"<<endl;
rectangle r1;
r1.display();
cout<<"Recatngle 2"<<endl;
rectangle r2(2.2,4.0);
r2.display();
cout<<"Recatngle 3"<<endl;
rectangle r3=r2;
r3.display();
}