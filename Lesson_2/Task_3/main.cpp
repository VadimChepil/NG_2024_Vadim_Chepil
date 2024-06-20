#include <iostream>

using namespace std;

int main() {
    int value[5] = {0};
    for (int col = 0; col < 5; col++)
    {
        // Changed the filling interface to a better version
        cout << "Enter length in " << (col + 1) << " column: ";
        cin >> value[col];
    }
    cout << "*****************RESULT*********************" << endl;
    for (int col = 0; col < 7; col++)
    {
        for (int row = 0; row < 5; row++)
        {
            if (value[row] > col)
            {
                cout << '*';
            }
            else
            {
                cout << ' ';
            }
        }
        cout << endl;
    }
    return 0;
}
