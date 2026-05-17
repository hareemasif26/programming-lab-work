#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
#include<windows.h>

using namespace std;

// ====================== STRUCTURES ======================

struct Package {
    char name[60];
    int days;
    double amount;
    char type[30];
    char includes[100];
};

struct Booking {
    char bookingId[15];
    char userId[50];
    char userName[60];
    char packageName[60];
    char bookingDate[15];
    char paymentStatus[10];
    char bankName[60];
    char accountNumber[20];
    bool cancelled;
};

struct User {
    char username[50];
    char password[50];
    char fullName[60];
    char phone[20];
    char email[60];
    char cnic[20];
};

// ====================== GLOBAL VARIABLES ======================

const int MAX_PACKAGES = 50;
const int MAX_BOOKINGS = 200;
const int MAX_USERS    = 100;

Package packages[MAX_PACKAGES];
Booking bookings[MAX_BOOKINGS];
User    users[MAX_USERS];

int packageCount = 0;
int bookingCount = 0;
int userCount    = 0;

string loggedInUser = "";
string loggedInName = "";

// Admin credentials (only one admin)
string adminUsername = "admin";
string adminPassword = "admin123";

// ====================== HELPER FUNCTIONS ======================

// Copy string into char array safely
void myCopy(char* dest, int size, string src) {
    int i = 0;
    while(i < size - 1 && i < (int)src.length()) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

// Check if string has only digits
bool isDigits(string s) {
    if(s.empty()) return false;
    for(int i = 0; i < (int)s.length(); i++) {
        if(s[i] < '0' || s[i] > '9') return false;
    }
    return true;
}

// Check if string has only letters and spaces
bool isLetters(string s) {
    if(s.empty()) return false;
    for(int i = 0; i < (int)s.length(); i++) {
        if(!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || s[i] == ' '))
            return false;
    }
    return true;
}

// Get today's date as string
string getDate() {
    SYSTEMTIME st;
    GetLocalTime(&st);
    string day = to_string(st.wDay);
    string month = to_string(st.wMonth);
    string year = to_string(st.wYear);
    return day + "/" + month + "/" + year;
}

void pressEnter() {
    cout << "\nPress any key to go back...";
    getch();
}

// ====================== FILE SAVE/LOAD ======================

void savePackages() {
    FILE* f = fopen("packages.dat", "wb");
    if(!f) return;
    fwrite(&packageCount, sizeof(int), 1, f);
    fwrite(packages, sizeof(Package), packageCount, f);
    fclose(f);
}

void loadPackages() {
    FILE* f = fopen("packages.dat", "rb");
    if(!f) return;
    fread(&packageCount, sizeof(int), 1, f);
    if(packageCount > MAX_PACKAGES) packageCount = MAX_PACKAGES;
    fread(packages, sizeof(Package), packageCount, f);
    fclose(f);
}

void saveBookings() {
    FILE* f = fopen("bookings.dat", "wb");
    if(!f) return;
    fwrite(&bookingCount, sizeof(int), 1, f);
    fwrite(bookings, sizeof(Booking), bookingCount, f);
    fclose(f);
}

void loadBookings() {
    FILE* f = fopen("bookings.dat", "rb");
    if(!f) return;
    fread(&bookingCount, sizeof(int), 1, f);
    if(bookingCount > MAX_BOOKINGS) bookingCount = MAX_BOOKINGS;
    fread(bookings, sizeof(Booking), bookingCount, f);
    fclose(f);
}

void saveUsers() {
    FILE* f = fopen("users.dat", "wb");
    if(!f) return;
    fwrite(&userCount, sizeof(int), 1, f);
    fwrite(users, sizeof(User), userCount, f);
    fclose(f);
}

void loadUsers() {
    FILE* f = fopen("users.dat", "rb");
    if(!f) return;
    fread(&userCount, sizeof(int), 1, f);
    if(userCount > MAX_USERS) userCount = MAX_USERS;
    fread(users, sizeof(User), userCount, f);
    fclose(f);
}

// ====================== DEFAULT PACKAGES ======================

