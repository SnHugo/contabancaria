/*
Autor: Hugo Cesar Fernandes de Macedo
Data: 27/10/2024
Objetivo do trecho: Implementando as funções tela para cada funcionalidade do algoritmo
*/

#include "C:\Trabalho_ControleBancario\funcoes.h"

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

void tela_CadastroDeContas(Lista_ContaBancaria *lista_contaBancaria)
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
                // imprimir_listaDasContasBancarias(lista_contaBancaria);
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


void ExibirCampoEDigitacaoContornado(int x, int y, char campo[100], int espaco_digitavel)
{
    int quantidade = strlen(campo);
    int coluna_esquerda = x - 1;
    int coluna_direita = x + quantidade + espaco_digitavel + 1;

    gotoxy(coluna_esquerda, y - 1);
    printf("%c", 218);
    gotoxy(coluna_esquerda, y);
    printf("%c", 179);
    gotoxy(coluna_esquerda, y + 1);
    printf("%c", 192);

    for (int coluna = x; coluna < coluna_direita; coluna++)
    {
        gotoxy(coluna, y - 1);
        printf("%c", 196);
        gotoxy(coluna, y + 1);
        printf("%c", 196);
    }

    gotoxy(coluna_direita, y - 1);
    printf("%c", 191);
    gotoxy(coluna_direita, y);
    printf("%c", 179);
    gotoxy(coluna_direita, y + 1);
    printf("%c", 217);

    gotoxy(x, y);
    printf("%s", campo);
}

void ExibirCampoEContornoDigitavelAbaixo(int x, int y, char campo[100], int espaco_digitavel)
{
    // int quantidade = strlen(campo);
    int coluna_direita = x + espaco_digitavel + 1;

    gotoxy(x, y);
    printf("%s", campo);

    gotoxy(x, y + 1);
    printf("%c", 218);
    gotoxy(x, y + 2);
    printf("%c", 179);
    gotoxy(x, y + 3);
    printf("%c", 192);

    for (int coluna = x + 1; coluna < coluna_direita; coluna++)
    {
        gotoxy(coluna, y + 1);
        printf("%c", 196);
        gotoxy(coluna, y + 3);
        printf("%c", 196);
    }

    gotoxy(coluna_direita, y + 1);
    printf("%c", 191);
    gotoxy(coluna_direita, y + 2);
    printf("%c", 179);
    gotoxy(coluna_direita, y + 3);
    printf("%c", 217);
}

void ExibirCampoEContornoDigitavelFrente(int x, int y, char campo[100], int espaco_digitavel)
{
    int quantidade = strlen(campo);
    int coluna_esquerda = x + quantidade;
    int coluna_direita = x + espaco_digitavel + quantidade + 1;

    gotoxy(x, y);
    printf("%s", campo);

    gotoxy(coluna_esquerda, y - 1);
    printf("%c", 218);
    gotoxy(coluna_esquerda, y);
    printf("%c", 179);
    gotoxy(coluna_esquerda, y + 1);
    printf("%c", 192);

    for (int coluna = coluna_esquerda + 1; coluna < coluna_direita; coluna++)
    {
        gotoxy(coluna, y -1);
        printf("%c", 196);
        gotoxy(coluna, y + 1);
        printf("%c", 196);
    }

    gotoxy(coluna_direita, y - 1);
    printf("%c", 191);
    gotoxy(coluna_direita, y);
    printf("%c", 179);
    gotoxy(coluna_direita, y + 1);
    printf("%c", 217);
}

// Coloca as coordenadas do canto superior esquerdo da tela, até o canto inferior direito, para indicar o tamanho
void CriarSubTela(int canto_superiorEsq_x, int canto_superiorEsq_y, int canto_inferiorDir_x, int canto_inferiorDir_y)
{
    gotoxy(canto_superiorEsq_x, canto_superiorEsq_y);
    printf("%c", 218);
    gotoxy(canto_superiorEsq_x, canto_inferiorDir_y);
    printf("%c", 192);

    for (int linha = canto_superiorEsq_y + 1; linha < canto_inferiorDir_y; linha++)
    {
        gotoxy(canto_superiorEsq_x, linha);
        printf("%c", 179);
        gotoxy(canto_inferiorDir_x, linha);
        printf("%c", 179);
    }

    for (int coluna = canto_superiorEsq_x + 1; coluna < canto_inferiorDir_x; coluna++)
    {
        gotoxy(coluna, canto_superiorEsq_y);
        printf("%c", 196);
        gotoxy(coluna, canto_inferiorDir_y);
        printf("%c", 196);
    }

    gotoxy(canto_inferiorDir_x, canto_superiorEsq_y);
    printf("%c", 191);
    gotoxy(canto_inferiorDir_x, canto_inferiorDir_y);
    printf("%c", 217);
}

void ImprimirLinhaPorTamanho(int canto_esquerdo_x, int canto_direito_x, int linha)
{
    gotoxy(canto_esquerdo_x, linha);
    printf("%c", 195);

    for (int tam_linha = canto_esquerdo_x + 1; tam_linha < canto_direito_x; tam_linha++)
    {
        gotoxy(tam_linha, linha);
        printf("%c", 196);
    }

    gotoxy(canto_direito_x, linha);
    printf("%c", 180);
}

void ImprimirColunaPorTamanho( int coluna, int linha_superior, int linha_inferior)
{
    gotoxy(coluna, linha_superior);
    printf("%c", 194);

    for (int linha = linha_superior + 1; linha < linha_inferior; linha++)
    {
        gotoxy(coluna, linha);
        printf("%c", 179);
    }

    gotoxy(coluna, linha_inferior);
    printf("%c", 193);
}

void LimparMensagem()
{
    gotoxy(8, 23);
    printf("                                                                      ");
}

void LimparPosicaoNaTela(int canto_supEsq_x, int canto_supEsq_y, int canto_infDir_x, int canto_infDir_y)
{
    for (int linha = canto_supEsq_y; linha <= canto_infDir_y; linha++)
    {
        for (int coluna = canto_supEsq_x; coluna <= canto_infDir_x; coluna++)
        {
            gotoxy(coluna, linha);
            printf(" ");
        }
    }
}