#pragma once
#include "Header.h"

// Gloabal definitions
int gNumOfDots = SIZE * SIZE;
int gnBullyRow = 0;
int gnBullyCol = 0;
int gnSnailBearRow = 0;
int gnSnailBearCol = 0;
int gnSavedMove = 0;

//---------------------------------------------------------------------------------------
//                                         Is In
//                                       ---------
//
// General      : The function checks if there is an deviation from the board
//
// Parameters   : 
//      char Borad[][SIZE]- a Matrix which represents the board game (In)
//		int nRow		  - Number of row in board (In)
//		int nCol		  - Number of column in board (In)
//
// Return Value : 1 if there is no exception, 0 otherwise
// 
//---------------------------------------------------------------------------------------
int  IsIn(char Borad[][SIZE], int nRow, int nCol)
{
	// Code section

	nRow--;
	nCol--;

	// Checking if there is an deviation from the board
	return (nRow < SIZE && nRow > -1 && nCol < SIZE && nCol > -1 
		&& (Borad[nRow][nCol] == '.' || Borad[nRow][nCol] == ' '));
}

//---------------------------------------------------------------------------------------
//                                         Input
//                                       ---------
//
// General      : The procedure gets the places of the walls, the place of BULLI 
//				  and place of SNAIL-BEAR in thr board game.
//
// Parameters   : 
//      char Borad[][SIZE]- a Matrix which represents the board game (In)
//
// Return Value : None (procedure)
// 
//---------------------------------------------------------------------------------------
void Input(char Borad[][SIZE])
{
	// Variable definitions
	int nRow,
		nCol,
		nBullyRow,
		nBullyCol,
		nSnailBearRow,
		nSnailBearCol,
		nNumOfWall = 1;

	// Code section

	InIt(Borad);
	printf("Enter the row of the %d wall\n", nNumOfWall);
	scanf("%d", &nRow);
	printf("Enter the col of the %d wall\n", nNumOfWall++);
	scanf("%d", &nCol);

	// Enter while entered row and column both different from 0
	while (nRow && nCol)
	{
		// Checking if there is an exception to the board
		if (IsIn(Borad ,nRow, nCol))
		{
			Borad[nRow - 1][nCol - 1] = '*';
			gNumOfDots--;
			printf("Enter the row of the %d wall\n", nNumOfWall);
			scanf("%d", &nRow);
			printf("Enter the col of the %d wall\n", nNumOfWall++);
			scanf("%d", &nCol);
		}

		else
		{
			nNumOfWall--;
			printf("\nInvalid place to put a wall in!\nTry again\n\n");
			printf("Enter the row of the %d wall\n", nNumOfWall);
			scanf("%d", &nRow);
			printf("Enter the col of the %d wall\n", nNumOfWall++);
			scanf("%d", &nCol);
		}
	}

	// Always enter
	while (1)
	{
		printf("Enter the row BULLI starts in\n");
		scanf("%d", &nBullyRow);
		printf("Enter the col BULLI starts in\n");
		scanf("%d", &nBullyCol);

		// Checking if there is an exception to the board
		if (IsIn(Borad ,nBullyRow, nBullyCol))
		{
			gnBullyRow = nBullyRow - 1;
			gnBullyCol = nBullyCol - 1;
			Borad[gnBullyRow][gnBullyCol] = 'B';
			break;
		}

		else
		{
			printf("\nInvalid place to put BULLI in!\nTry again\n\n");
		}
	}

	// Always enter
	while (1)
	{
		printf("Enter the row the SNAIL BEAR starts in\n");
		scanf("%d", &nSnailBearRow);
		printf("Enter the col the SNAIL BEAR starts in\n");
		scanf("%d", &nSnailBearCol);

		// Checking if there is an exception to the board
		if (IsIn(Borad , nSnailBearRow, nSnailBearCol))
		{
			gnSnailBearRow = nSnailBearRow - 1;
			gnSnailBearCol = nSnailBearCol - 1;
			Borad[gnSnailBearRow][gnSnailBearCol] = 'D';
			break;
		}

		else
		{
			printf("\nInvalid place to put SNAIL BEAR in!\nTry again\n\n");
		}
	}
}

