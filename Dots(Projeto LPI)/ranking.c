#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "ranking.h"
#include "nomejogador.h"
#include "funcoesauxiliares.h"
extern player jogador1, jogador2;
void ganhador()
{
    //tela de vitoria e salvar no arquivo do ranking o vencedor
    FILE *ranking;//criar file
    system("MODE con: cols=45 lines=30");
    system("cls");
    ranking = fopen("pontos.dados", "ab");//abrir o arquivo
    if (ranking == NULL)//caso de erro no arquivo
    {
        printf("\nErro no arquivo ");
        system("pause");
        exit(-1);
    }

    else
    {
        gotoxy(3, 10);
        textcolor(14);
        printf("!!!!!!!!!!!!!!FIM DE JOGO!!!!!!!!!!!!!!");
        gotoxy(10,13);
        if(jogador1.pontos>jogador2.pontos)//jogador1 ganha
        {
            fwrite(&jogador1,sizeof(player),1,ranking);//escrever pontuacao do jogador 1 no file
            textcolor(10);
            printf("%s GANHOU!!!!", jogador1.nome);
        }
        else if(jogador2.pontos > jogador1.pontos)//jogador2 ganha
        {
            fwrite(&jogador2,sizeof(player),1,ranking);
            textcolor(13);
            printf("%s GANHOU!!!!", jogador2.nome);
        }
        {
            //printar a pontucao de cada jogador na rodada
            gotoxy(10,15);
            textcolor(10);
            printf("%s: %d pontos", jogador1.nome, jogador1.pontos);
            gotoxy(10,16);
            textcolor(13);
            printf("%s: %d pontos\n\n", jogador2.nome, jogador2.pontos);
            textcolor(4);
            system("pause");
        }
        fclose(ranking);//fechar arquivo
    }
}
void rankingler()
{
    //ler e mostrar o ranking
    player winner;
    FILE *ler; //ponteiro file
    textcolor(3);
    printf("\t->PONTUACAO DOS JOGADORES<-\n\n");
    ler = fopen("pontos.dados", "rb");//abrir arquivo
    while((fread(&winner,sizeof(player),1,ler)) != 0) //loop para printar ate terminar de varrer o arquivo
    {
        printf("%s ---> %d pontos\n\n",winner.nome,winner.pontos);
    }
    fclose(ler);//fechar arquivo
}

