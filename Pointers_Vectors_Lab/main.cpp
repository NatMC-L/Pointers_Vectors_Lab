#include <iostream>
#include <vector>
#include <string>
using namespace std;

// book class 
class Book {
private:
    string title;
    string author;
    double price;

public: 
    Book(string t, string a, double p) {
        title = t;
        author = a;
        price = p;
    }

    void displayInfo() const { 
        cout <<"Title: " << title << ", Author: " << author << ", Price: $" << price << endl; 
    }
};

// Inventory class
class Inventory {
private: 
    vector<Book*> books; 

public:
    void addBook(Book* bookPtr) {
        books.push_back(bookPtr);

    }

    void displayAll() const {
        if (books.empty()){
            cout << "Inventory is empty."<< endl;
            return;
        }

        for (size_t i = 0; i < books.size(); ++i) {
            cout << "\n[" << i << "] ";
            books[i]->displayInfo();
        }
    }
    
    void removeBook(int index) {
        if (index >= 0 && index < static_cast<int>(books.size())) {
            delete books[index];
            books.erase(books.begin() + index);
            cout << "Book removed." << endl; 
        }
        else {
            cout << "Invalid index." << endl;
        }
    }

    ~Inventory() {
        for (Book* ptr : books) {
            delete ptr;
        }
    }

};

int main() {
    Inventory store;

    int choice = 0;

    while (choice != 4) {
        cout << "\n==== Book Inventory ====" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Display Books" << endl;
        cout << "3. Remove book" << endl;
        cout << "4. Quit" << endl;
        cout <<"Enter choice: ";
        cin >> choice; 
       

        if (choice == 1) {
            string title;
            string author;
            double price;
            
            cin.ignore();
            cout << "Enter title: ";
            getline(cin, title);
            cout << "Enter author: ";
            getline(cin, author);
            cout << "Enter price ";
            cin >> price; 

            Book* newBook = new Book(title, author, price);
            store.addBook(newBook);
        }
        else if (choice == 2) {
            store.displayAll();
        }
        else if (choice == 3) {
            int index;

            store.displayAll();
            cout <<"Enter index to remove: ";
            cin >> index;
            
            store.removeBook(index);
        }
        else if (choice == 4) {
            cout << "Goodbye!" << endl;
        }
        else {
            cout << "Invalid choice." << endl;
        }

    }

    return 0;
}