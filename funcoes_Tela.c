#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "funcoes.h"

// Montar a tela
void tela()
{
    int t;
    system("cls");
    gotoxy(01, 01);
    printf("+-----------------------------------------------------------------------------+");
    gotoxy(01, 02);
    printf("| UNICV");
    gotoxy(60, 02);
    printf("Estrutura de Dados |");
    gotoxy(66, 03);
    printf("Prof. Rodney");
    gotoxy(01, 03);
    printf("|");
    gotoxy(20, 02);
    printf("Alocamento de Contas Bancarias");
    gotoxy(79, 03);
    printf("|");
    gotoxy(01, 04);
    printf("+-----------------------------------------------------------------------------+");
    for (t = 5; t < 24; t++)
    {
        gotoxy(01, t);
        printf("|");
        gotoxy(79, t);
        printf("|");
    }
    gotoxy(01, 22);
    printf("+-----------------------------------------------------------------------------+");
    gotoxy(02, 23);
    printf("MSG.:");
    gotoxy(01, 24);
    printf("+-----------------------------------------------------------------------------+");
}

void tela_CadastroDeContas()
{
    int opcao;

    do
    {
        tela();
        gotoxy(25, 9);
        printf("1. Incluir conta.");
        gotoxy(25, 11);
        printf("2. Alterar Conta.");
        gotoxy(25, 13);
        printf("3. Consulta Conta.");
        gotoxy(25, 15);
        printf("4. Remover Conta");
        gotoxy(25, 17);
        printf("5. Voltar ao Menu Principal");
        gotoxy(8, 23);
        fflush(stdin);
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            default:
                gotoxy(8, 23);
                printf("                                                                     ");
                gotoxy(8, 23);
                printf("Opcao Invalida!!!");
                getch();
        }
    }while (opcao != 5);
}

void tela_MovimentacaoFinanceira()
{
    int opcao;

    do
    {
        tela();
        gotoxy(25, 10);
        printf("1. Registrar Entradas.");
        gotoxy(25, 12);
        printf("2. Registrar Saida");
        gotoxy(25, 14);
        printf("3. Consultar Movimentacao.");
        gotoxy(25, 16);
        printf("4. Voltar ao Menu Principal.");
        gotoxy(8, 23);
        fflush(stdin);
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            default:
                gotoxy(8, 23);
                printf("                                                                     ");
                gotoxy(8, 23);
                printf("Opcao Invalida!!!");
                getch();
        }
    }while (opcao != 4);
}