void addDefaultPackages() {
    if(packageCount == 0) {
        myCopy(packages[0].name,     60,  "Silver Package");
        packages[0].days   = 14;
        packages[0].amount = 150000;
        myCopy(packages[0].type,     30,  "Economy");
        myCopy(packages[0].includes, 100, "Flight + Hotel 3-Star + Transport");

        myCopy(packages[1].name,     60,  "Gold Package");
        packages[1].days   = 21;
        packages[1].amount = 250000;
        myCopy(packages[1].type,     30,  "Standard");
        myCopy(packages[1].includes, 100, "Flight + Hotel 4-Star + Transport + Ziyarat");

        myCopy(packages[2].name,     60,  "Diamond Package");
        packages[2].days   = 30;
        packages[2].amount = 400000;
        myCopy(packages[2].type,     30,  "Premium");
        myCopy(packages[2].includes, 100, "Flight + Hotel 5-Star + Transport + Ziyarat + Meals");

        packageCount = 3;
        savePackages();
    }
}

// ====================== ADMIN FUNCTIONS ======================

void adminAddPackage() {
    system("cls");
    cout << "===== ADD NEW PACKAGE =====\n\n";

    if(packageCount >= MAX_PACKAGES) {
        cout << "Error: Package list is full!\n";
        pressEnter();
        return;
    }

    string name, type, includes;
    int days;
    double amount;

    cin.ignore();

    cout << "Enter Package Name   : ";
    getline(cin, name);
    if(name.empty()) {
        cout << "Error: Name cannot be empty!\n";
        pressEnter();
        return;
    }

    // Check if name already exists
    for(int i = 0; i < packageCount; i++) {
        if(string(packages[i].name) == name) {
            cout << "Error: Package with this name already exists!\n";
            pressEnter();
            return;
        }
    }

    string daysInput;
    cout << "Enter Number of Days : ";
    getline(cin, daysInput);
    if(!isDigits(daysInput) || stoi(daysInput) <= 0) {
        cout << "Error: Days must be a positive number!\n";
        pressEnter();
        return;
    }
    days = stoi(daysInput);

    string amountInput;
    cout << "Enter Amount (PKR)   : ";
    getline(cin, amountInput);
    if(!isDigits(amountInput) || stod(amountInput) <= 0) {
        cout << "Error: Amount must be a positive number!\n";
        pressEnter();
        return;
    }
    amount = stod(amountInput);

    cout << "Enter Package Type   : ";
    getline(cin, type);
    if(type.empty()) {
        cout << "Error: Type cannot be empty!\n";
        pressEnter();
        return;
    }

    cout << "Enter Inclusions     : ";
    getline(cin, includes);
    if(includes.empty()) {
        cout << "Error: Inclusions cannot be empty!\n";
        pressEnter();
        return;
    }

    myCopy(packages[packageCount].name,     60,  name);
    packages[packageCount].days   = days;
    packages[packageCount].amount = amount;
    myCopy(packages[packageCount].type,     30,  type);
    myCopy(packages[packageCount].includes, 100, includes);
    packageCount++;
    savePackages();

    cout << "\nPackage added successfully!\n";
    cout << "Name   : " << name << "\n";
    cout << "Days   : " << days << "\n";
    cout << "Amount : PKR " << amount << "\n";
    pressEnter();
}

void adminViewPackages() {
    system("cls");
    cout << "===== ALL PACKAGES =====\n\n";

    if(packageCount == 0) {
        cout << "No packages available.\n";
        pressEnter();
        return;
    }

    for(int i = 0; i < packageCount; i++) {
        cout << "------------------------------\n";
        cout << "No.      : " << (i + 1) << "\n";
        cout << "Name     : " << packages[i].name << "\n";
        cout << "Days     : " << packages[i].days << "\n";
        cout << "Amount   : PKR " << packages[i].amount << "\n";
        cout << "Type     : " << packages[i].type << "\n";
        cout << "Includes : " << packages[i].includes << "\n";
    }
    cout << "------------------------------\n";
    cout << "Total Packages: " << packageCount << "\n";
    pressEnter();
}

