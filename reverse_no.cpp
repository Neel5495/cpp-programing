#include <iostream>
using namespace std;

int main() {
    int num, rever = 0, remain;
cout << "Enter an integer: ";
    cin >> num;
    while (num != 0) {
        remain = num % 10;
        rever = rever * 10 + remain;
        num /= 10;
      cout << "Reversed Number = " << rever << endl;
      return 0;
}
