#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define definition
#define SIZE 10

// Function prototypes
int IsIn(char Board[][SIZE], int nRow, int nCol);
void Input(char Borad[][SIZE]);
void PrintBoard(char Board[][SIZE]);
void InIt(char Board[][SIZE]);
void MoveBully(char Board[][SIZE]);
void MoveSnailBear(char Board[][SIZE]);
void Game();