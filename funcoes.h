/*
Autor: Hugo Cesar Fernandes de Macedo
Data: 24/10/2024
Objetivo do trecho: Criar as demais structs para criação de contas bancárias e movimentação
*/

#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED

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
} movimenta_bancaria;

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

void gotoxy(int x, int y);
void tela();
void tela_cadastroDeContas(Lista_ContaBancaria *lista_contaBancaria);
void tela_movimentacaoFinanceira();
void tela_digitacaoContas();
void tela_contasCadastradas(conta_bancaria reg_conta, int proximaLinha);

void iniciar_lista(Lista_ContaBancaria *lista_contaBancaria);

int contador(Lista_ContaBancaria *lista_contaBancaria);
TipoApontador pesquisa(Lista_ContaBancaria *lista_contaBancaria, int codigo);

void cadastrar_conta(Lista_ContaBancaria *lista_contaBancaria, int opc);
void imprimir_listaDasContasBancarias(Lista_ContaBancaria *lista_contaBancaria);

#endif