void adminUpdatePackage() {
    system("cls");
    cout << "===== UPDATE PACKAGE =====\n\n";

    if(packageCount == 0) {
        cout << "No packages available.\n";
        pressEnter();
        return;
    }

    cout << "Available Packages:\n";
    for(int i = 0; i < packageCount; i++) {
        cout << (i + 1) << ". " << packages[i].name << "\n";
    }

    cin.ignore();
    cout << "\nEnter Package Name to Update : ";
    string searchName;
    getline(cin, searchName);

    int idx = -1;
    for(int i = 0; i < packageCount; i++) {
        if(string(packages[i].name) == searchName) {
            idx = i;
            break;
        }
    }

    if(idx == -1) {
        cout << "Error: Package not found!\n";
        pressEnter();
        return;
    }

    cout << "\nCurrent Details:\n";
    cout << "Name   : " << packages[idx].name << "\n";
    cout << "Days   : " << packages[idx].days << "\n";
    cout << "Amount : PKR " << packages[idx].amount << "\n\n";

    cout << "Enter New Name   : ";
    string newName;
    getline(cin, newName);
    if(newName.empty()) {
        cout << "Error: Name cannot be empty!\n";
        pressEnter();
        return;
    }

    string daysInput;
    cout << "Enter New Days   : ";
    getline(cin, daysInput);
    if(!isDigits(daysInput) || stoi(daysInput) <= 0) {
        cout << "Error: Days must be positive!\n";
        pressEnter();
        return;
    }

    string amountInput;
    cout << "Enter New Amount : ";
    getline(cin, amountInput);
    if(!isDigits(amountInput) || stod(amountInput) <= 0) {
        cout << "Error: Amount must be positive!\n";
        pressEnter();
        return;
    }

    myCopy(packages[idx].name, 60, newName);
    packages[idx].days   = stoi(daysInput);
    packages[idx].amount = stod(amountInput);
    savePackages();

    cout << "\nPackage updated successfully!\n";
    pressEnter();
}

void adminDeletePackage() {
    system("cls");
    cout << "===== DELETE PACKAGE =====\n\n";

    if(packageCount == 0) {
        cout << "No packages available.\n";
        pressEnter();
        return;
    }

    cout << "Available Packages:\n";
    for(int i = 0; i < packageCount; i++) {
        cout << (i + 1) << ". " << packages[i].name << "\n";
    }

    cin.ignore();
    cout << "\nEnter Package Name to Delete : ";
    string delName;
    getline(cin, delName);

    int idx = -1;
    for(int i = 0; i < packageCount; i++) {
        if(string(packages[i].name) == delName) {
            idx = i;
            break;
        }
    }

    if(idx == -1) {
        cout << "Error: Package not found!\n";
        pressEnter();
        return;
    }

    cout << "\nAre you sure you want to delete: " << packages[idx].name << "?\n";
    cout << "1. Yes, Delete\n";
    cout << "2. No, Cancel\n";
    cout << "Enter choice : ";
    int choice;
    cin >> choice;

    if(choice == 1) {
        // Shift elements left to fill the gap
        for(int i = idx; i < packageCount - 1; i++) {
            packages[i] = packages[i + 1];
        }
        packageCount--;
        savePackages();
        cout << "\nPackage deleted successfully!\n";
    } else {
        cout << "\nDeletion cancelled.\n";
    }
    pressEnter();
}

void adminViewBookings() {
    system("cls");
    cout << "===== ALL BOOKINGS =====\n\n";

    if(bookingCount == 0) {
        cout << "No bookings found.\n";
        pressEnter();
        return;
    }

    for(int i = 0; i < bookingCount; i++) {
        cout << "------------------------------\n";
        cout << "Booking ID : " << bookings[i].bookingId << "\n";
        cout << "Customer   : " << bookings[i].userName << "\n";
        cout << "Package    : " << bookings[i].packageName << "\n";
        cout << "Date       : " << bookings[i].bookingDate << "\n";
        cout << "Payment    : " << bookings[i].paymentStatus << "\n";
        cout << "Status     : " << (bookings[i].cancelled ? "Cancelled" : "Active") << "\n";
    }
    cout << "------------------------------\n";

    int active = 0;
    for(int i = 0; i < bookingCount; i++) {
        if(!bookings[i].cancelled) active++;
    }
    cout << "Total: " << bookingCount << "  Active: " << active << "  Cancelled: " << (bookingCount - active) << "\n";
    pressEnter();
}

