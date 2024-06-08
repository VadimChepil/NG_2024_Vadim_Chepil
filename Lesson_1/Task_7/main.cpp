#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int radius_N = -1;
    int coordinate_x = -1;
    int coordinate_y = -1;
    int abs_x = -1;
    int abs_y = -1;
    float res = -1;

    cout << "Enter radius N: ";
    cin >> radius_N;
    cout << "Enter coordinate x: ";
    cin >> coordinate_x;
    cout << "Enter coordinate y: ";
    cin >> coordinate_y;

    abs_x = abs(coordinate_x);
    abs_y = abs(coordinate_y);

    if ((radius_N > coordinate_x && radius_N > coordinate_y) && (radius_N > abs_x && radius_N > abs_y))
    {
        if (coordinate_x == coordinate_y)
        {
            res = coordinate_x * sqrt(2);
        }
        else
        {
            res = sqrt(pow(coordinate_x, 2) + pow(coordinate_y, 2));
        }
        cout << "Distance from Konstantin (x,y) to the center of the field: " << abs(res) << endl;
    }
    else
    {
        cout << "Konstantin is outside the artifact field" << endl;
    }
    return 0;
}
