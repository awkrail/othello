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


void Board::Reverse(const int* const player_point, const int* const vector){
    if(_turn){
        _board[player_point[0]][player_point[1]] = 1; // black
    }else{
        _board[player_point[0]][player_point[1]] = 2; // white
    }

    int point[] = { player_point[0], player_point[1] };
    int rock_num;

    while(point[0] >= 0 && point[1] >= 0 && point[0] < _kBoardLength && point[1] < _kBoardLength){

        point[0] += vector[0];
        point[1] += vector[1];

        rock_num = GetBoardRock(point[0], point[1]);

        if(_turn){
            if(rock_num == 1){
                break;
            }else if(rock_num == 2){
                _board[point[0]][point[1]] = 1;
            }
        }else{
            if(rock_num == 2){
                break;
            }else if(rock_num == 1){
                _board[point[0]][point[1]] = 2;
            }
        }
    }
}

bool Board::ProcessGame(const int* const player_point){
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
        if(CheckPutDown(player_point, vectors[i], ok_flag)){
            ok_flag = true;
            Reverse(player_point, vectors[i]);
        }
    }

    return ok_flag;
}

bool Board::CheckPutDown(){
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

    for(int i=0; i<_kBoardLength; ++i){
        for(int j=0; j<_kBoardLength; ++j){

            const int row = i;
            const int col = j;
            const int player_point[] = { row, col };

            for(int i=0; i<_kVectorSize; ++i){
                if(CheckPutDown(player_point, vectors[i], ok_flag)){
                    return true;
                }
            }

        }
    }
    return false;
}

bool Board::CheckPutDown(const int* const player_point, const int* const vector, const bool ok_flag){

    bool player_flag = false;
    int turn2rock_num = _turn ? 2 : 1;
    int rock_num;
    int count_i = 0;
    int point[] = { player_point[0], player_point[1] };

    while(point[0] >= 0 && point[1] >= 0 && point[0] < _kBoardLength && point[1] < _kBoardLength){
        if(GetBoardRock(player_point[0], player_point[1]) != 0 && !ok_flag){
            return false;
        }

        point[0] += vector[0];
        point[1] += vector[1];

        rock_num = GetBoardRock(point[0], point[1]);

        if(count_i == 0 && rock_num == turn2rock_num){
            count_i++;
            player_flag = true;
            continue;
        }

        if(!player_flag){
            return false;
        }else{
            if(_turn){
            switch(rock_num){
                case 0 : return false; break;
                case 1 : return true; break;
                case 2 : continue;
                }
            }else{
            switch(rock_num){
                case 0 : return false; break;
                case 1 : continue; break;
                case 2 : return true;
                }
            }
        }
    }

    return false;
}

bool Board::GetTurn(){
    return _turn;
}

void Board::SetTurn(bool turn){
    _turn = turn;
}

void Board::CountRocks(){
    _black_rocks = 0;
    _white_rocks = 0;

    for(int i=0; i<_kBoardLength; ++i){
        for(int j=0; j<_kBoardLength; ++j){
            if(GetBoardRock(i, j) == 1){
                _black_rocks++;
            }else if(GetBoardRock(i, j) == 2){
                _white_rocks++;
            }
        }
    }
}

int Board::GetBlackRocks(){
    return _black_rocks;
}

int Board::GetWhiteRocks(){
    return _white_rocks;
}