void adminCancelBooking() {
    system("cls");
    cout << "===== CANCEL A BOOKING =====\n\n";

    if(bookingCount == 0) {
        cout << "No bookings found.\n";
        pressEnter();
        return;
    }

    cin.ignore();
    cout << "Enter Booking ID to Cancel : ";
    string bid;
    getline(cin, bid);

    int idx = -1;
    for(int i = 0; i < bookingCount; i++) {
        if(string(bookings[i].bookingId) == bid && !bookings[i].cancelled) {
            idx = i;
            break;
        }
    }

    if(idx == -1) {
        cout << "Error: Booking not found or already cancelled!\n";
        pressEnter();
        return;
    }

    cout << "\nBooking Details:\n";
    cout << "Customer : " << bookings[idx].userName << "\n";
    cout << "Package  : " << bookings[idx].packageName << "\n";
    cout << "Date     : " << bookings[idx].bookingDate << "\n";

    cout << "\n1. Cancel this booking\n";
    cout << "2. Go back\n";
    cout << "Enter choice : ";
    int ch;
    cin >> ch;

    if(ch == 1) {
        bookings[idx].cancelled = true;
        saveBookings();
        cout << "\nBooking cancelled successfully!\n";
    } else {
        cout << "\nOperation cancelled.\n";
    }
    pressEnter();
}

void adminViewCustomers() {
    system("cls");
    cout << "===== ALL CUSTOMERS =====\n\n";

    if(userCount == 0) {
        cout << "No customers registered.\n";
        pressEnter();
        return;
    }

    for(int i = 0; i < userCount; i++) {
        int bcount = 0;
        for(int j = 0; j < bookingCount; j++) {
            if(string(bookings[j].userId) == string(users[i].username)) bcount++;
        }

        cout << "------------------------------\n";
        cout << "No.      : " << (i + 1) << "\n";
        cout << "Name     : " << users[i].fullName << "\n";
        cout << "Username : " << users[i].username << "\n";
        cout << "Phone    : " << users[i].phone << "\n";
        cout << "Email    : " << users[i].email << "\n";
        cout << "CNIC     : " << users[i].cnic << "\n";
        cout << "Bookings : " << bcount << "\n";
    }
    cout << "------------------------------\n";
    pressEnter();
}

void adminMenu() {
    int choice;
    do {
        system("cls");
        cout << "===================================\n";
        cout << "       ADMIN CONTROL PANEL\n";
        cout << "===================================\n";
        cout << "1.  Add Package\n";
        cout << "2.  View All Packages\n";
        cout << "3.  Update Package\n";
        cout << "4.  Delete Package\n";
        cout << "5.  View All Bookings\n";
        cout << "6.  Cancel a Booking\n";
        cout << "7.  View All Customers\n";
        cout << "0.  Logout\n";
        cout << "===================================\n";
        cout << "Enter choice : ";
        cin >> choice;

        if(choice == 1) adminAddPackage();
        else if(choice == 2) adminViewPackages();
        else if(choice == 3) adminUpdatePackage();
        else if(choice == 4) adminDeletePackage();
        else if(choice == 5) adminViewBookings();
        else if(choice == 6) adminCancelBooking();
        else if(choice == 7) adminViewCustomers();
        else if(choice == 0) cout << "\nLogged out.\n";
        else cout << "\nWrong choice! Try again.\n";

    } while(choice != 0);
}

// ====================== USER FUNCTIONS ======================

