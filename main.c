<<<<<<< HEAD
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "funcoes.h"

=======
/*
Autor: Wesley Nobuyuki 
Data: 20/10/2024
Objetivo do trecho: Declaração da função main integrando o controle do usuário
*/

#include "funcoes.h"


>>>>>>> a88c15a59a68085d21ed026fa784e14f33c2aa71
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = (short)x;
    coord.Y = (short)y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main()
{
    int opcao;
<<<<<<< HEAD
=======

    Lista_ContaBancaria lista;
    ListaMovimentacaoFinanceira lista_movi_financeira;

    iniciar_lista(&lista, &lista_movi_financeira);
>>>>>>> a88c15a59a68085d21ed026fa784e14f33c2aa71
    
    do
    {
        tela();
        gotoxy(25, 10);
        printf("1. Cadastro de Contas.");
        gotoxy(25, 12);
        printf("2. Movimentacao Financeira.");
        gotoxy(25, 14);
        printf("3. Sair.");
        gotoxy(8, 23);
        printf("Selecione uma opcao:");
        gotoxy(29, 23);
        fflush(stdin);
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:
<<<<<<< HEAD
                tela_CadastroDeContas();
                break;
            case 2:
                tela_MovimentacaoFinanceira();
=======
                tela_cadastroDeContas(&lista);
                break;
            case 2:
                TelaMoviFinanceira(&lista_movi_financeira);
>>>>>>> a88c15a59a68085d21ed026fa784e14f33c2aa71
                break;
            case 3:
                break;
            default:
                gotoxy(8, 23);
                printf("                                                                     ");
                gotoxy(8, 23);
                printf("Opcao Invalida!!!");
                getch();
        }
    }while (opcao != 3);

    return 0;
}