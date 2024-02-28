#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

void display_board(char *);
int get_input(char *board);
char check_win(char *);


// TODO: block placing on top of already filled slots
// TODO: game end checking

int main()
{
    char board[] = {'0', '1', '2',
                    '3', '4', '5',
                    '6', '7', '8'};
    for (int i = 1;; i++)
    {
        display_board(board);
        // alternate placing X's and O's
        if (i % 2 == 1)
        {
            printf("Turn %d -- X's turn\n", i);
            board[get_input(board)] = 'X';
        }
        else 
        {
            printf("Turn %d -- O's turn\n", i);
            board[get_input(board)] = 'O';
        }
        // check if win or tie
        char winner = check_win(board);
        if (winner == 't') 
        {
            display_board(board);
            printf("Tie!");
            return 0;   
        }
        if (winner != 0)
        {
            display_board(board);
            printf("%c wins!", winner);
            return 0;
        }
    }
}

void display_board(char *board)
{
    const char *divider = "-----------------\n";
    printf(divider);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%c\t", board[3 * i + j]);
        }
        printf("\n\n");
    }
    printf(divider);
}

// returns array index as specified by user
int get_input(char *board) {
    int input = 0;
    while (true)
    {
        // validate input
        if ((scanf("%d", &input) == 1) && (0 <= input && input <= 9) && (isdigit(board[input])))
        {
            return input;
        }
        int buffer_flush_temp = 0; while ((buffer_flush_temp = getchar()) != '\n' && buffer_flush_temp != EOF) { } // magic buffer flush
        printf("invalid position, try again!\n");
    }
    return -1;
}

char check_win(char *board)
{
    // 8 checks
    if (board[0] == board[1] && board[1] == board[2])
    {
        return board[0];
    }
    if (board[3] == board[4] && board[4] == board[5])
    {
        return board[3];
    }
    if (board[6] == board[7] && board[7] == board[8])
    {
        return board[6];
    }
    if (board[0] == board[3] && board[3] == board[6])
    {
        return board[0];
    }
    if (board[1] == board[4] && board[4] == board[7])
    {
        return board[1];
    }
    if (board[2] == board[5] && board[5] == board[8])
    {
        return board[2];
    }
    if (board[0] == board[4] && board[4] == board[8])
    {
        return board[0];
    }
    if (board[2] == board[4] && board[4] == board[6])
    {
        return board[2];
    }
    // check for tie
    for (int i = 0; i < 9; i++)
    {
        if (isdigit(board[i])) 
        {
            return 0; // if there is a digit left, then there is no tie
        }
    }
    return 't';
}