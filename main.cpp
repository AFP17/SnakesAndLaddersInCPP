#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>

using namespace std;

int rollDice() {
    int result;
    do {
        result = rand() % 7;
    } while (result == 0);
    return result;
}

void displayChart(int curPos, const string& player) {
    if (curPos == 100) {
        cout << "*****Congratulations*****\n\n\nPlayer " << player << " wins\n";
        exit(0);
    }

    for (int i = 10; i > 0; --i) {
        int t = i - 1;
        for (int j = (i % 2 == 0 ? 10 : 1); (i % 2 == 0 ? j >= 1 : j <= 10); (i % 2 == 0 ? --j : ++j)) {
            int diceRes = i * 10 - t * (9 - abs(j-1));
            if (curPos == diceRes)
                cout << player << "\t";
            else
                cout << diceRes << "\t";
        }
        cout << "\n\n";
    }
    cout << "--------------------------------------------------------------------------\n";
}

int main() {
    srand(time(NULL)); 
    int curPos1 = 0, curPos2 = 0;
    char choice;

    while (true) {
        cout << "        ** SNAKE AND LADDER GAME ** \n";
        cout << "Snakes:- 25 to 9,\t 65 to 40,\t 99 to  1.\nLadder:- 13 to 42,\t 60 to 83,\t 70 to 93.\n";
        cout << "Choose your option\n";
        cout << "1. Player 1 plays\n";
        cout << "2. Player 2 plays\n";
        cout << "3. Exit\n";
        cin >> choice;

        int dice;
        switch (choice) {
            case '1':
                dice = rollDice();
                cout << "\t\t\t\tDice = " << dice << "\n\n";
                if (dice == 6)
                    cout << "Dice=6: You have earned a chance to play one more time.\n";
                curPos1 += dice;
                if (curPos1 > 100) curPos1 -= dice;
                displayChart(curPos1, "$P1$");
                cout << "Player 2 position is " << curPos2 << "\n";
                break;
            case '2':
                dice = rollDice();
                cout << "\t\t\t\tDice = " << dice << "\n\n";
                curPos2 += dice;
                if (curPos2 > 100) curPos2 -= dice;
                displayChart(curPos2, "$P2$");
                cout << "Player 1 position is " << curPos1 << "\n";
                break;
            case '3':
                exit(0);
            default:
                cout << "Incorrect choice. Try Again\n";
        }
    }
}
