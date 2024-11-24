#include "C:\Users\User\Documents\Tudo em C\Estrutura de dados\funcoes.h"

void iniciar_lista(Lista_ContaBancaria *lista_contaBancaria, ListaMovimentacaoFinanceira *lista_movi_financeira)
{
    lista_contaBancaria-> Primeiro = NULL;
    lista_contaBancaria-> Ultimo = NULL;

    lista_movi_financeira-> Primeiro = NULL;
    lista_movi_financeira-> Ultimo = NULL;
}