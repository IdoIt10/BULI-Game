#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"

//---------------------------------------------------------------------------------------
//										   BULLI
//										  -------
//
// General : The program runs the game "BULLI" - in which the player chooses where the
//			 walls on the board are that cannot be stepped on or passed and the location
//			 of BULLI. Also in the game he chases BULLI, the SNAIL-BEAR.
//			 The player will also enter the location of the SNAIL-BEAR.
//			 As soon as the game starts after receiving all the positions of the walls
//			 and the players on the board, the player chooses where to move BULLI in
//			 the direction of: right, left, up or down. Every time Bully moves, the
//			 SNAIL-BEAR will move closer to him. It should be noted that the
//			 SNAIL-BEAR can only move one step at a time, but unlike "Bolly" - it can
//			 also move diagonally. The aim of the game is not to be caught by the
// 			 SNAIL-BEAR and to capture all the points on the board - which are
//			 everywhere where there is no wall. Eating a point will be done by passing
//			 through it.
// 
// Input   : The places of the walls, the place of BULLI 
//			 and place of SNAIL-BEAR in the board game.
// 
// Process : The program moves the SNAIL-BEAR one step closer to BULLI
//			 in every stepof him, which the program gets by the user.
//
// Output  : The board in every chosen move of BULLI and prints a massage of who won.
// 
//---------------------------------------------------------------------------------------
// Programmer : Ido Itzhaki
// Student ID : 209771344
// Date       : 04.12.2022
//---------------------------------------------------------------------------------------

void main()
{
	Game();
}