#include <stdio.h>

void display_board(char *);

int main()
{
    char board[] = {'.', '.', '.',
                    '.', '.', '.',
                    '.', '.', '.'};
    int i = 1;
    printf("Turn %d\n", i);
    display_board(board);
}

void display_board(char *board)
{
    printf("-----------------\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%c\t", board[3 * i + j]);
        }
        printf("\n\n");
    }
    printf("-----------------\n\n");
}