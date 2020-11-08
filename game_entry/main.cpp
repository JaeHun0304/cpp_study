#include <iostream>
#include <string>
#include "game_entry.h"

int main()
{
    ScoreBoard my_board = ScoreBoard(3);

    my_board.updateBoard(0, "JaeHun", 7);
    my_board.updateBoard(1, "Jimmy", 5);
    my_board.updateBoard(2, "Alice", 3);
    my_board.printBoard();

    my_board.updateScore("JaeHun", 3);
    my_board.printBoard();
}
