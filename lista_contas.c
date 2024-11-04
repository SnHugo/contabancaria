#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include "funcoes.h"

void iniciar_lista(Lista_ContaBancaria *lista_contaBancaria)
{
    lista_contaBancaria-> Primeiro = NULL;
    lista_contaBancaria-> Ultimo = NULL;
}