#include<iostream>
#include<string>
using namespace std;
class employee
{
private:
int employeeid;
string name;
float salary;
public:
employee()
{
employeeid=0;
name="none";
salary=0.0;
}
employee(int id , string empname, float empsalary)
{
employeeid=id;
name=empname;
salary=empsalary;
}
employee(const employee &empl)
{
employeeid=empl.employeeid;
name=empl.name;
salary=empl.salary;
}
void display()
{
cout<<"employee ID: "<<employeeid<<endl;
cout<<"name: "<<name<<endl;
cout<<"salary: "<<salary<<endl;
}
};
int main()
{
employee emp1;
emp1.display();
employee emp2(3,"sandip",5000);
emp2.display();
employee emp3=emp2;
emp3.display();
}