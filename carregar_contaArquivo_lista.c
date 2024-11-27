/*
Autor: Wesley Nobuyuki Tomimori Waterkemper

    Nome: Hugo Cesar Fernandes de Macedo        RA: 161548-2023
    Nome: Wesley Nobuyuki Tomimori Waterkemper  RA: 175944-2024

Data: 26/11/2024
Objetivo do trecho: Funcao que que passa a conta no fwrite.
*/

#include "C:\Trabalho_ControleBancario\funcoes.h"

void salvar_contaArquivo_lista(Lista_ContaBancaria *lista_contaBancaria, ContaBancaria reg_conta)
{
        TipoApontadorConta aux = (TipoApontadorConta) malloc (sizeof(TipoConta));

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