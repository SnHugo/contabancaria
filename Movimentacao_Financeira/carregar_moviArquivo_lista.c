/*
Autor: Wesley Nobuyuki Tomimori Waterkemper

    Nome: Hugo Cesar Fernandes de Macedo        RA: 161548-2023
    Nome: Wesley Nobuyuki Tomimori Waterkemper  RA: 175944-2024

Data: 26/11/2024
Objetivo do trecho: Funcao que que passa a movimentacao no fwrite.
*/

#include "C:\Trabalho_ControleBancario\funcoes.h"


void salvar_moviArquivo_lista(ListaMovimentacaoFinanceira *lista_movi, MovimentacaoFinanceira reg_movi)
{
    TipoApontadorMovi pont_movi = (TipoApontadorMovi)malloc(sizeof(TipoMovimentacao));
    pont_movi-> conteudo_movi = reg_movi;
    
    if (lista_movi-> Primeiro == NULL)
    {
        pont_movi-> anterior = NULL;
        pont_movi-> proximo = NULL;
        lista_movi-> Primeiro = pont_movi;
    }
    else
    {
        pont_movi-> anterior = lista_movi-> Ultimo;
        pont_movi-> proximo = NULL;
        lista_movi-> Ultimo-> proximo = pont_movi;
    }
    lista_movi-> Ultimo = pont_movi;
}