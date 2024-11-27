/*
Autor: Wesley Nobuyuki Tomimori Waterkemper

    Nome: Hugo Cesar Fernandes de Macedo        RA: 161548-2023
    Nome: Wesley Nobuyuki Tomimori Waterkemper  RA: 175944-2024

Data: 26/11/2024
Objetivo do trecho: Salvar as movimentacoes no arquivo .DAT
*/

#include "funcoes.h"


void salvar_movi (ListaMovimentacaoFinanceira *lista_movi)
{
    FILE *MOVIM = fopen("lista_movi.dat", "wb+");
    TipoApontadorMovi percorrer_movi = lista_movi-> Primeiro;

    if (MOVIM != NULL)
    {
        while (fwrite(&percorrer_movi-> conteudo_movi, sizeof(ContaBancaria), 1, MOVIM))
        {
            percorrer_movi = percorrer_movi-> proximo;
        }
        gotoxy(7, 23);
        printf("Arquivos de Movimentacao salvos!!!");
        getch();
    }
    else
    {
        gotoxy(7, 23);
        printf("Erro: Falha ao abrir arquivo!!! ");
        getch();
    }

    fclose (MOVIM);
}