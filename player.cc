#include "player.h"
#include <iostream>
#include <assert.h>

void Player::Input(){
    std::cin >> _row_alphabet >> _col;
    assert(97 <= int(_row_alphabet) && int(_row_alphabet) <= 104);
    assert(0 <= _col && _col <= 7);
    _row = int(_row_alphabet) - 97;
}

int Player::GetRowIndex(){
    return _row;
}

int Player::GetColIndex(){
    return _col;
}

