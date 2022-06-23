#pragma once
#include <iostream>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#include <stdio.h>

//BLACK 0
//BLUE 1
//GREEN 2
//CYAN 3
//RED 4
//MAGENTA 5
//BROWN 6
//LIGHTGRAY 7
//DARKGRAY 8
//LIGHTBLUE 9
//LIGHTGREEN 10
//LIGHTCYAN 11
//LIGHTRED 12
//LIGHTMAGENTA 13
//YELLOW 14
//WHITE 15


void gotoxy(int x, int y);
void setcolor(int color, int bgcolor);
void fullscreen();
void Cursorhide();