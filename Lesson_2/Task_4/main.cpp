#include <iostream>
#include <cctype>

using namespace std;

int main()
{
    const int AMOUNT = 100; // Maximum text length
    char text[AMOUNT] = {0};
    int count_word = 0;
    int count_letter = 0;
    bool middle = false;

    cout << "Enter text: ";
    cin.getline(text, AMOUNT);
    for (int index = 0; index < AMOUNT; index++)
    {
        if (text[index] == '\0')
        {
            break;
        }
        if (isalpha(text[index]))
        {
            count_letter++;
            if (!middle)
            {
                middle = true;
                count_word++;
            }
        }
        else
        {
            middle = false;
        }
    }
    cout << "Word count: " << count_word << endl;
    cout << "Letter count: " << count_letter << endl;
    return 0;
}
