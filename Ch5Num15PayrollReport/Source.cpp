/************************************************
** Author: Andrea Hayes
** Date: March 31th, 2020
** Purpose: Display a weekly payroll report
** Input: Employee number, gross pay, state tax, federal tax,
          and FICA witholdings
** Processing: Create a loop with the above information
** Output: Display everything in input and also net pay
*************************************************/
#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    
    int employeeNumber = -1, count;  // Declare Variables 
    double totalGrossPay=0, totalState=0, totalFederal=0, totalFica=0, totalTaxesSum=0, totalNetPay=0;
    count = 0;                         

    while (employeeNumber != 0)  // Loop for Payroll Report 
    {
        double grossPay, state, federal, fica, taxesSum, netPay;

        cout << "Enter Employee Number: ";
        cin >> employeeNumber;

        if (employeeNumber == 0) {  // Break loop if 0 is entered for employee number
            break;
        }
        if (employeeNumber < 0) // Input Validation for Employee Number
        {
            cout << "Number cannot be negative. Please reenter data. ";
            continue;
        }
        
        cout << "Enter Gross Pay: ";
        cin >> grossPay;
        if (grossPay < 0 )  // Input Validation for negative number
        {
            cout << "Number cannot be negative. Please reenter data. ";
            continue;
        }

        cout << "Enter State Tax: ";
        cin >> state;
        if (state < 0)  // Input Validation for negative number
        {
            cout << "Number cannot be negative. Please reenter data. ";
            continue;
        }
        if (state > grossPay) // Input validation for tax more than gross pay
        {
            cout << "State taxes must be less than gross pay. Please reenter data.";
        continue;
        }

        cout << "Enter Federal Tax: ";
        cin >> federal;
        if (federal < 0)  // Input Validation for negative number
        {
            cout << "Number cannot be negative. Please reenter data. ";
            continue;
        }
        if (federal > grossPay) // Input validation for tax more than gross pay
        {
            cout << "Federal taxes must be less than gross pay. Please reenter data.";
        continue;
        }

        cout << "Enter FICA witholdings: ";
        cin >> fica;
        if (fica < 0)  // Input Validation for negative number
        {
            cout << "Number cannot be negative. Please reenter data. ";
            continue;
        }
        if (fica > grossPay)  // Input validation for tax more than gross pay
        {
                cout << "FICA Witholdings must be less than gross pay. Please reenter data.";
            continue;
        }

        taxesSum = state + federal + fica;  // Formula for adding taxes
        netPay = grossPay - taxesSum;  // Formula for figuring Net Pay

        if (taxesSum > grossPay)  // Input validation for tax more than gross pay
        {
            cout << "Total of taxes must to less than gross pay. Please reenter data. ";
            continue;
        }

            totalGrossPay += grossPay;  // Formulas for adding to taxes as data is inputed 
            totalState += state;
            totalFederal += federal;
            totalFica += fica;
            totalTaxesSum = totalState + totalFederal + totalFica;
            totalNetPay = totalGrossPay - totalTaxesSum;

            count++;  // Ends loop
        }

    cout << left << setprecision(2) << fixed;
    cout << "-------------------------" << endl;
    cout << "Gross Pay: " << right << setw(20) << totalGrossPay << endl;
    cout << "State Tax: " << right << setw(20) << totalState << endl;
    cout << "Federal Tax: " << right << setw(18) << totalFederal << endl;
    cout << "FICA witholdings: " << right << setw(13) << totalFica << endl;
    cout << "Net Pay: " << right << setw(22) << totalNetPay << endl;

    return 0;
}