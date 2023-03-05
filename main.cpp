#include <iostream>

#include "Game.h"

using namespace std;

int main() {
    cout << "Tik Tac Toe" << endl;
    Game game;
    int winner = -1;
    while (true) {
        winner = game.GetWinner();
        if (winner > 0) break;
        int player = game.GetActivePlayer();
        int row, col;
        while (true)
        {
            cout << "Player " << player << " enter row and column of your move: " << endl;
            cin >> row >> col;
            if (game.Move(row, col)) break;
            cout << "Invalid move: " << row << ", " << col << endl;
        }
        auto state = game.GetState();
        for (auto& row : state)
        {
            for (auto cell : row)
            {
                std::string view ;
                if(cell == 0) view = " ";
                else view = cell == 1 ? "X" : "O";
                cout << view;
            }
            cout << endl;
        }
    }
    cout << "Congrats! Player " << winner << " won!" << endl;
    return 0;
}