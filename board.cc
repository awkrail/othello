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
    std::cout << ' ';
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