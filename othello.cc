#include "board.h"
#include "player.h"
#include <iostream>
#include <assert.h>

int parse_alphabet(char row){
    assert(97 <= int(row) && int(row) <= 104);
    return int(row) - 97;
}

int main(){
    Board board = Board();
    board.Show();

    Player player = Player();
    player.Input();

    int row = player.GetRowIndex();
    int col = player.GetColIndex();

    std::cout << row << ' ' << col << std::endl;

    int player_point[] = { row, col };

    if(board.CheckPutDown(player_point)){
        std::cout << "you can put here" << std::endl;
        // 石がひっくり変える処理
        board.Reverse(player_point);
        board.Show();
    }else{
        std::cout << "you can't put here" << std::endl;
    }
}