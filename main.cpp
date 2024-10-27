#include <iostream>
#include "Book.h"
#include "Library.h"

int main() {
    Library library;
    int choice;

    do {
        std::cout << "Library Management System\n";
        std::cout << "1. Add Book\n";
        std::cout << "2. Borrow Book\n";
        std::cout << "3. Return Book\n";
        std::cout << "4. Show Available Books\n";
        std::cout << "5. Show Library Statistics\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); // Clear the newline character from the input buffer

        switch (choice) {
            case 1: {
                std::string title, author, ISBN, genre;
                bool available;

                std::cout << "Enter book title: ";
                std::getline(std::cin, title);
                std::cout << "Enter book author: ";
                std::getline(std::cin, author);
                std::cout << "Enter book ISBN: ";
                std::getline(std::cin, ISBN);
                std::cout << "Enter book genre: ";
                std::getline(std::cin, genre);
                std::cout << "Is the book available? (1 for Yes, 0 for No): ";
                std::cin >> available;

                library.addBook(Book(title, author, ISBN, genre, available));
                break;
            }
            case 2: {
                std::string title, author, ISBN, genre;
                std::cout << "Enter the title of the book to borrow: ";
                std::getline(std::cin, title);
                std::cout << "Enter the author of the book: ";
                std::getline(std::cin, author);
                std::cout << "Enter the ISBN of the book: ";
                std::getline(std::cin, ISBN);
                std::cout << "Enter the genre of the book: ";
                std::getline(std::cin, genre);

                library.withdrawBook(Book(title, author, ISBN, genre));
                break;
            }
            case 3: {
                std::string title, author, ISBN, genre;
                std::cout << "Enter the title of the book to return: ";
                std::getline(std::cin, title);
                std::cout << "Enter the author of the book: ";
                std::getline(std::cin, author);
                std::cout << "Enter the ISBN of the book: ";
                std::getline(std::cin, ISBN);
                std::cout << "Enter the genre of the book: ";
                std::getline(std::cin, genre);

                library.returnBook(Book(title, author, ISBN, genre));
                break;
            }
            case 4:
                std::cout << "Books available in the library:" << std::endl;
                library.allowedBooks();
                break;
            case 5:
                library.printStatistics();
                break;
            case 0:
                std::cout << "Exiting the program." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }

        std::cout << std::endl; // Print a newline for better readability
    } while (choice != 0);

    return 0;
}
