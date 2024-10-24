/*
Name: Iqra Ashraf
Roll No: 24K-0952
Problem: 9
*/

#include <stdio.h>

void showGrid(char grid[5][5]) {
	int i;
	int j;
    for (i=0; i<5; i++) {
        for (j=0; j<5; j++) {
            printf("%c ",grid[i][j]);
        }
        printf("\n");
    }
}

void findPosition(char grid[5][5], int *playerRow, int *playerCol) {
	int i;
	int j;
    for (i=0; i<5; i++) {
        for (j=0; j<5; j++) {
            if (grid[i][j]=='P') {
                *playerRow=i;
                *playerCol=j;
                return;
            }
        }
    }
}

int newPosition(char grid[5][5], int newRow, int newCol, int *collectedItems) {
    if (newRow<0 || newRow>=5 || newCol<0 || newCol>=5) {
        printf("Invalid move:(\n");
        return 0;
    }
    
    if (grid[newRow][newCol]=='X') {
        printf("Invalid move:(\n");
        return 0;
    }
    
    if (grid[5][5]=='I') {
        (*collectedItems)++;
        printf("Congrats! You collected an item:)\n Total items collected: %d\n", *collectedItems);
    }
    return 1;
}

int main() {
	char grid[5][5] = {
        {' ', ' ', 'I', 'X', ' '},
        {' ', 'X', ' ', ' ', ' '},
        {'I', ' ', 'X', 'X', ' '},
        {' ', ' ', ' ', 'I', 'X'},
        {' ', 'X', ' ', ' ', 'P'}
    };

    int playerRow, playerCol;
    int collectedItems = 0;
    char move;
    findPosition(grid, &playerRow, &playerCol);

    while(1){
        showGrid(grid);
        printf("Enter your move ('W' for up, 'S' for down, 'A' for left, 'D' for right, 'Q' for quit): ");
        scanf(" %c", &move);
        if (move=='Q') {
            printf("Thankyou:)");
            break;
        }
        int newRow=playerRow;
        int newCol=playerCol;

        if (move=='W') {
            newRow--;
        } else if(move=='S') {
            newRow++;
        } else if(move=='A') {
            newCol--;
        } else if(move=='D') {
            newCol++;
        } else {
            printf("Invalid input:(");
            continue;
        }
        if (newPosition(grid,newRow,newCol,&collectedItems)) {
            grid[playerRow][playerCol]=' ';
            grid[newRow][newCol]='P';
            playerRow=newRow;
            playerCol=newCol;
        }
    }

    return 0;
}
