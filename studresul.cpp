#include <iostream>
using namespace std;

class Result {
private:
    double marks[5];
    double total;
    double percentage;

public:
    void acceptMarks() {
        total = 0;
        cout << "Enter marks for 5 subjects (out of 100 each):" << endl;
        for (int i = 0; i < 5; i++) {
            cout << "Subject " << (i + 1) << ": ";
            cin >> marks[i];
            total += marks[i];
        }
    }

    void calculateAndDisplay() {
        percentage = (total / 500.0) * 100;

        cout << "\n--- Exam Result Sheet ---" << endl;
        cout << "Total Marks Obtained: " << total << " / 500" << endl;
        cout << "Percentage: " << percentage << "%" << endl;

        // Condition check for pass/fail status
        if (percentage >= 40.0) {
            cout << "Final Status: PASSED" << endl;
        } else {
            cout << "Final Status: FAILED" << endl;
        }
    }
};

int main() {
    Result studentResult;
    studentResult.acceptMarks();
    studentResult.calculateAndDisplay();
    return 0;
}
