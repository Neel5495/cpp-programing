#include <iostream>
using namespace std;
int main() 
{
    int a;
    cout << "Enter the value of a: ";
    cin >> a;
    int i = 1; 
    cout << "The first " << a << " natural numbers are: " << endl;
    while (i <= a)
    {
        cout << i << " ";
        i++;
    }
}
