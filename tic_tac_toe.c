#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 * Author: Jake Reed
 * Year: 2022
 * Purpose: TIC TAC TOE
 * Language:  C
 */

#define TRUE 1
#define FALSE 0
#define X 'X'
#define O 'O'

void grid_layout(char grid[9], char px_name[20], char po_name[20], int px_score, char po_score)
{
        // Grid layout
        system("clear");
        printf("\r    TIC TAC TOE");
        printf("\n  ---   ---   ---");
        printf("\n|  %c  |  %c  |  %c  |", grid[0], grid[1], grid[2]);
        printf("\n  --- + --- + ---");
        printf("\n|  %c  |  %c  |  %c  |", grid[3], grid[4], grid[5]);
        printf("\n  --- + --- + ---");
        printf("\n|  %c  |  %c  |  %c  |", grid[6], grid[7], grid[8]);
        printf("\n  ---   ---   ---");
        printf("\nScore");
        printf("\n%-12s: %2d", px_name, px_score);
        printf("\n%-12s: %2d\n", po_name, po_score);
}

int main()
{
int px_score, po_score, play, round, score, counter, cell;
char player, px_name[20], po_name[20];
char grid[] = {'1', '2' ,'3', '4', '5', '6', '7', '8', '9'};

play = round = TRUE;
player = X;
px_score = po_score = counter = cell = 0;
strcpy(px_name, "Player X");
strcpy(po_name, "Player O");

grid_layout(grid, px_name, po_name, px_score, po_score);

// Player X setup
printf("Player X enter name: ");
fgets(px_name, 20, stdin);
px_name[strcspn(px_name, "\n")] = 0;

grid_layout(grid, px_name, po_name, px_score, po_score);

// Player O setup
printf("Player O enter name: ");
fgets(po_name, 20, stdin);
po_name[strcspn(po_name, "\n")] = 0;

while (play == TRUE) {
        round = TRUE;

grid_layout(grid, px_name, po_name, px_score, po_score);
printf("%d", counter);

        while (round == TRUE) {
                // Player grid selection input
                if (player == X) {
                        printf("Player %s turn place your %c 1-9:",
                                px_name, player);
                        scanf("%d", &cell);
                        getchar();
                } else if (player == O) {
                        printf("Player %s turn place your %c 1-9: ",
                                po_name, player);
                        scanf("%d", &cell);
                        getchar();
                } else {
                        printf("ERROR WITH SELECTION INPUT!");
                        play = FALSE;
                        return 1;
                }

                // Action player move
                if (cell >= 1 && cell <= 9) {
                        cell = cell - 1;
                        if (player == X && grid[cell] != X && grid[cell] != O) {
                                grid[cell] = putchar(player);
                                round = FALSE;
                        } else if (player == O && grid[cell] != X && grid[cell] != O) {
                                grid[cell] = putchar(player);
                                round = FALSE;
                        } else {
                                printf("Cell already taken!\n");
                        }
                } else {
                        printf("Invalid input!\n");
                }

                // Win condition
                score = FALSE;
                if (score == FALSE) {
                        if (grid[0] == grid[1] && grid[1] == grid[2]) {
                                score = TRUE;
                        } else if (grid[3] == grid[4] && grid[4] == grid[5]){
                                score = TRUE;
                        } else if (grid[6] == grid[7] && grid[7] == grid[8]) {
                                 score = TRUE;
                        } else if (grid[0] == grid[3] && grid[3] == grid[6]) {
                                 score = TRUE;
                        } else if (grid[1] == grid[4] && grid[4] == grid[7]) {
                                 score = TRUE;
                        } else if (grid[2] == grid[5] && grid[5] == grid[8]) {
                                 score = TRUE;
                        } else if (grid[0] == grid[4] && grid[4] == grid[8]) {
                                 score = TRUE;
                        }else if (grid[2] == grid[4] && grid[4] == grid[6]) {
                                 score = TRUE;
                        }
                        if (score == TRUE){
                                if (player == X){
                                        px_score++;
                                } else {
                                        po_score++;
                                }
                        }
                }
        }

        counter++;
        if (counter >= 9 || score == TRUE) {
                cell = counter = 0;
                grid[0] = '1';
                grid[1] = '2';
                grid[2] = '3';
                grid[3] = '4';
                grid[4] = '5';
                grid[5] = '6';
                grid[6] = '7';
                grid[7] = '8';
                grid[8] = '9';
        }

        // Change player
        if (player == X)
                player = O;
        else
                player = X;
        }
        return 0;
}
