/*
Autor: Hugo Cesar Fernandes de Macedo
Data: 13/11/2024
Objetivo do trecho: Função para que no fgets do tipo_conta, o usuário escolha qual o tipo de conta ele deseja selecionar.
*/
#include "funcoes.h"
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>

const char* selecionar_tipo_conta() {
    
    int opcao;
    
    do {
        gotoxy(07, 23);
        printf("Digite 1 para Poupanca, 2 para Corrente, 3 para Cartao de Credito: ");
        fflush(stdin);
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Poupanca");
                return "Poupanca";
            case 2:
                printf("Corrente");
                return "Corrente";
            case 3:
                printf("Cartao de Credito");
                return "Cartao de Credito";
            default:
                gotoxy(07, 23);
                printf("                                                                        ");
                gotoxy(07, 23);
                printf("Opcao invalida. Tente novamente.");
        }
    } while (opcao < 1 || opcao > 3);

    return "";
}
