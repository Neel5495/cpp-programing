#include <iostream>
#include <string>

class Patient {
private:
    int patientId;
    std::string name;
    double consultationCharges;

public:
    // Function to register patient details
    void registerPatient(int id, std::string patientName) {
        patientId = id;
        name = patientName;
        consultationCharges = 0.0;
    }

    // Function to calculate/assign charges
    void calculateCharges(double baseFee, double extraTests = 0.0) {
        consultationCharges = baseFee + extraTests;
    }

    // Function to display patient info
    void displayPatientInfo() const {
        std::cout << "--- Patient Details ---\n"
                  << "ID: " << patientId << "\n"
                  << "Name: " << name << "\n"
                  << "Total Consultation Charges: $" << consultationCharges << "\n";
    }
};

int main() {
    Patient p1;
    p1.registerPatient(101, "John Doe");
    p1.calculateCharges(150.0, 45.50); // $150 base fee + $45.50 testing charges
    p1.displayPatientInfo();
    
    return 0;
}