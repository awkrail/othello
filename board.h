#ifndef BOARD_H_
#define BOARD_H_

class Board {
    public:
        Board();
        void Show();
        int CheckWhiteBetweenBlacks(int row, int col);
    private:
        static const int _kBoardLength = 8;
        int _board[8][8];
};

#endif // BOARD_H_