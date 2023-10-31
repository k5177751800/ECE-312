// life.h
// -- EE 312 Project 2

/* Student information for project:
 *
 * Replace <NAME> with your name.
 *
 * On my honor, <Konghwan Shin>, this programming project is my own work
 * and I have not provided this code to any other student.
 *
 * Name: Konghwan Shin
 * email address: kshin1@utexas.edu
 * UTEID: ks54897
 * Section 5 digit ID: 75590
 *
 *///
// Created by priebe on 9/5/2018.
//

#ifndef UNTITLED1_LIFE_H
#define UNTITLED1_LIFE_H

#endif //UNTITLED1_LIFE_H



void populateWorld(char fname[], char *grid[], int *numRows, int *numCols);
//Brings textfile and updates the grid. It updates rows and the column
void showWorld(char *grid[], int numRows, int numCols);
//changes the content of the grid makes the grid to show alive cells to * and the dead cells to .
void iterateGeneration(char *grid[], int numRows, int numCols);
//updating next generation to make the game work.
