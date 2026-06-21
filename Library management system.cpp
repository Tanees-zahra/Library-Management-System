#include"stdafx.h"
#include <iostream>
#include <string>
using namespace std;

// Book Structure
struct Book
{
    int id;
    string title;
    int quantity;
};

// Node for Doubly Linked List
struct Node
{
    Book book;
    Node* next;
    Node* prev;

    Node(Book b)
    {
        book = b;
        next = NULL;
        prev = NULL;
    }
};

class Library
{
private:
    Node* head;

public:
    Library()
    {
        head = NULL;
    }

    // Add Book
    void addBook(Book b)
    {
        Node* newNode = new Node(b);

        if (head == NULL)
        {
            head = newNode;
            return;
        }

        Node* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;

        cout << "Book Added Successfully!\n";
    }

    // Display Books
    void displayBooks()
    {
        if (head == NULL)
        {
            cout << "No Books Available!\n";
            return;
        }

        Node* temp = head;

        cout << "\n===== BOOK LIST =====\n";

        while (temp != NULL)
        {
            cout << "ID: " << temp->book.id
                 << "\nTitle: " << temp->book.title
                 << "\nQuantity: " << temp->book.quantity
                 << "\n-------------------\n";

            temp = temp->next;
        }
    }

    // Issue Book
    void issueBook(int id)
    {
        Node* temp = head;

        while (temp != NULL)
        {
            if (temp->book.id == id)
            {
                if (temp->book.quantity > 0)
                {
                    temp->book.quantity--;
                    cout << "Book Issued Successfully!\n";
                }
                else
                {
                    cout << "Book Out of Stock!\n";
                }
                return;
            }

            temp = temp->next;
        }

        cout << "Book Not Found!\n";
    }

    // Return Book
    void returnBook(int id)
    {
        Node* temp = head;

        while (temp != NULL)
        {
            if (temp->book.id == id)
            {
                temp->book.quantity++;
                cout << "Book Returned Successfully!\n";
                return;
            }

            temp = temp->next;
        }

        cout << "Book Not Found!\n";
    }

    // Delete Book
    void deleteBook(int id)
    {
        Node* temp = head;

        while (temp != NULL)
        {
            if (temp->book.id == id)
            {
                if (temp == head)
                {
                    head = temp->next;

                    if (head != NULL)
                    {
                        head->prev = NULL;
                    }
                }
                else
                {
                    temp->prev->next = temp->next;

                    if (temp->next != NULL)
                    {
                        temp->next->prev = temp->prev;
                    }
                }

                delete temp;
                cout << "Book Deleted Successfully!\n";
                return;
            }

            temp = temp->next;
        }

        cout << "Book Not Found!\n";
    }
};

int main()
{
    Library library;
    int choice, id;
    Book b;

    do
    {
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Issue Book\n";
        cout << "4. Return Book\n";
        cout << "5. Delete Book\n";
        cout << "6. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Book ID: ";
            cin >> b.id;

            cin.ignore();

            cout << "Enter Book Title: ";
            getline(cin, b.title);

            cout << "Enter Quantity: ";
            cin >> b.quantity;

            library.addBook(b);
            break;

        case 2:
            library.displayBooks();
            break;

        case 3:
            cout << "Enter Book ID: ";
            cin >> id;
            library.issueBook(id);
            break;

        case 4:
            cout << "Enter Book ID: ";
            cin >> id;
            library.returnBook(id);
            break;

        case 5:
            cout << "Enter Book ID: ";
            cin >> id;
            library.deleteBook(id);
            break;

        case 6:
            cout << "Program Ended!\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 6);
	system("pause");
    return 0;
}