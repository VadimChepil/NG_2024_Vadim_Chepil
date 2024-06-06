#include <iostream>
#include <complex>
#include <cmath>

using namespace std;

int main()
{
    double a,b,c,dyskryminant;
    cout << "Quadratic equation formula ax^2 + bx + c = 0" << endl;
    cout << "Enter coefficient a: ";
    cin >> a;
    cout << "Enter coefficient b: ";
    cin >> b;
    cout << "Enter coefficient c: ";
    cin >> c;
    dyskryminant = pow(b,2) - (4*a*c);
    if (dyskryminant > 0.0)
    {
        double x1 = (-b + sqrt(dyskryminant)) / (2.0 * a);
        double x2 = (-b - sqrt(dyskryminant)) / (2.0 * a);
        cout << "Result: " << "x1: " << x1 << ", x2: " << x2 << endl;
    }
    else if (dyskryminant < 0.0)
    {
        complex<double> sqrt_discriminant = sqrt(complex<double>(dyskryminant, 0.0));
        complex<double> x1 = (-b + sqrt_discriminant) / (2.0 * a);
        complex<double> x2 = (-b - sqrt_discriminant) / (2.0 * a);
        cout << "Result: " << "x1: " << x1 << ", x2: " << x2 << endl;
    }
    else
    {
        double x1 = -(b / (2.0 * a));
        double x2 = x1;
        cout << "Result: " << "x1: " << x1 << ", x2: " << x2 << endl;
    }
    return 0;
}

