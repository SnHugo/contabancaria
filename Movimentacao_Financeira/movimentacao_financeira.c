/*
Autor: Wesley Nobuyuki 
Data: 10/11/2024
Objetivo do trecho: 
*/

#include "C:\Trabalho_ContaBancaria\funcoes.h"

TipoApontadorMovi ValidarNumeroSequencial(ListaMovimentacaoFinanceira *lista_movi_financeira, int sequecial)
{
    TipoApontadorMovi pont = lista_movi_financeira-> Primeiro;

    if (pont != NULL)
    {
        while (pont != NULL)
        {
            if (pont-> conteudo_movi.sequencial == sequecial)
            {
                return pont;
            }
            pont = pont-> proximo;
        }
    }
    return NULL;
}

void RealizarMovimentacao(ListaMovimentacaoFinanceira *lista_movimentacao, MovimentacaoFinanceira reg_movimentacao)
{
    TipoApontadorMovi validar = (TipoApontadorMovi)malloc(sizeof(TipoMovimentacao));

}