void userViewPackages() {
    system("cls");
    cout << "===== AVAILABLE PACKAGES =====\n\n";

    if(packageCount == 0) {
        cout << "No packages available at the moment.\n";
        pressEnter();
        return;
    }

    for(int i = 0; i < packageCount; i++) {
        cout << "------------------------------\n";
        cout << "No.      : " << (i + 1) << "\n";
        cout << "Name     : " << packages[i].name << "\n";
        cout << "Days     : " << packages[i].days << "\n";
        cout << "Amount   : PKR " << packages[i].amount << "\n";
        cout << "Type     : " << packages[i].type << "\n";
        cout << "Includes : " << packages[i].includes << "\n";
    }
    cout << "------------------------------\n";
    pressEnter();
}

void userBookPackage() {
    system("cls");
    cout << "===== BOOK A PACKAGE =====\n\n";

    if(packageCount == 0) {
        cout << "No packages available for booking.\n";
        pressEnter();
        return;
    }

    cout << "Available Packages:\n";
    for(int i = 0; i < packageCount; i++) {
        cout << (i + 1) << ". " << packages[i].name << "  -  PKR " << packages[i].amount << "  (" << packages[i].days << " days)\n";
    }

    cin.ignore();
    cout << "\nEnter Package Name to Book : ";
    string pkgName;
    getline(cin, pkgName);

    int pkgIdx = -1;
    for(int i = 0; i < packageCount; i++) {
        if(string(packages[i].name) == pkgName) {
            pkgIdx = i;
            break;
        }
    }

    if(pkgIdx == -1) {
        cout << "Error: Package not found!\n";
        pressEnter();
        return;
    }

    if(bookingCount >= MAX_BOOKINGS) {
        cout << "Error: Booking list is full!\n";
        pressEnter();
        return;
    }

    string bookingId = "BK" + to_string(bookingCount + 1001);

    myCopy(bookings[bookingCount].bookingId,     15, bookingId);
    myCopy(bookings[bookingCount].userId,        50, loggedInUser);
    myCopy(bookings[bookingCount].userName,      60, loggedInName);
    myCopy(bookings[bookingCount].packageName,   60, pkgName);
    myCopy(bookings[bookingCount].bookingDate,   15, getDate());
    myCopy(bookings[bookingCount].paymentStatus, 10, "Unpaid");
    bookings[bookingCount].bankName[0]      = '\0';
    bookings[bookingCount].accountNumber[0] = '\0';
    bookings[bookingCount].cancelled        = false;
    bookingCount++;
    saveBookings();

    cout << "\nBooking confirmed!\n";
    cout << "Booking ID : " << bookingId << "\n";
    cout << "Package    : " << pkgName << "\n";
    cout << "Date       : " << getDate() << "\n";
    cout << "Payment    : Unpaid (go to Payment option to pay)\n";
    pressEnter();
}

void userPayment() {
    system("cls");
    cout << "===== PAYMENT =====\n\n";

    // Find unpaid booking for this user
    int idx = -1;
    for(int i = 0; i < bookingCount; i++) {
        if(string(bookings[i].userId) == loggedInUser && !bookings[i].cancelled && string(bookings[i].paymentStatus) == "Unpaid") {
            idx = i;
            break;
        }
    }

    if(idx == -1) {
        cout << "No unpaid bookings found.\n";
        pressEnter();
        return;
    }

    cout << "Booking ID : " << bookings[idx].bookingId << "\n";
    cout << "Package    : " << bookings[idx].packageName << "\n";

    for(int j = 0; j < packageCount; j++) {
        if(string(packages[j].name) == string(bookings[idx].packageName)) {
            cout << "Amount     : PKR " << packages[j].amount << "\n";
            break;
        }
    }

    cin.ignore();
    cout << "\nEnter Bank Name      : ";
    string bankName;
    getline(cin, bankName);
    if(bankName.empty() || !isLetters(bankName)) {
        cout << "Error: Bank name must have letters only!\n";
        pressEnter();
        return;
    }

    cout << "Enter Account Number : ";
    string accNum;
    getline(cin, accNum);
    if(!isDigits(accNum) || accNum.length() < 8) {
        cout << "Error: Account number must be at least 8 digits!\n";
        pressEnter();
        return;
    }

    cout << "\n1. Confirm Payment\n";
    cout << "2. Cancel\n";
    cout << "Enter choice : ";
    int ch;
    cin >> ch;

    if(ch == 1) {
        myCopy(bookings[idx].paymentStatus, 10, "Paid");
        myCopy(bookings[idx].bankName,      60, bankName);
        myCopy(bookings[idx].accountNumber, 20, accNum);
        saveBookings();
        cout << "\nPayment successful!\n";
        cout << "Status     : Paid\n";
        cout << "Bank       : " << bankName << "\n";
        cout << "Account No : " << accNum << "\n";
    } else {
        cout << "\nPayment cancelled.\n";
    }
    pressEnter();
}

