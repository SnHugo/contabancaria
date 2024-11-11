/*
Autor: Hugo Cesar Fernandes de Macedo
Data: 24/10/2024
Objetivo do trecho: Criar as demais structs para criação de contas bancárias e movimentação
*/

#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

// Estrutura typedef
typedef struct
{
    int cd_conta;
    char banco[50];
    char agencia[10];
    char numero_conta[20];
    char tipo_conta[20];
    double vl_saldo;
    double vl_limite;
    char status[10];
} conta_bancaria;

// Movimentacao bancaria
typedef struct
{
    int sequencial;
    int cd_conta;
    char dt_movimento[11];
    char tp_movimentacao[15];
    double vl_movimento;
    double vl_limite;
    char status[10];
} MovimentacaoFinanceira;



// Ponteiro
typedef struct ContaBancaria *TipoApontador;

// Estrutura para armazenar o conteudo
typedef struct ContaBancaria
{
    conta_bancaria conteudo;
    TipoApontador proximo;
} ContaBancaria;

// Estrutura para aterrar o ponteiro
typedef struct
{
    TipoApontador Primeiro;
    TipoApontador Ultimo;
} Lista_ContaBancaria;



typedef struct TipoMovimentacao *TipoApontadorMovi;

typedef struct TipoMovimentacao
{
    MovimentacaoFinanceira conteudo_movi;
    TipoApontadorMovi anterior;
    TipoApontadorMovi proximo;
}TipoMovimentacao;

typedef struct
{
    TipoApontadorMovi Primeiro;
    TipoApontadorMovi Ultimo;
}ListaMovimentacaoFinanceira;

// Pasta telas
// Telas de Cadastro de Contas
void gotoxy(int x, int y);
void tela();
void tela_cadastroDeContas(Lista_ContaBancaria *lista_contaBancaria);
void tela_digitacaoContas();
void tela_contasCadastradas(conta_bancaria reg_conta, int proximaLinha);

// Telas de Movimentacao Financeira
void TelaMoviFinanceira(ListaMovimentacaoFinanceira *lista_movi_financeira);

// Funcoes para posicionar os campos com espaco digitavel
void ExibirCampoEDigitacaoContornado(int x, int y, char campo[100], int espaco_digitavel);
void ExibirCampoEContornoDigitavelAbaixo(int x, int y, char campo[100], int espaco_digitavel);
void ExibirCampoEContornoDigitavelFrente(int x, int y, char campo[100], int espaco_digitavel);
void CriarSubTela(int canto_superiorEsq_x, int canto_superiorEsq_y, int canto_inferiorDir_x, int canto_inferiorDir_y);
void ImprimirLinhaPorTamanho(int canto_esquerdo_x, int canto_direito_x, int linha);

// Funcoes para iniciar as listas
void iniciar_lista(Lista_ContaBancaria *lista_contaBancaria, ListaMovimentacaoFinanceira *lista_movi_financeira);


// Funcoes cadastro
int contador(Lista_ContaBancaria *lista_contaBancaria);
TipoApontador pesquisa(Lista_ContaBancaria *lista_contaBancaria, int codigo);

void cadastrar_conta(Lista_ContaBancaria *lista_contaBancaria, int opc);
void imprimir_listaDasContasBancarias(Lista_ContaBancaria *lista_contaBancaria);


void RealizarMovimentacao(ListaMovimentacaoFinanceira *lista_movimentacao, MovimentacaoFinanceira reg_movimentacao);


#endif