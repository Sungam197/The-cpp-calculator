#include <iostream> 
#include <vector>
#include <numeric> // For accumulate
#include <cmath>   // For mathematical operations

using namespace std;

// Global variables
vector<double> numbers; // Dynamic array to store numbers
int run = 1;            // Control variable for the loop

void addition() {
    double input;
    numbers.clear();
    run = 1;

    cout << "You have selected addition." << endl;
    cout << "Enter numbers and press enter after each number." << endl;
    cout << "When you are done, type any one letter." << endl;

    while (run == 1) {
        if (cin >> input) {
            numbers.push_back(input);
        }
        else {
            run = 0;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    if (!numbers.empty()) {
        double result = accumulate(numbers.begin(), numbers.end(), 0.0);
        cout << "\nThe total sum of the numbers is: " << result << endl;
    }
    else {
        cout << "\nNo numbers were entered." << endl;
    }
}

void subtraction() {
    double input;
    numbers.clear();
    run = 1;

    cout << "You have selected subtraction." << endl;
    cout << "Enter numbers and press enter after each number." << endl;
    cout << "When you are done, type any one letter." << endl;

    while (run == 1) {
        if (cin >> input) {
            numbers.push_back(input);
        }
        else {
            run = 0;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    if (!numbers.empty()) {
        double result = accumulate(numbers.begin() + 1, numbers.end(), numbers[0],
            [](double total, double num) {
                return total - num;
            });
        cout << "\nThe result of the subtraction is: " << result << endl;
    }
    else {
        cout << "\nNo numbers were entered." << endl;
    }
}

void multiplication() {
    double input;
    numbers.clear();
    run = 1;

    cout << "You have selected multiplication." << endl;
    cout << "Enter numbers and press enter after each number." << endl;
    cout << "When you are done, type any one letter." << endl;

    while (run == 1) {
        if (cin >> input) {
            numbers.push_back(input);
        }
        else {
            run = 0;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    if (!numbers.empty()) {
        double result = accumulate(numbers.begin(), numbers.end(), 1.0,
            [](double total, double num) {
                return total * num;
            });
        cout << "\nThe result of the multiplication is: " << result << endl;
    }
    else {
        cout << "\nNo numbers were entered." << endl;
    }
}

void division() {
    double input;
    numbers.clear();
    run = 1;

    cout << "You have selected division." << endl;
    cout << "Enter numbers and press enter after each number." << endl;
    cout << "When you are done, type any one letter." << endl;

    while (run == 1) {
        if (cin >> input) {
            numbers.push_back(input);
        }
        else {
            run = 0;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    if (numbers.size() < 2) {
        cout << "\nNot enough numbers for division." << endl;
    }
    else {
        double result = accumulate(numbers.begin() + 1, numbers.end(), numbers[0],
            [](double total, double num) {
                if (num == 0) {
                    cout << "Division by zero encountered. Skipping this number." << endl;
                    return total;
                }
                return total / num;
            });
        cout << "\nThe result of the division is: " << result << endl;
    }
}

int main() {
    cout << "Welcome to the calculator program!" << endl;
    char choice;
    do {
        cout << "\nPlease select an operation:" << endl;
        cout << "A: Addition" << endl;
        cout << "S: Subtraction" << endl;
        cout << "M: Multiplication" << endl;
        cout << "D: Division" << endl;
        cout << "Enter your choice (A/S/M/D) or Q to quit: ";
        cin >> choice;

        switch (choice) {
        case 'A': case 'a': addition(); break;
        case 'S': case 's': subtraction(); break;
        case 'M': case 'm': multiplication(); break;
        case 'D': case 'd': division(); break;
        case 'Q': case 'q': cout << "Exiting the program." << endl; break;
        default: cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 'Q' && choice != 'q');

    return 0;
}
