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

    /**
    const int lvector[] = {0, -1};
    bool ok_flag = true; // 石が置けるかどうか
    int rock_num; // 白石があるかどうか
    bool white_flag = false;
    bool black_flag = false;
    int old_point[] = { row, col };
    int point[] = { row, col };

    while(point[0] >= 0 && point[1] >= 0){
        if(board.CheckWhiteBetweenBlacks(old_point[0], old_point[1]) != 0){
            std::cout << "すでに置かれています" << std::endl;
            break;
        }

        point[0] += lvector[0];
        point[1] += lvector[1];

        // 石の種類を確認する
        rock_num = board.CheckWhiteBetweenBlacks(point[0], point[1]);

        // 空白のとき
        if(rock_num == 0){
            ok_flag = false;
            break;
        }

        if(rock_num == 1){
            black_flag = true;
        }

        if(rock_num == 2){
            white_flag = true;
        }

        if(black_flag && white_flag){
            break;
        }
    }
    **/
    int player_point[] = { row, col };

    if(board.CheckPutDown(player_point)){
        std::cout << "you can put here" << std::endl;
    }else{
        std::cout << "you can't put here" << std::endl;
    }


    // 石が置けるかどうか
    /**
    static const int DIR = 8;
    const int lup[2] = {-1, -1};
    const int lev[2] = {-1, 0};
    const int ldw[2] = {-1, 1};
    const int nup[2] = {0, 1};
    const int ndw[2] = {0, -1};
    const int rup[2] = {1, -1};
    const int rev[2] = {1, 0};
    const int rdw[2] = {1, 1};
    const int* const dir[DIR] = {lup, lev, ldw, nup, ndw, rup, rev, rdw};
    bool flag = false;
    for(int i=0; i<DIR; ++i){
        int point[2] = { row_i, col };
        std::cout << dir[i][0] << ' ' << dir[i][1] << std::endl;
        while(point[0] >= 0 && point[1] >= 0){
            point[0] += dir[i][0];
            point[1] += dir[i][1];
            if(point[0] == 1 && point[1] == 1){
                // 置ける
                flag = true;
                break;
            }
        }
    }

    if(flag){
        std::cout << "you can put here" << std::endl;
    }else{
        std::cout << "you can't put here" << std::endl;
    }
    **/
}