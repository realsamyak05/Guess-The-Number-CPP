#include <bits/stdc++.h>
using namespace std;
int generateRandom()
{
    return (rand() % 100) + 1;
}

string giveHint(int answer, int guess, int level)
{
    if (answer == guess)
    {
        return "Right";
    }

    if (level == 1 || level == 2)
    {

        if (abs(answer - guess) <= 5)
        {
            return "Very Hot";
        }
        else if (abs(answer - guess) <= 10)
        {
            return "Hot";
        }
        else if (abs(answer - guess) <= 20)
        {
            return "Cold";
        }
        else
        {
            return "Very Cold";
        }
    }
    else if (level == 3)
    {
        if (abs(answer - guess) <= 5)
        {
            return "Very Hot";
        }
        else if (abs(answer - guess) <= 10)
        {
            return "Hot";
        }
        else
        {
            return "Cold";
        }
    }
    else
    {
        if (abs(answer - guess) <= 10)
        {
            return "Hot";
        }
        else
        {
            return "Cold";
        }
    }
}

void rules(int x)
{
    cout << "\n";
    if (x == 1)
    {
        cout << "Level : Very Easy" << endl;
        cout << "Number of guesses : 25 guesses" << endl
             << "4 type of hints : " << endl;
        cout << "-> Very Cold : not within +/- 20 range" << endl;
        cout << "-> Cold : within +/- 20 range" << endl;
        cout << "-> Hot : within +/- 10 range" << endl;
        cout << "-> Very Hot : within +/- 5 range\n"
             << endl;
    }

    else if (x == 2)
    {
        cout << "Level : Easy" << endl;
        cout << "Number of guesses : 20 guesses" << endl
             << "4 type of hints : " << endl;
        cout << "-> Very Cold : not within +/- 20 range" << endl;
        cout << "-> Cold : within +/- 20 range" << endl;
        cout << "-> Hot : within +/- 10 range" << endl;
        cout << "-> Very Hot : within +/- 5 range\n"
             << endl;
    }

    else if (x == 3)
    {
        cout << "Level : Medium" << endl;
        cout << "Number of guesses : 15 guesses" << endl
             << "3 types of hints : " << endl;
        cout << "-> Cold : not within +/- 10 range" << endl;
        cout << "-> Hot : within +/- 10 range" << endl;
        cout << "-> Very Hot : within +/- 5 range\n"
             << endl;
    }

    else if (x == 4)
    {
        cout << "Level : Hard" << endl;
        cout << "Number of guesses : 10 guesses" << endl
             << "2 types of hints : " << endl;
        cout << "-> Cold : not within +/- 10 range" << endl;
        cout << "-> Hot : within +/- 10 range\n"
             << endl;
    }
    else
    {
        cout << "Level : Very Hard" << endl;
        cout << "Number of guesses : 5 guesses" << endl
             << "2 types of hints : " << endl;
        cout << "-> Cold : not within +/- 10 range" << endl;
        cout << "-> Hot : within +/- 10 range\n"
             << endl;
    }
}

void runGuess(int guesses, int level)
{
    int secretNumber = generateRandom();
    int userGuess;
    while (guesses)
    {
        cout << "\nGuesses Left : " << guesses << "\n"
             << endl;
        cout << "Enter your guess (integer between 1 and 100) : ";
        cin >> userGuess;
        if (userGuess < 1 || userGuess > 100)
        {
            cout << "Invalid !!!";
            continue;
        }
        string hint = giveHint(secretNumber, userGuess, level);
        if (hint == "Right")
        {
            cout << "\nYOU'RE RIGHT !!! YOU WON !!! \n"
                 << endl;
            break;
        }
        else
        {
            cout << "\n"
                 << hint << endl;
            guesses--;
        }
    }
    if (guesses == 0)
    {
        cout << "YOU LOST !!!" << endl;
        cout << "The answer was : " << secretNumber << endl;
        return;
    }
}

int main()
{
    srand(time(0));
    cout << "Guess the random number to win!" << endl;
    int guesses;
    int op;
    cout << "Choose Level : " << endl;
    cout << "Enter corresponding digit : " << endl
         << "1. Very Easy\n"
         << "2. Easy\n"
         << "3. Medium\n"
         << "4. Hard\n"
         << "5. Very Hard \n"
         << endl;
    cout << "Input : ";
    cin >> op;
    if (op < 1 || op > 5)
    {
        cout << "Invalid" << endl;
        return 0;
    }
    switch (op)
    {
    case 1:
        rules(1);
        guesses = 25;
        break;
    case 2:
        rules(2);
        guesses = 20;
        break;
    case 3:
        rules(3);
        guesses = 15;
        break;
    case (4):
        rules(4);
        guesses = 10;
        break;
    case (5):
        rules(5);
        guesses = 5;
        break;
    }
    cout << "\n------------------------------------\n";
    runGuess(guesses, op);

    return 0;
}