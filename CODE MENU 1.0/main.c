#include <stdio.h>

#include <stdlib.h>

#include <locale.h>

#include <string.h>

#include "file.h"

int main()
{
    setlocale (LC_ALL,"");

    char nome[10], rank[10] ;

    int option, pontos, teste;

    do
    {
        molduraMenuPrincipal();
        scanf("%d",&option);

        // system("cls") -> limpar a tela antes de executar um novo comando
        // fflush(stdin) -> limpar o buffer antes de executar uma nova string ou caractere


        switch(option)
        {

        case 1:
            limparTela();
            iniciarMenu();
            break;

        case 2:
            limparTela();
            jogadorMenu();
            getchar();


            break;

        case 3:
            limparTela();
            rankingMenu();
            break;

        case 4:
            limparTela();
            creditMenu();
            break;

        case 5:
            //Sair do programa
            sairMenu();
            break;

        default: //Caso ele aperte qualquer outra opcao ai o programa vai executa os comandos listados
            molduraerro();



        }
    }
    while(option != 5 );
    return 0;
}
