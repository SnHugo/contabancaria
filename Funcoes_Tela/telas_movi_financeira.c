/*
Autor: Wesley Nobuyuki Tomimori Waterkemper 
Data: 10/11/2024
Objetivo do trecho: Telas onde são trabalhadas as Movimentacoes Financeiras
*/

#include "C:\Users\User\Documents\Tudo em C\Estrutura de dados\funcoes.h"

void TelaMoviFinanceira(ListaMovimentacaoFinanceira *lista_movi_financeira, Lista_ContaBancaria *lista_conta_bancaria)
{
    int opcao;

    do
    {
        tela();
        gotoxy(17, 10);
        printf("1. Realizar Movimentacao (Debito e Credito)");
        gotoxy(17, 12);
        printf("2. Transferencia entre Contas Bancarias");
        gotoxy(17, 14);
        printf("3. Consultar Movimentacoes Bancarias");
        gotoxy(17, 16);
        printf("4. Voltar ao Menu Principal");
        gotoxy(8, 23);
        fflush(stdin);
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:
                RealizarMovimentacao(lista_movi_financeira, lista_conta_bancaria);
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
    gotoxy(18, 3);
    printf("    Realizacao De Movimentacao Financeira    ");
    
    // Campos da tela da Conta
    CriarSubTela(2, 5, 78, 17);
    ExibirCampoEContornoDigitavelFrente(4, 7, "Sequencial.:", 12);
    ExibirCampoEContornoDigitavelFrente(31, 7, "Codigo.:", 2);
    ExibirCampoEContornoDigitavelFrente(55, 7, "Data.:", 12);
    ExibirCampoEContornoDigitavelFrente(4, 10, "Banco.:", 20);
    ExibirCampoEContornoDigitavelFrente(34, 10, "Agencia:", 6);
    ExibirCampoEContornoDigitavelFrente(51, 10, "Tipo Conta:", 14);
    ExibirCampoEContornoDigitavelFrente(4, 13, "Num. Conta:", 8);
    ExibirCampoEContornoDigitavelFrente(28, 13, "Saldo:", 12);
    ExibirCampoEContornoDigitavelFrente(50, 13, "Limite:", 12);
    gotoxy(4, 16);
    printf("Saldo Total (Saldo + Limite):");

    // Campos da tela Inferior
    // CriarSubTela(2, 18, 78, 21);
    gotoxy(3, 18);
    printf("Tipo Movimentacao.:");
    gotoxy(3, 19);
    printf("Favorecido........:");
    gotoxy(3, 20);
    printf("Valor Movimentacao:");
    gotoxy(3, 21);
    printf("Novo saldo........:");
}

void TelaExibirMovimentacoes()
{
    tela();
    gotoxy(18, 3);
    printf("    Consulta da Movimentacao Financeira    ");
    gotoxy(2, 5);
    printf("Codigo:");
    // gotoxy(10, 5);
    // printf("%d", 10);
    // gotoxy(13, 5);
    // printf("Banco do Brazil");
    gotoxy(33, 5);
    printf("Agenc:");
    // gotoxy(40, 5);
    // printf("1234-5");
    gotoxy(47, 5);
    printf("Cta:");
    // gotoxy(52, 5);
    // printf("123456-1");
    gotoxy(61, 5);
    printf("Tp:");
    // gotoxy(65, 5);
    // printf("Cartao Credito");

    ImprimirLinhaPorTamanho(1, 79, 6);
    ImprimirColunaPorTamanho(12, 4, 6);
    ImprimirColunaPorTamanho(32, 4, 6);
    ImprimirColunaPorTamanho(46, 4, 6);
    ImprimirColunaPorTamanho(60, 4, 6);

    gotoxy(3, 7);
    printf("Data Movi.");
    gotoxy(16, 7);
    printf("Favorecido");
    gotoxy(38, 7);
    printf("Tipo Movi.");
    gotoxy(54, 7);
    printf("Valor Movi.");
    gotoxy(67, 7);
    printf("Valor Saldo");

    ImprimirLinhaPorTamanho(2, 14, 8);
    ImprimirLinhaPorTamanho(15, 36, 8);
    ImprimirLinhaPorTamanho(37, 52, 8);
    ImprimirLinhaPorTamanho(53, 65, 8);
    ImprimirLinhaPorTamanho(66, 78, 8);
}