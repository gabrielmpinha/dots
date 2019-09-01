#include <stdio.h>
#include <stdlib.h>
#include "funcoesauxiliares.h"
#include "menu.h"
void instrucao()
{
    textcolor(15);
    printf("\t->Esse eh um jogo de 2 jogadores, em que existe um conjunto de pontos\n\tno qual os jogadores colocam tracos alternadamente entre esses pontos\n\tcom o objetivo de formar quadrados.\n\n");
    printf("\t->Quando um jogador completa um quadrado, ele deve jogar novamente.\n");
    printf("\t->O jogo encerra quando todos os quadrados forem preenchidos.\n");
    textcolor(14);
    printf("\n\t->Controle o cursor com wasd ou setas e insira os tracos com barra de espaco ou enter\n");
    textcolor(15);
    printf("\t->Nao eh permitido colocar tracos dentro de quadrados\n");
    printf("\t->Pontuacoes sao feitas apenas com formacao de quadrados de 4 linhas\n\n");
    textcolor(14);
    printf("\t->Caso queira sair durante o jogo aperte ESC\n\n");
}
