#include <iostream>
#include <string>

class LibraryBook {
private:
    std::string title;
    std::string author;
    bool isIssued;

public:
    // Constructor
    LibraryBook(std::string bookTitle, std::string bookAuthor) {
        title = bookTitle;
        author = bookAuthor;
        isIssued = false;
    }

    // Function to issue a book
    void issueBook() {
        if (!isIssued) {
            isIssued = true;
            std::cout << "Book '" << title << "' has been successfully issued.\n";
        } else {
            std::cout << "Sorry, '" << title << "' is already issued.\n";
        }
    }

    // Function to return a book
    void returnBook() {
        if (isIssued) {
            isIssued = false;
            std::cout << "Book '" << title << "' has been successfully returned.\n";
        } else {
            std::cout << "This book was not issued.\n";
        }
    }

    // Function to display book information
    void displayBookDetails() const {
        std::cout << "Title: " << title 
                  << " | Author: " << author 
                  << " | Status: " << (isIssued ? "Issued" : "Available") << "\n";
    }
};

int main() {
    LibraryBook book1("The C++ Programming Language", "Bjarne Stroustrup");
    
    book1.displayBookDetails();
    book1.issueBook();
    book1.displayBookDetails();
    book1.returnBook();
    
    return 0;
}