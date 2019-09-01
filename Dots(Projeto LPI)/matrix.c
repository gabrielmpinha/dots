#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "nomejogador.h"
#include "funcoesauxiliares.h"
#define pontos 250

extern player jogador1, jogador2;

char tab[8][8];
const int linha=7;
const int coluna=7;

void matrix() //TABULEIRO
{
    int y; //colunas da matrix
    int x; //linhas da matrix
    //linha = 7, coluna = linha;
    textcolor(15);
    for(x=0; x<linha; x++)//printando tabuleiro
    {
        for(y=0; y<coluna; y++)
        {
            if(x%2==0 && y%2==0)
                tab[x][y]=pontos;
            else
                tab[x][y]=' ';
            printf("%c", tab[x][y]);
        }
        printf("\n");
    }
    {
        //printando dados iniciais do jogo
        textcolor(10);
        gotoxy(15, 0);
        printf("*Turno do JOGADOR 1*\n");
        gotoxy(14, 2);
        printf("JOGADOR 1(%s): 0 pontos", jogador1.nome);
        textcolor(13);
        gotoxy(14, 4);
        printf("JOGADOR 2(%s): 0 pontos", jogador2.nome);
        textcolor(12);
        gotoxy(16, 6);
        printf("ESC voltar ao menu");
        textcolor(10);
    }

}
