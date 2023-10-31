//Konghwan Shin
//KS54897
//ECE 312
#include <stdio.h>
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
//
void Rep(int row1, int col1, char color, char oCol){
    if (row1<0|| col1<0 || row1 > 24 || col1 > 24 || oCol != img[row1][col1]){
        return;
    }
    img[row1][col1] = color;

    Rep(row1-1, col1, color, oCol);
    Rep(row1+1, col1, color, oCol);
    Rep(row1, col1-1, color, oCol);
    Rep(row1, col1+1, color, oCol);
    Rep(row1-1, col1-1, color, oCol);
    Rep(row1+1, col1+1, color, oCol);
    Rep(row1-1, col1+1, color, oCol);
    Rep(row1+1, col1-1, color, oCol);
}

int main(int argc, char **argv) {
    picR(argv[1]);
    picD();
    int row, col;
    char color, oCol;

    while (1) { //While loop to print user inputs to play the game
        printf("\n");
        printf("Enter a row: ");
        scanf("%d", &row);
        printf("Enter a column: ");
        scanf("%d", &col);
        printf("Enter a color: ");
        scanf(" %c", &color);
        oCol = img[row][col];
        if (col < 0 || row < 0) {  //code is finished when user enters -1 for either col or row.
            break;
        }
        Rep(row, col, color, oCol);
        picD();

    }

    return 0;
}
