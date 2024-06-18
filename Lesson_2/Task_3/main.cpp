#include <iostream>

using namespace std;

int main() {
    const int ROW = 7; // Number of lines (maximum column length)
    const int COL = 5; // Number of columns (maximum row length)
    char data[ROW][COL] = {0};
    int value[ROW] = {0};
    for (int col = 0; col < COL; col++)
    {
        // Changed the filling interface to a better version
        cout << "Enter length in " << (col + 1) << " column: ";
        cin >> value[col];
        for (int row = 0; row < ROW; row++)
        {
            if (value[col] > 0)
            {
                data[row][col] = '*';
            }
            else
            {
                data[row][col] = ' ';
            }
            value[col]--;
        }
    }
    cout << "*****************RESULT*********************" << endl;
    for (int row = 0; row < ROW; row++)
    {
        for (int col = 0; col < COL; col++)
        {
            cout << data[row][col] ;
        }
        cout << endl;
    }
    return 0;
}
