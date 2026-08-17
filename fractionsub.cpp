#include <iostream>
#include <numeric> // Required for std::gcd

class Fraction {
private:
    int numerator;
    int denominator;

public:
    // Constructor to initialize fraction
    Fraction(int num = 0, int den = 1) : numerator(num), denominator(den) {}

    // Member function to accept fraction details from user
    void accept() {
        std::cout << "Enter numerator: ";
        std::cin >> numerator;
        std::cout << "Enter denominator: ";
        std::cin >> denominator;
        
        // Validation to prevent division by zero
        while (denominator == 0) {
            std::cout << "Denominator cannot be zero. Please re-enter: ";
            std::cin >> denominator;
        }
    }

    // Member function to subtract two fractions
    Fraction subtract(const Fraction& other) {
        int resultNum = (this->numerator * other.denominator) - (other.numerator * this->denominator);
        int resultDen = this->denominator * other.denominator;
        return Fraction(resultNum, resultDen);
    }

    // Member function to simplify and display the fraction
    void display() {
        // Find greatest common divisor to simplify the fraction
        int commonDivisor = std::gcd(numerator, denominator);
        numerator /= commonDivisor;
        denominator /= commonDivisor;

        // Keep the negative sign in the numerator if present
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }

        // Print the result cleanly
        if (denominator == 1) {
            std::cout << numerator << std::endl;
        } else {
            std::cout << numerator << "/" << denominator << std::endl;
        }
    }
};

int main() {
    Fraction f1, f2, result;

    std::cout << "Enter details for First Fraction:" << std::endl;
    f1.accept();

    std::cout << "\nEnter details for Second Fraction:" << std::endl;
    f2.accept();

    result = f1.subtract(f2);

    std::cout << "\nResult of Subtraction (Simplified Form): ";
    result.display();

    return 0;
}