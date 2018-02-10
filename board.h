#ifndef BOARD_H_
#define BOARD_H_

class Board {
    public:
        Board();
        void Show();
        int GetBoardRock(int row, int col);
        void Reverse(const int* const player_point, const int* const vector);
        bool ProcessGame(const int* const player_point);
        bool CheckPutDown();
        bool CheckPutDown(const int* const player_point, const int* const vector, const bool ok_flag);
        bool GetTurn();
        void SetTurn(bool turn);
        void CountRocks();
        int GetBlackRocks();
        int GetWhiteRocks();
    private:
        bool _turn;
        static const int _kVectorSize = 8;
        static const int _kBoardLength = 8;
        int _board[8][8];
        int _black_rocks;
        int _white_rocks;
};

#endif // BOARD_H_