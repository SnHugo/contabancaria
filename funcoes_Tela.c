/*
Autor: Hugo Cesar Fernandes de Macedo
Data: 27/10/2024
Objetivo do trecho: Implementando as funções tela para cada funcionalidade do algoritmo
*/
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
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

void tela_cadastroDeContas(Lista_ContaBancaria *lista_contaBancaria)
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
                cadastrar_conta(lista_contaBancaria, opcao);
                break;
            case 2:
                cadastrar_conta(lista_contaBancaria, opcao);
                break;
            case 3:
                imprimir_listaDasContasBancarias(lista_contaBancaria);
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

void tela_movimentacaoFinanceira()
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

void tela_digitacaoContas()
{
    tela();
    gotoxy(8, 23);
    printf("Digite 0 para sair");
    gotoxy(10, 6);
    printf("Codigo.........:");
    gotoxy(10, 8);
    printf("1-Banco........:");
    gotoxy(10, 10);
    printf("2-Agencia......:");
    gotoxy(10, 12);
    printf("3-Numero Conta.:");
    gotoxy(10, 14);
    printf("4-Tipo da Conta:");
    gotoxy(10, 16);
    printf("5-Saldo........:");
    gotoxy(10, 18);
    printf("6-Limite.......:");
    gotoxy(10, 20);
    printf("7-Status.......:");
}

void tela_contasCadastradas(conta_bancaria reg_conta, int proximaLinha)
{
    tela();
    gotoxy(3, 6);
    printf("+");
    gotoxy(77, 6);
    printf("+");
    gotoxy(3, 20);
    printf("+");
    gotoxy(77, 20);
    printf("+");

    for (int coluna = 4; coluna <= 76; coluna++)
    {
        gotoxy(coluna, 6);
        printf("-");
        gotoxy(coluna, 20);
        printf("-");
    }

    for (int linha = 7; linha <= 19; linha++)
    {
        gotoxy(3, linha);
        printf("|");
        gotoxy(77, linha);
        printf("|");
    }

    gotoxy(5, 7);
    printf("Codigo: %d", reg_conta.cd_conta);
    gotoxy(5, 9);
    printf("Banco.: %s", reg_conta.banco);
    gotoxy(64, 9);
    printf("Agencia: %s", reg_conta.agencia);
    gotoxy(5, 11);
    printf("N. da Conta: %s", reg_conta.numero_conta);
    gotoxy(39, 11);
    printf("Tipo Conta: %s", reg_conta.tipo_conta);
    gotoxy(5, 13);
    printf("Saldo Atual: %lf", reg_conta.vl_saldo);
    gotoxy(38, 13);
    printf("Limite: %lf", reg_conta.vl_limite);
    gotoxy(60, 13);
    printf("Status: %s", reg_conta.status);
    getch();
}