//---------------------------------------------------------------------------------------
//                                        Print Board
//                                       -------------
//
// General      : The procedure prints the board game.
//
// Parameters   : 
//      Mat_Building[][Apartments] - a Matrix which represents the board game (In)
//
// Return Value : None (procedure)
// 
//---------------------------------------------------------------------------------------
void PrintBoard(char Board[][SIZE])
{
	// Variable definitions
	int nRow,
		nCol;

	// Code section
	
	// Printing all row numbers
	printf("    ");
	for (int nRow = 1; nRow <= SIZE; nRow++)
	{
		printf("%d ", nRow);
	}
	printf("\n");

	// Going throught all the rows in the board
	for (int nRow = 0; nRow < SIZE; nRow++)
	{
		// Printing all column numbers
		if (nRow + 1 < SIZE / 10)
		{
			printf("%d   ", nRow + 1);
		}
		else
		{
			if (nRow + 1 < SIZE)
			{
				printf("%d  ", nRow + 1);
			}
			else
			{
				if (nRow + 1 == SIZE)
				{
					printf("%d ", nRow + 1);
				}
			}
		}

		// Going throught all the columns in the board
		for (int nCol = 0; nCol < SIZE; nCol++)
		{
			printf("|%c", Board[nRow][nCol]);
		}
		printf("|\n");
	}
	printf("\n");
}

//---------------------------------------------------------------------------------------
//											In It
//                                         -------
//
// General      : The procedure initializes the game board so that every
//				  cell in it contains a dot.
//
// Parameters   : 
//      Mat_Building[][Apartments] - a Matrix which represents the board game (In)
//
// Return Value : None (procedure)
// 
//---------------------------------------------------------------------------------------
void InIt(char Board[][SIZE])
{
	// Variable definitions
	int nRow,
		nCol;

	// Code section
	
	// Going throught all the rows in board
	for (int nRow = 0; nRow < SIZE; nRow++)
	{
		// Going throught all the columns in board
		for (int nCol = 0; nCol < SIZE; nCol++)
		{
			Board[nRow][nCol] = '.';
		}
	}
}

//---------------------------------------------------------------------------------------
//                                         Move Bully
//                                        ------------
//
// General      : The procedure moves BULLI in the chosen direction
//				  (which can be only: right, left, up and down).
//
// Parameters   : 
//      Mat_Building[][Apartments] - a Matrix which represents the board game (In)
//
// Return Value : None (procedure)
// 
//---------------------------------------------------------------------------------------
void MoveBully(char Board[][SIZE])
{
	// Variable definitions
	int Move = 0,
		flag = 0,
		flag2 = 0;

	// Code Section

	Board[gnBullyRow][gnBullyCol] = ' ';

	// Always enter
	while (1)
	{
		printf("Enter num of direction:\n0 - same as before\n");
		printf("1 - right\n2 - left\n3 - up\n4 - down\n");
		scanf("%d", &Move);
		printf("\n");

		// Checking if direction entered is 0 - meaning same as before
		if (Move == 0)
		{
			Move = gnSavedMove;
		}

		switch (Move)
		{
		case 0:

			// Checking if direction has been entered yet
			if (gnSavedMove)
			{
				Move = gnSavedMove;
				flag2 = 1;
			}

			else
			{
				printf("Try again, no direction has been chosen yet\n\n");
			}

			break;

		case 1:

			// Checking if BULLI can move right
			if (Board[gnBullyRow][gnBullyCol + 1] != '*' && gnBullyCol + 1 < SIZE)
			{
				gnBullyCol++;
			}

			else
			{
				flag = 1;
			}

			gnSavedMove = Move;
			break;

		case 2:

			// Checking if BULLI can move left
			if (Board[gnBullyRow][gnBullyCol - 1] != '*' && gnBullyCol - 1 > -1)
			{
				gnBullyCol--;
			}

			else
			{
				flag = 1;
			}

			gnSavedMove = Move;
			break;

		case 3:

			// Checking if BULLI can move up
			if (Board[gnBullyRow - 1][gnBullyCol] != '*' && gnBullyRow - 1 > -1)
			{
				gnBullyRow--;
			}

			else
			{
				flag = 1;
			}

			gnSavedMove = Move;
			break;

		case 4:

			// Checking if BULLI can move down
			if (Board[gnBullyRow + 1][gnBullyCol] != '*' && gnBullyRow + 1 < SIZE)
			{
				gnBullyRow++;
			}

			else
			{
				flag = 1;
			}

			gnSavedMove = Move;
			break;

		default:
			break;
		}

		if (!flag2)
		{
			break;
		}
	}

	Board[gnBullyRow][gnBullyCol] = 'B';
	// Checking if BULLI changed his place
	if (!flag)
	{
		gNumOfDots--;
	}
}

