#include <iostream>
using namespace std;
int main()
{
    int n;
    try
    {
        cout << "Enter a number: ";
        cin >> n;
        if (n < 0)
        {
            throw n;
        }
        cout << "Number is positive: " << n << endl;
    }
    catch (int x)
    {
        cout << "Exception: Negative number is not allowed!";
    }
}
