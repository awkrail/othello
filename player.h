#ifndef PLAYER_H_
#define PLAYER_H_

class Player {
    public:
        void Input();
        int GetRowIndex();
        int GetColIndex();
    private:
        char _row_alphabet;
        int _row;
        int _col;
};

#endif // PLAYER_H_