
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "file.h"

char nome[10], rank[10];

int option, pontos, teste;

int a = 0 ;

void molduraMenuPrincipal()

{

    limparTela();

    printf("=======BEM-VINDO========\n");
    printf("========= AO ===========\n") ;
    printf("=====FORGE & EMPIRE ==== \n");

    printf("\nSelecione uma das opções para continuar:\n");
    printf("\n1 - Iniciar ");
    printf("\n2 - Jogador");
    printf("\n3 - Ranking");
    printf("\n4 - Créditos");
    printf("\n5 - Sair\n");
    printf("\nOpção selecionada:");



}

void iniciarMenu()
{
    limparTela();
    printf("EM CONSTRUCAO.......\n");
    getchar();
    getchar();
}

int jogadorMenu()
{
    char aux[24];
    int encon = -1, i;

    printf("Digite seu nome:");
    gets(aux);
    getchar();
    getchar();


    for(i = 0 ; i < a ; i++)
    {
        if(strcmp(aux,player[i].jogador)==0)
        {
            encon = i ;
            break ;

        }

    }


if (encon == -1)
{
    encon = a;
    strcpy(aux,player[encon].jogador);
    a++;

}
printf("\nDigite sua pontuação: ");
scanf("%d", &player[encon].pontos);
getchar();

int rankingMenu()
{
    limparTela();
    ranking org ;
    int i, j ;

    for (i=0; i<a-1; i++)
    {
        for (j=0; j<a-1; j++)
        {
            if (player[j].pontos < player[j+1].pontos)
            {

                org = player[j];
                player[j] = player[j+1];
                player[j+1] = org;

            }
        }
    }
}
void creditMenu()
{
    limparTela();
    printf("\t\t\t\t\t\t****CREDITOS****\n");
    printf("\t\t\t\t\t\t***EQUIPE 7-8 **\n\n");
    printf("\t***Bouchra***\t\t***Emilio***\t\t\t***Gustavo***\t\t\t***Humam***");
    getchar();
    getchar();

}

void molduraerro()
{
    limparTela();
    printf("OPCAO INVALIDA\n");
    printf("TENTE OUTRA TECLA\n");
    getchar();
    getchar();
}

void sairMenu()
{
    return 0 ;
}

void limparTela()
{
    system("cls");
}
