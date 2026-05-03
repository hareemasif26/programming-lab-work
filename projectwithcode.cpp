#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
#include<windows.h>
#include<iomanip>
#include<ctime>
#include<sstream>
#include<cctype>

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void setColor(int color){
    SetConsoleTextAttribute(hConsole, color);
}

void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(hConsole, coord);
}

void hideCursor(){
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

void showCursor(){
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 10;
    cursorInfo.bVisible = TRUE;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

void clearScreen(){
    system("cls");
}

void drawBox(int x, int y, int width, int height, int color){
    setColor(color);
    gotoxy(x, y);
    cout << char(201);
    for(int i = 0; i < width - 2; i++) cout << char(205);
    cout << char(187);
    for(int i = 1; i < height - 1; i++){
        gotoxy(x, y + i);
        cout << char(186);
        gotoxy(x + width - 1, y + i);
        cout << char(186);
    }
    gotoxy(x, y + height - 1);
    cout << char(200);
    for(int i = 0; i < width - 2; i++) cout << char(205);
    cout << char(188);
}

void printCentered(int y, int width, string text, int color){
    setColor(color);
    int x = (width - text.length()) / 2;
    gotoxy(x, y);
    cout << text;
}

string getCurrentDate(){
    time_t now = time(0);
    tm* ltm = localtime(&now);
    stringstream ss;
    ss << setfill('0') << setw(2) << ltm->tm_mday << "/"
       << setfill('0') << setw(2) << (1 + ltm->tm_mon) << "/"
       << (1900 + ltm->tm_year);
    return ss.str();
}

// ====================== VALIDATION FUNCTIONS ======================

bool isAlphaOnly(const string& s){
    if(s.empty()) return false;
    for(char c : s){
        if(!isalpha(c) && c != ' ') return false;
    }
    return true;
}

bool isDigitsOnly(const string& s){
    if(s.empty()) return false;
    for(char c : s){
        if(!isdigit(c)) return false;
    }
    return true;
}

bool isValidPhone(const string& s){
    if(s.empty()) return false;
    for(char c : s){
        if(!isdigit(c) && c != '+' && c != '-') return false;
    }
    return s.length() >= 10 && s.length() <= 15;
}

bool isValidCNIC(const string& s){
    // Format: 42201-1234567-1 (13 digits with dashes) or 13 digits only
    string digits = "";
    for(char c : s){
        if(isdigit(c)) digits += c;
        else if(c != '-') return false;
    }
    return digits.length() == 13;
}

bool isValidEmail(const string& s){
    if(s.empty()) return false;
    int atCount = 0;
    int atPos = -1;
    for(int i = 0; i < (int)s.length(); i++){
        if(s[i] == '@'){
            atCount++;
            atPos = i;
        }
    }
    if(atCount != 1 || atPos == 0 || atPos == (int)s.length()-1) return false;
    // Must have a dot after @
    string afterAt = s.substr(atPos + 1);
    bool hasDot = false;
    for(char c : afterAt){
        if(c == '.') hasDot = true;
    }
    return hasDot && afterAt.length() > 2;
}

bool isValidUsername(const string& s){
    if(s.length() < 4) return false;
    for(char c : s){
        if(!isalnum(c) && c != '_') return false;
    }
    return true;
}

bool isValidPassword(const string& s){
    return s.length() >= 6;
}

void showError(const string& msg){
    setColor(12);
    cout << "\n  [!] " << msg << "\n";
    setColor(7);
}

void showSuccess(const string& msg){
    setColor(10);
    cout << "\n  [+] " << msg << "\n";
    setColor(7);
}

// ====================== STRUCTURES ======================

struct Package {
    string name;
    int days;
    double amount;
    string type;
    string includes;
};

struct Booking {
    string bookingId;
    string userId;
    string userName;
    string packageName;
    string bookingDate;
    string paymentStatus;
    string bankName;
    string accountNumber;
    bool cancelled;
};

struct User {
    string username;
    string password;
    string fullName;
    string phone;
    string email;
    string cnic;
};

// ====================== PREDEFINED ADMIN ACCOUNTS ======================

struct AdminAccount {
    string username;
    string password;
    string displayName;
};

const int ADMIN_COUNT = 3;
AdminAccount admins[ADMIN_COUNT] = {
    {"admin",     "admin123",   "Super Admin"},
    {"manager",   "manager@456","Tour Manager"},
    {"staff",     "staff#789",  "Staff Member"}
};

const int MAX_PACKAGES = 50;
const int MAX_BOOKINGS = 200;
const int MAX_USERS = 100;

Package packages[MAX_PACKAGES];
Booking bookings[MAX_BOOKINGS];
User users[MAX_USERS];

int packageCount = 0;
int bookingCount = 0;
int userCount = 0;

string loggedInUser = "";
string loggedInName = "";

// ====================== FILE OPERATIONS ======================

void savePackages(){
    ofstream file("packages.dat");
    file << packageCount << " ";
    for(int i = 0; i < packageCount; i++){
        file << packages[i].name << " ";
        file << packages[i].days << " ";
        file << packages[i].amount << " ";
        file << packages[i].type << " ";
        file << packages[i].includes << " ";
    }
    file.close();
}

void loadPackages(){
    ifstream file("packages.dat");
    if(!file.is_open()) return;
    file >> packageCount;
    file.ignore();
    for(int i = 0; i < packageCount; i++){
        getline(file, packages[i].name);
        file >> packages[i].days;
        file >> packages[i].amount;
        file.ignore();
        getline(file, packages[i].type);
        getline(file, packages[i].includes);
    }
    file.close();
}

void saveBookings(){
    ofstream file("bookings.dat");
    file << bookingCount << " ";
    for(int i = 0; i < bookingCount; i++){
        file << bookings[i].bookingId << " ";
        file << bookings[i].userId << " ";
        file << bookings[i].userName << " ";
        file << bookings[i].packageName << " ";
        file << bookings[i].bookingDate << " ";
        file << bookings[i].paymentStatus << " ";
        file << bookings[i].bankName << " ";
        file << bookings[i].accountNumber << " ";
        file << bookings[i].cancelled << " ";
    }
    file.close();
}

void loadBookings(){
    ifstream file("bookings.dat");
    if(!file.is_open()) return;
    file >> bookingCount;
    file.ignore();
    for(int i = 0; i < bookingCount; i++){
        getline(file, bookings[i].bookingId);
        getline(file, bookings[i].userId);
        getline(file, bookings[i].userName);
        getline(file, bookings[i].packageName);
        getline(file, bookings[i].bookingDate);
        getline(file, bookings[i].paymentStatus);
        getline(file, bookings[i].bankName);
        getline(file, bookings[i].accountNumber);
        file >> bookings[i].cancelled;
        file.ignore();
    }
    file.close();
}

void saveUsers(){
    ofstream file("users.dat");
    file << userCount << " ";
    for(int i = 0; i < userCount; i++){
        file << users[i].username << " ";
        file << users[i].password << " ";
        file << users[i].fullName << " ";
        file << users[i].phone << " ";
        file << users[i].email << " ";
        file << users[i].cnic << " ";
    }
    file.close();
}

void loadUsers(){
    ifstream file("users.dat");
    if(!file.is_open()) return;
    file >> userCount;
    file.ignore();
    for(int i = 0; i < userCount; i++){
        getline(file, users[i].username);
        getline(file, users[i].password);
        getline(file, users[i].fullName);
        getline(file, users[i].phone);
        getline(file, users[i].email);
        getline(file, users[i].cnic);
    }
    file.close();
}

void initializeDefaultData(){
    if(packageCount == 0){
        packages[0].name = "Silver Package";
        packages[0].days = 14;
        packages[0].amount = 150000;
        packages[0].type = "Economy";
        packages[0].includes = "Flight + Hotel (3-Star) + Transport";

        packages[1].name = "Gold Package";
        packages[1].days = 21;
        packages[1].amount = 250000;
        packages[1].type = "Standard";
        packages[1].includes = "Flight + Hotel (4-Star) + Transport + Ziyarat";

        packages[2].name = "Diamond Package";
        packages[2].days = 30;
        packages[2].amount = 400000;
        packages[2].type = "Premium";
        packages[2].includes = "Flight + Hotel (5-Star) + Transport + Ziyarat + Meals";

        packageCount = 3;
        savePackages();
    }
}

void displayHeader(){
    setColor(14);
    cout << "  ";
    for(int i=0;i<78;i++) cout << char(205);
    cout << " ";
    setColor(11);
    cout << "  " << char(186) << "                                                                              " << char(186) << "\n";
    setColor(14);
    cout << "  " << char(186);
    setColor(10);
    cout << "              ** UMRAH PACKAGE BOOKING MANAGEMENT SYSTEM **                  ";
    setColor(14);
    cout << char(186) << " ";
    setColor(11);
    cout << "  " << char(186) << "                     AL-HARAMAIN TOURS & TRAVELS                              " << char(186) << "\n";
    cout << "  " << char(186) << "                                                                              " << char(186) << "\n";
    setColor(14);
    cout << "  ";
    for(int i=0;i<78;i++) cout << char(205);
    cout << " ";
    setColor(7);
}

void pressAnyKey(){
    setColor(11);
    cout << " Press any key to return to main menu...";
    setColor(7);
    getch();
}

// ====================== ADMIN FUNCTIONS ======================

void adminAddPackage(){
    clearScreen();
    displayHeader();
    setColor(14);
    cout << "\n  " << char(201);
    for(int i=0;i<60;i++) cout << char(205);
    cout << char(187) << "";
    cout << "  " << char(186) << "              ADD NEW UMRAH PACKAGE                         " << char(186) << "\n";
    cout << "  " << char(200);
    for(int i=0;i<60;i++) cout << char(205);
    cout << char(188) << "";
    setColor(7);

    if(packageCount >= MAX_PACKAGES){
        showError("Package storage full!");
        pressAnyKey();
        return;
    }

    string pname, ptype, pincludes;
    int pdays;
    double pamount;

    cin.ignore();

    // Package Name
    while(true){
        setColor(11);
        cout << " Enter Package Name     : ";
        setColor(7);
        getline(cin, pname);
        if(pname.empty()){
            showError("Package name cannot be empty!");
            continue;
        }
        bool exists = false;
        for(int i = 0; i < packageCount; i++){
            if(packages[i].name == pname){ exists = true; break; }
        }
        if(exists){ showError("Package with this name already exists!"); continue; }
        break;
    }

    // Days
    while(true){
        setColor(11);
        cout << "  Enter Number of Days   : ";
        setColor(7);
        string inp; getline(cin, inp);
        if(!isDigitsOnly(inp) || stoi(inp) <= 0){
            showError("Days must be a positive number (digits only)!");
            continue;
        }
        pdays = stoi(inp);
        break;
    }

    // Amount
    while(true){
        setColor(11);
        cout << "  Enter Package Amount   : ";
        setColor(7);
        string inp; getline(cin, inp);
        bool valid = !inp.empty();
        int dotCount = 0;
        for(char c : inp){
            if(!isdigit(c) && c != '.') { valid = false; break; }
            if(c == '.') dotCount++;
        }
        if(!valid || dotCount > 1 || stod(inp) <= 0){
            showError("Amount must be a valid positive number!");
            continue;
        }
        pamount = stod(inp);
        break;
    }

    // Type
    while(true){
        setColor(11);
        cout << "  Enter Package Type     : ";
        setColor(7);
        getline(cin, ptype);
        if(ptype.empty()){
            showError("Package type cannot be empty!");
            continue;
        }
        break;
    }

    // Inclusions
    while(true){
        setColor(11);
        cout << "  Enter Inclusions       : ";
        setColor(7);
        getline(cin, pincludes);
        if(pincludes.empty()){
            showError("Inclusions cannot be empty!");
            continue;
        }
        break;
    }

    packages[packageCount].name = pname;
    packages[packageCount].days = pdays;
    packages[packageCount].amount = pamount;
    packages[packageCount].type = ptype;
    packages[packageCount].includes = pincludes;
    packageCount++;
    savePackages();

    setColor(10);
    cout << " " << char(201);
    for(int i=0;i<50;i++) cout << char(205);
    cout << char(187) << "";
    cout << "  " << char(186) << "   Package Added Successfully!                    " << char(186) << " ";
    cout << "  " << char(186) << "   Package Name : " << left << setw(32) << pname << char(186) << " ";
    cout << "  " << char(186) << "   Days         : " << left << setw(32) << pdays << char(186) << " ";
    cout << "  " << char(186) << "   Amount       : PKR " << left << setw(29) << pamount << char(186) << " ";
    cout << "  " << char(200);
    for(int i=0;i<50;i++) cout << char(205);
    cout << char(188) << "";
    setColor(7);
    pressAnyKey();
}

void adminViewPackages(){
    clearScreen();
    displayHeader();
    setColor(14);
    cout << "  " << char(201);
    for(int i=0;i<76;i++) cout << char(205);
    cout << char(187) << "";
    cout << "  " << char(186) << "                        ALL AVAILABLE UMRAH PACKAGES                            " << char(186) << " ";
    cout << "  " << char(200);
    for(int i=0;i<76;i++) cout << char(205);
    cout << char(188) << "";

    if(packageCount == 0){
        showError("No packages available.");
        pressAnyKey();
        return;
    }

    setColor(11);
    cout << " " << left << setw(5) << "No." << setw(22) << "Package Name" << setw(8) << "Days" << setw(16) << "Amount (PKR)" << setw(15) << "Type" << "Inclusions";
    setColor(14);
    cout << "  ";
    for(int i=0;i<76;i++) cout << char(196);
    cout << "";
    setColor(7);

    for(int i = 0; i < packageCount; i++){
        setColor(10);
        cout << "  " << left << setw(5) << (i+1);
        setColor(15);
        cout << setw(22) << packages[i].name;
        setColor(11);
        cout << setw(8) << packages[i].days;
        setColor(14);
        cout << setw(16) << packages[i].amount;
        setColor(13);
        cout << setw(15) << packages[i].type;
        setColor(7);
        cout << packages[i].includes << " ";
    }

    setColor(14);
    cout << "  ";
    for(int i=0;i<76;i++) cout << char(196);
    cout << " ";
    setColor(11);
    cout << "  Total Packages: " << packageCount << " ";
    setColor(7);
    pressAnyKey();
}

void adminViewPackagesSummary(){
    clearScreen();
    displayHeader();
    setColor(14);
    cout << "" << char(201);
    for(int i=0;i<60;i++) cout << char(205);
    cout << char(187) << "";
    cout << "  " << char(186) << "                 PACKAGES SUMMARY REPORT                    " << char(186) << " ";
    cout << "  " << char(200);
    for(int i=0;i<60;i++) cout << char(205);
    cout << char(188) << "";

    setColor(11);
    cout << "  Total Packages Available : " << packageCount << "";

    double totalRevenue = 0;
    for(int i = 0; i < bookingCount; i++){
        if(!bookings[i].cancelled && bookings[i].paymentStatus == "Paid"){
            for(int j = 0; j < packageCount; j++){
                if(packages[j].name == bookings[i].packageName){
                    totalRevenue += packages[j].amount;
                    break;
                }
            }
        }
    }

    setColor(10);
    cout << "  Total Revenue Collected  : PKR " << fixed << setprecision(2) << totalRevenue << "";
    setColor(7);

    for(int i = 0; i < packageCount; i++){
        int bookingsCnt = 0;
        for(int j = 0; j < bookingCount; j++){
            if(bookings[j].packageName == packages[i].name && !bookings[j].cancelled)
                bookingsCnt++;
        }
        setColor(14);
        cout << "  " << char(254) << " ";
        setColor(15);
        cout << left << setw(25) << packages[i].name;
        setColor(11);
        cout << "Bookings: " << bookingsCnt;
        setColor(10);
        cout << "   Revenue: PKR " << (bookingsCnt * packages[i].amount) << "";
    }

    setColor(7);
    pressAnyKey();
}

void adminUpdatePackage(){
    clearScreen();
    displayHeader();
    setColor(14);
    cout << "  " << char(201);
    for(int i=0;i<60;i++) cout << char(205);
    cout << char(187) << "";
    cout << "  " << char(186) << "               UPDATE UMRAH PACKAGE                         " << char(186) << "\n";
    cout << "  " << char(200);
    for(int i=0;i<60;i++) cout << char(205);
    cout << char(188) << "";

    if(packageCount == 0){
        showError("No packages available to update.");
        pressAnyKey();
        return;
    }

    setColor(11);
    cout << "  Available Packages:";
    setColor(14);
    cout << "  ";
    for(int i=0;i<50;i++) cout << char(196);
    cout << " ";
    for(int i = 0; i < packageCount; i++){
        setColor(10);
        cout << "  [" << (i+1) << "] ";
        setColor(15);
        cout << packages[i].name << "";
    }
    setColor(14);
    cout << "  ";
    for(int i=0;i<50;i++) cout << char(196);
    cout << "";

    setColor(11);
    cout << "  Enter Package Name to Update : ";
    setColor(7);
    cin.ignore();
    string searchName;
    getline(cin, searchName);

    int idx = -1;
    for(int i = 0; i < packageCount; i++){
        if(packages[i].name == searchName){ idx = i; break; }
    }

    if(idx == -1){
        showError("Package not found!");
        pressAnyKey();
        return;
    }

    setColor(10);
    cout << "Current Details:";
    cout << "  Name    : " << packages[idx].name << "";
    cout << "  Days    : " << packages[idx].days << "";
    cout << "  Amount  : PKR " << packages[idx].amount << "";

    string newName;
    while(true){
        setColor(11);
        cout << "  Enter New Package Name   : ";
        setColor(7);
        getline(cin, newName);
        if(newName.empty()){ showError("Name cannot be empty!"); continue; }
        break;
    }

    int newDays;
    while(true){
        setColor(11);
        cout << "  Enter New Number of Days : ";
        setColor(7);
        string inp; getline(cin, inp);
        if(!isDigitsOnly(inp) || stoi(inp) <= 0){
            showError("Days must be a positive number!");
            continue;
        }
        newDays = stoi(inp);
        break;
    }

    double newAmount;
    while(true){
        setColor(11);
        cout << "  Enter New Amount         : ";
        setColor(7);
        string inp; getline(cin, inp);
        bool valid = !inp.empty();
        int dotCount = 0;
        for(char c : inp){
            if(!isdigit(c) && c != '.') { valid = false; break; }
            if(c == '.') dotCount++;
        }
        if(!valid || dotCount > 1 || stod(inp) <= 0){
            showError("Amount must be a valid positive number!");
            continue;
        }
        newAmount = stod(inp);
        break;
    }

    packages[idx].name = newName;
    packages[idx].days = newDays;
    packages[idx].amount = newAmount;
    savePackages();

    setColor(10);
    cout << " " << char(201);
    for(int i=0;i<40;i++) cout << char(205);
    cout << char(187) << "";
    cout << "  " << char(186) << "      Updated Successfully!               " << char(186) << "\n";
    cout << "  " << char(200);
    for(int i=0;i<40;i++) cout << char(205);
    cout << char(188) << "";
    setColor(7);
    pressAnyKey();
}

void adminDeletePackage(){
    clearScreen();
    displayHeader();
    setColor(14);
    cout << "  " << char(201);
    for(int i=0;i<60;i++) cout << char(205);
    cout << char(187) << "";
    cout << "  " << char(186) << "               DELETE UMRAH PACKAGE                         " << char(186) << "";
    cout << "  " << char(200);
    for(int i=0;i<60;i++) cout << char(205);
    cout << char(188) << "";

    if(packageCount == 0){
        showError("No packages available.");
        pressAnyKey();
        return;
    }

    setColor(11);
    cout << "  Available Packages:";
    for(int i = 0; i < packageCount; i++){
        setColor(10);
        cout << "  [" << (i+1) << "] ";
        setColor(15);
        cout << packages[i].name << "";
    }

    setColor(11);
    cout << " Enter Package Name to Delete : ";
    setColor(7);
    cin.ignore();
    string delName;
    getline(cin, delName);

    int idx = -1;
    for(int i = 0; i < packageCount; i++){
        if(packages[i].name == delName){ idx = i; break; }
    }

    if(idx == -1){
        showError("Package not found!");
        pressAnyKey();
        return;
    }

    setColor(14);
    cout << " Package Found: " << packages[idx].name << "";
    setColor(12);
    cout << "  [1] Delete";
    setColor(11);
    cout << "  [2] Cancel";
    setColor(7);
    cout << " Enter Choice : ";
    int choice;
    cin >> choice;

    if(choice == 1){
        for(int i = idx; i < packageCount - 1; i++) packages[i] = packages[i+1];
        packageCount--;
        savePackages();
        setColor(10);
        cout << " " << char(201);
        for(int i=0;i<40;i++) cout << char(205);
        cout << char(187) << "";
        cout << "  " << char(186) << "      Deleted Successfully!               " << char(186) << "";
        cout << "  " << char(200);
        for(int i=0;i<40;i++) cout << char(205);
        cout << char(188) << "";
    } else {
        setColor(13);
        cout << " Deletion Cancelled.";
    }
    setColor(7);
    pressAnyKey();
}

void adminSearchPackage(){
    clearScreen();
    displayHeader();
    setColor(14);
    cout << " " << char(201);
    for(int i=0;i<60;i++) cout << char(205);
    cout << char(187) << "";
    cout << "  " << char(186) << "               SEARCH UMRAH PACKAGE                         " << char(186) << "";
    cout << "  " << char(200);
    for(int i=0;i<60;i++) cout << char(205);
    cout << char(188) << "";

    setColor(11);
    cout << "  Enter Package Name : ";
    setColor(7);
    cin.ignore();
    string searchName;
    getline(cin, searchName);

    int idx = -1;
    for(int i = 0; i < packageCount; i++){
        if(packages[i].name == searchName){ idx = i; break; }
    }

    if(idx == -1){
        showError("Package not found!");
        pressAnyKey();
        return;
    }

    setColor(14);
    cout << " " << char(201);
    for(int i=0;i<55;i++) cout << char(205);
    cout << char(187) << "";
    cout << "  " << char(186) << "               PACKAGE DETAILS                          " << char(186) << "";
    cout << "  " << char(204);
    for(int i=0;i<55;i++) cout << char(205);
    cout << char(185) << "";
    setColor(15);
    cout << "  " << char(186) << "  Package Name  : " << left << setw(38) << packages[idx].name << char(186) << "";
    setColor(11);
    cout << "  " << char(186) << "  Duration      : " << left << setw(35) << (to_string(packages[idx].days) + " Days") << char(186) << "";
    setColor(10);
    cout << "  " << char(186) << "  Amount        : PKR " << left << setw(34) << packages[idx].amount << char(186) << "";
    setColor(13);
    cout << "  " << char(186) << "  Package Type  : " << left << setw(38) << packages[idx].type << char(186) << "";
    setColor(14);
    cout << "  " << char(186) << "  Inclusions    : " << left << setw(38) << packages[idx].includes << char(186) << "";
    cout << "  " << char(200);
    for(int i=0;i<55;i++) cout << char(205);
    cout << char(188) << "";
    setColor(7);
    pressAnyKey();
}

void adminViewBookings(){
    clearScreen();
    displayHeader();
    setColor(14);
    cout << "" << char(201);
    for(int i=0;i<76;i++) cout << char(205);
    cout << char(187) << "";
    cout << "  " << char(186) << "                         ALL BOOKINGS LIST                                      " << char(186) << "";
    cout << "  " << char(200);
    for(int i=0;i<76;i++) cout << char(205);
    cout << char(188) << "";

    if(bookingCount == 0){
        showError("No bookings found.");
        pressAnyKey();
        return;
    }

    setColor(11);
    cout << "  " << left << setw(12) << "Booking ID" << setw(16) << "Customer" << setw(22) << "Package" << setw(13) << "Date" << setw(8) << "Payment" << "Status";
    setColor(14);
    cout << "  ";
    for(int i=0;i<76;i++) cout << char(196);
    cout << "";

    for(int i = 0; i < bookingCount; i++){
        if(bookings[i].cancelled){
            setColor(12);
            cout << "  " << left << setw(12) << bookings[i].bookingId << setw(16) << bookings[i].userName
                 << setw(22) << bookings[i].packageName << setw(13) << bookings[i].bookingDate
                 << setw(8) << bookings[i].paymentStatus << "Cancelled\n";
        } else {
            setColor(10);
            cout << "  " << left << setw(12) << bookings[i].bookingId;
            setColor(15);
            cout << setw(16) << bookings[i].userName;
            setColor(11);
            cout << setw(22) << bookings[i].packageName;
            setColor(14);
            cout << setw(13) << bookings[i].bookingDate;
            if(bookings[i].paymentStatus == "Paid") setColor(10);
            else setColor(12);
            cout << setw(8) << bookings[i].paymentStatus;
            setColor(10);
            cout << "Active";
        }
    }

    setColor(14);
    cout << "  ";
    for(int i=0;i<76;i++) cout << char(196);
    cout << "";
    setColor(11);
    int activeCount = 0;
    for(int i = 0; i < bookingCount; i++) if(!bookings[i].cancelled) activeCount++;
    cout << "  Total Bookings: " << bookingCount << "   Active: " << activeCount << "   Cancelled: " << (bookingCount - activeCount) << "";
    setColor(7);
    pressAnyKey();
}

void adminCancelBooking(){
    clearScreen();
    displayHeader();
    setColor(14);
    cout << "" << char(201);
    for(int i=0;i<60;i++) cout << char(205);
    cout << char(187) << "";
    cout << "  " << char(186) << "               CANCEL A BOOKING                             " << char(186) << "";
    cout << "  " << char(200);
    for(int i=0;i<60;i++) cout << char(205);
    cout << char(188) << "";

    if(bookingCount == 0){
        showError("No bookings available.");
        pressAnyKey();
        return;
    }

    setColor(11);
    cout << "  Enter Booking ID to Cancel : ";
    setColor(7);
    cin.ignore();
    string bid;
    getline(cin, bid);

    int idx = -1;
    for(int i = 0; i < bookingCount; i++){
        if(bookings[i].bookingId == bid && !bookings[i].cancelled){ idx = i; break; }
    }

    if(idx == -1){
        showError("Booking not found or already cancelled!");
        pressAnyKey();
        return;
    }

    setColor(14);
    cout << " Booking Details:";
    setColor(11);
    cout << "  Customer : " << bookings[idx].userName << "";
    cout << "  Package  : " << bookings[idx].packageName << "";
    cout << "  Date     : " << bookings[idx].bookingDate << "";
    setColor(12);
    cout << "  [1] Cancel Booking";
    setColor(11);
    cout << "  [2] Go Back";
    setColor(7);
    cout << "  Enter Choice : ";
    int ch;
    cin >> ch;

    if(ch == 1){
        bookings[idx].cancelled = true;
        saveBookings();
        showSuccess("Booking Cancelled Successfully!");
    } else {
        setColor(13);
        cout << " Operation Cancelled.";
    }
    setColor(7);
    pressAnyKey();
}

void adminCustomerList(){
    clearScreen();
    displayHeader();
    setColor(14);
    cout << "  " << char(201);
    for(int i=0;i<60;i++) cout << char(205);
    cout << char(187) << "";
    cout << "  " << char(186) << "                    CUSTOMER LIST                            " << char(186) << "";
    cout << "  " << char(200);
    for(int i=0;i<60;i++) cout << char(205);
    cout << char(188) << "";

    if(bookingCount == 0){
        showError("No customers found.");
        pressAnyKey();
        return;
    }

    setColor(11);
    cout << "  " << left << setw(5) << "No." << setw(25) << "Customer Name" << setw(20) << "User ID" << "Bookings";
    setColor(14);
    cout << "  ";
    for(int i=0;i<60;i++) cout << char(196);
    cout << "";

    int serial = 1;
    for(int i = 0; i < bookingCount; i++){
        bool alreadyPrinted = false;
        for(int j = 0; j < i; j++){
            if(bookings[j].userId == bookings[i].userId){ alreadyPrinted = true; break; }
        }
        if(!alreadyPrinted){
            int bcount = 0;
            for(int j = 0; j < bookingCount; j++){
                if(bookings[j].userId == bookings[i].userId && !bookings[j].cancelled) bcount++;
            }
            setColor(10);
            cout << "  " << left << setw(5) << serial++;
            setColor(15);
            cout << setw(25) << bookings[i].userName;
            setColor(11);
            cout << setw(20) << bookings[i].userId;
            setColor(14);
            cout << bcount << "";
        }
    }

    setColor(14);
    cout << "  ";
    for(int i=0;i<60;i++) cout << char(196);
    cout << "";
    setColor(7);
    pressAnyKey();
}

void adminCustomerDetails(){
    clearScreen();
    displayHeader();
    setColor(14);
    cout << "" << char(201);
    for(int i=0;i<72;i++) cout << char(205);
    cout << char(187) << "";
    cout << "  " << char(186) << "                       COMPLETE CUSTOMER DETAILS                                " << char(186) << "\n";
    cout << "  " << char(200);
    for(int i=0;i<72;i++) cout << char(205);
    cout << char(188) << "";

    if(userCount == 0){
        showError("No customers registered.");
        pressAnyKey();
        return;
    }

    for(int i = 0; i < userCount; i++){
        int bcount = 0;
        for(int j = 0; j < bookingCount; j++){
            if(bookings[j].userId == users[i].username) bcount++;
        }

        setColor(14);
        cout << "  " << char(201);
        for(int k=0;k<68;k++) cout << char(205);
        cout << char(187) << "";
        setColor(15);
        cout << "  " << char(186) << "  Customer #" << (i+1) << " : " << left << setw(56) << users[i].fullName << char(186) << "\n";
        setColor(14);
        cout << "  " << char(204);
        for(int k=0;k<68;k++) cout << char(205);
        cout << char(185) << "";
        setColor(11);
        cout << "  " << char(186) << "  Username    : " << left << setw(53) << users[i].username << char(186) << "\n";
        cout << "  " << char(186) << "  Phone       : " << left << setw(53) << users[i].phone << char(186) << "\n";
        cout << "  " << char(186) << "  Email       : " << left << setw(53) << users[i].email << char(186) << "\n";
        cout << "  " << char(186) << "  CNIC        : " << left << setw(53) << users[i].cnic << char(186) << "\n";
        setColor(10);
        cout << "  " << char(186) << "  Bookings    : " << left << setw(53) << bcount << char(186) << "\n";

        for(int j = 0; j < bookingCount; j++){
            if(bookings[j].userId == users[i].username){
                string status = bookings[j].cancelled ? "Cancelled" : "Active";
                string binfo = "  [" + bookings[j].bookingId + "] " + bookings[j].packageName + " | " + bookings[j].bookingDate + " | " + bookings[j].paymentStatus + " | " + status;
                setColor(13);
                if((int)binfo.length() < 69)
                    binfo += string(69 - binfo.length(), ' ');
                else if((int)binfo.length() > 68)
                    binfo = binfo.substr(0, 68);
                cout << "  " << char(186) << binfo << char(186) << "\n";
            }
        }

        setColor(14);
        cout << "  " << char(200);
        for(int k=0;k<68;k++) cout << char(205);
        cout << char(188) << "\n\n";
    }
    setColor(7);
    pressAnyKey();
}

void adminMenu(){
    int choice;
    do {
        clearScreen();
        displayHeader();
        setColor(14);
        cout << "\n  " << char(201);
        for(int i=0;i<50;i++) cout << char(205);
        cout << char(187) << "\n";
        cout << "  " << char(186) << "               ADMIN CONTROL PANEL                  " << char(186) << "\n";
        cout << "  " << char(204);
        for(int i=0;i<50;i++) cout << char(205);
        cout << char(185) << "\n";
        setColor(11);
        cout << "  " << char(186) << "   [1]  Add Package                              " << char(186) << "\n";
        cout << "  " << char(186) << "   [2]  View All Packages                        " << char(186) << "\n";
        cout << "  " << char(186) << "   [3]  Packages Summary Report                  " << char(186) << "\n";
        cout << "  " << char(186) << "   [4]  Update Package                           " << char(186) << "\n";
        cout << "  " << char(186) << "   [5]  Delete Package                           " << char(186) << "\n";
        cout << "  " << char(186) << "   [6]  Search Package                           " << char(186) << "\n";
        cout << "  " << char(186) << "   [7]  View Bookings                            " << char(186) << "\n";
        cout << "  " << char(186) << "   [8]  Cancel Booking                           " << char(186) << "\n";
        cout << "  " << char(186) << "   [9]  Customer List                            " << char(186) << "\n";
        cout << "  " << char(186) << "   [10] Customer Details                         " << char(186) << "\n";
        setColor(12);
        cout << "  " << char(186) << "   [0]  Logout                                   " << char(186) << "\n";
        setColor(14);
        cout << "  " << char(200);
        for(int i=0;i<50;i++) cout << char(205);
        cout << char(188) << "\n";
        setColor(11);
        cout << "\n  Enter Your Choice : ";
        setColor(7);
        cin >> choice;

        switch(choice){
            case 1: adminAddPackage(); break;
            case 2: adminViewPackages(); break;
            case 3: adminViewPackagesSummary(); break;
            case 4: adminUpdatePackage(); break;
            case 5: adminDeletePackage(); break;
            case 6: adminSearchPackage(); break;
            case 7: adminViewBookings(); break;
            case 8: adminCancelBooking(); break;
            case 9: adminCustomerList(); break;
            case 10: adminCustomerDetails(); break;
            case 0: break;
            default:
                showError("Invalid choice! Try again.");
                Sleep(1000);
        }
    } while(choice != 0);
}

// ====================== USER FUNCTIONS ======================

void userViewPackages(){
    clearScreen();
    displayHeader();
    setColor(14);
    cout << "\n  " << char(201);
    for(int i=0;i<76;i++) cout << char(205);
    cout << char(187) << "\n";
    cout << "  " << char(186) << "                    AVAILABLE UMRAH PACKAGES                                    " << char(186) << "\n";
    cout << "  " << char(200);
    for(int i=0;i<76;i++) cout << char(205);
    cout << char(188) << "\n\n";

    if(packageCount == 0){
        showError("No packages available at the moment.");
        pressAnyKey();
        return;
    }

    for(int i = 0; i < packageCount; i++){
        setColor(14);
        cout << "  " << char(201);
        for(int k=0;k<60;k++) cout << char(205);
        cout << char(187) << "\n";
        setColor(15);
        cout << "  " << char(186) << "  " << char(254) << " " << left << setw(57) << packages[i].name << char(186) << "\n";
        setColor(14);
        cout << "  " << char(204);
        for(int k=0;k<60;k++) cout << char(205);
        cout << char(185) << "\n";
        setColor(11);
        cout << "  " << char(186) << "  Duration     : " << left << setw(44) << (to_string(packages[i].days) + " Days") << char(186) << "\n";
        setColor(10);
        cout << "  " << char(186) << "  Amount       : PKR " << left << setw(40) << packages[i].amount << char(186) << "\n";
        setColor(13);
        cout << "  " << char(186) << "  Type         : " << left << setw(44) << packages[i].type << char(186) << "\n";
        setColor(7);
        cout << "  " << char(186) << "  Includes     : " << left << setw(44) << packages[i].includes << char(186) << "\n";
        setColor(14);
        cout << "  " << char(200);
        for(int k=0;k<60;k++) cout << char(205);
        cout << char(188) << "\n\n";
    }
    setColor(7);
    pressAnyKey();
}

void userBookPackage(){
    clearScreen();
    displayHeader();
    setColor(14);
    cout << "\n  " << char(201);
    for(int i=0;i<60;i++) cout << char(205);
    cout << char(187) << "\n";
    cout << "  " << char(186) << "                BOOK UMRAH PACKAGE                           " << char(186) << "\n";
    cout << "  " << char(200);
    for(int i=0;i<60;i++) cout << char(205);
    cout << char(188) << "\n\n";

    if(packageCount == 0){
        showError("No packages available for booking.");
        pressAnyKey();
        return;
    }

    setColor(11);
    cout << "  Available Packages:\n";
    setColor(14);
    cout << "  ";
    for(int i=0;i<55;i++) cout << char(196);
    cout << "\n";
    for(int i = 0; i < packageCount; i++){
        setColor(10);
        cout << "  [" << (i+1) << "] ";
        setColor(15);
        cout << left << setw(25) << packages[i].name;
        setColor(11);
        cout << "PKR " << packages[i].amount << "   (" << packages[i].days << " days)\n";
    }
    setColor(14);
    cout << "  ";
    for(int i=0;i<55;i++) cout << char(196);
    cout << "\n\n";

    setColor(11);
    cout << "  Enter Package Name to Book : ";
    setColor(7);
    cin.ignore();
    string pkgName;
    getline(cin, pkgName);

    int pkgIdx = -1;
    for(int i = 0; i < packageCount; i++){
        if(packages[i].name == pkgName){ pkgIdx = i; break; }
    }

    if(pkgIdx == -1){
        showError("Package not found!");
        pressAnyKey();
        return;
    }

    string bookingId = "BK" + to_string(bookingCount + 1001);
    bookings[bookingCount].bookingId = bookingId;
    bookings[bookingCount].userId = loggedInUser;
    bookings[bookingCount].userName = loggedInName;
    bookings[bookingCount].packageName = pkgName;
    bookings[bookingCount].bookingDate = getCurrentDate();
    bookings[bookingCount].paymentStatus = "Unpaid";
    bookings[bookingCount].bankName = "";
    bookings[bookingCount].accountNumber = "";
    bookings[bookingCount].cancelled = false;
    bookingCount++;
    saveBookings();

    setColor(10);
    cout << "\n  " << char(201);
    for(int i=0;i<55;i++) cout << char(205);
    cout << char(187) << "\n";
    cout << "  " << char(186) << "      Booking Confirmed!                               " << char(186) << "\n";
    cout << "  " << char(186) << "      Booking ID : " << left << setw(36) << bookingId << char(186) << "\n";
    cout << "  " << char(186) << "      Package    : " << left << setw(36) << pkgName << char(186) << "\n";
    cout << "  " << char(186) << "      Date       : " << left << setw(36) << getCurrentDate() << char(186) << "\n";
    cout << "  " << char(186) << "      Payment    : Unpaid (Complete from Option 4)   " << char(186) << "\n";
    cout << "  " << char(200);
    for(int i=0;i<55;i++) cout << char(205);
    cout << char(188) << "\n";
    setColor(7);
    pressAnyKey();
}

void userPayment(){
    clearScreen();
    displayHeader();
    setColor(14);
    cout << "\n  " << char(201);
    for(int i=0;i<60;i++) cout << char(205);
    cout << char(187) << "\n";
    cout << "  " << char(186) << "                   PAYMENT SYSTEM                            " << char(186) << "\n";
    cout << "  " << char(200);
    for(int i=0;i<60;i++) cout << char(205);
    cout << char(188) << "\n\n";

    bool hasUnpaid = false;
    for(int i = 0; i < bookingCount; i++){
        if(bookings[i].userId == loggedInUser && !bookings[i].cancelled && bookings[i].paymentStatus == "Unpaid"){
            hasUnpaid = true;
            setColor(11);
            cout << "  Pending Payment:\n";
            cout << "  Booking ID : " << bookings[i].bookingId << "\n";
            cout << "  Package    : " << bookings[i].packageName << "\n";
            for(int j = 0; j < packageCount; j++){
                if(packages[j].name == bookings[i].packageName){
                    setColor(10);
                    cout << "  Amount     : PKR " << packages[j].amount << "\n";
                    break;
                }
            }
            setColor(7);
            cout << "\n";
            break;
        }
    }

    if(!hasUnpaid){
        showSuccess("All your bookings are already paid or no active bookings found.");
        pressAnyKey();
        return;
    }

    string bankName;
    while(true){
        setColor(11);
        cout << "  Enter Bank Name       : ";
        setColor(7);
        cin.ignore();
        getline(cin, bankName);
        if(bankName.empty()){
            showError("Bank name cannot be empty!");
            cin.clear();
            continue;
        }
        if(!isAlphaOnly(bankName)){
            showError("Bank name must contain letters only!");
            continue;
        }
        break;
    }

    string accNum;
    while(true){
        setColor(11);
        cout << "  Enter Account Number  : ";
        setColor(7);
        getline(cin, accNum);
        if(!isDigitsOnly(accNum) || accNum.length() < 8){
            showError("Account number must be digits only (minimum 8 digits)!");
            continue;
        }
        break;
    }

    setColor(14);
    cout << "\n  [1] Confirm Payment\n";
    setColor(12);
    cout << "  [2] Cancel\n";
    setColor(7);
    cout << "\n  Enter Choice : ";
    int ch;
    cin >> ch;

    if(ch == 1){
        for(int i = 0; i < bookingCount; i++){
            if(bookings[i].userId == loggedInUser && !bookings[i].cancelled && bookings[i].paymentStatus == "Unpaid"){
                bookings[i].paymentStatus = "Paid";
                bookings[i].bankName = bankName;
                bookings[i].accountNumber = accNum;
                break;
            }
        }
        saveBookings();
        setColor(10);
        cout << "\n  " << char(201);
        for(int i=0;i<45;i++) cout << char(205);
        cout << char(187) << "\n";
        cout << "  " << char(186) << "   Payment Status = Paid                         " << char(186) << "\n";
        cout << "  " << char(186) << "   Bank Name      : " << left << setw(26) << bankName << char(186) << "\n";
        cout << "  " << char(186) << "   Account No     : " << left << setw(26) << accNum << char(186) << "\n";
        cout << "  " << char(200);
        for(int i=0;i<45;i++) cout << char(205);
        cout << char(188) << "\n";
    } else {
        setColor(13);
        cout << "\n  Payment Status = Unpaid\n";
    }
    setColor(7);
    pressAnyKey();
}

void userCancelBooking(){
    clearScreen();
    displayHeader();
    setColor(14);
    cout << "\n  " << char(201);
    for(int i=0;i<60;i++) cout << char(205);
    cout << char(187) << "\n";
    cout << "  " << char(186) << "               CANCEL YOUR BOOKING                           " << char(186) << "\n";
    cout << "  " << char(200);
    for(int i=0;i<60;i++) cout << char(205);
    cout << char(188) << "\n\n";

    bool hasBooking = false;
    for(int i = 0; i < bookingCount; i++){
        if(bookings[i].userId == loggedInUser && !bookings[i].cancelled){
            hasBooking = true;
            setColor(10);
            cout << "  ID: " << bookings[i].bookingId << "  |  " << bookings[i].packageName << "  |  " << bookings[i].bookingDate << "\n";
        }
    }

    if(!hasBooking){
        showError("No active bookings found.");
        pressAnyKey();
        return;
    }

    setColor(11);
    cout << "\n  Enter Booking ID to Cancel : ";
    setColor(7);
    cin.ignore();
    string bid;
    getline(cin, bid);

    int idx = -1;
    for(int i = 0; i < bookingCount; i++){
        if(bookings[i].bookingId == bid && bookings[i].userId == loggedInUser && !bookings[i].cancelled){ idx = i; break; }
    }

    if(idx == -1){
        showError("Booking not found!");
        pressAnyKey();
        return;
    }

    setColor(12);
    cout << "\n  [1] Confirm Cancellation\n";
    setColor(11);
    cout << "  [2] Go Back\n";
    setColor(7);
    cout << "\n  Enter Choice : ";
    int ch;
    cin >> ch;

    if(ch == 1){
        bookings[idx].cancelled = true;
        saveBookings();
        showSuccess("Booking Cancelled Successfully.");
    } else {
        setColor(13);
        cout << "\n  Operation Cancelled.\n";
    }
    setColor(7);
    pressAnyKey();
}

void userViewBookingDetails(){
    clearScreen();
    displayHeader();
    setColor(14);
    cout << "\n  " << char(201);
    for(int i=0;i<65;i++) cout << char(205);
    cout << char(187) << "\n";
    cout << "  " << char(186) << "                   YOUR BOOKING DETAILS                            " << char(186) << "\n";
    cout << "  " << char(200);
    for(int i=0;i<65;i++) cout << char(205);
    cout << char(188) << "\n\n";

    bool found = false;
    for(int i = 0; i < bookingCount; i++){
        if(bookings[i].userId == loggedInUser && !bookings[i].cancelled){
            found = true;
            setColor(14);
            cout << "  " << char(201);
            for(int k=0;k<60;k++) cout << char(205);
            cout << char(187) << "\n";
            setColor(15);
            cout << "  " << char(186) << "  Booking ID     : " << left << setw(42) << bookings[i].bookingId << char(186) << "\n";
            setColor(11);
            cout << "  " << char(186) << "  Package        : " << left << setw(42) << bookings[i].packageName << char(186) << "\n";
            cout << "  " << char(186) << "  Booking Date   : " << left << setw(42) << bookings[i].bookingDate << char(186) << "\n";
            if(bookings[i].paymentStatus == "Paid") setColor(10);
            else setColor(12);
            cout << "  " << char(186) << "  Payment Status : " << left << setw(42) << bookings[i].paymentStatus << char(186) << "\n";
            if(bookings[i].paymentStatus == "Paid"){
                setColor(13);
                cout << "  " << char(186) << "  Bank Name      : " << left << setw(42) << bookings[i].bankName << char(186) << "\n";
                cout << "  " << char(186) << "  Account No     : " << left << setw(42) << bookings[i].accountNumber << char(186) << "\n";
            }
            for(int j = 0; j < packageCount; j++){
                if(packages[j].name == bookings[i].packageName){
                    setColor(10);
                    cout << "  " << char(186) << "  Duration       : " << left << setw(39) << (to_string(packages[j].days) + " Days") << char(186) << "\n";
                    cout << "  " << char(186) << "  Amount         : PKR " << left << setw(39) << packages[j].amount << char(186) << "\n";
                    break;
                }
            }
            setColor(14);
            cout << "  " << char(200);
            for(int k=0;k<60;k++) cout << char(205);
            cout << char(188) << "\n\n";
        }
    }

    if(!found){
        showError("No active bookings found.");
    }
    setColor(7);
    pressAnyKey();
}

void userRatePackage(){
    clearScreen();
    displayHeader();
    setColor(14);
    cout << "\n  " << char(201);
    for(int i=0;i<60;i++) cout << char(205);
    cout << char(187) << "\n";
    cout << "  " << char(186) << "               RATE YOUR PACKAGE                             " << char(186) << "\n";
    cout << "  " << char(200);
    for(int i=0;i<60;i++) cout << char(205);
    cout << char(188) << "\n\n";

    bool found = false;
    for(int i = 0; i < bookingCount; i++){
        if(bookings[i].userId == loggedInUser && !bookings[i].cancelled){
            found = true;
            setColor(11);
            cout << "  Your Package: " << bookings[i].packageName << "\n";
            break;
        }
    }

    if(!found){
        showError("No active bookings to rate.");
        pressAnyKey();
        return;
    }

    int rating = 0;
    while(true){
        setColor(11);
        cout << "\n  Rate the package (1-5 stars): ";
        setColor(7);
        string inp;
        cin >> inp;
        if(!isDigitsOnly(inp)){
            showError("Please enter a number between 1 and 5!");
            continue;
        }
        rating = stoi(inp);
        if(rating < 1 || rating > 5){
            showError("Rating must be between 1 and 5!");
            continue;
        }
        break;
    }

    setColor(10);
    cout << "\n  Thank you for your rating: ";
    setColor(14);
    for(int i = 0; i < rating; i++) cout << char(1) << " ";
    cout << "\n";
    setColor(11);
    cout << "  Your feedback has been recorded.\n";
    setColor(7);
    pressAnyKey();
}

void userCheckPaymentStatus(){
    clearScreen();
    displayHeader();
    setColor(14);
    cout << "\n  " << char(201);
    for(int i=0;i<55;i++) cout << char(205);
    cout << char(187) << "\n";
    cout << "  " << char(186) << "               CHECK PAYMENT STATUS                      " << char(186) << "\n";
    cout << "  " << char(200);
    for(int i=0;i<55;i++) cout << char(205);
    cout << char(188) << "\n\n";

    bool found = false;
    for(int i = 0; i < bookingCount; i++){
        if(bookings[i].userId == loggedInUser && !bookings[i].cancelled){
            found = true;
            setColor(11);
            cout << "  Booking ID : " << bookings[i].bookingId << "\n";
            cout << "  Package    : " << bookings[i].packageName << "\n";
            if(bookings[i].paymentStatus == "Paid"){
                setColor(10);
                cout << "\n  " << char(201);
                for(int k=0;k<35;k++) cout << char(205);
                cout << char(187) << "\n";
                cout << "  " << char(186) << "   Payment Status = Paid              " << char(186) << "\n";
                cout << "  " << char(200);
                for(int k=0;k<35;k++) cout << char(205);
                cout << char(188) << "\n";
            } else {
                setColor(12);
                cout << "\n  " << char(201);
                for(int k=0;k<35;k++) cout << char(205);
                cout << char(187) << "\n";
                cout << "  " << char(186) << "   Payment Status = Unpaid            " << char(186) << "\n";
                cout << "  " << char(200);
                for(int k=0;k<35;k++) cout << char(205);
                cout << char(188) << "\n";
            }
            cout << "\n";
        }
    }

    if(!found){
        showError("No active bookings found.");
    }
    setColor(7);
    pressAnyKey();
}

void userBookingHistory(){
    clearScreen();
    displayHeader();
    setColor(14);
    cout << "\n  " << char(201);
    for(int i=0;i<65;i++) cout << char(205);
    cout << char(187) << "\n";
    cout << "  " << char(186) << "                    BOOKING HISTORY                                " << char(186) << "\n";
    cout << "  " << char(200);
    for(int i=0;i<65;i++) cout << char(205);
    cout << char(188) << "\n\n";

    int total = 0, active = 0, cancelled = 0;
    for(int i = 0; i < bookingCount; i++){
        if(bookings[i].userId == loggedInUser){
            total++;
            if(bookings[i].cancelled) cancelled++;
            else active++;
        }
    }

    setColor(11);
    cout << "  Total Packages Booked : " << total << "\n";
    cout << "  Active Bookings       : " << active << "\n";
    cout << "  Cancelled Bookings    : " << cancelled << "\n\n";

    if(total == 0){
        showError("No booking history found.");
        pressAnyKey();
        return;
    }

    setColor(14);
    cout << "  " << left << setw(12) << "Booking ID" << setw(25) << "Package Name" << setw(14) << "Booking Date" << setw(10) << "Payment" << "Status\n";
    cout << "  ";
    for(int i=0;i<65;i++) cout << char(196);
    cout << "\n";

    for(int i = 0; i < bookingCount; i++){
        if(bookings[i].userId == loggedInUser){
            if(bookings[i].cancelled) setColor(12);
            else setColor(10);
            cout << "  " << left << setw(12) << bookings[i].bookingId
                 << setw(25) << bookings[i].packageName
                 << setw(14) << bookings[i].bookingDate
                 << setw(10) << bookings[i].paymentStatus
                 << (bookings[i].cancelled ? "Cancelled" : "Active") << "\n";
        }
    }

    setColor(14);
    cout << "  ";
    for(int i=0;i<65;i++) cout << char(196);
    cout << "\n";
    setColor(7);
    pressAnyKey();
}

void userMenu(){
    int choice;
    do {
        clearScreen();
        displayHeader();
        setColor(14);
        cout << "\n  " << char(201);
        for(int i=0;i<50;i++) cout << char(205);
        cout << char(187) << "\n";
        setColor(10);
        cout << "  " << char(186) << "   Welcome, " << left << setw(38) << loggedInName << char(186) << "\n";
        setColor(14);
        cout << "  " << char(204);
        for(int i=0;i<50;i++) cout << char(205);
        cout << char(185) << "\n";
        cout << "  " << char(186) << "               USER PANEL                           " << char(186) << "\n";
        cout << "  " << char(204);
        for(int i=0;i<50;i++) cout << char(205);
        cout << char(185) << "\n";
        setColor(11);
        cout << "  " << char(186) << "   [1]  View Packages                            " << char(186) << "\n";
        cout << "  " << char(186) << "   [2]  Book a Package                           " << char(186) << "\n";
        cout << "  " << char(186) << "   [3]  Rate Package                             " << char(186) << "\n";
        cout << "  " << char(186) << "   [4]  Payment System                           " << char(186) << "\n";
        cout << "  " << char(186) << "   [5]  Cancel Booking                           " << char(186) << "\n";
        cout << "  " << char(186) << "   [6]  View Booking Details                     " << char(186) << "\n";
        cout << "  " << char(186) << "   [7]  Rate Package (Feedback)                  " << char(186) << "\n";
        cout << "  " << char(186) << "   [8]  Check Payment Status                     " << char(186) << "\n";
        cout << "  " << char(186) << "   [9]  Booking History                          " << char(186) << "\n";
        setColor(12);
        cout << "  " << char(186) << "   [0]  Logout                                   " << char(186) << "\n";
        setColor(14);
        cout << "  " << char(200);
        for(int i=0;i<50;i++) cout << char(205);
        cout << char(188) << "\n";
        setColor(11);
        cout << "\n  Enter Your Choice : ";
        setColor(7);
        cin >> choice;

        switch(choice){
            case 1: userViewPackages(); break;
            case 2: userBookPackage(); break;
            case 3: userRatePackage(); break;
            case 4: userPayment(); break;
            case 5: userCancelBooking(); break;
            case 6: userViewBookingDetails(); break;
            case 7: userRatePackage(); break;
            case 8: userCheckPaymentStatus(); break;
            case 9: userBookingHistory(); break;
            case 0: break;
            default:
                showError("Invalid choice! Try again.");
                Sleep(1000);
        }
    } while(choice != 0);
}

// ====================== SPLASH SCREEN ======================

void displaySplash(){
    clearScreen();
    hideCursor();
    setColor(14);
    cout << "\n\n\n\n\n";
    cout << "          " << char(201);
    for(int i=0;i<60;i++) cout << char(205);
    cout << char(187) << "\n";
    cout << "          " << char(186) << "                                                            " << char(186) << "\n";
    setColor(11);
    cout << "          " << char(186) << "       UMRAH PACKAGE BOOKING MANAGEMENT SYSTEM          " << char(186) << "\n";
    setColor(14);
    cout << "          " << char(186) << "                                                            " << char(186) << "\n";
    setColor(10);
    cout << "          " << char(186) << "             AL-HARAMAIN TOURS & TRAVELS                " << char(186) << "\n";
    setColor(14);
    cout << "          " << char(186) << "                                                            " << char(186) << "\n";
    setColor(13);
    cout << "          " << char(186) << "                   Karachi, Pakistan                    " << char(186) << "\n";
    setColor(14);
    cout << "          " << char(186) << "                                                            " << char(186) << "\n";
    cout << "          " << char(200);
    for(int i=0;i<60;i++) cout << char(205);
    cout << char(188) << "\n\n";

    setColor(11);
    cout << "                          Loading";
    for(int i = 0; i < 5; i++){
        Sleep(300);
        cout << ".";
    }
    cout << "\n\n";
    setColor(7);
    Sleep(500);
    showCursor();
}

// ====================== LOGIN FUNCTIONS ======================

bool adminLogin(){
    clearScreen();
    displayHeader();
    setColor(14);
    cout << "\n  " << char(201);
    for(int i=0;i<55;i++) cout << char(205);
    cout << char(187) << "\n";
    cout << "  " << char(186) << "              ADMIN LOGIN PORTAL                         " << char(186) << "\n";
    cout << "  " << char(204);
    for(int i=0;i<55;i++) cout << char(205);
    cout << char(185) << "\n";
    setColor(13);
    cout << "  " << char(186) << "   Predefined Admins: admin | manager | staff           " << char(186) << "\n";
    setColor(14);
    cout << "  " << char(200);
    for(int i=0;i<55;i++) cout << char(205);
    cout << char(188) << "\n\n";

    const int MAX_ATTEMPTS = 3;
    int attempts = 0;

    while(attempts < MAX_ATTEMPTS){
        string uname, pass;

        setColor(11);
        cout << "  Enter Admin Username : ";
        setColor(7);
        cin >> uname;

        setColor(11);
        cout << "  Enter Admin Password : ";
        setColor(7);
        pass = "";
        char ch;
        while((ch = getch()) != 13){
            if(ch == 8){
                if(!pass.empty()){ pass.pop_back(); cout << "\b \b"; }
            } else {
                pass += ch;
                cout << "*";
            }
        }
        cout << "\n";

        // Check against predefined admins
        bool found = false;
        for(int i = 0; i < ADMIN_COUNT; i++){
            if(admins[i].username == uname && admins[i].password == pass){
                setColor(10);
                cout << "\n  " << char(201);
                for(int k=0;k<45;k++) cout << char(205);
                cout << char(187) << "\n";
                cout << "  " << char(186) << "   Login Successful!                           " << char(186) << "\n";
                cout << "  " << char(186) << "   Welcome, " << left << setw(34) << admins[i].displayName << char(186) << "\n";
                cout << "  " << char(200);
                for(int k=0;k<45;k++) cout << char(205);
                cout << char(188) << "\n";
                Sleep(900);
                found = true;
                return true;
            }
        }

        if(!found){
            attempts++;
            int remaining = MAX_ATTEMPTS - attempts;
            setColor(12);
            cout << "\n  " << char(201);
            for(int k=0;k<50;k++) cout << char(205);
            cout << char(187) << "\n";
            cout << "  " << char(186) << "   [!] Invalid username or password!              " << char(186) << "\n";
            if(remaining > 0){
                cout << "  " << char(186) << "   [!] Attempts remaining: " << left << setw(24) << remaining << char(186) << "\n";
            } else {
                cout << "  " << char(186) << "   [!] Access denied. Too many failed attempts." << char(186) << "\n";
            }
            cout << "  " << char(200);
            for(int k=0;k<50;k++) cout << char(205);
            cout << char(188) << "\n\n";
            setColor(7);
            Sleep(1000);

            if(remaining > 0){
                setColor(11);
                cout << "  Please try again...\n\n";
                setColor(7);
            }
        }
    }

    return false;
}

bool userLogin(){
    clearScreen();
    displayHeader();
    setColor(14);
    cout << "\n  " << char(201);
    for(int i=0;i<50;i++) cout << char(205);
    cout << char(187) << "\n";
    cout << "  " << char(186) << "              USER LOGIN PORTAL                      " << char(186) << "\n";
    cout << "  " << char(200);
    for(int i=0;i<50;i++) cout << char(205);
    cout << char(188) << "\n\n";

    const int MAX_ATTEMPTS = 3;
    int attempts = 0;

    while(attempts < MAX_ATTEMPTS){
        string uname, pass;

        setColor(11);
        cout << "  Enter Username : ";
        setColor(7);
        cin >> uname;

        setColor(11);
        cout << "  Enter Password : ";
        setColor(7);
        pass = "";
        char ch;
        while((ch = getch()) != 13){
            if(ch == 8){
                if(!pass.empty()){ pass.pop_back(); cout << "\b \b"; }
            } else {
                pass += ch;
                cout << "*";
            }
        }
        cout << "\n";

        bool found = false;
        for(int i = 0; i < userCount; i++){
            if(users[i].username == uname && users[i].password == pass){
                loggedInUser = uname;
                loggedInName = users[i].fullName;
                setColor(10);
                cout << "\n  " << char(201);
                for(int k=0;k<45;k++) cout << char(205);
                cout << char(187) << "\n";
                cout << "  " << char(186) << "   Login Successful!                           " << char(186) << "\n";
                cout << "  " << char(186) << "   Welcome, " << left << setw(34) << users[i].fullName << char(186) << "\n";
                cout << "  " << char(200);
                for(int k=0;k<45;k++) cout << char(205);
                cout << char(188) << "\n";
                Sleep(900);
                found = true;
                return true;
            }
        }

        if(!found){
            attempts++;
            int remaining = MAX_ATTEMPTS - attempts;
            setColor(12);
            cout << "\n  " << char(201);
            for(int k=0;k<50;k++) cout << char(205);
            cout << char(187) << "\n";
            cout << "  " << char(186) << "   [!] Invalid username or password!              " << char(186) << "\n";
            if(remaining > 0){
                cout << "  " << char(186) << "   [!] Attempts remaining: " << left << setw(24) << remaining << char(186) << "\n";
            } else {
                cout << "  " << char(186) << "   [!] Access denied. Too many failed attempts." << char(186) << "\n";
            }
            cout << "  " << char(200);
            for(int k=0;k<50;k++) cout << char(205);
            cout << char(188) << "\n\n";
            setColor(7);
            Sleep(1000);

            if(remaining > 0){
                setColor(11);
                cout << "  Please try again...\n\n";
                setColor(7);
            }
        }
    }

    return false;
}

// ====================== USER REGISTRATION WITH VALIDATION ======================

void userRegister(){
    clearScreen();
    displayHeader();
    setColor(14);
    cout << "\n  " << char(201);
    for(int i=0;i<60;i++) cout << char(205);
    cout << char(187) << "\n";
    cout << "  " << char(186) << "               NEW USER REGISTRATION                        " << char(186) << "\n";
    cout << "  " << char(204);
    for(int i=0;i<60;i++) cout << char(205);
    cout << char(185) << "\n";
    setColor(13);
    cout << "  " << char(186) << "   All fields are required and validated.               " << char(186) << "\n";
    setColor(14);
    cout << "  " << char(200);
    for(int i=0;i<60;i++) cout << char(205);
    cout << char(188) << "\n\n";

    if(userCount >= MAX_USERS){
        showError("User registration limit reached!");
        pressAnyKey();
        return;
    }

    string uname, pass, fullname, phone, email, cnic;

    // === USERNAME ===
    while(true){
        setColor(11);
        cout << "  Enter Username       : ";
        setColor(7);
        cin >> uname;
        if(!isValidUsername(uname)){
            showError("Username must be at least 4 characters, letters/digits/underscore only!");
            continue;
        }
        bool taken = false;
        for(int i = 0; i < userCount; i++){
            if(users[i].username == uname){ taken = true; break; }
        }
        if(taken){
            showError("Username already taken! Choose a different one.");
            continue;
        }
        setColor(10);
        cout << "  [OK] Username accepted.\n";
        setColor(7);
        break;
    }

    // === PASSWORD ===
    while(true){
        setColor(11);
        cout << "  Enter Password       : ";
        setColor(7);
        pass = "";
        char ch;
        while((ch = getch()) != 13){
            if(ch == 8){
                if(!pass.empty()){ pass.pop_back(); cout << "\b \b"; }
            } else {
                pass += ch;
                cout << "*";
            }
        }
        cout << "\n";
        if(!isValidPassword(pass)){
            showError("Password must be at least 6 characters long!");
            continue;
        }
        // Confirm password
        setColor(11);
        cout << "  Confirm Password     : ";
        setColor(7);
        string confirmPass = "";
        while((ch = getch()) != 13){
            if(ch == 8){
                if(!confirmPass.empty()){ confirmPass.pop_back(); cout << "\b \b"; }
            } else {
                confirmPass += ch;
                cout << "*";
            }
        }
        cout << "\n";
        if(pass != confirmPass){
            showError("Passwords do not match! Try again.");
            continue;
        }
        setColor(10);
        cout << "  [OK] Password accepted.\n";
        setColor(7);
        break;
    }

    cin.ignore();

    // === FULL NAME ===
    while(true){
        setColor(11);
        cout << "  Enter Full Name      : ";
        setColor(7);
        getline(cin, fullname);
        if(fullname.length() < 3){
            showError("Full name must be at least 3 characters!");
            continue;
        }
        if(!isAlphaOnly(fullname)){
            showError("Full name must contain letters and spaces only (no digits or symbols)!");
            continue;
        }
        setColor(10);
        cout << "  [OK] Name accepted.\n";
        setColor(7);
        break;
    }

    // === PHONE ===
    while(true){
        setColor(11);
        cout << "  Enter Phone Number   : ";
        setColor(13);
        cout << "(digits only, 10-15 chars): ";
        setColor(7);
        getline(cin, phone);
        if(!isValidPhone(phone)){
            showError("Phone must contain digits only (and optionally + or -), 10-15 characters!");
            continue;
        }
        setColor(10);
        cout << "  [OK] Phone accepted.\n";
        setColor(7);
        break;
    }

    // === EMAIL ===
    while(true){
        setColor(11);
        cout << "  Enter Email          : ";
        setColor(13);
        cout << "(e.g. name@domain.com): ";
        setColor(7);
        getline(cin, email);
        if(!isValidEmail(email)){
            showError("Invalid email! Must contain '@' and a domain (e.g. abc@gmail.com).");
            continue;
        }
        setColor(10);
        cout << "  [OK] Email accepted.\n";
        setColor(7);
        break;
    }

    // === CNIC ===
    while(true){
        setColor(11);
        cout << "  Enter CNIC           : ";
        setColor(13);
        cout << "(13 digits, e.g. 42201-1234567-1): ";
        setColor(7);
        getline(cin, cnic);
        if(!isValidCNIC(cnic)){
            showError("CNIC must have exactly 13 digits (format: 42201-1234567-1)!");
            continue;
        }
        setColor(10);
        cout << "  [OK] CNIC accepted.\n";
        setColor(7);
        break;
    }

    // Save user
    users[userCount].username = uname;
    users[userCount].password = pass;
    users[userCount].fullName = fullname;
    users[userCount].phone = phone;
    users[userCount].email = email;
    users[userCount].cnic = cnic;
    userCount++;
    saveUsers();

    setColor(10);
    cout << "\n  " << char(201);
    for(int i=0;i<52;i++) cout << char(205);
    cout << char(187) << "\n";
    cout << "  " << char(186) << "   Registration Successful!                           " << char(186) << "\n";
    cout << "  " << char(186) << "   You can now login with your credentials.           " << char(186) << "\n";
    cout << "  " << char(186) << "   Username : " << left << setw(39) << uname << char(186) << "\n";
    cout << "  " << char(200);
    for(int i=0;i<52;i++) cout << char(205);
    cout << char(188) << "\n";
    setColor(7);

    pressAnyKey();
}

// ====================== MAIN ======================

int main(){
    

    COORD bufferSize = {100, 3000};
    SetConsoleScreenBufferSize(hConsole, bufferSize);

    SMALL_RECT windowSize = {0, 0, 99, 35};
    SetConsoleWindowInfo(hConsole, TRUE, &windowSize);

    loadPackages();
    loadBookings();
    loadUsers();
    initializeDefaultData();

    displaySplash();

    int mainChoice;
    do {
        clearScreen();
        displayHeader();
        setColor(14);
        cout << "\n\n";
        cout << "          " << char(201);
        for(int i=0;i<42;i++) cout << char(205);
        cout << char(187) << "\n";
        cout << "          " << char(186) << "           MAIN MENU                        " << char(186) << "\n";
        cout << "          " << char(204);
        for(int i=0;i<42;i++) cout << char(205);
        cout << char(185) << "\n";
        setColor(11);
        cout << "          " << char(186) << "   [1]  Admin Login                        " << char(186) << "\n";
        cout << "          " << char(186) << "   [2]  User Login                         " << char(186) << "\n";
        cout << "          " << char(186) << "   [3]  New User Registration              " << char(186) << "\n";
        setColor(12);
        cout << "          " << char(186) << "   [0]  Exit System                        " << char(186) << "\n";
        setColor(14);
        cout << "          " << char(200);
        for(int i=0;i<42;i++) cout << char(205);
        cout << char(188) << "\n\n";
        setColor(11);
        cout << "          Enter Your Choice : ";
        setColor(7);
        cin >> mainChoice;

        switch(mainChoice){
            case 1:
                if(adminLogin()) adminMenu();
                break;
            case 2:
                if(userLogin()) userMenu();
                break;
            case 3:
                userRegister();
                break;
            case 0:
                clearScreen();
                displayHeader();
                setColor(10);
                cout << "\n\n";
                cout << "          " << char(201);
                for(int i=0;i<47;i++) cout << char(205);
                cout << char(187) << "\n";
                cout << "          " << char(186) << "   Thank you for using our system!              " << char(186) << "\n";
                cout << "          " << char(186) << "   AL-HARAMAIN Tours & Travels                  " << char(186) << "\n";
                cout << "          " << char(186) << "   May Allah Accept Your Umrah. Ameen.          " << char(186) << "\n";
                cout << "          " << char(200);
                for(int i=0;i<47;i++) cout << char(205);
                cout << char(188) << "\n\n";
                setColor(7);
                Sleep(1500);
                break;
            default:
                showError("Invalid choice!");
                Sleep(800);
        }
    } while(mainChoice != 0);

    return 0;
}
