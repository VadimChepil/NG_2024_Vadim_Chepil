#include <iostream>

using namespace std;

int main()
{
    short int size = -1;
    short int count_star = 0;
    cout << "Enter size: ";
    cin >> size;
    short int count_space = size - 1;
    for (short int repetition = 0; repetition < size; repetition++)
    {
        for (short int space = 0; space < count_space; space++)
        {
            cout << " ";
        }
        count_space--;
        count_star++;
        for (short int star = 0; star < count_star; star++)
        {
            cout << '*';
            if (star == 1)
            {
                count_star++;
            }
        }
        cout << endl;
    }
    while(size - 1)
    {
        size--;
        cout << " ";
    }
    cout << '*';
    return 0;
}
