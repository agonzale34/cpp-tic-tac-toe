//
// Created by agonzalez on 18/03/19.
//
#include<iostream>

using namespace std;

class Board {
    const char X = 'X';
    const char O = 'O';
    int playing;
    char playerTurn;
    string pXname;
    string pOname;
    string board[4][4];
public:
    Board();
    void askPlayerName(const char &xORo);
    void initGame();
    void print();
    void askPlayerInput();
};

Board::Board() {
    playerTurn = X;
    playing = 0;
    pXname = "";
    pOname = "";
    for (auto &i : board) {
        for (auto &j : i) {
            j = '_';
        }
    }
}

void Board::print() {
    cout << endl;
    for (int i = -1; i < 4; ++i) {
        if (i == -1) {
            cout << "* ";
        } else {
            cout << i << " ";
        }
        for (int j = 0; j < 4; ++j) {
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

void Board::initGame() {
    playing = 1;
    askPlayerName(X);
    askPlayerName(O);
    cout << "The game is started" << endl;
    print();
    while (playing == 1) {
        askPlayerInput();
    }
}

void Board::askPlayerName(const char &xORo) {
    cout << xORo << " user enter your name: ";
    if (xORo == X) {
        cin >> pXname;
    } else {
        cin >> pOname;
    }
}

void Board::askPlayerInput() {
    string playerName;
    if (playerTurn == X) {
        playerName = pXname;
    } else {
        playerName = pOname;
    }
    cout << playerName << " select a grid position where they would like to place an " << playerTurn << " example 1,2" << endl;
    string pos;
    cin >> pos;
    int i = stoi(pos.substr(0, 1));
    int j = stoi(pos.substr(2, 3));
    board[i][j] = playerTurn;
    if (playerTurn == X) {
        playerTurn = O;
    } else {
        playerTurn = X;
    }
    print();
}


