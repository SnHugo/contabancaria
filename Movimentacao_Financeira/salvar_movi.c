#include "C:\Trabalho_ControleBancario\funcoes.h"


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