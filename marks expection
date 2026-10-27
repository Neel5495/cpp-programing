#include <iostream>
#include <exception>
using namespace std;\
class InvalidMarksException : public exception
{
public:
    const char* what() const throw()
    {
        return "Invalid marks! Marks must be between 0 and 100.";
    }
};
int main()
{
    int marks;
    try
    {
        cout << "Enter marks: ";
        cin >> marks;
        if (marks < 0 || marks > 100)
        {
            InvalidMarksException e;
            throw e;
        }
        cout << "Valid marks: " << marks << endl;
    }
    catch (exception& e)
    {
        cout << e.what();
    }
}
