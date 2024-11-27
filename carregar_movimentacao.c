/*
Autor: Wesley Nobuyuki Tomimori Waterkemper

    Nome: Hugo Cesar Fernandes de Macedo        RA: 161548-2023
    Nome: Wesley Nobuyuki Tomimori Waterkemper  RA: 175944-2024

Data: 26/11/2024
Objetivo do trecho: Função para carregar as movimentações financeiras salvas
*/
#include "funcoes.h"


ListaMovimentacaoFinanceira carregar_movim() 
{
    tela();
    FILE *MOVIM = fopen("lista_movi.dat", "rb");
    ListaMovimentacaoFinanceira m;
    MovimentacaoFinanceira reg_mov;

    iniciar_lista_movi(&m);


    if (MOVIM == NULL) {
        gotoxy(07, 23);
        printf("Erro ao abrir arquivo de movimentacoes");
        getch();
    }
    else
    {
        while (fread(&reg_mov, sizeof(MovimentacaoFinanceira), 1, MOVIM)) 
        {
            salvar_moviArquivo_lista(&m, reg_mov);
        }

        fclose(MOVIM);
        gotoxy(07, 23);
        printf("Lista de movimentacoes carregada com sucesso!");
        getch();
    }
    return m;
}