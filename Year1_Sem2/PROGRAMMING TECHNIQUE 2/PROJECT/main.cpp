#include "UserAdmin.cpp"
#include<iostream>
#include <iomanip>

using namespace std;
int main() {
    double yI, tR, tI, iT, r, mtd;
    int choice, temp_id;

    User u; 
    Admin a;
    
    do {
        cout << "\n------------------- Welcome to Income Tax Calculation System -------------------\n" << endl;
        cout << "1. Admin" << endl;
        cout << "2. User" << endl;
        cout << "3. Exit" << endl;
        cout << "\nPlease enter your choice (1/2/3): ";
        cin >> choice;
        cout << endl;
    } while (choice < 1 || choice > 3);

    if (choice == 1) {
        cout << "\n--------------------------- Welcome to the Admin Page ---------------------------" << endl << endl;
        do {
            int temp_choice;
            cout << "Please enter your admin ID : ";
            cin >> temp_id;
            
            if (temp_id == a.getId()) {
                cout << "Welcome!" << endl << endl;
                cout << "--------------------------------- Current Rate ----------------------------------\n" << endl;
                a.displayRate();
                a.updateRate();
                cout << "---------------------------------------------------------------------------------" << endl;
                
                cout << "\nDo you want to test the income tax calculation system ?" << endl;
                cout << "1. Yes\n2. No" << endl;
                cout << "\nEnter your choice :";
                cin >> temp_choice;
                
                if (temp_choice == 1) {
                    cout << "\n---------------------------- Welcome to the User Page ----------------------------\n" << endl;
                    yI = u.calcYearlyIncome();
                    u.setYearlyIncome(yI);
                    tR = u.calcTotalRelief();
                    u.setRelief(tR);
                    tI = u.calcTaxableIncome(yI, tR);
                    u.setTaxableIncome(tI);
                    iT = u.calcIncomeTax(tI, a);
                    u.setIncomeTax(iT);
                    r = u.calcRebate(tI);
                    u.setRebate(r);
                    cout << "\nPlease enter the Monthly Tax Deduction (MTD) : RM";
                    cin >> mtd;
                    mtd *= 12;
                    u.setMtd(mtd);
                    u.displaySummary();
                } else {
                    cout << "Logging out from Admin Page....";
                }
            } else {
                cout << "Incorrect ID..." << endl << endl;
            }
        } while (temp_id != a.getId());
    } else if (choice == 2) {
        cout << "\n---------------------------- Welcome to the User Page ----------------------------\n" << endl;
        yI = u.calcYearlyIncome();
        u.setYearlyIncome(yI);
        tR = u.calcTotalRelief();
        u.setRelief(tR);
        tI = u.calcTaxableIncome(yI, tR);
        u.setTaxableIncome(tI);
        iT = u.calcIncomeTax(tI, a);
        u.setIncomeTax(iT);
        r = u.calcRebate(tI);
        u.setRebate(r);
        cout << "\nPlease enter the Monthly Tax Deduction (MTD) : RM";
        cin >> mtd;
        mtd *= 12;
        u.setMtd(mtd);
        u.displaySummary();
    } else {
        cout << "Thank you for using our system !!" << endl;
        cout << "Goodbye...";
    }

    return 0;
}
