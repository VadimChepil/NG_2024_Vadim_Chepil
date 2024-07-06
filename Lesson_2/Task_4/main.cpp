#include <iostream>

using namespace std;

int TextNumberCheck(char text[], int index)
{
    char capitalLetter = 'A';
    char smallLetter = 'a';
    if ((text[index] >= capitalLetter && text[index] <= 'Z') || (text[index] >= smallLetter && text[index] <= 'z'))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    const int AMOUNT = 100; // Maximum text length
    char text[AMOUNT] = {0};
    int countWord = 0;
    int countLetter = 0;
    bool middle = false;

    cout << "Enter text: ";
    cin.getline(text, AMOUNT);
    for (int index = 0; index < AMOUNT; index++)
    {
        if (text[index] == '\0')
        {
            break;
        }
        else
        {
            if (TextNumberCheck(text, index) == 1)
            {
                countLetter++;
                if (!middle)
                {
                    middle = true;
                    countWord++;
                }
            }
            else
            {
                middle = false;
            }
        }
    }
    cout << "Word count: " << countWord << endl;
    cout << "Letter count: " << countLetter << endl;
    return 0;
}
