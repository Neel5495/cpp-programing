#include <iostream>
#include <iomanip> // Required for formatting the output with leading zeros

using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    // Member function to accept time values from the user
    void acceptTime() {
        cout << "Enter hours: ";
        cin >> hours;
        cout << "Enter minutes: ";
        cin >> minutes;
        cout << "Enter seconds: ";
        cin >> seconds;
    }

    // Member function to add two Time objects
    void addTime(const Time& t1, const Time& t2) {
        // Add seconds and compute carry-over to minutes
        seconds = t1.seconds + t2.seconds;
        int carryMinutes = seconds / 60;
        seconds %= 60;

        // Add minutes along with carry-over, then compute carry-over to hours
        minutes = t1.minutes + t2.minutes + carryMinutes;
        int carryHours = minutes / 60;
        minutes %= 60;

        // Add hours along with carry-over
        hours = t1.hours + t2.hours + carryHours;
    }

    // Member function to display the time in HH:MM:SS format
    void displayTime() const {
        // setfill('0') and setw(2) ensure single-digit numbers are prefixed with a zero
        cout << setfill('0') << setw(2) << hours << ":"
             << setfill('0') << setw(2) << minutes << ":"
             << setfill('0') << setw(2) << seconds << endl;
    }
};

int main() {
    Time t1, t2, resultantTime;

    cout << "--- Enter First Time Value ---" << endl;
    t1.acceptTime();

    cout << "\n--- Enter Second Time Value ---" << endl;
    t2.acceptTime();

    // Calculate the total time
    resultantTime.addTime(t1, t2);

    cout << "\nResultant Time (HH:MM:SS): ";
    resultantTime.displayTime();

    return 0;
}