/*
Autor: Hugo Cesar Fernandes de Macedo
Data: 23/11/2024
Objetivo do trecho: Imprimir registro das contas selecionadas
*/
#include "C:\Users\User\Documents\Tudo em C\Estrutura de dados\funcoes.h"

void imprimir_Registro(ContaBancaria reg_conta)
{
    tela();

    gotoxy(10, 7);
    printf("[1] Codigo..............: %d", reg_conta.cd_conta);
    gotoxy(10, 9);
    printf("[2] Banco...............: %s", reg_conta.banco);
    gotoxy(10, 11);
    printf("[3] Agencia.............: %s", reg_conta.agencia);
    gotoxy(10, 13);
    printf("[4] Numero conta........: %s", reg_conta.numero_conta);
    gotoxy(10, 15);
    printf("[5] Tipo conta..........: %s", reg_conta.tipo_conta);
    gotoxy(10, 17);
    printf("[6] Saldo...............: %.2lf", reg_conta.vl_saldo);
    gotoxy(10, 19);
    printf("[7] Limite..............: %.2lf", reg_conta.vl_limite);
    gotoxy(10, 21);
    printf("[8] Status..............: %s", reg_conta.status);
}
