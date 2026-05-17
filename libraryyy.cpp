#include <iostream>
using namespace std;

int main() {
    int id[100];
    string title[100];
    bool borrowed[100];

    int count = 0;
    int choice;

    do {
        cout << "\n--- Library Menu ---\n";
        cout << "1. Add Books\n";
        cout << "2. View Books\n";
        cout << "3. Borrow Book\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter Book ID: ";
            cin >> id[count];

            cout << "Enter Book Title: ";
            cin >> title[count];

            borrowed[count] = false;
            count++;

            cout << "Book added!\n";
        }

        else if (choice == 2) {
            if (count == 0) {
                cout << "No books available\n";
            } else {
                for (int i = 0; i < count; i++) {
                    cout << "\nID: " << id[i];
                    cout << "\nTitle: " << title[i];
                    if (borrowed[i])
                        cout << "\nStatus: Borrowed\n";
                    else
                        cout << "\nStatus: Available\n";
                }
            }
        }

        else if (choice == 3) {
            int searchId;
            cout << "Enter Book ID to borrow: ";
            cin >> searchId;

            bool found = false;

            for (int i = 0; i < count; i++) {
                if (id[i] == searchId) {
                    found = true;

                    if (borrowed[i] == false) {
                        borrowed[i] = true;
                        cout << "Book borrowed!\n";
                    } else {
                        cout << "Already borrowed\n";
                    }
                }
            }

            if (!found) {
                cout << "Book not found\n";
            }
        }

        else if (choice == 4) {
            cout << "Goodbye!\n";
        }

        else {
            cout << "Invalid choice\n";
        }

    } while (choice != 4);

    return 0;
}