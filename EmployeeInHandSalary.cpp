#include <iostream>
using namespace std;
 int main(){
    /*Accept Employee Basic Salary
        Calculate HRA = 10% of Basic Salary
        Calculate TA = 5% of Basic Salary
        Calculate Gross Salary = Basic Salary + HRA + TA
        Calculate Tax = 2% of Gross Salary
        Calculate Inhand Salary = Gross Salary - Tax*/

    float BasicSalary, HRA, TA, GrossSalary, Tax, InhandSalary;

    cout << "Enter the Basic Salary of the Employee: ";
    cin >> BasicSalary;
    HRA = 0.1 * BasicSalary;
    TA = 0.05 * BasicSalary;
    GrossSalary = BasicSalary + HRA + TA;
    Tax = 0.02 * GrossSalary;
    InhandSalary = GrossSalary - Tax;

    cout << "The HRA of the Employee is: " << HRA << endl;
    cout << "The TA of the Employee is: " << TA << endl;
    cout << "The Gross Salary of the Employee is: " << GrossSalary << endl;
    cout << "The Tax of the Employee is: " << Tax << endl;
    cout << "The Inhand Salary of the Employee is: " << InhandSalary << endl;

    return 0;
 }