//---------------------------------------------------------------------------------------
//                                       Move Snail Bear
//                                      -----------------
//
// General      : The procedure moves SNAIL-BEAR one step closer to BULLI.
//
// Parameters   : 
//      Mat_Building[][Apartments] - a Matrix which represents the board game (In)
//
// Return Value : None (procedure)
// 
//---------------------------------------------------------------------------------------
void MoveSnailBear(char Board[][SIZE])
{
	// Variable definitions
	int nNewRow,
		nNewCol;

	// Code section

	nNewRow = gnBullyRow - gnSnailBearRow;
	nNewCol = gnBullyCol - gnSnailBearCol;

	// Checking the possibility of diagonal move
	if (nNewCol && nNewRow)
	{
		// Checking if needs to move to bottom right corner and validation
		if (nNewRow > 0 && nNewCol > 0 &&
			Board[gnSnailBearRow + 1][gnSnailBearCol + 1] != '*' &&
			gnSnailBearRow + 1 < SIZE && gnSnailBearCol + 1 < SIZE)
		{
			gnSnailBearRow++;
			gnSnailBearCol++;
		}

		// Checking if needs to move to bottom left corner and validation
		if (nNewRow > 0 && nNewCol < 0 &&
			Board[gnSnailBearRow + 1][gnSnailBearCol - 1] != '*' &&
			gnSnailBearRow + 1 < SIZE && gnSnailBearCol - 1 > -1)
		{
			gnSnailBearRow++;
			gnSnailBearCol--;
		}

		// Checking if needs to move to top left corner and validation
		if (nNewRow < 0 && nNewCol < 0 &&
			Board[gnSnailBearRow - 1][gnSnailBearCol - 1] != '*' &&
			gnSnailBearRow - 1 > -1 && gnSnailBearCol - 1 > -1)
		{
			gnSnailBearRow--;
			gnSnailBearCol--;
		}

		// Checking if needs to move to top right corner and validation
		if (nNewRow < 0 && nNewCol > 0 &&
			Board[gnSnailBearRow - 1][gnSnailBearCol + 1] != '*' &&
			gnSnailBearRow - 1 > -1 && gnSnailBearCol + 1 < SIZE)
		{
			gnSnailBearRow--;
			gnSnailBearCol++;
		}
	}

	else
	{
		// Checking whether movement needs to be balanced or vertical
		if (nNewCol || nNewRow)
		{
			// Checking whether movement needs to be vertical
			if (nNewCol)
			{
				// Checking if needs to move roght and validation
				if (nNewCol > 0 && gnSnailBearCol + 1 < SIZE &&
					Board[gnSnailBearRow][gnSnailBearCol + 1] != '*')
				{
					gnSnailBearCol++;
				}

				else
				{
					// Checking if needs to move left and validation
					if (nNewCol < 0 && gnSnailBearCol - 1 > -1 &&
						Board[gnSnailBearRow][gnSnailBearCol - 1] != '*')
					{
						gnSnailBearCol--;
					}
				}
			}
			else 
			{
				// Checking if needs to move up and validation
				if (nNewRow < 0 && gnSnailBearRow - 1 > -1 &&
					Board[gnSnailBearRow - 1][gnSnailBearCol] != '*')
				{
					gnSnailBearRow--;
				}

				else 
				{
					// Checking if needs to move down and validation
					if (nNewRow > 0 && gnSnailBearRow + 1 < SIZE &&
						Board[gnSnailBearRow + 1][gnSnailBearCol] != '*')
					{
						gnSnailBearRow++;
					}
				}
				
			}
		}
	}
	Board[gnSnailBearRow][gnSnailBearCol] = 'D';
}

//---------------------------------------------------------------------------------------
//                                       Move Snail Bear
//                                      -----------------
//
// General      : The procedure runs the game, checks who won
//				  and prints a message accordingly.
//
// Parameters   : None
//
// Return Value : None (procedure)
// 
//---------------------------------------------------------------------------------------
void Game()
{
	// Variable definitions
	int  flag = 0;
	
	// Array definition
	char Mat[SIZE][SIZE] = { NULL };

	// Code section

	InIt(Mat);
	PrintBoard(Mat);
	Input(Mat);

	// enter if game isn't over
	while (gNumOfDots)
	{
		PrintBoard(Mat);
		MoveBully(Mat);
		MoveSnailBear(Mat);

		// Check if SNAIL BEAR ate BULLI - meaning game is over
		if (gnSnailBearRow == gnBullyRow && gnSnailBearCol == gnBullyCol)
		{
			PrintBoard(Mat);
			printf("\nSNAIL BEAR ate you! You lose!\n");
			break;
		}
	}

	// Check if BULLI won
	if (!gNumOfDots)
	{
		PrintBoard(Mat);
		printf("You won!\n");
	}
}