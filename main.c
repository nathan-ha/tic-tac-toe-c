#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

void display_board(char *);
int get_input();

int main()
{
    char board[] = {'0', '1', '2',
                    '3', '4', '5',
                    '6', '7', '8'};
    bool game_end = false;
    for (int i = 1; !game_end; i++)
    {
        display_board(board);
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
        display_board(board);
        game_end = true;
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
int get_input() {
    int input = 0;
    while (true)
    {
         if ((scanf("%d", &input) == 1) && (0 <= input && input <= 9))
        {
            return input;
        }
        int buffer_flush_temp = 0; while ((buffer_flush_temp = getchar()) != '\n' && buffer_flush_temp != EOF) { } // magic buffer flush
        printf("invalid position, try again!\n");
    }
    return -1;
}