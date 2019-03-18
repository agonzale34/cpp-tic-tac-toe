#include<iostream>
#include "models/Board.cpp"

using namespace std;

int main() {
    std::cout << "Welcome to the Awesome tic tac toe in  C++" << std::endl;

    // creating the necessary objects
    Board game = Board();
    game.initGame();

    return 0;
}