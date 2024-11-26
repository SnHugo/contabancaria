/*
Autor: Hugo Cesar Fernandes de Macedo
Data: 26/11/2024
Objetivo do trecho: Carregar as contas cadastradas anteriormente no arquivo .DAT
*/
#include "C:\Users\User\Documents\Tudo em C\Estrutura de dados\funcoes.h"

void carregar_contas(Lista_ContaBancaria *lista_contaBancaria, const char *name) {
    FILE *CONTAS = fopen(name, "rb");
    ContaBancaria reg_conta;
    TipoApontadorConta aux;

    if (CONTAS == NULL) {
        gotoxy(07, 23);
        printf("Erro ao abrir lista de contas.");
        getch();
        return;
    }

    while (fread(&reg_conta, sizeof(ContaBancaria), 1, CONTAS) == 1) {
        aux = (TipoApontadorConta) malloc (sizeof(TipoConta));

        aux->conteudo = reg_conta;
        aux->proximo = NULL;

        if (lista_contaBancaria->Primeiro == NULL) {
            lista_contaBancaria->Primeiro = aux;
            lista_contaBancaria->Ultimo = aux;
        } else {
            lista_contaBancaria->Ultimo->proximo = aux;
            lista_contaBancaria->Ultimo = aux;
        }
    }

    fclose(CONTAS);
    gotoxy(07, 23);
    printf("Lista de contas carregada.");
    getch();
}