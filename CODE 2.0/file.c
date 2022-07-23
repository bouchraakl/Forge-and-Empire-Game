#include "file.h"
typedef struct
{
    char jogador[20];
    int pontuacao;
} rank;
rank ranking[3]; //armazendando nome e pontuacao

rank aux[1]; //auxiliar para ordenar
//\-\-\-\-\--\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\//
//\-\-\-\-\--\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\//
void menuChad()
{
    int aux;

    FILE *pf; // declaração do arquivo

    pf = fopen("menu1.txt","r"); //cria o arquivo como leitura

    if (pf == NULL) // caso o arquivo nao exista ou coisas adversas
    {
        printf ("Erro ao abrir arquivo");
        exit(1);
    }
    for(int i=0; i<3; i++)
    {   // se novo jogador esta em branco, reseta e aloca pontuacao 0
        snprintf(ranking[i].jogador,20,"Novo Jogo");
        ranking[i].pontuacao = 0;
        fscanf(pf,"%s %i \n",ranking[i].jogador,&ranking[i].pontuacao); // retira do arquivo o nome e sua pontuacao
    }
    fclose(pf);// fecha o arquivo
}
//\-\-\-\-\--\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\//
//\-\-\-\-\--\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\//
int menu1(void)
{
    int menu;
    system("cls");
    printf("\t FORGE & EMPIRE \n");
    printf("\t1-->Jogar\n\t2-->Creditos\n\t3-->Ranking\n\t4-->Sair\n");
    scanf("%i",&menu);

    return menu;
}
//\-\-\-\-\--\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\//
//\-\-\-\-\--\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\//
int menu2nome(void)
{
    int armazen; //inteira armazena
    system("cls");
    for (int i=0; i<3; i++)  // printa o jogador, o nome, a pont.
    {
        printf ("%i- %s     %i Pontos\n",i+1,ranking[i].jogador,ranking[i].pontuacao); //se vazio" Novo Jogador//
    }
    printf ("\n4-->Adicionar Jogador\n");

    scanf ("%i",&armazen); //utilizada pra selecionar o nome ou um novo
    system("cls");
    switch (armazen)
    {
    case 1:
        nomes(armazen);
        break;
    case 2:
        nomes(armazen);
        break;
    case 3:
        nomes(armazen);
        break;
    case 4:
        adicJogador();
        break;
    }
    return armazen;
}
//\-\-\-\-\--\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\//
//\-\-\-\-\--\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\//
void nomes(int a)
{
    char nome_jogador[20];
    //verifica se ja tem jogo salvo
    if(strcmp(ranking[a-1].jogador,"Novo Jogo")==0)
    {
        getchar();
        printf("Digite seu primeiro nome: ");
        fflush(stdin);
        gets(nome_jogador);

        printf ("Digite sua pontuacao: ");
        scanf ("%i",&ranking[a-1].pontuacao); //verifica se a alguem com esse nome salvo

        for(int i=0; i<3; i++)
        {
            if(strcmp(nome_jogador,ranking[i].jogador)==0) //modificar apenas a pontucao do nome salvo
            {
                printf("O Jogador já existe...");
                printf("substituindo os dados...");
                getchar();
                getchar();
                ranking[i].pontuacao = ranking[a-1].pontuacao; //pontuacao nova recebe os dados
                ranking[a-1].pontuacao = 0; //zera a antiga
            }
        }
        if (strcmp(nome_jogador,ranking[0].jogador) //salvando os dados
            !=0&&strcmp(nome_jogador,ranking[1].jogador) // se nao ouver nome repetido
            !=0&&strcmp(nome_jogador,ranking[2].jogador)!=0)
        {
            snprintf(ranking[a-1].jogador,20,nome_jogador); //guarda os caracteres do array
        }
    }
}
//\-\-\-\-\--\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\//
//\-\-\-\-\--\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\//
void adicJogador()
{
    ordem();
    int a;
    char nome_jogador[20];
    printf("Digite seu nome: ");//pede o nome
    getchar(); //pra n bugar<3
    gets(nome_jogador);//armazena

    printf ("Digite sua pontuacao: ");//pede pontos
    scanf ("%i",&a);//armazena no int a

    for(int i=0; i<3; i++)
    {
        if(strcmp(nome_jogador,ranking[i].jogador)==0) //comparando se o jogador ja existe
        {
            printf("Jogador ja existe...");
            printf("substituindo pontos...");
            getchar();
            getchar();
            ranking[i].pontuacao = a; //substitue pra nova pontuação se for
        }
    }
    if (strcmp(nome_jogador,ranking[0].jogador) //se nao é existente ele armazena
        !=0&&strcmp(nome_jogador,ranking[1].jogador) //o nome e a pontucao na pontucao mais baixa
        !=0&&strcmp(nome_jogador,ranking[2].jogador)!=0)
    {
        snprintf(ranking[2].jogador,20,nome_jogador);
        ranking[2].pontuacao = a;
    }
}
//\-\-\-\-\--\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\//
//\-\-\-\-\--\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\//
void ordem(void)//pra ordenar conforme a pontuacao
{
    system("cls");//limpa a tela

    for (int i=0; i<3; i++)
    {
        if (strcmp(ranking[i].jogador,"Novo Jogo")!=0) //verifica se existe uma pontuacao pra ordenar
        {
        for (int x=0; x<3; x++)
        {
            for (int y=0; y<3; y++)
            {
            if (ranking[y].pontuacao<ranking[x].pontuacao)//verifica qual é maior
            {
                aux[0]=ranking[y];
                ranking[y]=ranking[x]; //troca os valores com base no tamanho
                ranking[x]=aux[0];
            }
            }
        }
        }
    }
    for(int i=0; i<3; i++)
    {
        printf ("%i - %s: %i pontos\n",i+1,ranking[i].jogador,ranking[i].pontuacao); //printa o resultado
    }
    sleep(3);
}
//\-\-\-\-\--\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\//
//\-\-\-\-\--\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\//
int sairMenu()
{
    system("cls");
    int sair, menu;

    printf ("\tQuer sair?\n1-sim ||2-nao\n");
    scanf ("%i",&sair);

    if (sair==1)
    {
        cria_arq(); //salva os dados no arquivo
    }
    else if (sair==2)
    {
        menu=5; //variavel menu recebe 5
    }
    else
    {
        printf ("opcao invalida\n");
        getchar();
        menu=5;
    }
    return menu;
}
//\-\-\-\-\--\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\//
//\-\-\-\-\--\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\//
void  cria_arq()
{

    FILE *pf;
    pf = fopen("menu1.txt","w");//criar no final so pra salvar

    if (pf == NULL)
    {
        printf ("Erro ao abrir arquivo");
        exit (1);
    }
    for(int i=0; i<3; i++)
    {
        fprintf (pf,"%s\t%i\n",ranking[i].jogador,ranking[i].pontuacao); //armazena os novos valores
    }
    fclose(pf);
}
void creditos(){
    int op;
system("cls");
printf("\t\t\t\tEquipe 7&8\n");
printf("\t Emilio\n");
printf("\t Boushra\n");
printf("\t Gustavo \n");
printf("\t Bruna \n");
printf("\t Homam \n");
printf("\t 5- sair");
scanf("%i",&op);
if(op==5)
    {
        system("cls");
    }
    return op;

}
