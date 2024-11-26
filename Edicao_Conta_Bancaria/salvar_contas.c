/*
Autor: Wesley Nobuyuki Tomimori Waterkemper

    Nome: Hugo Cesar Fernandes de Macedo        RA: 161548-2023
    Nome: Wesley Nobuyuki Tomimori Waterkemper  RA: 175944-2024

Data: 26/11/2024
Objetivo do trecho: Salvar as contas no arquivo .DAT
*/

#include "C:\Trabalho_ControleBancario\funcoes.h"


void salvar_contas (Lista_ContaBancaria *lista_conta)
{
    FILE *CONTAS = fopen("lista_conta.dat", "wb+");
    TipoApontadorConta percorrer_conta = lista_conta-> Primeiro;

    if (CONTAS != NULL)
    {
        while (fwrite(&percorrer_conta-> conteudo, sizeof(ContaBancaria), 1, CONTAS))
        {
            percorrer_conta = percorrer_conta-> proximo;
        }
        gotoxy(7, 23);
        printf("Arquivos Cadastro Salvos!!!");
        getch();
    }
    else
    {
        gotoxy(7, 23);
        printf("Erro: Falha ao abrir arquivo!!! ");
        getch();
    }

    fclose (CONTAS);
}