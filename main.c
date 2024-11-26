/*
Autor: Wesley Nobuyuki
Data: 20/10/2024

    Nome: Hugo Cesar Fernandes de Macedo        RA: 161548-2023
    Nome: Wesley Nobuyuki Tomimori Waterkemper  RA: 175944-2024

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

    Lista_ContaBancaria lista_conta = carregar_contas();
    ListaMovimentacaoFinanceira lista_movi_financeira = carregar_movim();

    do
    {
        tela();
        gotoxy(25, 10);
        printf("1. Cadastro de Contas");
        gotoxy(25, 12);
        printf("2. Movimentacao Financeira");
        gotoxy(25, 14);
        printf("3. Sair do Programa");
        gotoxy(07, 23);
        printf("Selecione uma opcao:");
        gotoxy(29, 23);
        fflush(stdin);
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            tela_CadastroDeContas(&lista_conta);
            break;
        case 2:
            TelaMoviFinanceira(&lista_movi_financeira, &lista_conta);
            break;
        case 3:
            exit;
        default:
            salvar_contas(&lista_conta);
            salvar_movi(&lista_movi_financeira);
            gotoxy(07, 23);
            printf("                                                                     ");
            gotoxy(07, 23);
            printf("Saindo...");
            getch();
        }
    } while (opcao != 3);

    return 0;
}