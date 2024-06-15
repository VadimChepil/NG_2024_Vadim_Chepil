#include <iostream>

using namespace std;

int main()
{
    int values[20] = {0};
    int value = -1;
    int max_value = -1;
    max_value = values[0];
    for (int index = 0; index < 20; index++)
    {
        cout << "Enter value: ";
        cin >> value;
        values[index] = value;
        if (values[index] > max_value)
        {
            max_value = values[index];
        }
        if (value == 0)
        {
            break;
        }
    }
    for (int iteration = 0; iteration < 20; iteration++)
    {
        for (int space = max_value; space > values[iteration]; space-= 2)
        {
            cout << " ";
        }
        for (int star = 0; star < values[iteration]; star++)
        {
            cout << "*";
        }
        cout << endl;
        if (values[iteration] == 0)
        {
            break;
        }
    }
    return 0;
}
