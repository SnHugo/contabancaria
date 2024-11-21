<<<<<<< HEAD

#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "funcoes.h"

=======
>>>>>>> 4c8230c3df9d56e1507a83a6fc44c263060dae3d
/*
Autor: Wesley Nobuyuki 
Data: 20/10/2024
Objetivo do trecho: Declaração da função main integrando o controle do usuário
*/

#include "funcoes.h"


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
>>>>>>> 4c8230c3df9d56e1507a83a6fc44c263060dae3d

    Lista_ContaBancaria lista;
    ListaMovimentacaoFinanceira lista_movi_financeira;

    iniciar_lista(&lista, &lista_movi_financeira);

    
    do
    {
        tela();
        gotoxy(25, 10);
        printf("1. Cadastro de Contas");
        gotoxy(25, 12);
        printf("2. Movimentacao Financeira");
        gotoxy(25, 14);
        printf("3. Sair do Programa");
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

                tela_cadastroDeContas(&lista);
                break;
            case 2:
                TelaMoviFinanceira(&lista_movi_financeira);

=======
                tela_CadastroDeContas(&lista);
                break;
            case 2:
                // if (contador(&lista) == 0)
                // {
                //     gotoxy(8, 23);
                //     printf("Erro: Necessario ter pelo menos uma Conta Bancaria!!!");
                //     getch();
                // }
                // else
                // {
                        TelaMoviFinanceira(&lista_movi_financeira, &lista);
                // }
>>>>>>> 4c8230c3df9d56e1507a83a6fc44c263060dae3d
                break;
            case 3:
                exit;
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