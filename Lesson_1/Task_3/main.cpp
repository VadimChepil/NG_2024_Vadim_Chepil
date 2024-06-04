#include <iostream>

using namespace std;

int main()
{
    int salary = -1;
    cout << "Enter your salary: ";
    cin >> salary;
    if (salary < 1000) {
        cout << "work harder" << endl;
    }
    if (salary > 1000) {
        if (salary > 1000000) {
            cout << "Yes, you are millionaire!" << endl;
        }
        if (salary < 1000000) {
            cout << "Good work!" << endl;
        }
    }
    cout << "But you are well done!" << endl;
    return 0;
}
