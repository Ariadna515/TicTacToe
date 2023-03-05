#ifndef GAME_H
#define GAME_H

#include <iostream> // TODO remove
#include <vector>

struct Move
{
    int row;
    int col;
};

using Moves = std::vector<Move>;

class Game
{
    Moves moves;
    int player = 0;
    static const int NumberOfPlayers = 2;
    static const int NumberOfCells = 3;
public:
    int GetActivePlayer()
    {
        return player + 1;
    }
    /**
     * Returns 1 when first player won, 2 - when second, 
     * 0 - when game is still in progress (nobody has won yet)
     */
    int GetWinner() const
    {
        std::vector< std::vector<int> > rows(NumberOfPlayers);
        for (auto& r : rows) r.resize(NumberOfCells);
        std::vector< std::vector<int> > cols(NumberOfPlayers);
        for (auto& c : cols) c.resize(NumberOfCells);
        std::vector<int> main_diags(NumberOfPlayers);
        std::vector<int> sec_diags(NumberOfPlayers);
        // [[0,0,0], [0,0,0]]
        int active = 0;
        for (auto& move : moves)
        {
            //std::vector<int> active_player_cols(NumberOfCells);
            // [0,0,0]
            //++active_player_cols[move.col];
            ++rows[active][move.row];
            if (rows[active][move.row] == NumberOfCells) return active + 1;
            ++cols[active][move.col];
            if (cols[active][move.col] == NumberOfCells) return active + 1;
            if (move.row == move.col) // main diagonal
            {
                ++main_diags[active];
                //std::cout << active << " -> " << move.row << ", " << move.col << std::endl;
                if (main_diags[active] == NumberOfCells) return active + 1;
            }
            if (move.row == NumberOfCells - move.col - 1) // secondary diagonal
            {
                ++sec_diags[active];
                if (sec_diags[active] == NumberOfCells) return active + 1;
            }
            active = (active + 1) % NumberOfPlayers;
        }
        return 0;
    }

    bool Move(int row, int col)
    {
        // TODO return false if not valid move
        moves.push_back({ row, col });
        player = (player + 1) % NumberOfPlayers;
        return true;
    }

    /**
     * A 1st player moved to 1,1 and a 2nd to 2,0:
     * [
     * [0,0,0],
     * [0,1,0],
     * [2,0,0]
     * ]
     */
    std::vector< std::vector<int> > GetState()
    {
        std::vector< std::vector<int> > state(NumberOfCells);
        for (auto& row : state) row.resize(NumberOfCells);
        int active = 0;
        for (auto& move : moves) 
        {
            state[move.row][move.col] = active + 1;
            active = (active + 1) % NumberOfPlayers;
        }
        return state;
    }
};

#endif