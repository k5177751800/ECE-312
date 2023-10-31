#include "life.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


void populateWorld(char fname[], char *grid[], int *numRows, int *numCols){
    FILE* fptr;
    char dummyStr[80];
    char dummyChar;


// Open file
    fptr = fopen(fname, "r");
// if file can't be read, return with error
    if(fptr == NULL) {
        perror("Error opening file"); // print error

    }
// Count the number of columns
    *numCols = 0;
// Read characters in the first line until a newline is seen
// This is the number of columns
    dummyChar = fgetc(fptr);
    while ((dummyChar != '\n')){
        *numCols+=1;
        dummyChar = fgetc(fptr);
    }
    printf("Number of columns = %d\n",*numCols);

// Rewind file back to beginning
    rewind(fptr);
// Count the number of rows
    *numRows = 0;
// Read lines the in the file until a NULL is seen
// This is the number of rows
    while (fgets(dummyStr, *numCols+2, fptr) != NULL) {
        grid[*numRows] = (char *) malloc((*numCols + 1) * sizeof(char)); // Allocate memory for row
        for (int i = 0; i < *numCols; i++) {
            grid[*numRows][i] = dummyStr[i]; // Copy character by character
        }
        grid[*numRows][*numCols] = '\0'; // Null-terminate the row string
        (*numRows)++;
    }
    printf("Number of rows = %d\n",*numRows);
    fclose(fptr);
    return;

}







// changing 1 to * and 0 to .
void showWorld(char *grid[], int numRows, int numCols){
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if (grid[i][j] == '1') {
                printf("*");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}



//Implementing rules updating next generation
void iterateGeneration(char *grid[], int numRows, int numCols){
    int k[3]={-1,0,1};
    char gridt[numRows][numCols]; //an array that stores tmp value

    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            int inc=0;
            int count=0;
            while (inc<9){
                int x = i+k[inc%3];
                int y = j+k[inc/3];
                if ((x >numRows-1|| y>numCols-1 || x<0 || y<0)||(inc%3 == 1&&inc/3==1)){
                        count = count;
                } else{
                    if (grid[x][y] == '1'){
                        count++;
                    }
                }
                inc++;
            }
            if (count==3 ||(count ==2 && grid[i][j]=='1')){
                gridt[i][j] ='1';
            }else{
                gridt[i][j] = '0';
            }
        }
    }
    for (int i = 0; i < numRows; ++i) {
        strcpy(grid[i],gridt[i]);
    }


}





