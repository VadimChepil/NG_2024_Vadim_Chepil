#include <iostream>

using namespace std;

int main()
{
    int num1 = -1;
    int num2 = -1;
    int sum = 0;
    cout << "Enter two numbers to calculate the amount" << endl;
    cout << "First number: ";
    cin >> num1;
    cout << "Second number: ";
    cin >> num2;
    sum = num1 + num2;
    cout << "Sum: " << sum << endl;
    return 0;
}
