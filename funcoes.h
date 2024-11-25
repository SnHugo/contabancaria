/*
Autor: Hugo Cesar Fernandes de Macedo || Wesley Nobuyuki Waterkemper
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
} ContaBancaria;

// Movimentacao bancaria
typedef struct
{
    int sequencial;
    int cd_conta;
    char dt_movimento[11];
    char tp_movimentacao[15];
    char favorecido[30];
    double vl_movimento;
    double vl_saldo;
} MovimentacaoFinanceira;

// Ponteiro
typedef struct TipoConta *TipoApontadorConta;

// Estrutura para armazenar o conteúdo
typedef struct TipoConta
{
    ContaBancaria conteudo;
    TipoApontadorConta proximo;
} TipoConta;

// Estrutura para aterrar o ponteiro
typedef struct
{
    TipoApontadorConta Primeiro;
    TipoApontadorConta Ultimo;
} Lista_ContaBancaria;

typedef struct TipoMovimentacao *TipoApontadorMovi;

// Estrutura para armazenar a movimentação
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

// Funcao que posiciona o cursor na tela
void gotoxy(int x, int y);

// Estrutura principal da tela
void tela();

// Telas de Cadastro de Contas
void tela_CadastroDeContas(Lista_ContaBancaria *lista_contaBancaria);
void tela_digitacaoContas();
void tela_listagem();

// Telas de Movimentacao Financeira
void TelaMoviFinanceira(ListaMovimentacaoFinanceira *lista_movi_financeira, Lista_ContaBancaria *lista_conta_bancaria);
void TelaCadastroMovimentacao();

// Funcoes da Tela para posicionar os campos com espaco digitavel, sub telas, linhas e colunas com a tabela ASCCI
void ExibirCampoEDigitacaoContornado(int x, int y, char campo[100], int espaco_digitavel);
void ExibirCampoEContornoDigitavelAbaixo(int x, int y, char campo[100], int espaco_digitavel);
void ExibirCampoEContornoDigitavelFrente(int x, int y, char campo[100], int espaco_digitavel);
void CriarSubTela(int canto_superiorEsq_x, int canto_superiorEsq_y, int canto_inferiorDir_x, int canto_inferiorDir_y);
void ImprimirLinhaPorTamanho(int canto_esquerdo_x, int canto_direito_x, int linha);
void ImprimirColunaPorTamanho( int coluna, int linha_superior, int linha_inferior);

// Funcoes para iniciar as listas
void iniciar_lista(Lista_ContaBancaria *lista_contaBancaria, ListaMovimentacaoFinanceira *lista_movi_financeira);

// Funcoes cadastro
int contador(Lista_ContaBancaria *lista_contaBancaria);
TipoApontadorConta pesquisa(Lista_ContaBancaria *lista_contaBancaria, int codigo);
char *selecionar_tipo_conta();
void cadastrar_conta(Lista_ContaBancaria *lista_contaBancaria, int opc);
void remover_conta(Lista_ContaBancaria *lista_contaBancaria, int opc);
void alterar_dados(Lista_ContaBancaria *lista_contaBancaria);
void imprimir_Registro(ContaBancaria reg_conta);
void consultar_contas(Lista_ContaBancaria *lista_contaBancaria);
void exibir_contas_geral(Lista_ContaBancaria *lista_contaBancaria);
void consultar_ordem_alfabetica(Lista_ContaBancaria *lista_contaBancaria);
void consultar_conta_ordem_cd(Lista_ContaBancaria *lista_contaBancaria);

// Funcoes Movimentacao Financeira
void RealizarMovimentacao(ListaMovimentacaoFinanceira *lista_movi_financeira, Lista_ContaBancaria *lista_conta_bancaria);
TipoApontadorConta ValidarConta (Lista_ContaBancaria *lista_conta_bancaria);
char *ValidarTipoMovi();
double ValidarValorMovi (char *tipo_movi);
void SalvarMoviNaLista(ListaMovimentacaoFinanceira *lista_movi, TipoApontadorMovi pont_movi);

#endif