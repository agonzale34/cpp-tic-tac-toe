//
// Created by agonzalez on 18/03/19.
//
#include<iostream>

using namespace std;

const int size = 3;

class Board {
    const char X = 'X';
    const char O = 'O';
    int playing;
    int numTurns;
    char playerTurn;
    string pXname;
    string pOname;
    char board[size][size]{};
public:

    Board() {
        playerTurn = X;
        playing = 0;
        numTurns = 0;
        pXname = "";
        pOname = "";
        for (auto &i : board) {
            for (auto &j : i) {
                j = '_';
            }
        }
    }

    void print() {
        cout << endl;
        for (int i = -1; i < size; ++i) {
            if (i == -1) {
                cout << "* ";
            } else {
                cout << i << " ";
            }
            for (int j = 0; j < size; ++j) {
                if (i == -1) {
                    cout << j << " ";
                } else {
                    cout << board[i][j] << " ";
                }
            }
            cout << endl;
        }
        cout << endl;
    }

    void initGame() {
        playing = 1;
        askPlayerName(X);
        askPlayerName(O);
        cout << "The game is started" << endl;
        print();
        while (playing == 1 && numTurns < size*size) {
            askPlayerInput();
        }
        if (numTurns == size*size) {
            cout << "Tie game." << endl;
        }
    }

    void askPlayerName(const char &xORo) {
        cout << xORo << " user enter your name: ";
        if (xORo == X) {
            cin >> pXname;
        } else {
            cin >> pOname;
        }
    }

    void askPlayerInput() {
        string playerName;
        if (playerTurn == X) {
            playerName = pXname;
        } else {
            playerName = pOname;
        }
        cout << playerName
             << " select a grid position where they would like to place an "
             << playerTurn
             << " example 1,2"
             << endl;
        string pos;
        cin >> pos;
        int i = stoi(pos.substr(0, 1));
        int j = stoi(pos.substr(2, 3));
        if (board[i][j] == '_') {
            board[i][j] = playerTurn;
            if (validateWinner() == 1) {
                cout << "Congrats " << playerName << " you won!" << endl;
                playing = 0;
            } else {
                changeTurn();
                print();
            }
            numTurns++;
        } else {
            cout << playerName << " this position is used try again" << endl;
        }
    }

    void changeTurn() {
        if (playerTurn == X) {
            playerTurn = O;
        } else {
            playerTurn = X;
        }
    }

    int validateWinner() {
        int winner = validateRows();
        if (winner == 0) {
            winner = validateCols();
        }
        if (winner == 0) {
            winner = validateDiagonals();
        }
        return winner;
    }

    int validateRows() {
        for (auto &i : board) {
            int total = 0;
            for (char j : i) {
                if (j == playerTurn) {
                    total++;
                }
            }
            if (total == size) {
                return 1;
            }
        }
        return 0;
    }

    int validateCols() {
        for (int i = 0; i < size; ++i) {
            int total = 0;
            for (auto &j : board) {
                if (j[i] == playerTurn) {
                    total++;
                }
            }
            if (total == size) {
                return 1;
            }
        }
        return 0;
    }

    int validateDiagonals() {
        int totalInMainDiagonal = 0;
        int totalInSecondDiagonal = 0;
        for (int i = 0; i < size; ++i) {
            if (board[i][i] == playerTurn) {
                totalInMainDiagonal++;
            }
            if (board[i][size - 1 - i] == playerTurn) {
                totalInSecondDiagonal++;
            }
        }
        if (totalInMainDiagonal == size || totalInSecondDiagonal == size) {
            return 1;
        } else {
            return 0;
        }
    }

};