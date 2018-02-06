#include "board.h"
#include <iostream>

Board::Board(){
    for(int i=0; i<_kBoardLength; ++i){
        for(int j=0; j<_kBoardLength; ++j){
            _board[i][j] = 0;
        }
    }

    // initialize
    _board[3][3] = 1;
    _board[4][4] = 1;
    _board[3][4] = 2;
    _board[4][3] = 2;
}

void Board::Show(){
    // col
    std::cout << "  ";
    for(int i=0; i<_kBoardLength; ++i){
        std::cout << i << ' ';
    }
    std::cout << std::endl;
    for(int i=0; i<_kBoardLength; ++i){
        for(int j=0; j<_kBoardLength; ++j){
            // row
            if(j==0){
                std::cout << char(97 + i) << ' ';
            }

            // board information
            switch(_board[i][j]){
                case 0 : std::cout << "-" << ' '; break;
                case 1 : std::cout << "●" << ' '; break;
                case 2 : std::cout << "○" << ' '; break;
            }
        }
        std::cout << std::endl;
    }
}

int Board::GetBoardRock(int row, int col){
    return _board[row][col];
}

bool Board::CheckPutDown(const int* const player_point){
    //const int lvector[] = {0, -1};
    const int lvector[] = {-1, 0};

    bool ok_flag = true;
    bool white_flag = false;
    bool black_flag = false;
    int rock_num;
    int point[] = { player_point[0], player_point[1] };

    while(point[0] >= 0 && point[1] >= 0){
        if(GetBoardRock(player_point[0], player_point[1]) != 0){
            ok_flag = false;
            break;
        }

        point[0] += lvector[0];
        point[1] += lvector[1];

        // 石の種類を確認する
        rock_num = GetBoardRock(point[0], point[1]);

        switch(rock_num){
            case 0 : ok_flag = false; break;
            case 1 : black_flag = true; break;
            case 2 : white_flag = true; break;
        }

        if(black_flag && white_flag){
            break;
        }
    }

    return black_flag && white_flag && ok_flag;
}
