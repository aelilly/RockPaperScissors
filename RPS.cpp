// RPS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;
int getPlayerSelection(int, int*);
void determineWinner(int p1Choice, int p2Choice, int* p1Score, int* p2Score);

int main()
{
    //Arrays, and Pointers
    int choice[2], score[2]{ 0, 0 };
    int* pChoice = choice;
    int* p1Score = &score[0];
    int* p2Score = &score[1];


    do {        //Loop to play game infintely
        if (getPlayerSelection(1, pChoice) == -1) //Condition to end loop
            break;
        pChoice++;
        if (getPlayerSelection(2, pChoice) == -1) //Condition to end loop
            break;
        pChoice--;

        determineWinner(choice[0], choice[1], p1Score, p2Score);
    } while (*pChoice != -1);

    //End of Program Output
    cout << endl << "GAME OVER" << endl;
    if (*p1Score > *p2Score)
        cout << "Player one wins with a score of " << *p1Score << " to " << *p2Score;
    else if (*p1Score < *p2Score)
        cout << "Player two wins with a score of " << *p2Score << " to " << *p1Score;
    else
        cout << "The game is a tie, with both players having a score of " << *p1Score;
    
}

int getPlayerSelection(int player, int* choice) {
    static int player1Choice;
    string playNum;
    (player == 1) ? (playNum = "one") : (playNum = "two");
    do {            //Validation Loop
        cout << "Player " << playNum << " input choice (1: rock, 2: paper, 3: scissors, -1: quit): ";
        cin >> *choice;
        if ((*choice < 1 || *choice > 3) && *choice != -1)
            cout << "Invalid Input, Try Again" << endl;
    } while ((*choice < 1 || *choice > 3) && *choice != -1);
    
    //Output of each player's selection
    if (player == 1)
        player1Choice = *choice;
    else if (player == 2 && *choice != -1) {
        if (player1Choice == 1)
            cout << "Player one chooses rock, ";
        else if (player1Choice == 2)
            cout << "Player one chooses paper, ";
        else if (player1Choice == 3)
            cout << "Player one chooses scissors, ";

        if (*choice == 1)
            cout << "player two chooses rock" << endl;
        else if (*choice == 2)
            cout << "player two chooses paper" << endl;
        else if (*choice == 3)
            cout << "player two chooses scissors" << endl;
    }
    return *choice;
}

void determineWinner(int p1Choice, int p2Choice, int* p1Score, int* p2Score) {
    string winner[2]{ "PLAYER ONE WINS", "PLAYER TWO WINS" };
    if (p1Choice != p2Choice) { //Tests for tie between players first then tests each combination and its reverse
        if (p1Choice == 1)
            if (p2Choice == 2) {
                *p2Score += 1;
                cout << winner[1] << endl;
            }
            else {
                *p1Score += 1;
                cout << winner[0] << endl;
            }
        else if (p1Choice == 2) {
            if (p2Choice == 3) {
                *p2Score += 1;
                cout << winner[1] << endl;
            }
            else {
                *p1Score += 1;
                cout << winner[0] << endl;
            }
        }
        else if (p1Choice == 3) {
            if (p2Choice == 1) {
                *p2Score += 1;
                cout << winner[1] << endl;
            }
            else {
                *p1Score += 1;
                cout << winner[0] << endl;
            }
        }
    }
    else {
        cout << "TIE, NO WINNER" << endl;
    }
}

/*  Output 1
Player one input choice (1: rock, 2: paper, 3: scissors, -1: quit): -1

GAME OVER
The game is a tie, with both players having a score of 0
*/

/*  Output 2
Player one input choice (1: rock, 2: paper, 3: scissors, -1: quit): 2
Player two input choice (1: rock, 2: paper, 3: scissors, -1: quit): -1

GAME OVER
The game is a tie, with both players having a score of 0
*/

/*  Output 3
Player one input choice (1: rock, 2: paper, 3: scissors, -1: quit): 1
Player two input choice (1: rock, 2: paper, 3: scissors, -1: quit): 3
Player one chooses rock, player two chooses scissors
PLAYER ONE WINS
Player one input choice (1: rock, 2: paper, 3: scissors, -1: quit): 4
Invalid Input, Try Again
Player one input choice (1: rock, 2: paper, 3: scissors, -1: quit): -1

GAME OVER
Player one wins with a score of 1 to 0
*/

/*  Output 4
Player one input choice (1: rock, 2: paper, 3: scissors, -1: quit): 2
Player two input choice (1: rock, 2: paper, 3: scissors, -1: quit): 2
Player one chooses paper, player two chooses paper
TIE, NO WINNER
Player one input choice (1: rock, 2: paper, 3: scissors, -1: quit): 3
Player two input choice (1: rock, 2: paper, 3: scissors, -1: quit): 1
Player one chooses scissors, player two chooses rock
PLAYER TWO WINS
Player one input choice (1: rock, 2: paper, 3: scissors, -1: quit): -1

GAME OVER
Player two wins with a score of 1 to 0
*/