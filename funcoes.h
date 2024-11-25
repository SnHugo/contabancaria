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
    char favorecido[30];
    double vl_movimento;
    double vl_saldo;
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

// Funcao que posiciona o cursor na tela
void gotoxy(int x, int y);

// Estrutura principal da tela
void tela();

// Telas de Cadastro de Contas
void tela_CadastroDeContas(Lista_ContaBancaria *lista_contaBancaria);
void tela_digitacaoContas();
void tela_contasCadastradas(conta_bancaria reg_conta, int proximaLinha);



// Telas de Movimentacao Financeira
void TelaMoviFinanceira(ListaMovimentacaoFinanceira *lista_movi_financeira, Lista_ContaBancaria *lista_conta_bancaria);
void TelaCadastroMovimentacao();
void TelaExibirContaDasMovimentacoes();
void TelaExibirMovimentacoesCadastradas(TipoApontadorMovi reg_movi, int linha);

// Funcoes da Tela para posicionar os campos com espaco digitavel, sub telas, linhas e colunas com a tabela ASCCI
void ExibirCampoEDigitacaoContornado(int x, int y, char campo[100], int espaco_digitavel);
void ExibirCampoEContornoDigitavelAbaixo(int x, int y, char campo[100], int espaco_digitavel);
void ExibirCampoEContornoDigitavelFrente(int x, int y, char campo[100], int espaco_digitavel);
void CriarSubTela(int canto_superiorEsq_x, int canto_superiorEsq_y, int canto_inferiorDir_x, int canto_inferiorDir_y);
void ImprimirLinhaPorTamanho(int canto_esquerdo_x, int canto_direito_x, int linha);
void ImprimirColunaPorTamanho( int coluna, int linha_superior, int linha_inferior);
void LimparMensagem();
void LimparPosicaoNaTela(int canto_supEsq_x, int canto_supEsq_y, int canto_infDir_x, int canto_infDir_y);




// Funcoes para iniciar as listas
void iniciar_lista(Lista_ContaBancaria *lista_contaBancaria, ListaMovimentacaoFinanceira *lista_movi_financeira);



// Funcoes cadastro
int contador(Lista_ContaBancaria *lista_contaBancaria);
TipoApontador pesquisa(Lista_ContaBancaria *lista_contaBancaria, int codigo);
char *selecionar_tipo_conta();
void cadastrar_conta(Lista_ContaBancaria *lista_contaBancaria, int opc);


// Funcoes Movimentacao Financeira
void RealizarMovimentacao(ListaMovimentacaoFinanceira *lista_movi_financeira, Lista_ContaBancaria *lista_conta_bancaria);
TipoApontador ValidarConta (Lista_ContaBancaria *lista_conta_bancaria, int x, int y);
char *ValidarTipoMovi ();
double ValidarValorMovi (char *tipo_movi);
void SalvarMoviNaLista(ListaMovimentacaoFinanceira *lista_movi, TipoApontadorMovi pont_movi);
char *ValidarData (ListaMovimentacaoFinanceira *lista_movi, int codigo);
TipoApontadorMovi BuscarUltimaData(ListaMovimentacaoFinanceira *lista_movi, int codigo);
ListaMovimentacaoFinanceira *BuscarMoviPorCodigo(TipoApontador reg_conta, ListaMovimentacaoFinanceira *lista_movi);
void ListarMovi(Lista_ContaBancaria *lista_conta, ListaMovimentacaoFinanceira *lista_movi);

#endif