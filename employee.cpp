#include<iostream>
#include<string>
using namespace std;
class employee{
private:
int employeeID;
string name;
double salary;
public:
void acceptdetails(){
cout<<"Enter the employee ID:";
cin>>employeeID;
cin.ignore();
cout<<"Enter Name:";
getline(cin,name);
cout<<"Enter salary:";
cin>>salary;
}
void displaydetails(){
cout<<"\n***EMPLOYEE DETAILS***"<<endl;
cout<<"ID"<<employeeID<<endl;
cout<<"name"<<name<<endl;
cout<<"salary"<<salary<<endl;
}
};
int main(){
employee emp;
emp.acceptdetails();
emp.displaydetails();
return 0;
}
