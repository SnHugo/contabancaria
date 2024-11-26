/*
Autor: Wesley Nobuyuki Tomimori Waterkemper
Data: 10/11/2024
Objetivo do trecho: Inicializar a lista bancária
*/
#include "funcoes.h"

void iniciar_lista_conta(Lista_ContaBancaria *lista_contaBancaria)
{
    lista_contaBancaria-> Primeiro = NULL;
    lista_contaBancaria-> Ultimo = NULL;
}

void iniciar_lista_movi(ListaMovimentacaoFinanceira *lista_movi_financeira)
{
    lista_movi_financeira-> Primeiro = NULL;
    lista_movi_financeira-> Ultimo = NULL;
}