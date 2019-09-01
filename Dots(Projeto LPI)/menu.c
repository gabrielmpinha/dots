#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "menu.h"
#include "instrucao.h"
#include "matrix.h"
#include "gameplay.h"
#include "nomejogador.h"
#include "ranking.h"
#include "funcoesauxiliares.h"
#define seta_cima 72
#define seta_baixo 80
#define enter 13
#define espaco 32
#define nao 0
void desenharmenu()
{
    //desenha a borda e as opcoes do menu
    int menulinha, menucoluna;
    textcolor(14);
    for(menulinha = 0; menulinha <15; menulinha++)
    {
        for(menucoluna = 0; menucoluna<45; menucoluna++)
        {
            if(menulinha==0 || menulinha==14 || menucoluna==0 || menucoluna == 44 )
                printf("%c", 219);
            else
                printf(" ");
        }
    }

    textcolor(12);
    gotoxy(20,3);
    printf("DOTS");
    gotoxy(17,5);
    textcolor(15);
    printf("-Jogar");
    printf("\n\t\t -Instrucoes");
    printf("\n\t\t -Ranking");
    printf("\n\t\t -Creditos");
    printf("\n\t\t -Sair");
}

void escolher_opcao(const int escolha)
{
    //verifica qual opcao o jogador escolheu usando como base a posicao do cursor
    if(escolha==5)
    {
        nomejogador();
        system("MODE con: cols=46 lines=9");
        matrix();
        jogo();
    }
    else if(escolha==6)
    {
        system("MODE con: cols=100 lines=16");
        instrucao();
    }
    else if(escolha==7)
    {
        system("MODE con: cols=45 lines=30");
        rankingler();
    }
    else if(escolha==8)
    {
        printf("\n->Developers:");
        textcolor(12);
        printf("\n\t\tArthur Brito\n\t\tGabriel Pinheiro\n\t\tLucas Cavalcanti\n\t\tVinicius Martins\n\n");
    }
    else if(escolha==9)
        exit(0);
    if(escolha==6 || escolha==7 || escolha==8)
    {
        textcolor(4);
        system("pause");
    }
}
void menu()
{
    //funcionamento do menu
    char opcao=enter;//começa no "enter" para desenhar o menu
    int ymenu=5;
    int xmenu=15;
    int yapagar=ymenu;//começa no ymenu para pegar a primeira posicao do cursor
    do//Loop infinito
    {
        if(opcao==enter || opcao==espaco)//printa menu novamente caso o jogador tenha selecionado alguma opcao do menu anteriormente
        {
            ShowConsoleCursor(nao);//esconde o cursor da tela
            system("MODE con: cols=45 lines=15");
            desenharmenu();
            gotoxy(xmenu, ymenu);
        }

        textcolor(10);
        printf("->");//printa seta

        opcao = getch();
        switch(opcao)//posicao do cursor e selecionar opcao
        {
        case 'w':
        case seta_cima:
            ymenu--;
            break;
        case 's':
        case seta_baixo:
            ymenu++;
            break;
        case enter:
        case espaco:
            system("cls");
            escolher_opcao(ymenu);
        }
        //corrigir caso o jogador passe do menu
        if(ymenu>9)
            ymenu=5;
        if(ymenu<5)
            ymenu=9;

        gotoxy(xmenu, yapagar);//vai para a posicao anterior da seta
        printf("  ");//apaga seta anterior
        yapagar=ymenu;//salva a posicao da seta anterior para apagar apos mover
        gotoxy(xmenu, ymenu);//vai para nova posicao da seta
    }
    while(1);
}
