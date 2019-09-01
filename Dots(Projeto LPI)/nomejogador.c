#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "nomejogador.h"

player jogador1, jogador2;
void nomejogador()
{
    //obter nome do jogador 1
    system("color 0a");
    do
    {
        printf("\nNome JOGADOR 1");
        printf("(MAX 10 CARACTERES):\n");
        gets(jogador1.nome);
        system("cls");
    }
    while(strlen(jogador1.nome)>10 || strlen(jogador1.nome)==0);
    //obter nome do jogador 2
    system("color 0d");
    do
    {
        printf("\nNome JOGADOR 2");
        printf("(MAX 10 CARACTERES):\n");
        gets(jogador2.nome);
        system("cls");
    }
    while(strlen(jogador2.nome)>10 || strlen(jogador2.nome)==0);
}
