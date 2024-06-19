#include <iostream>

using namespace std;

int main()
{
    const int AMOUNT = 100; // Maximum text length
    char text[AMOUNT] = {0};
    int count_word = 0;
    int count_letter = 0;
    for (int iteration = 0; iteration < AMOUNT; iteration++)
    {
        text[iteration] = ' ';
    }
    cout << "Enter text: ";
    cin.getline(text, 100);
    for (int index = 0; index < AMOUNT; index++)
    {
        if (text[index] != ' ')
        {
            count_letter++;
        }
        if ((text[index] == ' ') && (text[(index+1)] != ' '))
        {
            count_word++;
        }
        if ((text[index] == ' ') && (text[(index+1)] == ' '))
        {
            count_word++;
            break;
        }
    }
    cout << "Word count: " << count_word << endl;
    cout << "Letter count: " << count_letter << endl;
    return 0;
}
