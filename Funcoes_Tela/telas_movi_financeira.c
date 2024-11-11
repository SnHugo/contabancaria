/*
Autor: Wesley Nobuyuki 
Data: 10/11/2024
Objetivo do trecho: 
*/

#include "C:\Trabalho_ContaBancaria\funcoes.h"


void TelaMoviFinanceira(ListaMovimentacaoFinanceira *lista_movi_financeira)
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

void TelaCadastroMovimentacao()
{
    tela();
    gotoxy(31, 6);
    printf("MOVIMENTACAO FINANCEIRA");
    CriarSubTela(9, 7, 72, 21);
    ImprimirLinhaPorTamanho(9, 72, 11);
    ExibirCampoEContornoDigitavelFrente(12, 9, "Sequencial:", 6);
    ExibirCampoEContornoDigitavelFrente(35, 9, "Codigo:", 6);
    ExibirCampoEContornoDigitavelFrente(53, 9, "Data:", 11);
    ExibirCampoEContornoDigitavelAbaixo(12, 13, "Tipo Movimentacao:", 19);
    ExibirCampoEContornoDigitavelAbaixo(33, 13, "Valor Movimentado:", 19);
    ExibirCampoEDigitacaoContornado(13, 19, "Saldo Atual:", 10);
    getch();
}