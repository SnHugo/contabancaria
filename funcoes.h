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






void tela();

#endif