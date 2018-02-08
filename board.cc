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

// this method is called only after Board::CheckPutDown
void Board::Reverse(const int* const player_point){
    const int lup[] = {-1, -1};
    const int lnw[] = {0, -1};
    const int ldw[] = {1, -1};
    const int evup[] = {-1, 0};
    const int evdw[] = {1, 0};
    const int rup[] = {-1, 1};
    const int rnw[] = {0, 1};
    const int rdw[] = {1, 1};
    const int* const vectors[] = {lup, lnw, ldw, evup, evdw, rup, rnw, rdw};
    int point[] = { player_point[0], player_point[1] };

    for(int i=0; i<_kVectorSize; ++i){
        Reverse(player_point, vectors[i]);
    }
}

void Board::Reverse(const int* const player_point, const int* const vector){
    _board[player_point[0]][player_point[1]] = 1; // black

    int point[] = { player_point[0], player_point[1] };
    int rock_num;

    while(point[0] >= 0 && point[1] >= 0 && point[0] < _kBoardLength && point[1] < _kBoardLength){

        point[0] += vector[0];
        point[1] += vector[1];

        // TODO: Blackの立場でもWhiteの立場でも, ひっくり返るメソッドに変更する
        // 今はBlackのみ
        rock_num = GetBoardRock(point[0], point[1]);

        if(rock_num == 1){
            break;
        }else if(rock_num == 2){
            _board[point[0]][point[1]] = 1;
        }
    }
}

bool Board::CheckPutDown(const int* const player_point){
    const int lup[] = {-1, -1};
    const int lnw[] = {0, -1};
    const int ldw[] = {1, -1};
    const int evup[] = {-1, 0};
    const int evdw[] = {1, 0};
    const int rup[] = {-1, 1};
    const int rnw[] = {0, 1};
    const int rdw[] = {1, 1};
    const int* const vectors[] = {lup, lnw, ldw, evup, evdw, rup, rnw, rdw};
    bool ok_flag = false;

    for(int i=0; i<_kVectorSize; ++i){
        if(CheckPutDown(player_point, vectors[i])){
            ok_flag = true;
        }
    }

    return ok_flag;
}

bool Board::CheckPutDown(const int* const player_point, const int* const vector){

    bool ok_flag = true;
    bool white_flag = false;
    bool black_flag = false;
    int rock_num;
    int point[] = { player_point[0], player_point[1] };

    while(point[0] >= 0 && point[1] >= 0 && point[0] < _kBoardLength && point[1] < _kBoardLength){
        if(GetBoardRock(player_point[0], player_point[1]) != 0){
            ok_flag = false;
            break;
        }

        point[0] += vector[0];
        point[1] += vector[1];

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

bool Board::GetTurn(){
    return _turn;
}

void Board::SetTurn(bool turn){
    _turn = turn;
}