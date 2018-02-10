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
    board.SetTurn(true);
    Player player = Player();

    // 後でOpponentのクラスの作成をする
    // Playerクラスを継承させても良さそう.
    // 一旦入力はユーザができる形にする
    Player opponent = Player();
    int double_skip = 0;

    // 両方が置けるかどうかのチェック
    while(1){

        bool skip = !board.CheckPutDown();
        if(skip){
            std::cout << "skip turn " << (board.GetTurn() ? "black user" : "white user") << std::endl;
            board.SetTurn(!board.GetTurn());
            double_skip++;
        }
        if(double_skip == 2) break;

        if(board.GetTurn()){
            double_skip = 0;
            player.Input();
            int row = player.GetRowIndex();
            int col = player.GetColIndex();

            int player_point[] = { row, col };
            std::cout << row << ' ' << col << std::endl;

            if(board.ProcessGame(player_point)){
                board.Show();
                board.SetTurn(!board.GetTurn());
            }else{
                std::cout << "you can't put here. please write again" << std::endl;
                continue;
            }
        }else{
            double_skip = 0;
            player.Input();
            int row = player.GetRowIndex();
            int col = player.GetColIndex();

            int player_point[] = { row, col };
            std::cout << row << ' ' << col << std::endl;

            if(board.ProcessGame(player_point)){
                board.Show();
                board.SetTurn(!board.GetTurn());
            }else{
                std::cout << "you can't put here. please write again" << std::endl;
                continue;
            }
        }
    }

    board.CountRocks();
    if(board.GetBlackRocks() > board.GetWhiteRocks()){
        std::cout << "Player 1 win" << std::endl;
    }else if(board.GetBlackRocks() < board.GetWhiteRocks()){
        std::cout << "Player 2 win" << std::endl;
    }else{
        std::cout << "Draw" << std::endl;
    }
}