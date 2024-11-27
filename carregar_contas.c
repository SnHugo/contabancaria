/*
Autor: Wesley Nobuyuki Tomimori Waterkemper

    Nome: Hugo Cesar Fernandes de Macedo        RA: 161548-2023
    Nome: Wesley Nobuyuki Tomimori Waterkemper  RA: 175944-2024

Data: 26/11/2024
Objetivo do trecho: Funcao que que passa a conta no fwrite.
*/
#include "funcoes.h"


Lista_ContaBancaria carregar_contas() 
{
    tela();
    FILE *CONTAS = fopen("lista_conta.dat", "rb");
    ContaBancaria reg_conta;
    TipoApontadorConta aux;
    Lista_ContaBancaria lista_contaBancaria;

    iniciar_lista_conta(&lista_contaBancaria);

    if (CONTAS == NULL) {
        gotoxy(07, 23);
        printf("Erro ao abrir lista de contas.");
        getch();
    }
    else
    {
        while (fread(&reg_conta, sizeof(ContaBancaria), 1, CONTAS))
        {
            salvar_contaArquivo_lista(&lista_contaBancaria, reg_conta);
        }

        fclose(CONTAS);
        gotoxy(07, 23);
        printf("Lista de contas carregada.");
        getch();
    }

    return lista_contaBancaria;
}