void userCancelBooking() {
    system("cls");
    cout << "===== CANCEL YOUR BOOKING =====\n\n";

    bool hasBooking = false;
    for(int i = 0; i < bookingCount; i++) {
        if(string(bookings[i].userId) == loggedInUser && !bookings[i].cancelled) {
            hasBooking = true;
            cout << "ID: " << bookings[i].bookingId << "  |  " << bookings[i].packageName << "  |  " << bookings[i].bookingDate << "\n";
        }
    }

    if(!hasBooking) {
        cout << "No active bookings found.\n";
        pressEnter();
        return;
    }

    cin.ignore();
    cout << "\nEnter Booking ID to Cancel : ";
    string bid;
    getline(cin, bid);

    int idx = -1;
    for(int i = 0; i < bookingCount; i++) {
        if(string(bookings[i].bookingId) == bid && string(bookings[i].userId) == loggedInUser && !bookings[i].cancelled) {
            idx = i;
            break;
        }
    }

    if(idx == -1) {
        cout << "Error: Booking not found!\n";
        pressEnter();
        return;
    }

    cout << "\n1. Confirm Cancellation\n";
    cout << "2. Go back\n";
    cout << "Enter choice : ";
    int ch;
    cin >> ch;

    if(ch == 1) {
        bookings[idx].cancelled = true;
        saveBookings();
        cout << "\nBooking cancelled successfully.\n";
    } else {
        cout << "\nOperation cancelled.\n";
    }
    pressEnter();
}

void userViewBookings() {
    system("cls");
    cout << "===== YOUR BOOKINGS =====\n\n";

    bool found = false;
    for(int i = 0; i < bookingCount; i++) {
        if(string(bookings[i].userId) == loggedInUser && !bookings[i].cancelled) {
            found = true;
            cout << "------------------------------\n";
            cout << "Booking ID : " << bookings[i].bookingId << "\n";
            cout << "Package    : " << bookings[i].packageName << "\n";
            cout << "Date       : " << bookings[i].bookingDate << "\n";
            cout << "Payment    : " << bookings[i].paymentStatus << "\n";
            if(string(bookings[i].paymentStatus) == "Paid") {
                cout << "Bank       : " << bookings[i].bankName << "\n";
                cout << "Account No : " << bookings[i].accountNumber << "\n";
            }
            for(int j = 0; j < packageCount; j++) {
                if(string(packages[j].name) == string(bookings[i].packageName)) {
                    cout << "Duration   : " << packages[j].days << " Days\n";
                    cout << "Amount     : PKR " << packages[j].amount << "\n";
                    break;
                }
            }
        }
    }

    if(!found) cout << "No active bookings found.\n";
    cout << "------------------------------\n";
    pressEnter();
}

void userBookingHistory() {
    system("cls");
    cout << "===== BOOKING HISTORY =====\n\n";

    int total = 0, active = 0, cancelled = 0;
    for(int i = 0; i < bookingCount; i++) {
        if(string(bookings[i].userId) == loggedInUser) {
            total++;
            if(bookings[i].cancelled) cancelled++;
            else active++;
        }
    }

    cout << "Total Bookings     : " << total << "\n";
    cout << "Active Bookings    : " << active << "\n";
    cout << "Cancelled Bookings : " << cancelled << "\n\n";

    if(total == 0) {
        cout << "No booking history found.\n";
        pressEnter();
        return;
    }

    cout << "Booking ID   Package Name             Date          Payment    Status\n";
    cout << "----------------------------------------------------------------------\n";

    for(int i = 0; i < bookingCount; i++) {
        if(string(bookings[i].userId) == loggedInUser) {
            cout << bookings[i].bookingId << "   "
                 << bookings[i].packageName << "   "
                 << bookings[i].bookingDate << "   "
                 << bookings[i].paymentStatus << "   "
                 << (bookings[i].cancelled ? "Cancelled" : "Active") << "\n";
        }
    }
    pressEnter();
}

