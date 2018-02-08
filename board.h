#ifndef BOARD_H_
#define BOARD_H_

class Board {
    public:
        Board();
        void Show();
        int GetBoardRock(int row, int col);
        void Reverse(const int* const player_point);
        void Reverse(const int* const player_point, const int* const vector);
        bool CheckPutDown(const int* const player_point);
        bool CheckPutDown(const int* const player_point, const int* const vector);
        bool GetTurn();
        void SetTurn(bool turn);
    private:
        bool _turn;
        static const int _kVectorSize = 8;
        static const int _kBoardLength = 8;
        int _board[8][8];
};

#endif // BOARD_H_