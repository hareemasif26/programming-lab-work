#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<ctime>
#include<sstream>
#include<cctype>
#include<cstdlib>

using namespace std;

int main(){
    // Package storage
    string packageNames[50];
    int packageDays[50];
    double packageAmounts[50];
    string packageTypes[50];
    string packageIncludes[50];
    int packageCount = 0;
    
    // Booking storage
    string bookingIds[200];
    string bookingUserIds[200];
    string bookingUserNames[200];
    string bookingPackageNames[200];
    string bookingDates[200];
    string bookingPaymentStatus[200];
    string bookingBankNames[200];
    string bookingAccountNumbers[200];
    bool bookingCancelled[200];
    int bookingCount = 0;
    
    // User storage
    string userUsernames[100];
    string userPasswords[100];
    string userFullNames[100];
    string userPhones[100];
    string userEmails[100];
    string userCnic[100];
    int userCount = 0;
    
    // Admin accounts
    string adminUsernames[3] = {"admin", "manager", "staff"};
    string adminPasswords[3] = {"admin123", "manager@456", "staff#789"};
    string adminDisplayNames[3] = {"Super Admin", "Tour Manager", "Staff Member"};
    
    // Login session
    string loggedInUser = "";
    string loggedInName = "";
    
    // Load data from files
    ifstream packageFile("packages.txt");
    if(packageFile.is_open()){
        packageFile >> packageCount;
        packageFile.ignore();
        for(int i = 0; i < packageCount; i++){
            getline(packageFile, packageNames[i]);
            packageFile >> packageDays[i];
            packageFile >> packageAmounts[i];
            packageFile.ignore();
            getline(packageFile, packageTypes[i]);
            getline(packageFile, packageIncludes[i]);
        }
        packageFile.close();
    }
    
    ifstream bookingFile("bookings.txt");
    if(bookingFile.is_open()){
        bookingFile >> bookingCount;
        bookingFile.ignore();
        for(int i = 0; i < bookingCount; i++){
            getline(bookingFile, bookingIds[i]);
            getline(bookingFile, bookingUserIds[i]);
            getline(bookingFile, bookingUserNames[i]);
            getline(bookingFile, bookingPackageNames[i]);
            getline(bookingFile, bookingDates[i]);
            getline(bookingFile, bookingPaymentStatus[i]);
            getline(bookingFile, bookingBankNames[i]);
            getline(bookingFile, bookingAccountNumbers[i]);
            bookingFile >> bookingCancelled[i];
            bookingFile.ignore();
        }
        bookingFile.close();
    }
    
    ifstream userFile("users.txt");
    if(userFile.is_open()){
        userFile >> userCount;
        userFile.ignore();
        for(int i = 0; i < userCount; i++){
            getline(userFile, userUsernames[i]);
            getline(userFile, userPasswords[i]);
            getline(userFile, userFullNames[i]);
            getline(userFile, userPhones[i]);
            getline(userFile, userEmails[i]);
            getline(userFile, userCnic[i]);
        }
        userFile.close();
    }
    
    // Initialize default packages if none exist
    if(packageCount == 0){
        packageNames[0] = "Silver Package";
        packageDays[0] = 14;
        packageAmounts[0] = 150000;
        packageTypes[0] = "Economy";
        packageIncludes[0] = "Flight + Hotel (3-Star) + Transport";
        
        packageNames[1] = "Gold Package";
        packageDays[1] = 21;
        packageAmounts[1] = 250000;
        packageTypes[1] = "Standard";
        packageIncludes[1] = "Flight + Hotel (4-Star) + Transport + Ziyarat";
        
        packageNames[2] = "Diamond Package";
        packageDays[2] = 30;
        packageAmounts[2] = 400000;
        packageTypes[2] = "Premium";
        packageIncludes[2] = "Flight + Hotel (5-Star) + Transport + Ziyarat + Meals";
        
        packageCount = 3;
        
        ofstream savePackage("packages.txt");
        savePackage << packageCount << "\n";
        for(int i = 0; i < packageCount; i++){
            savePackage << packageNames[i] << "\n";
            savePackage << packageDays[i] << "\n";
            savePackage << packageAmounts[i] << "\n";
            savePackage << packageTypes[i] << "\n";
            savePackage << packageIncludes[i] << "\n";
        }
        savePackage.close();
    }
    
    int mainChoice;
    
    do {
        // Clear screen for online compilers
        cout << "\033[2J\033[1;1H";
        
        // Display header
        cout << "\n  ";
        for(int i=0;i<78;i++) cout << "-";
        cout << "\n";
        cout << "  |                                                                              |\n";
        cout << "  |";
        cout << "              ** UMRAH PACKAGE BOOKING MANAGEMENT SYSTEM **                  ";
        cout << "|\n";
        cout << "  |                     AL-HARAMAIN TOURS & TRAVELS                              |\n";
        cout << "  |                                                                              |\n";
        cout << "  ";
        for(int i=0;i<78;i++) cout << "-";
        cout << "\n";
        
        cout << "\n\n";
        cout << "          +------------------------------------------+\n";
        cout << "          |           MAIN MENU                        |\n";
        cout << "          |------------------------------------------|\n";
        cout << "          |   [1]  Admin Login                        |\n";
        cout << "          |   [2]  User Login                         |\n";
        cout << "          |   [3]  New User Registration              |\n";
        cout << "          |   [0]  Exit System                        |\n";
        cout << "          +------------------------------------------+\n\n";
        cout << "          Enter Your Choice : ";
        cin >> mainChoice;
        
        if(mainChoice == 1){
            // Admin Login
            cout << "\033[2J\033[1;1H";
            cout << "\n  +-------------------------------------------------------+\n";
            cout << "  |              ADMIN LOGIN PORTAL                         |\n";
            cout << "  |-------------------------------------------------------|\n";
            cout << "  |   Predefined Admins: admin | manager | staff           |\n";
            cout << "  +-------------------------------------------------------+\n\n";
            
            string uname, pass;
            cout << "  Enter Admin Username : ";
            cin >> uname;
            cout << "  Enter Admin Password : ";
            cin >> pass;
            
            bool adminFound = false;
            for(int i = 0; i < 3; i++){
                if(adminUsernames[i] == uname && adminPasswords[i] == pass){
                    adminFound = true;
                    loggedInName = adminDisplayNames[i];
                    break;
                }
            }
            
            if(adminFound){
                cout << "\n  Login Successful! Welcome, " << loggedInName << "\n";
                cout << "\n  Press Enter to continue...";
                cin.ignore();
                cin.get();
                
                // Admin Menu
                int adminChoice;
                do {
                    cout << "\033[2J\033[1;1H";
                    cout << "\n  +--------------------------------------------------+\n";
                    cout << "  |               ADMIN CONTROL PANEL                  |\n";
                    cout << "  |--------------------------------------------------|\n";
                    cout << "  |   [1]  Add Package                              |\n";
                    cout << "  |   [2]  View All Packages                        |\n";
                    cout << "  |   [3]  Packages Summary Report                  |\n";
                    cout << "  |   [4]  Update Package                           |\n";
                    cout << "  |   [5]  Delete Package                           |\n";
                    cout << "  |   [6]  Search Package                           |\n";
                    cout << "  |   [7]  View Bookings                            |\n";
                    cout << "  |   [8]  Cancel Booking                           |\n";
                    cout << "  |   [9]  Customer List                            |\n";
                    cout << "  |   [10] Customer Details                         |\n";
                    cout << "  |   [0]  Logout                                   |\n";
                    cout << "  +--------------------------------------------------+\n";
                    cout << "\n  Enter Your Choice : ";
                    cin >> adminChoice;
                    
                    if(adminChoice == 1){
                        // Add Package
                        cout << "\033[2J\033[1;1H";
                        cout << "\n  +------------------------------------------------------------+\n";
                        cout << "  |              ADD NEW UMRAH PACKAGE                         |\n";
                        cout << "  +------------------------------------------------------------+\n";
                        
                        if(packageCount >= 50){
                            cout << "\n  Package storage full!\n";
                        } else {
                            string pname, ptype, pincludes;
                            int pdays;
                            double pamount;
                            
                            cin.ignore();
                            
                            cout << "\n  Enter Package Name     : ";
                            getline(cin, pname);
                            cout << "  Enter Number of Days   : ";
                            cin >> pdays;
                            cout << "  Enter Package Amount   : ";
                            cin >> pamount;
                            cin.ignore();
                            cout << "  Enter Package Type     : ";
                            getline(cin, ptype);
                            cout << "  Enter Inclusions       : ";
                            getline(cin, pincludes);
                            
                            packageNames[packageCount] = pname;
                            packageDays[packageCount] = pdays;
                            packageAmounts[packageCount] = pamount;
                            packageTypes[packageCount] = ptype;
                            packageIncludes[packageCount] = pincludes;
                            packageCount++;
                            
                            // Save to file
                            ofstream savePackage("packages.txt");
                            savePackage << packageCount << "\n";
                            for(int i = 0; i < packageCount; i++){
                                savePackage << packageNames[i] << "\n";
                                savePackage << packageDays[i] << "\n";
                                savePackage << packageAmounts[i] << "\n";
                                savePackage << packageTypes[i] << "\n";
                                savePackage << packageIncludes[i] << "\n";
                            }
                            savePackage.close();
                            
                            cout << "\n  Package Added Successfully!\n";
                        }
                        cout << "\n  Press Enter to continue...";
                        cin.ignore();
                        cin.get();
                    }
                    else if(adminChoice == 2){
                        // View Packages
                        cout << "\033[2J\033[1;1H";
                        cout << "\n  +----------------------------------------------------------------------------+\n";
                        cout << "  |                        ALL AVAILABLE UMRAH PACKAGES                            |\n";
                        cout << "  +----------------------------------------------------------------------------+\n";
                        
                        if(packageCount == 0){
                            cout << "\n  No packages available.\n";
                        } else {
                            cout << "\n  " << left << setw(5) << "No." << setw(22) << "Package Name" << setw(8) << "Days" << setw(16) << "Amount (PKR)" << setw(15) << "Type" << "Inclusions\n";
                            cout << "  ";
                            for(int i=0;i<76;i++) cout << "-";
                            cout << "\n";
                            
                            for(int i = 0; i < packageCount; i++){
                                cout << "  " << left << setw(5) << (i+1);
                                cout << setw(22) << packageNames[i];
                                cout << setw(8) << packageDays[i];
                                cout << setw(16) << packageAmounts[i];
                                cout << setw(15) << packageTypes[i];
                                cout << packageIncludes[i] << "\n";
                            }
                        }
                        cout << "\n  Press Enter to continue...";
                        cin.ignore();
                        cin.get();
                    }
                    else if(adminChoice == 3){
                        // Packages Summary Report
                        cout << "\033[2J\033[1;1H";
                        cout << "\n  +------------------------------------------------------------+\n";
                        cout << "  |                 PACKAGES SUMMARY REPORT                    |\n";
                        cout << "  +------------------------------------------------------------+\n\n";
                        
                        cout << "  Total Packages Available : " << packageCount << "\n\n";
                        
                        double totalRevenue = 0;
                        for(int i = 0; i < bookingCount; i++){
                            if(!bookingCancelled[i] && bookingPaymentStatus[i] == "Paid"){
                                for(int j = 0; j < packageCount; j++){
                                    if(packageNames[j] == bookingPackageNames[i]){
                                        totalRevenue += packageAmounts[j];
                                        break;
                                    }
                                }
                            }
                        }
                        
                        cout << "  Total Revenue Collected  : PKR " << fixed << setprecision(2) << totalRevenue << "\n\n";
                        
                        for(int i = 0; i < packageCount; i++){
                            int bookingsCnt = 0;
                            for(int j = 0; j < bookingCount; j++){
                                if(bookingPackageNames[j] == packageNames[i] && !bookingCancelled[j])
                                    bookingsCnt++;
                            }
                            cout << "  * " << left << setw(25) << packageNames[i];
                            cout << "Bookings: " << bookingsCnt;
                            cout << "   Revenue: PKR " << (bookingsCnt * packageAmounts[i]) << "\n";
                        }
                        cout << "\n  Press Enter to continue...";
                        cin.ignore();
                        cin.get();
                    }
                    else if(adminChoice == 4){
                        // Update Package
                        cout << "\033[2J\033[1;1H";
                        cout << "\n  +------------------------------------------------------------+\n";
                        cout << "  |               UPDATE UMRAH PACKAGE                         |\n";
                        cout << "  +------------------------------------------------------------+\n\n";
                        
                        if(packageCount == 0){
                            cout << "\n  No packages available to update.\n";
                        } else {
                            cout << "  Available Packages:\n";
                            for(int i = 0; i < packageCount; i++){
                                cout << "  [" << (i+1) << "] " << packageNames[i] << "\n";
                            }
                            
                            cout << "\n  Enter Package Name to Update : ";
                            cin.ignore();
                            string searchName;
                            getline(cin, searchName);
                            
                            int idx = -1;
                            for(int i = 0; i < packageCount; i++){
                                if(packageNames[i] == searchName){
                                    idx = i;
                                    break;
                                }
                            }
                            
                            if(idx == -1){
                                cout << "\n  Package not found!\n";
                            } else {
                                cout << "\n  Current Details:\n";
                                cout << "  Name    : " << packageNames[idx] << "\n";
                                cout << "  Days    : " << packageDays[idx] << "\n";
                                cout << "  Amount  : PKR " << packageAmounts[idx] << "\n\n";
                                
                                string newName;
                                int newDays;
                                double newAmount;
                                
                                cout << "  Enter New Package Name   : ";
                                getline(cin, newName);
                                cout << "  Enter New Number of Days : ";
                                cin >> newDays;
                                cout << "  Enter New Amount         : ";
                                cin >> newAmount;
                                
                                packageNames[idx] = newName;
                                packageDays[idx] = newDays;
                                packageAmounts[idx] = newAmount;
                                
                                // Save to file
                                ofstream savePackage("packages.txt");
                                savePackage << packageCount << "\n";
                                for(int i = 0; i < packageCount; i++){
                                    savePackage << packageNames[i] << "\n";
                                    savePackage << packageDays[i] << "\n";
                                    savePackage << packageAmounts[i] << "\n";
                                    savePackage << packageTypes[i] << "\n";
                                    savePackage << packageIncludes[i] << "\n";
                                }
                                savePackage.close();
                                
                                cout << "\n  Updated Successfully!\n";
                            }
                        }
                        cout << "\n  Press Enter to continue...";
                        cin.ignore();
                        cin.get();
                    }
                    else if(adminChoice == 5){
                        // Delete Package
                        cout << "\033[2J\033[1;1H";
                        cout << "\n  +------------------------------------------------------------+\n";
                        cout << "  |               DELETE UMRAH PACKAGE                         |\n";
                        cout << "  +------------------------------------------------------------+\n\n";
                        
                        if(packageCount == 0){
                            cout << "\n  No packages available.\n";
                        } else {
                            cout << "  Available Packages:\n";
                            for(int i = 0; i < packageCount; i++){
                                cout << "  [" << (i+1) << "] " << packageNames[i] << "\n";
                            }
                            
                            cout << "\n  Enter Package Name to Delete : ";
                            cin.ignore();
                            string delName;
                            getline(cin, delName);
                            
                            int idx = -1;
                            for(int i = 0; i < packageCount; i++){
                                if(packageNames[i] == delName){
                                    idx = i;
                                    break;
                                }
                            }
                            
                            if(idx == -1){
                                cout << "\n  Package not found!\n";
                            } else {
                                cout << "\n  Package Found: " << packageNames[idx] << "\n\n";
                                cout << "  [1] Delete\n";
                                cout << "  [2] Cancel\n";
                                cout << "\n  Enter Choice : ";
                                int choice;
                                cin >> choice;
                                
                                if(choice == 1){
                                    for(int i = idx; i < packageCount - 1; i++){
                                        packageNames[i] = packageNames[i+1];
                                        packageDays[i] = packageDays[i+1];
                                        packageAmounts[i] = packageAmounts[i+1];
                                        packageTypes[i] = packageTypes[i+1];
                                        packageIncludes[i] = packageIncludes[i+1];
                                    }
                                    packageCount--;
                                    
                                    // Save to file
                                    ofstream savePackage("packages.txt");
                                    savePackage << packageCount << "\n";
                                    for(int i = 0; i < packageCount; i++){
                                        savePackage << packageNames[i] << "\n";
                                        savePackage << packageDays[i] << "\n";
                                        savePackage << packageAmounts[i] << "\n";
                                        savePackage << packageTypes[i] << "\n";
                                        savePackage << packageIncludes[i] << "\n";
                                    }
                                    savePackage.close();
                                    
                                    cout << "\n  Deleted Successfully!\n";
                                } else {
                                    cout << "\n  Cancel Deletion\n";
                                }
                            }
                        }
                        cout << "\n  Press Enter to continue...";
                        cin.ignore();
                        cin.get();
                    }
                    else if(adminChoice == 6){
                        // Search Package
                        cout << "\033[2J\033[1;1H";
                        cout << "\n  +------------------------------------------------------------+\n";
                        cout << "  |               SEARCH UMRAH PACKAGE                         |\n";
                        cout << "  +------------------------------------------------------------+\n\n";
                        
                        cout << "  Enter Package Name : ";
                        cin.ignore();
                        string searchName;
                        getline(cin, searchName);
                        
                        int idx = -1;
                        for(int i = 0; i < packageCount; i++){
                            if(packageNames[i] == searchName){
                                idx = i;
                                break;
                            }
                        }
                        
                        if(idx == -1){
                            cout << "\n  Package not found!\n";
                        } else {
                            cout << "\n  +-------------------------------------------------------+\n";
                            cout << "  |               PACKAGE DETAILS                          |\n";
                            cout << "  +-------------------------------------------------------+\n";
                            cout << "  |  Package Name  : " << left << setw(38) << packageNames[idx] << "|\n";
                            cout << "  |  Duration      : " << left << setw(38) << (to_string(packageDays[idx]) + " Days") << "|\n";
                            cout << "  |  Amount        : PKR " << left << setw(37) << packageAmounts[idx] << "|\n";
                            cout << "  |  Package Type  : " << left << setw(38) << packageTypes[idx] << "|\n";
                            cout << "  |  Inclusions    : " << left << setw(38) << packageIncludes[idx] << "|\n";
                            cout << "  +-------------------------------------------------------+\n";
                        }
                        cout << "\n  Press Enter to continue...";
                        cin.ignore();
                        cin.get();
                    }
                    else if(adminChoice == 7){
                        // View Bookings
                        cout << "\033[2J\033[1;1H";
                        cout << "\n  +----------------------------------------------------------------------------+\n";
                        cout << "  |                         ALL BOOKINGS LIST                                      |\n";
                        cout << "  +----------------------------------------------------------------------------+\n";
                        
                        if(bookingCount == 0){
                            cout << "\n  No bookings found.\n";
                        } else {
                            cout << "\n  " << left << setw(12) << "Booking ID" << setw(16) << "Customer" << setw(22) << "Package" << setw(13) << "Date" << setw(8) << "Payment" << "Status\n";
                            cout << "  ";
                            for(int i=0;i<76;i++) cout << "-";
                            cout << "\n";
                            
                            for(int i = 0; i < bookingCount; i++){
                                if(bookingCancelled[i]){
                                    cout << "  " << left << setw(12) << bookingIds[i] << setw(16) << bookingUserNames[i]
                                         << setw(22) << bookingPackageNames[i] << setw(13) << bookingDates[i]
                                         << setw(8) << bookingPaymentStatus[i] << "Cancelled\n";
                                } else {
                                    cout << "  " << left << setw(12) << bookingIds[i];
                                    cout << setw(16) << bookingUserNames[i];
                                    cout << setw(22) << bookingPackageNames[i];
                                    cout << setw(13) << bookingDates[i];
                                    cout << setw(8) << bookingPaymentStatus[i];
                                    cout << "Active\n";
                                }
                            }
                        }
                        cout << "\n  Press Enter to continue...";
                        cin.ignore();
                        cin.get();
                    }
                    else if(adminChoice == 8){
                        // Cancel Booking (Admin)
                        cout << "\033[2J\033[1;1H";
                        cout << "\n  +------------------------------------------------------------+\n";
                        cout << "  |               CANCEL A BOOKING                             |\n";
                        cout << "  +------------------------------------------------------------+\n\n";
                        
                        if(bookingCount == 0){
                            cout << "\n  No bookings available.\n";
                        } else {
                            cout << "  Enter Booking ID to Cancel : ";
                            cin.ignore();
                            string bid;
                            getline(cin, bid);
                            
                            int idx = -1;
                            for(int i = 0; i < bookingCount; i++){
                                if(bookingIds[i] == bid && !bookingCancelled[i]){
                                    idx = i;
                                    break;
                                }
                            }
                            
                            if(idx == -1){
                                cout << "\n  Booking not found or already cancelled!\n";
                            } else {
                                cout << "\n  Booking Details:\n";
                                cout << "  Customer : " << bookingUserNames[idx] << "\n";
                                cout << "  Package  : " << bookingPackageNames[idx] << "\n";
                                cout << "  Date     : " << bookingDates[idx] << "\n\n";
                                cout << "  [1] Cancel Booking\n";
                                cout << "  [2] Go Back\n";
                                cout << "\n  Enter Choice : ";
                                int ch;
                                cin >> ch;
                                
                                if(ch == 1){
                                    bookingCancelled[idx] = true;
                                    
                                    // Save to file
                                    ofstream saveBooking("bookings.txt");
                                    saveBooking << bookingCount << "\n";
                                    for(int i = 0; i < bookingCount; i++){
                                        saveBooking << bookingIds[i] << "\n";
                                        saveBooking << bookingUserIds[i] << "\n";
                                        saveBooking << bookingUserNames[i] << "\n";
                                        saveBooking << bookingPackageNames[i] << "\n";
                                        saveBooking << bookingDates[i] << "\n";
                                        saveBooking << bookingPaymentStatus[i] << "\n";
                                        saveBooking << bookingBankNames[i] << "\n";
                                        saveBooking << bookingAccountNumbers[i] << "\n";
                                        saveBooking << bookingCancelled[i] << "\n";
                                    }
                                    saveBooking.close();
                                    
                                    cout << "\n  Booking Cancelled Successfully!\n";
                                } else {
                                    cout << "\n  Operation Cancelled.\n";
                                }
                            }
                        }
                        cout << "\n  Press Enter to continue...";
                        cin.ignore();
                        cin.get();
                    }
                    else if(adminChoice == 9){
                        // Customer List
                        cout << "\033[2J\033[1;1H";
                        cout << "\n  +------------------------------------------------------------+\n";
                        cout << "  |                    CUSTOMER LIST                            |\n";
                        cout << "  +------------------------------------------------------------+\n\n";
                        
                        if(bookingCount == 0){
                            cout << "\n  No customers found.\n";
                        } else {
                            cout << "  " << left << setw(5) << "No." << setw(25) << "Customer Name" << setw(20) << "User ID" << "Bookings\n";
                            cout << "  ";
                            for(int i=0;i<60;i++) cout << "-";
                            cout << "\n";
                            
                            int serial = 1;
                            for(int i = 0; i < bookingCount; i++){
                                bool alreadyPrinted = false;
                                for(int j = 0; j < i; j++){
                                    if(bookingUserIds[j] == bookingUserIds[i]){
                                        alreadyPrinted = true;
                                        break;
                                    }
                                }
                                if(!alreadyPrinted){
                                    int bcount = 0;
                                    for(int j = 0; j < bookingCount; j++){
                                        if(bookingUserIds[j] == bookingUserIds[i] && !bookingCancelled[j]) bcount++;
                                    }
                                    cout << "  " << left << setw(5) << serial++;
                                    cout << setw(25) << bookingUserNames[i];
                                    cout << setw(20) << bookingUserIds[i];
                                    cout << bcount << "\n";
                                }
                            }
                        }
                        cout << "\n  Press Enter to continue...";
                        cin.ignore();
                        cin.get();
                    }
                    else if(adminChoice == 10){
                        // Customer Details
                        cout << "\033[2J\033[1;1H";
                        cout << "\n  +--------------------------------------------------------------------------+\n";
                        cout << "  |                       COMPLETE CUSTOMER DETAILS                                |\n";
                        cout << "  +--------------------------------------------------------------------------+\n\n";
                        
                        if(userCount == 0){
                            cout << "\n  No customers registered.\n";
                        } else {
                            for(int i = 0; i < userCount; i++){
                                int bcount = 0;
                                for(int j = 0; j < bookingCount; j++){
                                    if(bookingUserIds[j] == userUsernames[i]) bcount++;
                                }
                                
                                cout << "  +--------------------------------------------------------------------+\n";
                                cout << "  |  Customer #" << (i+1) << " : " << left << setw(56) << userFullNames[i] << "|\n";
                                cout << "  |--------------------------------------------------------------------|\n";
                                cout << "  |  Username    : " << left << setw(53) << userUsernames[i] << "|\n";
                                cout << "  |  Phone       : " << left << setw(53) << userPhones[i] << "|\n";
                                cout << "  |  Email       : " << left << setw(53) << userEmails[i] << "|\n";
                                cout << "  |  CNIC        : " << left << setw(53) << userCnic[i] << "|\n";
                                cout << "  |  Bookings    : " << left << setw(53) << bcount << "|\n";
                                
                                for(int j = 0; j < bookingCount; j++){
                                    if(bookingUserIds[j] == userUsernames[i]){
                                        string status = bookingCancelled[j] ? "Cancelled" : "Active";
                                        cout << "  |  [" << bookingIds[j] << "] " << bookingPackageNames[j] << " | " 
                                             << bookingDates[j] << " | " << bookingPaymentStatus[j] << " | " << status;
                                        cout << string(68 - (bookingIds[j] + bookingPackageNames[j] + bookingDates[j] + bookingPaymentStatus[j] + status).length(), ' ') << "|\n";
                                    }
                                }
                                
                                cout << "  +--------------------------------------------------------------------+\n\n";
                            }
                        }
                        cout << "\n  Press Enter to continue...";
                        cin.ignore();
                        cin.get();
                    }
                    
                } while(adminChoice != 0);
            } else {
                cout << "\n  Invalid username or password!\n";
                cout << "\n  Press Enter to return to main menu...";
                cin.ignore();
                cin.get();
            }
        }
        else if(mainChoice == 2){
            // User Login
            cout << "\033[2J\033[1;1H";
            cout << "\n  +--------------------------------------------------+\n";
            cout << "  |              USER LOGIN PORTAL                      |\n";
            cout << "  +--------------------------------------------------+\n\n";
            
            string uname, pass;
            cout << "  Enter Username : ";
            cin >> uname;
            cout << "  Enter Password : ";
            cin >> pass;
            
            bool userFound = false;
            for(int i = 0; i < userCount; i++){
                if(userUsernames[i] == uname && userPasswords[i] == pass){
                    userFound = true;
                    loggedInUser = uname;
                    loggedInName = userFullNames[i];
                    break;
                }
            }
            
            if(userFound){
                cout << "\n  Login Successful! Welcome, " << loggedInName << "\n";
                cout << "\n  Press Enter to continue...";
                cin.ignore();
                cin.get();
                
                // User Menu
                int userChoice;
                do {
                    cout << "\033[2J\033[1;1H";
                    cout << "\n  +--------------------------------------------------+\n";
                    cout << "  |   Welcome, " << left << setw(38) << loggedInName << "|\n";
                    cout << "  |--------------------------------------------------|\n";
                    cout << "  |               USER PANEL                           |\n";
                    cout << "  |--------------------------------------------------|\n";
                    cout << "  |   [1]  View Packages                            |\n";
                    cout << "  |   [2]  Book a Package                           |\n";
                    cout << "  |   [3]  Rate Package                             |\n";
                    cout << "  |   [4]  Payment System                           |\n";
                    cout << "  |   [5]  Cancel Booking                           |\n";
                    cout << "  |   [6]  View Booking Details                     |\n";
                    cout << "  |   [7]  Rate Package (Feedback)                  |\n";
                    cout << "  |   [8]  Check Payment Status                     |\n";
                    cout << "  |   [9]  Booking History                          |\n";
                    cout << "  |   [0]  Logout                                   |\n";
                    cout << "  +--------------------------------------------------+\n";
                    cout << "\n  Enter Your Choice : ";
                    cin >> userChoice;
                    
                    if(userChoice == 1){
                        // View Packages
                        cout << "\033[2J\033[1;1H";
                        cout << "\n  +----------------------------------------------------------------------------+\n";
                        cout << "  |                    AVAILABLE UMRAH PACKAGES                                    |\n";
                        cout << "  +----------------------------------------------------------------------------+\n\n";
                        
                        if(packageCount == 0){
                            cout << "\n  No packages available at the moment.\n";
                        } else {
                            for(int i = 0; i < packageCount; i++){
                                cout << "  +------------------------------------------------------------+\n";
                                cout << "  |  * " << left << setw(57) << packageNames[i] << "|\n";
                                cout << "  |------------------------------------------------------------|\n";
                                cout << "  |  Duration     : " << left << setw(44) << (to_string(packageDays[i]) + " Days") << "|\n";
                                cout << "  |  Amount       : PKR " << left << setw(40) << packageAmounts[i] << "|\n";
                                cout << "  |  Type         : " << left << setw(44) << packageTypes[i] << "|\n";
                                cout << "  |  Includes     : " << left << setw(44) << packageIncludes[i] << "|\n";
                                cout << "  +------------------------------------------------------------+\n\n";
                            }
                        }
                        cout << "\n  Press Enter to continue...";
                        cin.ignore();
                        cin.get();
                    }
                    else if(userChoice == 2){
                        // Book a Package
                        cout << "\033[2J\033[1;1H";
                        cout << "\n  +------------------------------------------------------------+\n";
                        cout << "  |                BOOK UMRAH PACKAGE                           |\n";
                        cout << "  +------------------------------------------------------------+\n\n";
                        
                        if(packageCount == 0){
                            cout << "\n  No packages available for booking.\n";
                        } else {
                            cout << "  Available Packages:\n";
                            cout << "  ";
                            for(int i=0;i<55;i++) cout << "-";
                            cout << "\n";
                            for(int i = 0; i < packageCount; i++){
                                cout << "  [" << (i+1) << "] ";
                                cout << left << setw(25) << packageNames[i];
                                cout << "PKR " << packageAmounts[i] << "   (" << packageDays[i] << " days)\n";
                            }
                            cout << "  ";
                            for(int i=0;i<55;i++) cout << "-";
                            cout << "\n\n";
                            
                            cout << "  Enter Package Name to Book : ";
                            cin.ignore();
                            string pkgName;
                            getline(cin, pkgName);
                            
                            int pkgIdx = -1;
                            for(int i = 0; i < packageCount; i++){
                                if(packageNames[i] == pkgName){
                                    pkgIdx = i;
                                    break;
                                }
                            }
                            
                            if(pkgIdx == -1){
                                cout << "\n  Package not found!\n";
                            } else {
                                // Get current date
                                time_t now = time(0);
                                tm* ltm = localtime(&now);
                                stringstream ss;
                                ss << setfill('0') << setw(2) << ltm->tm_mday << "/"
                                   << setfill('0') << setw(2) << (1 + ltm->tm_mon) << "/"
                                   << (1900 + ltm->tm_year);
                                string currentDate = ss.str();
                                
                                string bookingId = "BK" + to_string(bookingCount + 1001);
                                bookingIds[bookingCount] = bookingId;
                                bookingUserIds[bookingCount] = loggedInUser;
                                bookingUserNames[bookingCount] = loggedInName;
                                bookingPackageNames[bookingCount] = pkgName;
                                bookingDates[bookingCount] = currentDate;
                                bookingPaymentStatus[bookingCount] = "Unpaid";
                                bookingBankNames[bookingCount] = "";
                                bookingAccountNumbers[bookingCount] = "";
                                bookingCancelled[bookingCount] = false;
                                bookingCount++;
                                
                                // Save to file
                                ofstream saveBooking("bookings.txt");
                                saveBooking << bookingCount << "\n";
                                for(int i = 0; i < bookingCount; i++){
                                    saveBooking << bookingIds[i] << "\n";
                                    saveBooking << bookingUserIds[i] << "\n";
                                    saveBooking << bookingUserNames[i] << "\n";
                                    saveBooking << bookingPackageNames[i] << "\n";
                                    saveBooking << bookingDates[i] << "\n";
                                    saveBooking << bookingPaymentStatus[i] << "\n";
                                    saveBooking << bookingBankNames[i] << "\n";
                                    saveBooking << bookingAccountNumbers[i] << "\n";
                                    saveBooking << bookingCancelled[i] << "\n";
                                }
                                saveBooking.close();
                                
                                cout << "\n  Booking Confirmed!\n";
                                cout << "  Booking ID : " << bookingId << "\n";
                                cout << "  Package    : " << pkgName << "\n";
                                cout << "  Date       : " << currentDate << "\n";
                                cout << "  Payment    : Unpaid (Complete from Option 4)\n";
                            }
                        }
                        cout << "\n  Press Enter to continue...";
                        cin.ignore();
                        cin.get();
                    }
                    else if(userChoice == 3 || userChoice == 7){
                        // Rate Package
                        cout << "\033[2J\033[1;1H";
                        cout << "\n  +------------------------------------------------------------+\n";
                        cout << "  |               RATE YOUR PACKAGE                             |\n";
                        cout << "  +------------------------------------------------------------+\n\n";
                        
                        bool found = false;
                        for(int i = 0; i < bookingCount; i++){
                            if(bookingUserIds[i] == loggedInUser && !bookingCancelled[i]){
                                found = true;
                                cout << "  Your Package: " << bookingPackageNames[i] << "\n";
                                break;
                            }
                        }
                        
                        if(!found){
                            cout << "\n  No active bookings to rate.\n";
                        } else {
                            int rating;
                            cout << "\n  Rate the package (1-5 stars): ";
                            cin >> rating;
                            
                            if(rating >= 1 && rating <= 5){
                                cout << "\n  Thank you for your rating: ";
                                for(int i = 0; i < rating; i++) cout << "* ";
                                cout << "\n";
                                cout << "  Your feedback has been recorded.\n";
                            } else {
                                cout << "\n  Invalid rating! Please rate between 1-5.\n";
                            }
                        }
                        cout << "\n  Press Enter to continue...";
                        cin.ignore();
                        cin.get();
                    }
                    else if(userChoice == 4){
                        // Payment System
                        cout << "\033[2J\033[1;1H";
                        cout << "\n  +------------------------------------------------------------+\n";
                        cout << "  |                   PAYMENT SYSTEM                            |\n";
                        cout << "  +------------------------------------------------------------+\n\n";
                        
                        bool hasUnpaid = false;
                        int unpaidIndex = -1;
                        for(int i = 0; i < bookingCount; i++){
                            if(bookingUserIds[i] == loggedInUser && !bookingCancelled[i] && bookingPaymentStatus[i] == "Unpaid"){
                                hasUnpaid = true;
                                unpaidIndex = i;
                                cout << "  Pending Payment:\n";
                                cout << "  Booking ID : " << bookingIds[i] << "\n";
                                cout << "  Package    : " << bookingPackageNames[i] << "\n";
                                for(int j = 0; j < packageCount; j++){
                                    if(packageNames[j] == bookingPackageNames[i]){
                                        cout << "  Amount     : PKR " << packageAmounts[j] << "\n";
                                        break;
                                    }
                                }
                                cout << "\n";
                                break;
                            }
                        }
                        
                        if(!hasUnpaid){
                            cout << "\n  All your bookings are already paid or no active bookings found.\n";
                        } else {
                            string bankName, accNum;
                            cin.ignore();
                            cout << "  Enter Bank Name       : ";
                            getline(cin, bankName);
                            cout << "  Enter Account Number  : ";
                            getline(cin, accNum);
                            
                            cout << "\n  [1] Confirm Payment\n";
                            cout << "  [2] Cancel\n";
                            cout << "\n  Enter Choice : ";
                            int ch;
                            cin >> ch;
                            
                            if(ch == 1){
                                bookingPaymentStatus[unpaidIndex] = "Paid";
                                bookingBankNames[unpaidIndex] = bankName;
                                bookingAccountNumbers[unpaidIndex] = accNum;
                                
                                // Save to file
                                ofstream saveBooking("bookings.txt");
                                saveBooking << bookingCount << "\n";
                                for(int i = 0; i < bookingCount; i++){
                                    saveBooking << bookingIds[i] << "\n";
                                    saveBooking << bookingUserIds[i] << "\n";
                                    saveBooking << bookingUserNames[i] << "\n";
                                    saveBooking << bookingPackageNames[i] << "\n";
                                    saveBooking << bookingDates[i] << "\n";
                                    saveBooking << bookingPaymentStatus[i] << "\n";
                                    saveBooking << bookingBankNames[i] << "\n";
                                    saveBooking << bookingAccountNumbers[i] << "\n";
                                    saveBooking << bookingCancelled[i] << "\n";
                                }
                                saveBooking.close();
                                
                                cout << "\n  Payment Status = Paid\n";
                                cout << "  Bank Name      : " << bankName << "\n";
                                cout << "  Account No     : " << accNum << "\n";
                            } else {
                                cout << "\n  Payment Status = Unpaid\n";
                            }
                        }
                        cout << "\n  Press Enter to continue...";
                        cin.ignore();
                        cin.get();
                    }
                    else if(userChoice == 5){
                        // Cancel Booking
                        cout << "\033[2J\033[1;1H";
                        cout << "\n  +------------------------------------------------------------+\n";
                        cout << "  |               CANCEL YOUR BOOKING                           |\n";
                        cout << "  +------------------------------------------------------------+\n\n";
                        
                        bool hasBooking = false;
                        for(int i = 0; i < bookingCount; i++){
                            if(bookingUserIds[i] == loggedInUser && !bookingCancelled[i]){
                                hasBooking = true;
                                cout << "  ID: " << bookingIds[i] << "  |  " << bookingPackageNames[i] << "  |  " << bookingDates[i] << "\n";
                            }
                        }
                        
                        if(!hasBooking){
                            cout << "\n  No active bookings found.\n";
                        } else {
                            cout << "\n  Enter Booking ID to Cancel : ";
                            cin.ignore();
                            string bid;
                            getline(cin, bid);
                            
                            int idx = -1;
                            for(int i = 0; i < bookingCount; i++){
                                if(bookingIds[i] == bid && bookingUserIds[i] == loggedInUser && !bookingCancelled[i]){
                                    idx = i;
                                    break;
                                }
                            }
                            
                            if(idx == -1){
                                cout << "\n  Booking not found!\n";
                            } else {
                                cout << "\n  [1] Confirm Cancellation\n";
                                cout << "  [2] Go Back\n";
                                cout << "\n  Enter Choice : ";
                                int ch;
                                cin >> ch;
                                
                                if(ch == 1){
                                    bookingCancelled[idx] = true;
                                    
                                    // Save to file
                                    ofstream saveBooking("bookings.txt");
                                    saveBooking << bookingCount << "\n";
                                    for(int i = 0; i < bookingCount; i++){
                                        saveBooking << bookingIds[i] << "\n";
                                        saveBooking << bookingUserIds[i] << "\n";
                                        saveBooking << bookingUserNames[i] << "\n";
                                        saveBooking << bookingPackageNames[i] << "\n";
                                        saveBooking << bookingDates[i] << "\n";
                                        saveBooking << bookingPaymentStatus[i] << "\n";
                                        saveBooking << bookingBankNames[i] << "\n";
                                        saveBooking << bookingAccountNumbers[i] << "\n";
                                        saveBooking << bookingCancelled[i] << "\n";
                                    }
                                    saveBooking.close();
                                    
                                    cout << "\n  Booking Cancelled Successfully.\n";
                                } else {
                                    cout << "\n  Operation Cancelled.\n";
                                }
                            }
                        }
                        cout << "\n  Press Enter to continue...";
                        cin.ignore();
                        cin.get();
                    }
                    else if(userChoice == 6){
                        // View Booking Details
                        cout << "\033[2J\033[1;1H";
                        cout << "\n  +-----------------------------------------------------------------+\n";
                        cout << "  |                   YOUR BOOKING DETAILS                            |\n";
                        cout << "  +-----------------------------------------------------------------+\n\n";
                        
                        bool found = false;
                        for(int i = 0; i < bookingCount; i++){
                            if(bookingUserIds[i] == loggedInUser && !bookingCancelled[i]){
                                found = true;
                                cout << "  +------------------------------------------------------------+\n";
                                cout << "  |  Booking ID     : " << left << setw(42) << bookingIds[i] << "|\n";
                                cout << "  |  Package        : " << left << setw(42) << bookingPackageNames[i] << "|\n";
                                cout << "  |  Booking Date   : " << left << setw(42) << bookingDates[i] << "|\n";
                                cout << "  |  Payment Status : " << left << setw(42) << bookingPaymentStatus[i] << "|\n";
                                if(bookingPaymentStatus[i] == "Paid"){
                                    cout << "  |  Bank Name      : " << left << setw(42) << bookingBankNames[i] << "|\n";
                                    cout << "  |  Account No     : " << left << setw(42) << bookingAccountNumbers[i] << "|\n";
                                }
                                for(int j = 0; j < packageCount; j++){
                                    if(packageNames[j] == bookingPackageNames[i]){
                                        cout << "  |  Duration       : " << left << setw(39) << (to_string(packageDays[j]) + " Days") << "|\n";
                                        cout << "  |  Amount         : PKR " << left << setw(39) << packageAmounts[j] << "|\n";
                                        break;
                                    }
                                }
                                cout << "  +------------------------------------------------------------+\n\n";
                            }
                        }
                        
                        if(!found){
                            cout << "\n  No active bookings found.\n";
                        }
                        cout << "\n  Press Enter to continue...";
                        cin.ignore();
                        cin.get();
                    }
                    else if(userChoice == 8){
                        // Check Payment Status
                        cout << "\033[2J\033[1;1H";
                        cout << "\n  +-------------------------------------------------------+\n";
                        cout << "  |               CHECK PAYMENT STATUS                      |\n";
                        cout << "  +-------------------------------------------------------+\n\n";
                        
                        bool found = false;
                        for(int i = 0; i < bookingCount; i++){
                            if(bookingUserIds[i] == loggedInUser && !bookingCancelled[i]){
                                found = true;
                                cout << "  Booking ID : " << bookingIds[i] << "\n";
                                cout << "  Package    : " << bookingPackageNames[i] << "\n";
                                if(bookingPaymentStatus[i] == "Paid"){
                                    cout << "\n  Payment Status = Paid\n";
                                } else {
                                    cout << "\n  Payment Status = Unpaid\n";
                                }
                                cout << "\n";
                            }
                        }
                        
                        if(!found){
                            cout << "\n  No active bookings found.\n";
                        }
                        cout << "\n  Press Enter to continue...";
                        cin.ignore();
                        cin.get();
                    }
                    else if(userChoice == 9){
                        // Booking History
                        cout << "\033[2J\033[1;1H";
                        cout << "\n  +-----------------------------------------------------------------+\n";
                        cout << "  |                    BOOKING HISTORY                                |\n";
                        cout << "  +-----------------------------------------------------------------+\n\n";
                        
                        int total = 0, active = 0, cancelled = 0;
                        for(int i = 0; i < bookingCount; i++){
                            if(bookingUserIds[i] == loggedInUser){
                                total++;
                                if(bookingCancelled[i]) cancelled++;
                                else active++;
                            }
                        }
                        
                        cout << "  Total Packages Booked : " << total << "\n";
                        cout << "  Active Bookings       : " << active << "\n";
                        cout << "  Cancelled Bookings    : " << cancelled << "\n\n";
                        
                        if(total == 0){
                            cout << "\n  No booking history found.\n";
                        } else {
                            cout << "  " << left << setw(12) << "Booking ID" << setw(25) << "Package Name" << setw(14) << "Booking Date" << setw(10) << "Payment" << "Status\n";
                            cout << "  ";
                            for(int i=0;i<65;i++) cout << "-";
                            cout << "\n";
                            
                            for(int i = 0; i < bookingCount; i++){
                                if(bookingUserIds[i] == loggedInUser){
                                    cout << "  " << left << setw(12) << bookingIds[i]
                                         << setw(25) << bookingPackageNames[i]
                                         << setw(14) << bookingDates[i]
                                         << setw(10) << bookingPaymentStatus[i]
                                         << (bookingCancelled[i] ? "Cancelled" : "Active") << "\n";
                                }
                            }
                        }
                        cout << "\n  Press Enter to continue...";
                        cin.ignore();
                        cin.get();
                    }
                    
                } while(userChoice != 0);
            } else {
                cout << "\n  Invalid username or password!\n";
                cout << "\n  Press Enter to return to main menu...";
                cin.ignore();
                cin.get();
            }
        }
        else if(mainChoice == 3){
            // New User Registration
            cout << "\033[2J\033[1;1H";
            cout << "\n  +------------------------------------------------------------+\n";
            cout << "  |               NEW USER REGISTRATION                        |\n";
            cout << "  |------------------------------------------------------------|\n";
            cout << "  |   All fields are required and validated.                   |\n";
            cout << "  +------------------------------------------------------------+\n\n";
            
            if(userCount >= 100){
                cout << "\n  User registration limit reached!\n";
            } else {
                string uname, pass, fullname, phone, email, cnic;
                
                cout << "  Enter Username       : ";
                cin >> uname;
                cout << "  Enter Password       : ";
                cin >> pass;
                cout << "  Confirm Password     : ";
                string confirmPass;
                cin >> confirmPass;
                
                if(pass != confirmPass){
                    cout << "\n  Passwords do not match!\n";
                } else {
                    cin.ignore();
                    cout << "  Enter Full Name      : ";
                    getline(cin, fullname);
                    cout << "  Enter Phone Number   : ";
                    getline(cin, phone);
                    cout << "  Enter Email          : ";
                    getline(cin, email);
                    cout << "  Enter CNIC           : ";
                    getline(cin, cnic);
                    
                    userUsernames[userCount] = uname;
                    userPasswords[userCount] = pass;
                    userFullNames[userCount] = fullname;
                    userPhones[userCount] = phone;
                    userEmails[userCount] = email;
                    userCnic[userCount] = cnic;
                    userCount++;
                    
                    // Save to file
                    ofstream saveUser("users.txt");
                    saveUser << userCount << "\n";
                    for(int i = 0; i < userCount; i++){
                        saveUser << userUsernames[i] << "\n";
                        saveUser << userPasswords[i] << "\n";
                        saveUser << userFullNames[i] << "\n";
                        saveUser << userPhones[i] << "\n";
                        saveUser << userEmails[i] << "\n";
                        saveUser << userCnic[i] << "\n";
                    }
                    saveUser.close();
                    
                    cout << "\n  Registration Successful!\n";
                    cout << "  You can now login with your credentials.\n";
                }
            }
            cout << "\n  Press Enter to return to main menu...";
            cin.ignore();
            cin.get();
        }
        
    } while(mainChoice != 0);
    
    // Exit message
    cout << "\033[2J\033[1;1H";
    cout << "\n\n\n";
    cout << "          +-------------------------------------------------+\n";
    cout << "          |   Thank you for using our system!              |\n";
    cout << "          |   AL-HARAMAIN Tours & Travels                  |\n";
    cout << "          |   May Allah Accept Your Umrah. Ameen.          |\n";
    cout << "          +-------------------------------------------------+\n\n";
    
    return 0;
}