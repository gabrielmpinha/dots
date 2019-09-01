#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "gameplay.h"
#include "funcoesauxiliares.h"
#include "nomejogador.h"
#include "matrix.h"
#include "ranking.h"
#define seta_cima 72
#define seta_baixo 80
#define seta_esquerda 75
#define seta_direita 77
#define espaco 32
#define enter 13
#define esc 27
#define sim 1
#define nao 0

extern char tab[8][8];
extern const int linha;
extern const int coluna;
extern player jogador1, jogador2;

void jogo()
{
    //funcionamento do jogo
    int i, j;
    char movimento; //caractere usado para mover, marcar pontos e sair do jogo
    int counter=0;//resetar contador da ultima partida
    jogador1.pontos=0;//resetar pontos da ultima partida
    jogador2.pontos=0;
    i = 0;
    j = 1;
    gotoxy(j, i); //cursor iniciar na coordenada quando o jogo for iniciado
    ShowConsoleCursor(sim);//mostra o cursor do console na tela
    do//Loop infinito
    {
        //checar se jogo acabou
        if((jogador1.pontos + jogador2.pontos) == ((linha-1)/2)*((linha-1)/2))
        {
            ganhador();
            return;
        }

        //MOVIMENTACAO DO CURSOR
        //if(kbhit())
        {
            fflush(stdin);
            movimento = getch();//direcao do cursor wasd
            switch(movimento) //movimentacao do cursor
            {
            case 'w'://mover p cima
            case seta_cima:
                if(i%2==0 && j%2==1)//caso passe pelo meio do quadrado
                    i-=2;
                else
                    i--;
                break;
            case 's'://mover p baixo
            case seta_baixo:
                if(i%2==0 && j%2==1)
                    i+=2;
                else
                    i++;
                break;
            case 'a'://mover p esquerda
            case seta_esquerda:
                if(i%2==1 && j%2==0)//caso passe pelo meio do quadrado
                    j-=2;
                else
                    j--;

                break;
            case 'd'://mover p direita
            case seta_direita:
                if(i%2==1 && j%2==0)
                    j+=2;
                else
                    j++;

                break;
            case espaco: //tracos
            case enter:
                if(i%2==0 && j%2==1 && tab[i][j]==' ')
                {
                    tab[i][j]='-';
                    printf("%c", tab[i][j]);
                    checar_pontos(i,j, &counter);//checar se jogador fez pontos
                    trocar_turno(counter);//trocar turno para o proximo jogador
                }
                else if(i%2==1 && j%2==0 && tab[i][j]==' ')
                {
                    tab[i][j]='|';
                    printf("%c", tab[i][j]);
                    checar_pontos(i,j, &counter);
                    trocar_turno(counter);
                }
                break;
            case esc:
                return;
            }//FIM DO SWITCHtrocar_turno

            //correcao de posicao do jogador
            {
                if(i<0) //limite superior
                    i=linha-1;

                else if(i>=linha) //limite inferior
                    i=0;

                if(j<0) //limite da esquerda
                    j=coluna-1;

                else if(j>=coluna) //limite da direita
                    j=0;
            }
            gotoxy(j, i);//mover o cursor para a posicao escolhida pelo jogador
        }
    }
    while(1); //FIM DO LOOP
}

void checar_pontos(const int i_anterior, const int j_anterior, int *counter)
{
    //checa se um jogador fez ponto ao jogar
    int fez_ponto=nao;//reiniciar o valor de fez_ponto
    int i1, j1;
    //MARCACAO DE PONTUACAO DO JOGADOR
    for(i1=0; i1<(linha); i1++)
    {
        for(j1=0; j1<(coluna); j1++)
        {
            if(tab[i1][j1]=='|' && tab[i1][j1-2]=='|' && tab[i1-1][j1-1]=='-' && tab[i1+1][j1-1]=='-' && tab[i1][j1-1]==' ')
            {
                //checa se foi feito um quadrado/ponto

                if (*counter%2==0) //JOGADOR 1 FAZ PONTO
                {
                    textcolor(10);
                    jogador1.pontos++;
                    gotoxy(14, 2);
                    printf("JOGADOR 1(%s): %d pontos", jogador1.nome, jogador1.pontos);
                    tab[i1][j1-1]='1';
                }//FIM DO JOGADOR 1

                else if (*counter%2==1) //JOGADOR 2 FAZ PONTO
                {
                    textcolor(13);
                    jogador2.pontos++;
                    gotoxy(14, 4);
                    printf("JOGADOR 2(%s): %d pontos", jogador2.nome,  jogador2.pontos);
                    tab[i1][j1-1]='2';
                }//FIM DO JOGADOR 2
                gotoxy(j1-1, i1);//vai para a posicao do meio do quadrado para printar o ponto
                printf("%c", tab[i1][j1-1]);
                gotoxy(j_anterior, i_anterior);//volta para a posicao anterior do jogador
                fez_ponto=sim;//marca que foi feito algum ponto nessa rodada
            }
        }
    }
    if(fez_ponto==sim)//continuar no mesmo turno caso o jogador tenha feito ponto
        (*counter)+=2;
    else//ir para o proximo turno caso o jogador nao tenha feito ponto
        (*counter)++;
}

void trocar_turno(const int counter)
{
    //troca o turno apos jogada do jogador
    gotoxy(15, 0);
    if(counter%2==0)
    {
        textcolor(10);
        printf("*Turno de JOGADOR 1*");
    }
    else if(counter%2==1)
    {
        textcolor(13);
        printf("*Turno de JOGADOR 2*");
    }
}
