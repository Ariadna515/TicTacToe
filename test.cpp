#include <gtest/gtest.h>
#include "Game.h"

// TDD: red, green, refactor

// Given, when, then
TEST(GameTest, GetWinnerReturnsZeroWhenThereIsNoWinner) {
    Game game;
    EXPECT_EQ(0, game.GetWinner());
}

TEST(GameTest, GetWinnerReturnsOneWhenFirstPlayerFillsThirdColumn) {
    Game game;
    game.Move(2, 2); // 1st player
    game.Move(1, 1);
    game.Move(1, 2); // 1st player
    game.Move(0, 0);
    game.Move(0, 2); // 1st player
    EXPECT_EQ(1, game.GetWinner());
}

TEST(GameTest, GetWinnerReturnsOneWhenFirstPlayerFillsThirdRow) {
    Game game;
    game.Move(2, 2); // 1st player
    game.Move(1, 1);
    game.Move(2, 1); // 1st player
    game.Move(0, 0);
    game.Move(2, 0); // 1st player
    EXPECT_EQ(1, game.GetWinner());
}

TEST(GameTest, GetWinnerReturnsTwoWhenSecondPlayerFillsThirdRow) {
    Game game;
    game.Move(1, 1); // 1st player
    game.Move(2, 2);
    game.Move(0, 0); // 1st player
    game.Move(2, 1);
    game.Move(1, 0); // 1st player
    game.Move(2, 0);
    EXPECT_EQ(2, game.GetWinner());
}

TEST(GameTest, GetWinnerReturnsTwoWhenSecondPlayerFillsMainDiagonal) {
    Game game;
    game.Move(0, 1); // 1st player
    game.Move(2, 2);
    game.Move(1, 0); // 1st player
    game.Move(1, 1);
    game.Move(1, 2); // 1st player
    game.Move(0, 0);
    EXPECT_EQ(2, game.GetWinner());
}

TEST(GameTest, GetWinnerReturnsOneWhenFirstPlayerFillsSecondDiagonal) {
    Game game;
    game.Move(2, 0); // 1st player
    game.Move(2, 2);
    game.Move(1, 1); // 1st player
    game.Move(2, 1);
    game.Move(0, 2); // 1st player
    EXPECT_EQ(1, game.GetWinner());
}

TEST(GameTest, GetStateReturnsThreeByThreeMatrix) {
    Game game;
    game.Move(2, 0); // 1st player
    game.Move(2, 2);
    game.Move(1, 1); // 1st player

    auto state = game.GetState();
    
    EXPECT_EQ(3, state.size());
    EXPECT_EQ(3, state[0].size());
    EXPECT_EQ(3, state[1].size());
    EXPECT_EQ(3, state[2].size());
    EXPECT_EQ(0, state[0][0]);
    EXPECT_EQ(1, state[1][1]);
    EXPECT_EQ(2, state[2][2]);
    EXPECT_EQ(1, state[2][0]);
}