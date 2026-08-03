#include <iostream>
using namespace std;
int main() 
{
    int n;
    int sum=0;
    cout << "Enter the value of n: ";
    cin >> n; 
    cout << "The sum of " << n << " natural numbers are: " << endl;
    sum=n*(n+1)/2;
    cout<<sum;
}
