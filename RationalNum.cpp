#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
struct Rational
{
    int numer; 
    int denom; 
};
// function prototypes
Rational add(const Rational,const Rational);
Rational subtract(const Rational, const Rational);
Rational multiply(const Rational, const Rational);
Rational divide(const Rational, const Rational);
// void printRational(const Rational r);
void printRational(const Rational r) 
{
    // Print the rational number in n/d form
    cout <<  "Result as a Rational Number (P/Q) " << r.numer << "/" << r.denom<< 
endl;
    // Print the rational number in floating-point form
    cout << fixed << setprecision(2)<< "Result as a Floating point " << (double) 
r.numer / r.denom << endl;
}
// find the greatest common divisor of two numbers using Euclid's algorithm
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
// reduce a rational number to its lowest terms
void reduce(Rational r) 
{
    int gcd_value = gcd(r.numer, r.denom);
    r.numer /= gcd_value;
    r.denom /= gcd_value;
}
// add two rational numbers and return the result in reduced form
Rational add(const Rational r1, const Rational r2) 
{
    Rational result;
    result.numer = r1.numer * r2.denom + r2.numer * r1.denom;
    result.denom = r1.denom * r2.denom;
    reduce(result);
    return result;
}
// subtract two rational numbers and return the result in reduced form
Rational subtract(const Rational r1, const Rational r2) {
    Rational result;
    result.numer = r1.numer * r2.denom - r2.numer * r1.denom;
    result.denom = r1.denom * r2.denom;
    reduce(result);
    return result;
}
Rational multiply(const Rational r1, const Rational r2)
{
    Rational result; 
    result.numer = r1.numer * r2.numer;
    result.denom = r1.denom * r2.denom;
    reduce(result);
    
    return result;
}
Rational divi(const Rational r1, const Rational r2)
{
    Rational result; 
    result.numer = r1.numer * r2.denom;
    result.denom = r1.denom * r2.numer;
    reduce(result);
    
    return result;
}
int main()
{
    Rational userR1, userR2;
    bool run = true;
    bool runSame = true;
    char runAgain; 
    int choice;
    do
    {
        cout << "Enter numerator for 1: " << endl;
        while(!(cin >> userR1.numer))
        {
            cout << "Invalid input, try again\n";
            cout << "Enter numerator for 1:" << endl;
            cin.clear();    
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
       
        cout << "Enter denominator for 1: " << endl;
        if(!(cin >> userR1.denom) || userR1.denom == 0)
        {
            do
            {
                cout << "Invalid input, try again\n";
                cout << "Enter denominator for 1: " << endl;
                cin.clear();    
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }while(!(cin >> userR1.denom) || userR1.denom == 0);
            
        }
       
        cout << "Enter numerator for 2: " << endl;
        while(!(cin >> userR2.numer))
        {
            cout << "Invalid input, try again\n";
            cout << "Enter numerator for 2:" << endl;
            cin.clear();    
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout << "Enter denominator for 2: " << endl;
        if(!(cin >> userR2.denom) || userR2.denom == 0)
        {
            do
            {
                cout << "Invalid input, try again\n";
                cout << "Enter denominator for 2: " << endl;
                cin.clear();    
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }while(!(cin >> userR2.denom) || userR2.denom == 0);
            
        }
    
        cout << "--------SELECT OPERATION--------------" <<endl;
            cout <<" 1. Addition: " << endl;
            cout <<" 3. Multiplication: " << endl;
            cout <<" 2. Subtraction " << endl;
            cout <<" 4. Division: " << endl;
            
        while(!(cin >> choice) || choice < 1 || choice > 4)
        {
            cout << "Invalid input, try again\n";
            cout << "--------SELECT OPERATION--------------" <<endl;
                cout <<" 1. Addition: " << endl;
                cout <<" 3. Multiplication: " << endl;
                cout <<" 2. Subtraction " << endl;
                cout <<" 4. Division: " << endl;
            
            cin.clear();    
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
            
            if(choice == 1)
            {
                printRational(add(userR1, userR2));
            }
            else if(choice == 2)
            {
                 printRational(subtract(userR1, userR2));
            }
            else if(choice == 3)
            {
                printRational(multiply(userR1, userR2));
            }
            else if(choice == 4)
            {
                printRational(divi(userR1, userR2));
            }
            else
            {
                cout << "Not in range. Try again: " <<endl;
                cin.clear();
            }
        
        
        cout << "Do again? y/n" << endl;
        cin >> runAgain; 
        if(runAgain == 'y' || runAgain == 'Y')
        {
            run = true; 
        }
        else if(runAgain =='n' || runAgain || 'N')
        {
            run = false;
            string enter = "";
            do 
            {
                cout << "As you wanted to stop the program, press the <Enter> key 
to do so.";
                getline(cin, enter);
            }while (enter.length() != 0); 
    
        cout << "GOODBYE!\n";
        cout << "Programmer: David Joves - written for the class CISC 192 - C++ \
n";
        cout << "Programming.\n";
        }
        else
        {
            cin.clear(); 
            cout << "Invalid input again" << endl;
            cin >> runAgain;
        }
    }while(run == true);
    return 0;
}
