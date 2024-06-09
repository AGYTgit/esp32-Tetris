#ifndef board_h
#define board_h

#include <ST7789V.h>

#include <tetris_settings.h>
#include <dimensions.h>

class Board {
public:
    Board(int board_pos_x = 0, int board_pos_y = 0);

    void draw(ST7789V lcd, bool force_draw = false);
    int clear_completed_lines();

// private:
    int board_pos_x;
    int board_pos_y;
    char board_matrix[BOARD::HEIGHT][BOARD::WIDTH][BOARD::DEPTH]; // 2D array to store board state

    void move_lines(int height);
};

#endif // board_h