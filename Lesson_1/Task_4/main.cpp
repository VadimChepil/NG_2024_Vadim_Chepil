#include <iostream>

using namespace std;

int main()
{
    float num1 = -1;
    float num2 = -1;
    float res = 0;
    char action = '\0';
    cout << "Select an action (+,-,*,/,^,s(sqrt)): ";
    cin >> action;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    switch (action)
    {
    case '+':
        res = num1 + num2;
        break;
    case '-':
        res = num1 - num2;
        break;
    case '*':
        res = num1 * num2;
        break;
    case '/':
        res = num1 / num2;
        break;
    case '^':
        res = pow(num1,num2);
        break;
    case 's':
        res = pow(num1,(1/num2));
        break;
    }
    cout << "Result: " << res << endl;
    return 0;
}
