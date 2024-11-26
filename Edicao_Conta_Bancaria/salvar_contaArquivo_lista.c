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