void userCheckPayment() {
    system("cls");
    cout << "===== PAYMENT STATUS =====\n\n";

    bool found = false;
    for(int i = 0; i < bookingCount; i++) {
        if(string(bookings[i].userId) == loggedInUser && !bookings[i].cancelled) {
            found = true;
            cout << "Booking ID : " << bookings[i].bookingId << "\n";
            cout << "Package    : " << bookings[i].packageName << "\n";
            cout << "Status     : " << bookings[i].paymentStatus << "\n\n";
        }
    }

    if(!found) cout << "No active bookings found.\n";
    pressEnter();
}

void userMenu() {
    int choice;
    do {
        system("cls");
        cout << "===================================\n";
        cout << "   Welcome, " << loggedInName << "\n";
        cout << "         USER PANEL\n";
        cout << "===================================\n";
        cout << "1.  View Packages\n";
        cout << "2.  Book a Package\n";
        cout << "3.  Make Payment\n";
        cout << "4.  Cancel Booking\n";
        cout << "5.  View My Bookings\n";
        cout << "6.  Check Payment Status\n";
        cout << "7.  Booking History\n";
        cout << "0.  Logout\n";
        cout << "===================================\n";
        cout << "Enter choice : ";
        cin >> choice;

        if(choice == 1) userViewPackages();
        else if(choice == 2) userBookPackage();
        else if(choice == 3) userPayment();
        else if(choice == 4) userCancelBooking();
        else if(choice == 5) userViewBookings();
        else if(choice == 6) userCheckPayment();
        else if(choice == 7) userBookingHistory();
        else if(choice == 0) cout << "\nLogged out.\n";
        else cout << "\nWrong choice! Try again.\n";

    } while(choice != 0);
}

// ====================== LOGIN FUNCTIONS ======================

bool adminLogin() {
    system("cls");
    cout << "===== ADMIN LOGIN =====\n\n";

    string uname, pass;

    cout << "Enter Username : ";
    cin >> uname;

    cout << "Enter Password : ";
    pass = "";
    char ch;
    while((ch = getch()) != 13) {
        if(ch == 8) {
            if(!pass.empty()) {
                pass.pop_back();
                cout << "\b \b";
            }
        } else {
            pass += ch;
            cout << "*";
        }
    }
    cout << "\n";

    if(uname == adminUsername && pass == adminPassword) {
        cout << "\nLogin successful! Welcome Admin.\n";
        Sleep(800);
        return true;
    } else {
        cout << "\nWrong username or password!\n";
        pressEnter();
        return false;
    }
}

bool userLogin() {
    system("cls");
    cout << "===== USER LOGIN =====\n\n";

    string uname, pass;

    cout << "Enter Username : ";
    cin >> uname;

    cout << "Enter Password : ";
    pass = "";
    char ch;
    while((ch = getch()) != 13) {
        if(ch == 8) {
            if(!pass.empty()) {
                pass.pop_back();
                cout << "\b \b";
            }
        } else {
            pass += ch;
            cout << "*";
        }
    }
    cout << "\n";

    for(int i = 0; i < userCount; i++) {
        if(string(users[i].username) == uname && string(users[i].password) == pass) {
            loggedInUser = uname;
            loggedInName = string(users[i].fullName);
            cout << "\nLogin successful! Welcome, " << users[i].fullName << "\n";
            Sleep(800);
            return true;
        }
    }

    cout << "\nWrong username or password!\n";
    pressEnter();
    return false;
}

// ====================== REGISTRATION ======================

