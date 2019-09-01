#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

void ShowConsoleCursor(int showFlag)// 0 deixa o cursor invisivel e 1 deixa o cursor visivel
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag;
    SetConsoleCursorInfo(out, &cursorInfo);
}

int textcolor(int cor)//trocar cor de um texto
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cor);
    return 0;
}

void gotoxy(int x, int y)//mover cursor
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
