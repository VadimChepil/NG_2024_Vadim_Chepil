#include <iostream>
#include <string>

using namespace std;

int main()
{
    int bank[10] = {0};
    int score = -1;
    int sum = -1;
    int account = -1;
    int min_score = -1;
    int max_score = -1;
    string input = "default";
    char operation = '\0';
    //Generation of 10 different accounts
    bank[1] = 2000;
    bank[2] = 10000;
    bank[3] = 300;
    bank[4] = 100000;
    bank[5] = 4500;
    bank[6] = 89433;
    bank[7] = 24324;
    bank[8] = 653567;
    bank[9] = 864532;
    bank[10] = 1000000;

    cout << "Welcome to Bank" << endl;
    while(true)
    {
        cout << "Enter your accounts: ";
        cin >> account;
        if (account > 0 && account <= 10)
        {
            score = bank[account];
            cout << "Select an operation(Cash replenishment(+), Withdrawal of cash(-), View all accounts(#)): ";
            cin >> operation;
            switch (operation)
            {
            case '+':
                cout << "Enter the cash top-up amount: ";
                cin >> sum;
                score += sum;
                break;
            case '-':
                cout << "Enter the cash withdrawal amount: ";
                cin >> sum;
                score -= sum;
                break;
            case '#':
                min_score = bank[1];
                max_score = bank[1];
                for (int count = 1; count <= 10; count++)
                {
                    cout << "Account: " << count << ", Score: " << bank[count] << endl;
                    if (bank[count] < min_score)
                    {
                        min_score = bank[count];
                    }
                    if (bank[count] > max_score)
                    {
                        max_score = bank[count];
                    }
                }
                cout << "The least amount of money from all accounts: " << min_score << endl;
                cout << "The most money from all accounts: " << max_score << endl;
                break;
            default:
                cout << "Invalid operation!" << endl;
                break;
            }
            if (score < 0)
            {
                cout << "You don't have enough funds!" << endl;
            }
            else
            {
            bank[account] = score;
            cout << "Your score: " << bank[account] << endl;
            }
        }
        else
        {
            cout << "The account number you entered was not found!" << endl;
        }
        cout << "Enter 'exit' to quit: ";
        cin.ignore();
        getline(cin, input);
        if (input == "exit")
        {
            break;
        }
    }
    cout << "The operation was completed successfully" << endl;
    return 0;
}
