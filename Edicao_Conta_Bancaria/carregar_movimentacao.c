/*
Autor: Hugo Cesar Fernandes de Macedo
Data: 26/11/2024
Objetivo do trecho: Função para carregar as movimentações financeiras salvas
*/
#include "C:\Users\User\Documents\Tudo em C\Estrutura de dados\funcoes.h"

void carregar_movim(ListaMovimentacaoFinanceira *m, const char *name) {
    FILE *MOVIM = fopen(name, "rb");
    MovimentacaoFinanceira reg_mov;
    TipoApontadorMovi movi;

    if (MOVIM == NULL) {
        gotoxy(07, 23);
        printf("Erro ao abrir arquivo de movimentacoes");
        getch();
        return;
    }

    while (fread(&reg_mov, sizeof(MovimentacaoFinanceira), 1, MOVIM) == 1) {
        movi = (TipoApontadorMovi)malloc(sizeof(TipoMovimentacao));

        movi->conteudo_movi = reg_mov;
        movi->proximo = NULL;

        if (m->Primeiro == NULL) {
            m->Primeiro = movi;
            m->Ultimo = movi;
        } else {
            m->Ultimo->proximo = movi;
            m->Ultimo = movi;
        }
    }

    fclose(MOVIM);
    gotoxy(07, 23);
    printf("Lista de movimentacoes carregada com sucesso!");
    getch();
}