/*
Autor: Wesley Nobuyuki Tomimori Waterkemper
Data: 10/11/2024
Objetivo do trecho: Inicializar a lista bancária
*/
#include "funcoes.h"

void iniciar_lista(Lista_ContaBancaria *lista_contaBancaria, ListaMovimentacaoFinanceira *lista_movi_financeira)
{
    lista_contaBancaria-> Primeiro = NULL;
    lista_contaBancaria-> Ultimo = NULL;

    lista_movi_financeira-> Primeiro = NULL;
    lista_movi_financeira-> Ultimo = NULL;
}