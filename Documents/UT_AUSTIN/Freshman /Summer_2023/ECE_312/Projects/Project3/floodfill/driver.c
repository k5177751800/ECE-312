//Konghwan Shin
//ECE 312, project 3
//KS54897
#include <stdio.h>
#include <stdbool.h>
#include "stack312_ll.h"
int Rows= 0;
int Cols=0;
char img[25][25];
void picR(char* fileName){
    FILE* file = fopen(fileName, "r"); //Opens file
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }
    char c;
    int row = 0;
    int col = 0;
    do {
        c = fgetc(file);

        if (c == '\n') {
            row++;
            col = 0;
        }
        else if (c != EOF) {
            img[row][col] = c;
            col++;
            if (col > Cols)
                Cols = col;
        }
    } while (c != EOF);

    Rows = row;
    fclose(file);
}



void picD(){    //Displays the image
    for (int i = 0; i < Rows; i++){
        for (int k = 0; k < Cols; k++){
            printf("%c", img[i][k]);
        }
        printf("\n");
    }
}

void floodFill(int row, int colum, char Color) {
    Stack312 stack;
    makeStack(&stack);

    char OldC = img[row][colum];
    Pixel OldPix = {row, colum, Color};
    push(OldPix, &stack);

    while (isEmpty(stack)==false) {
        Pixel newPixel = pop(&stack);
        img[newPixel.row][newPixel.col] = Color;

        int dummy[] = {
                [0] = 0,
                [1] = 0,
                [2] = -1,
                [3] = 1,
                [4] = -1,
                [5] = -1,
                [6] = 1,
                [7] = 1

        };

        int colDummy[] = {
                [0] = -1,
                [1] = 1,
                [2] = 0,
                [3] = 0,
                [4] = -1,
                [5] = 1,
                [6] = -1,
                [7] = 1
        };
        for (int i = 0; i < 8; i++) {
            int newRows = newPixel.row + dummy[i];
            int newColumn = newPixel.col + colDummy[i];

            while (1) {
                int isValid = (newRows >= 0 && newRows < Rows && newColumn >= 0 && newColumn < Cols && img[newRows][newColumn] == OldC);
                while (isValid) {
                    Pixel newPixel = {
                            .row = newRows,
                            .col = newColumn,
                            .color = Color
                    };
                    push(newPixel, &stack);
                    break;
                }
                break;
            }
        }
    }

    picD();
}

int main(int argc, char **argv) {
    picR(argv[1]);
    picD();

    int row, col;
    char color;

    while (1) { //While loop to print user inputs to play the game
        printf("\n");
        printf("Enter a row: ");
        scanf("%d", &row);
        printf("Enter a column: ");
        scanf("%d", &col);
        printf("Enter a color: ");
        scanf(" %c", &color);

        if (col < 0 || row <0) {  //code is finished when user enters -1 for either col or row.
            break;
        }
        floodFill(row, col, color);
    }

    return 0;
}
