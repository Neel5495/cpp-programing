#include<iostream>
#include<string>
using namespace std;
class product
{
private:
int productid;
string name;
float price;
public:
product()
{
productid=0;
name="none";
price=0;
}
product(int id, string proname, float proprice)
{
productid=id;
name=proname;
price=proprice;
}
void display()
{
cout<<"Product id: "<<productid<<endl;
cout<<"Product name: "<<name<<endl;
cout<<"Product price: "<<price<<endl;
}
};
int main()
{
product pro1;
pro1.display();
product pro2(999,"mice",399);
pro2.display();
}