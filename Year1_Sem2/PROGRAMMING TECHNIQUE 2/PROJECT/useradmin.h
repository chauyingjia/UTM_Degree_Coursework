#ifndef USERADMIN_H
#define USERADMIN_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Admin;

class User {
private:
    double yearlyIncome, relief, taxableIncome, incomeTax, rebate, MTD;

public:
    User(double yI = 0.0, double rl = 0.0, double tI = 0.0, double iT = 0.0, double rb = 0.0, double mtd = 0.0);
    
    void setYearlyIncome(double yI);
    void setRelief(double rl);
    void setTaxableIncome(double tI);
    void setIncomeTax(double iT);
    void setRebate(double rb);
    void setMtd(double mtd);
    
    double calcYearlyIncome();
    double calcTotalRelief();
    double calcTaxableIncome(double y, double r);
    double calcIncomeTax(double tI, Admin& obj1);
    double calcRebate(double tI);
    void calcFinal(double r, double iT, double mtd);
    void displaySummary();

    friend class Admin;
};

class Admin {
private:
    int id = 007;
    double rate[12] = {0.00, 0.01, 0.03, 0.08, 0.14, 0.21, 0.24, 0.245, 0.25, 0.26, 0.28, 0.30};
    double amount[12] = {0.00, 0.00, 150.00, 600.00, 1800.00, 4600.00, 10900.00, 46900.00, 83650.00, 133650.00, 237650.00, 517650.00};

public:
    int getId() { return id; }
    void updateRate();
    void displayRate();

    friend class User;
};

#endif
