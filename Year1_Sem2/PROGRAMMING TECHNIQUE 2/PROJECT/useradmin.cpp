#include "UserAdmin.h"
#include<iostream>
#include <iomanip>

using namespace std;

// User Constructor
User::User(double yI, double rl, double tI, double iT, double rb, double mtd) {
    yearlyIncome = yI;
    relief = rl;
    taxableIncome = tI;
    incomeTax = iT;
    rebate = rb;
    MTD = mtd;
}

// Mutator Functions
void User::setYearlyIncome(double yI) { yearlyIncome = yI; }
void User::setRelief(double rl) { relief = rl; }
void User::setTaxableIncome(double tI) { taxableIncome = tI; }
void User::setIncomeTax(double iT) { incomeTax = iT; }
void User::setRebate(double rb) { rebate = rb; }
void User::setMtd(double mtd) { MTD = mtd; }

// User Member Functions
double User::calcYearlyIncome() {
    double act_income, pas_income;
    cout << "Please enter the details of your ANNUAL INCOME : " << endl;
    cout << "Active income  = RM";
    cin >> act_income;
    cout << "Passive income = RM";
    cin >> pas_income;
    return act_income + pas_income;
}

double User::calcTotalRelief() {
    double r = 0.0;
    double IDR, edu, disabled, m1, m2;
    cout << "\nPlease enter the details of TAX RELIEF : " << endl;
    cout << "Amount of individual & dependent relatives (Limit RM9000)= RM";
    cin >> IDR;
    if (IDR > 9000) { IDR = 9000; }
    cout << "Amount of education fee for self (Limit RM7000)= RM";
    cin >> edu;
    if (edu > 7000) { edu = 7000; }
    cout << "Amount of equipment for disabled person (Limit RM6000)= RM";
    cin >> disabled;
    if (disabled > 6000) { disabled = 6000; }
    cout << "Amount of medical expenses for self, spouse or children (Limit RM10000)= RM";
    cin >> m1;
    if (m1 > 10000) { m1 = 10000; }
    cout << "Amount of medical expenses for parent (Limit RM8000)= RM";
    cin >> m2;
    if (m2 > 8000) { m2 = 8000; }
    r = IDR + edu + disabled + m1 + m2;
    return r;
}

double User::calcTaxableIncome(double y, double r) {
    return y - r;
}

double User::calcIncomeTax(double tI, Admin& obj1) {
    double iT = 0.00;
    if (tI <= 5000.00) {
        iT = 0.00;
    } else if (tI <= 20000.00) {
        iT = 0.00;
        tI -= 5000.00;
        iT += tI * obj1.rate[1];
    } else if (tI <= 35000.00) {
        iT = obj1.amount[2];
        tI -= 20000.00;
        iT += tI * obj1.rate[2];
    } else if (tI <= 50000.00) {
        iT = obj1.amount[3];
        tI -= 35000.00;
        iT += tI * obj1.rate[3];
    } else if (tI <= 70000.00) {
        iT = obj1.amount[4];
        tI -= 50000.00;
        iT += tI * obj1.rate[4];
    } else if (tI <= 100000.00) {
        iT = obj1.amount[5];
        tI -= 70000.00;
        iT += tI * obj1.rate[5];
    } else if (tI <= 250000.00) {
        iT = obj1.amount[6];
        tI -= 100000.00;
        iT += tI * obj1.rate[6];
    } else if (tI <= 400000.00) {
        iT = obj1.amount[7];
        tI -= 250000.00;
        iT += tI * obj1.rate[7];
    } else if (tI <= 600000.00) {
        iT = obj1.amount[8];
        tI -= 400000.00;
        iT += tI * obj1.rate[8];
    } else if (tI <= 1000000.00) {
        iT = obj1.amount[9];
        tI -= 600000.00;
        iT += tI * obj1.rate[9];
    } else if (tI <= 2000000.00) {
        iT = obj1.amount[10];
        tI -= 1000000.00;
        iT += tI * obj1.rate[10];
    } else {
        iT = obj1.amount[11];
        tI -= 2000000.00;
        iT += tI * obj1.rate[11];
    }
    return iT;
}

double User::calcRebate(double tI) {
    double zakat, rebate;
    double taxRebate = 0.0;
    cout << "\nPlease enter the details of TAX REBATE : " << endl;
    cout << "Zakat & fitrah = RM";
    cin >> zakat;
    if (tI <= 35000.00) {
        rebate = 400.00;
    } else {
        rebate = 0.00;
    }
    taxRebate = zakat + rebate;
    return taxRebate;
}

void User::calcFinal(double r, double iT, double mtd) {
    double final;
    double temp_iT = iT - r;
    cout << "\n\n---------------------------------------------------------------------------------" << endl;
    if (temp_iT < 0) {
        temp_iT = 0;
    }
    if (temp_iT > mtd) {
        final = temp_iT - mtd;
        cout << "\nAmount need to pay to LHDN = RM" << final << endl;
    } else {
        final = mtd - temp_iT;
        cout << "\nAmount need to return by LHDN = RM" << final << endl;
    }
}

void User::displaySummary() {
    cout << "\n------------------------------------ SUMMARY ------------------------------------" << endl;
    cout << "\nYearly Income   = RM" << fixed << setprecision(2) << yearlyIncome << endl;
    cout << "Total Relief    = RM" << relief << endl;
    cout << "Taxable Income  = RM" << taxableIncome << endl;
    cout << "Income Tax      = RM" << incomeTax << endl;
    cout << "Rebate          = RM" << rebate << endl;
    cout << "Total MTD       = RM" << MTD << endl;
    calcFinal(rebate, incomeTax, MTD);
}

// Admin Member Functions
void Admin::updateRate() {
    double newRate[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    cout << "\n---------------------------------------------------------------------------------" << endl << endl;
    cout << "Please enter the NEW income tax rate" << endl << endl;
    for (int i = 0; i < 12; i++) {
        cout << "Rate " << i + 1 << " : ";
        cin >> newRate[i];
        rate[i] = newRate[i];
    }
    cout << endl << "---------------------------------------------------------------------------------" << endl;
    cout << "\nTax rate renew successfully!\n" << endl;
}

void Admin::displayRate() {
    for (int i = 0; i < 12; i++) {
        cout << "Rate " << i + 1 << " :" << fixed << setprecision(3) << rate[i] << endl;
    }
}
