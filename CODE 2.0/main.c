#include "file.h"

//===================================Int Main===================================
int main ()
{
    int menu,save,sair,op;
    menuChad(); //(1)
    do
    {
        menu = menu1(); //(2)
        switch (menu)
        {
        case 1:
            save=menu2nome(); //(3)
            break;

        case 2:
            creditos(); //(7)
            break;

        case 3:
            ordem(); //(8)
            break;

            break;
        case 4:
            menu=sairMenu(); //(9)

            break;

        default:
            system("cls");
            printf("\nUse apenas numeros de 1~4\nAperte qualquer tecla para continuar\n");
            getchar();

        }
    }
    while(menu!=4);

    return 0;
    system("pause");
}

