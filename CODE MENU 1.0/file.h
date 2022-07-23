#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED

typedef struct
{
    char jogador[24];
    int pontos;

} ranking;

ranking player[10];


void molduraMenuPrincipal(void);
void iniciarMenu(void);
int jogadorMenu();
int rankingMenu();
void creditMenu(void);
void molduraerro(void);

void sairMenu(void);
void limparTela(void);


#endif // FILE_H_INCLUDED