void userRegister() {
    system("cls");
    cout << "===== NEW USER REGISTRATION =====\n\n";

    if(userCount >= MAX_USERS) {
        cout << "Error: User limit reached!\n";
        pressEnter();
        return;
    }

    string uname, pass, fullname, phone, email, cnic;

    cout << "Enter Username       : ";
    cin >> uname;
    if(uname.length() < 4) {
        cout << "Error: Username must be at least 4 characters!\n";
        pressEnter();
        return;
    }
    for(int i = 0; i < userCount; i++) {
        if(string(users[i].username) == uname) {
            cout << "Error: Username already taken!\n";
            pressEnter();
            return;
        }
    }

    cout << "Enter Password       : ";
    pass = "";
    char ch;
    while((ch = getch()) != 13) {
        if(ch == 8) {
            if(!pass.empty()) { pass.pop_back(); cout << "\b \b"; }
        } else {
            pass += ch;
            cout << "*";
        }
    }
    cout << "\n";
    if(pass.length() < 6) {
        cout << "Error: Password must be at least 6 characters!\n";
        pressEnter();
        return;
    }

    cin.ignore();

    cout << "Enter Full Name      : ";
    getline(cin, fullname);
    if(fullname.length() < 3 || !isLetters(fullname)) {
        cout << "Error: Full name must be letters only, at least 3 characters!\n";
        pressEnter();
        return;
    }

    cout << "Enter Phone Number   : ";
    getline(cin, phone);
    if(!isDigits(phone) || phone.length() < 10 || phone.length() > 15) {
        cout << "Error: Phone must be 10 to 15 digits!\n";
        pressEnter();
        return;
    }

    cout << "Enter Email          : ";
    getline(cin, email);
    if(email.find('@') == string::npos || email.find('.') == string::npos) {
        cout << "Error: Invalid email! Must have @ and .\n";
        pressEnter();
        return;
    }

    cout << "Enter CNIC (13 digits, e.g. 42201-1234567-1) : ";
    getline(cin, cnic);
    string digits = "";
    for(int i = 0; i < (int)cnic.length(); i++) {
        if(cnic[i] >= '0' && cnic[i] <= '9') digits += cnic[i];
    }
    if(digits.length() != 13) {
        cout << "Error: CNIC must have exactly 13 digits!\n";
        pressEnter();
        return;
    }

    myCopy(users[userCount].username, 50, uname);
    myCopy(users[userCount].password, 50, pass);
    myCopy(users[userCount].fullName, 60, fullname);
    myCopy(users[userCount].phone,    20, phone);
    myCopy(users[userCount].email,    60, email);
    myCopy(users[userCount].cnic,     20, cnic);
    userCount++;
    saveUsers();

    cout << "\nRegistration successful!\n";
    cout << "Username : " << uname << "\n";
    cout << "You can now login.\n";
    pressEnter();
}

// ====================== MAIN ======================

int main() {
    // Load saved data from files
    loadPackages();
    loadBookings();
    loadUsers();
    addDefaultPackages();

    cout << "===================================\n";
    cout << "  UMRAH PACKAGE BOOKING SYSTEM\n";
    cout << "  AL-HARAMAIN TOURS & TRAVELS\n";
    cout << "===================================\n\n";
    Sleep(1000);

    int mainChoice;
    do {
        system("cls");
        cout << "===================================\n";
        cout << "         MAIN MENU\n";
        cout << "===================================\n";
        cout << "1.  Admin Login\n";
        cout << "2.  User Login\n";
        cout << "3.  New User Registration\n";
        cout << "0.  Exit\n";
        cout << "===================================\n";
        cout << "Enter choice : ";
        cin >> mainChoice;

        if(mainChoice == 1) {
            if(adminLogin()) adminMenu();
        }
        else if(mainChoice == 2) {
            if(userLogin()) userMenu();
        }
        else if(mainChoice == 3) {
            userRegister();
        }
        else if(mainChoice == 0) {
            cout << "\nThank you! Goodbye.\n";
        }
        else {
            cout << "\nWrong choice!\n";
            Sleep(600);
        }

    } while(mainChoice != 0);

    return 0;
}