#include <iostream>

using namespace std;

int main()
{
    short int size = -1;
    cout << "Enter size: ";
    cin >> size;
    if (size <= 0)
    {
        cout << "The entered size is not positive!" << endl;
    }
    for (short int repetition = size; repetition > 0; repetition--)
    {
        for (short int space = repetition - 1; space > 0; space--)
        {
            cout << " ";
        }
        for (short int star = 0; star <= (size - repetition) * 2; star++)
        {
            cout << "*";
        }
        cout << endl;
    }
    for (short int end = 0; end < size - 1; end++)
    {
        cout << " ";
    }
    cout << "*";
    return 0;
}
