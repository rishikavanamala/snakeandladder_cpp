#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to roll a die (1-6)
int rollDie() {
    return rand() % 6 + 1;
}

// Function to play a turn
int playTurn(string  player, int currentPosition) {
    cout << player << ", press Enter to roll the die...";
    cin.get();

    int roll = rollDie();
    cout <<player<< "    rolled  " << roll << endl;

    if (currentPosition + roll <= 100) {
        currentPosition += roll;
        switch (currentPosition) {
            // Snake positions
            case 16: currentPosition = 6; cout<<" it's a snake,    "; break;
            case 47: currentPosition = 26;  cout<<" it's a snake,     ";break;
            case 49: currentPosition = 11;cout<<" it's a snake,   "; break;
            case 56: currentPosition = 53;cout<<"it's a snake,     "; break;
            case 62: currentPosition = 19;cout<<"it's a snake,     " ; break;
            case 64: currentPosition = 60;cout<<" it's a snake,    "; break;
            case 87: currentPosition = 24;cout<<" it's a snake,    "; break;
            case 93: currentPosition = 73;cout<<"it's a snake,    "; break;
            case 95: currentPosition = 75; cout<<"it's a snake,    ";break;
            case 98: currentPosition = 78;cout<<"it's a snake,    "; break;
            // Ladder positions
            case 1: currentPosition = 38; cout<<"yeah!"<<player<<"  you got ladder, "; break;
            case 4: currentPosition = 14; cout<<"yeah!"<<player<<"   you got ladder, ";break;
            case 9: currentPosition = 31; cout<<"yeah!"<<player<<"  you got ladder,  ";break;
            case 21: currentPosition = 42;cout<<"yeah!"<<player<<"  you got ladder, "; break;
            case 28: currentPosition = 84;cout<<"yeah!"<<player<<"  you got ladder, "; break;
            case 36: currentPosition = 44;cout<<"yeah!"<<player<<"  you got ladder, "; break;
            case 51: currentPosition = 67; cout<<"yeah!"<<player<<" you got ladder, ";break;
            case 71: currentPosition = 91; cout<<"yeah!"<<player<<"  you got ladder, ";break;
            case 80: currentPosition = 100;cout<<"yeah!"<<player<<"  you got ladder, "; break;
        }
        cout << player<<"  is at position " << currentPosition << endl;
    } else {
        cout << "You need " << 100 - currentPosition << " to win. Try again next turn." << endl;
    }

    return currentPosition;
}

int main() {
    srand(time(nullptr));

    int player1Position = 0;
    int player2Position = 0;
    string s1,s2;
    cout<<"Enter name of first player"<<endl;
    cin>>s1;
    cout<<"Enter name of second player"<<endl;
    cin>>s2;

    cout << "Welcome to Snake and Ladder!" << endl;

    while (player1Position < 100 && player2Position < 100) {
        player1Position = playTurn(s1, player1Position);
        if (player1Position == 100) {
            cout <<s1<<" won" << endl;
            break;
        }

        player2Position = playTurn(s2, player2Position);
        if (player2Position == 100) {
            cout <<s2<<" won"<< endl;
            break;
        }
    }

    cout << "Game Over!" << endl;

    return 0;
}